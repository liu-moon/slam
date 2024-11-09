#include "myslam/dataset.h"
#include <fstream>

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
        for (int k = 0; k < 3; ++k) {
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