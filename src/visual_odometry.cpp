#include "myslam/visual_odometry.h"
#include "myslam/config.h"

VisualOdometry::VisualOdometry(std::string &config_path)
    : config_file_path_(config_path) {}

bool VisualOdometry::Init() {
    // 读取配置文件
    if (Config::SetParameterFile(config_file_path_) == false) {
        return false;
    }

    dataset_ =  Dataset::Ptr(new Dataset(Config::Get<std::string>("dataset_dir"))); // 返回string类型的变量
    CHECK_EQ(dataset_->Init(), true);   // CHECK_EQ 判断是否初始化成功

    // create components and links
    // 创建组件和链接
    frontend_ = Frontend::Ptr(new Frontend);
    backend_ = Backend::Ptr(new Backend);
    map_ = Map::Ptr(new Map);
    viewer_ = Viewer::Ptr(new Viewer);

    // frontend_->SetBackend(backend_);
    // frontend_->SetMap(map_);
    // frontend_->SetViewer(viewer_);
    // frontend_->SetCameras(dataset_->GetCamera(0), dataset_->GetCamera(1));

    // backend_->SetMap(map_);
    // backend_->SetCameras(dataset_->GetCamera(0), dataset_->GetCamera(1));

    // viewer_->SetMap(map_);

    return true;
}