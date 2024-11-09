#pragma once

struct Frame
{
public:
    EIGEN_MAKE_ALIGNED_OPERATOR_NEW;    // 内存对齐
    typedef std::shared_ptr<Frame> Ptr; // 共享指针

    unsigned long id_ = 0;          // 当前帧的id
    unsigned long keyframe_id_ = 0; // 关键帧的id
    bool is_keyframe_ = false;      // 是否为关键帧
    double time_stamp_;             // 时间戳
    SE3 pose_;                      // Tcw 形式的Pose
    std::mutex pose_mutex_;         // Pose数据锁
    cv::Mat left_img_, right_img_;  // stereo images

    // 左图中提取的特征
    std::vector<std::shared_ptr<Feature>> features_left_;
    // 右图中对应的特征，如果没有对应的，则设置为 nullptr
    std::vector<std::shared_ptr<Feature>> features_right_;

public: // 数据成员
    Frame() {}

    Frame(long id, double time_stamp, const SE3 &pose, const Mat &left,
          const Mat &right);

    // set and get pose, thread safe
    SE3 Pose()
    {
        std::unique_lock<std::mutex> lck(pose_mutex_);
        return pose_;
    }

    void SetPose(const SE3 &pose)
    {
        std::unique_lock<std::mutex> lck(pose_mutex_);
        pose_ = pose;
    }

    /// 设置关键帧并分配并键帧id
    void SetKeyFrame();

    /// 工厂构建模式，分配id
    static std::shared_ptr<Frame> CreateFrame();
};
