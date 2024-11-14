#include "myslam/frontend.h"
#include <opencv2/opencv.hpp>
#include "myslam/config.h"
#include "myslam/viewer.h"
#include "myslam/mappoint.h"
#include "myslam/algorithm.h"
#include "myslam/map.h"
#include "myslam/backend.h"

Frontend::Frontend()
{
    // todo
    // 在config/default.yaml中获取
    LOG(INFO) << "num_features:" << Config::Get<int>("num_features");
    gftt_ =
        cv::GFTTDetector::create(Config::Get<int>("num_features"), 0.01, 20);
    // GFTT 角点检测方法
    // maxCorners(最大角点数量) Config::Get<int>("num_features")
    // qualityLevel(角点质量的最低水平)：典型值为 0.01 ～ 0.1 设置较低的值会找到更多的角点  0.01
    // minDistance(角点之间的最小距离，单位为像素)  20

    num_features_init_ = Config::Get<int>("num_features_init"); // 特征点数量初始化

    num_features_ = Config::Get<int>("num_features"); // 特征点数量
                                                      // todo 区别 num_features_init_ and num_features_
};

bool Frontend::AddFrame(Frame::Ptr frame)
{
    current_frame_ = frame;

    switch (status_)
    {
    case FrontendStatus::INITING:
        StereoInit();
        break;
        // case FrontendStatus::TRACKING_GOOD:
        // case FrontendStatus::TRACKING_BAD:
        //     Track();
        //     break;
        // case FrontendStatus::LOST:
        //     Reset();
        //     break;
    }

    last_frame_ = current_frame_;
    return true;
}

bool Frontend::StereoInit()
{
    int num_features_left = DetectFeatures();      // 检测左图特征
    int num_coor_features = FindFeaturesInRight(); // 在当前帧的右图中查找 **对应的** 特征 特征：特征点坐标以及邻域
    if (num_coor_features < num_features_init_)
    {
        return false;
    }

    bool build_map_success = BuildInitMap(); // 使用单幅图像构建初始地图
    if (build_map_success)  // 初始化成功
    {
        status_ = FrontendStatus::TRACKING_GOOD;    // 更新状态
        if (viewer_)
        {
            viewer_->AddCurrentFrame(current_frame_);
            viewer_->UpdateMap();
        }
        return true;
    }
    return false;
}

bool Frontend::Track()
{
    // if (last_frame_) {
    //     current_frame_->SetPose(relative_motion_ * last_frame_->Pose());
    // }

    // int num_track_last = TrackLastFrame();
    // tracking_inliers_ = EstimateCurrentPose();

    // if (tracking_inliers_ > num_features_tracking_) {
    //     // tracking good
    //     status_ = FrontendStatus::TRACKING_GOOD;
    // } else if (tracking_inliers_ > num_features_tracking_bad_) {
    //     // tracking bad
    //     status_ = FrontendStatus::TRACKING_BAD;
    // } else {
    //     // lost
    //     status_ = FrontendStatus::LOST;
    // }

    // InsertKeyframe();
    // relative_motion_ = current_frame_->Pose() * last_frame_->Pose().inverse();

    // if (viewer_) viewer_->AddCurrentFrame(current_frame_);
    return true;
}

bool Frontend::Reset()
{
    LOG(INFO) << "Reset is not implemented. ";
    return true;
}

int Frontend::DetectFeatures()
{
    cv::Mat mask(current_frame_->left_img_.size(), CV_8UC1, 255); // 掩膜图像
    for (auto &feat : current_frame_->features_left_)
    { // 第一次运行时跳过 还没有特征点
        cv::rectangle(mask, feat->position_.pt - cv::Point2f(10, 10),
                      feat->position_.pt + cv::Point2f(10, 10), 0, cv::FILLED);
    }

    std::vector<cv::KeyPoint> keypoints;
    gftt_->detect(current_frame_->left_img_, keypoints, mask); // GFTT 检测器检测新特征点 mask限制检测区域
    int cnt_detected = 0;                                      // 新特征点数量
    for (auto &kp : keypoints)
    {
        current_frame_->features_left_.push_back(
            Feature::Ptr(new Feature(current_frame_, kp)));
        cnt_detected++;
    }

    LOG(INFO) << "Detect " << cnt_detected << " new features";
    return cnt_detected;
}

int Frontend::FindFeaturesInRight()
{
    // use LK flow to estimate points in the right image LK光流法
    std::vector<cv::Point2f> kps_left, kps_right;
    for (auto &kp : current_frame_->features_left_) // 遍历左图特征点
    {
        kps_left.push_back(kp->position_.pt); // kps_left添加特征点
        auto mp = kp->map_point_.lock();      // std::weak_ptr 类型的 map_point_ 需要调用lock()方法获得一个有效的 std::shared_ptr
        if (mp)
        { // 目前未执行
            // use projected points as initial guess
            auto px =
                camera_right_->world2pixel(mp->pos_, current_frame_->Pose());
            kps_right.push_back(cv::Point2f(px[0], px[1]));
        }
        else
        {
            // use same pixel in left iamge
            kps_right.push_back(kp->position_.pt); // 没有投影点的情况下，直接使用左图的特征点
        }
    }

    std::vector<uchar> status;
    Mat error;
    cv::calcOpticalFlowPyrLK(
        current_frame_->left_img_, current_frame_->right_img_, kps_left,
        kps_right, status, error, cv::Size(11, 11), 3,
        cv::TermCriteria(cv::TermCriteria::COUNT + cv::TermCriteria::EPS, 30,
                         0.01),
        cv::OPTFLOW_USE_INITIAL_FLOW); // status 输出状态向量 值为 1 表示光流跟踪成功，值为 0 表示跟踪失败。
                                       // error 输出错误向量 对应特征点的跟踪误差 用于过滤掉跟踪效果较差的点
                                       // cv::Size(11, 11) 搜索窗口大小
                                       // 3 金字塔的最大层数
                                       // TermCriteria 终止条件 最多迭代 30 次，或当误差小于 0.01 时停止
                                       // OPTFLOW_USE_INITIAL_FLOW 是否使用提供的初始点位置作为光流估计的起始值

    int num_good_pts = 0; // 成功跟踪的特征点数量
    for (size_t i = 0; i < status.size(); ++i)
    {
        if (status[i]) // 跟踪成功
        {
            cv::KeyPoint kp(kps_right[i], 7);                   // 7 特征点的邻域大小 经验值
            Feature::Ptr feat(new Feature(current_frame_, kp)); // 创建2D特征点
            feat->is_on_left_image_ = false;                    // 标识特征点在 左图还是右图
            current_frame_->features_right_.push_back(feat);    // 添加到右图特征
            num_good_pts++;
        }
        else // 跟踪失败
        {
            current_frame_->features_right_.push_back(nullptr); // 插入空指针 表示跟踪失败
        }
    }
    LOG(INFO) << "Find " << num_good_pts << " in the right image.";
    return num_good_pts;
}

bool Frontend::BuildInitMap()
{
    std::vector<SE3> poses{camera_left_->pose(), camera_right_->pose()};    // 相机的位姿
    for (size_t i = 0; i < poses.size(); ++i)
    {
        const auto &pose = poses[i];
        LOG(INFO) << "Pose " << i << ":";
        LOG(INFO) << "Translation:\n"
                  << pose.translation();
        LOG(INFO) << "Rotation Matrix:\n"
                  << pose.rotationMatrix();
    }

    size_t cnt_init_landmarks = 0;                                     // 初始化地图点计数器
    for (size_t i = 0; i < current_frame_->features_left_.size(); ++i) // 遍历左图中的特征点
    {
        if (current_frame_->features_right_[i] == nullptr) // 在右图中没有对应的特征点 则跳过
            continue;
        // create map point from triangulation 根据三角测量创建地图点
        std::vector<Vec3> points{   // 特征点在相机坐标系下的图像坐标
            camera_left_->pixel2camera( // 将图像的像素坐标转换为相机坐标系中的三维坐标 这里需要depth 默认为1
                Vec2(current_frame_->features_left_[i]->position_.pt.x,
                     current_frame_->features_left_[i]->position_.pt.y)),
            camera_right_->pixel2camera(
                Vec2(current_frame_->features_right_[i]->position_.pt.x,
                     current_frame_->features_right_[i]->position_.pt.y))};

        for (size_t i = 0; i < points.size(); ++i)
        {
            const auto &point = points[i];
            LOG(INFO) << "Point " << i << ": ("
                      << point[0] << ", "
                      << point[1] << ", "
                      << point[2] << ")";
        }

        Vec3 pworld = Vec3::Zero(); // 存储求解后的三维空间点

        if (triangulation(poses, points, pworld) && pworld[2] > 0)  // 三角化求点在世界坐标系中的位置
        {
            LOG(INFO) << pworld;
            auto new_map_point = MapPoint::CreateNewMappoint();
            new_map_point->SetPos(pworld);  // 设置三维坐标
            new_map_point->AddObservation(current_frame_->features_left_[i]);   // 建立左图和地图点的观测 该地图点在图中被观测 地图点->帧(特征点)
            new_map_point->AddObservation(current_frame_->features_right_[i]);  // 建立右图和地图点的观测
            current_frame_->features_left_[i]->map_point_ = new_map_point;  //该特征观察到了该地图点    特征点->地图点 双向关联
            current_frame_->features_right_[i]->map_point_ = new_map_point;
            cnt_init_landmarks++;   // 地图点计数器+1
            map_->InsertMapPoint(new_map_point);    // 插入地图
        }
    }
    current_frame_->SetKeyFrame();  // 标记为关键帧
    map_->InsertKeyFrame(current_frame_);   // 将当前关键帧插入到全局地图中
    backend_->UpdateMap();  // 后端更新

    LOG(INFO) << "Initial map created with " << cnt_init_landmarks
              << " map points";

    return true;
}