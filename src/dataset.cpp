#include "myslam/dataset.h"
#include <fstream>
#include <boost/format.hpp>
#include <opencv2/opencv.hpp>

using namespace std;

Dataset::Dataset(const std::string& dataset_path)
    : dataset_path_(dataset_path) {}


bool Dataset::Init() {
    // read camera intrinsics and extrinsics
    ifstream fin(dataset_path_ + "/calib.txt");
    if (!fin) {
        LOG(ERROR) << "cannot find " << dataset_path_ << "/calib.txt!";
        return false;
    }

    for (int i = 0; i < 4; ++i) {
        char camera_name[3];
        for (int k = 0; k < 3; ++k) {   // 读取名称
            fin >> camera_name[k];
            LOG(INFO) << camera_name[k];
        }
        double projection_data[12];
        for (int k = 0; k < 12; ++k) {
            fin >> projection_data[k];
        }
        Mat33 K;
        K << projection_data[0], projection_data[1], projection_data[2],
            projection_data[4], projection_data[5], projection_data[6],
            projection_data[8], projection_data[9], projection_data[10];
        LOG(INFO) << "K = " << endl << K << endl;
        Vec3 t;
        t << projection_data[3], projection_data[7], projection_data[11];
        LOG(INFO) << "t = " << endl << t << endl;
        t = K.inverse() * t;    // 平移量转换到相机坐标系
        LOG(INFO) << "t = " << endl << t << endl;
        K = K * 0.5;
        LOG(INFO) << "K = " << endl << K << endl;
        
        Camera::Ptr new_camera(new Camera(K(0, 0), K(1, 1), K(0, 2), K(1, 2),
                                          t.norm(), SE3(SO3(), t)));
        cameras_.push_back(new_camera);
        LOG(INFO) << "Camera " << i << " extrinsics: " << t.transpose();
    }
    fin.close();
    current_image_index_ = 0;
    return true;
}


Frame::Ptr Dataset::NextFrame() {
    boost::format fmt("%s/image_%d/%06d.png");  // 生成字符串
    cv::Mat image_left, image_right;    // 左图 右图
    // read images
    image_left =
        cv::imread((fmt % dataset_path_ % 0 % current_image_index_).str(),
                   cv::IMREAD_GRAYSCALE);   // 以灰度模式加载图像 拼接路径
    image_right =
        cv::imread((fmt % dataset_path_ % 1 % current_image_index_).str(),
                   cv::IMREAD_GRAYSCALE);

    if (image_left.data == nullptr || image_right.data == nullptr) {    // 判断是否读到图像
        LOG(WARNING) << "cannot find images at index " << current_image_index_;
        return nullptr;
    }

    cv::Mat image_left_resized, image_right_resized;    // 缩放图像
    cv::resize(image_left, image_left_resized, cv::Size(), 0.5, 0.5,
               cv::INTER_NEAREST);  // 宽度方向缩放比例 高度方向缩放比例 最近邻插值
    cv::resize(image_right, image_right_resized, cv::Size(), 0.5, 0.5,
               cv::INTER_NEAREST);

    auto new_frame = Frame::CreateFrame();
    new_frame->left_img_ = image_left_resized;
    new_frame->right_img_ = image_right_resized;
    current_image_index_++;
    return new_frame;
}