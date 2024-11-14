#include "myslam/visual_odometry.h"
#include "myslam/config.h"

VisualOdometry::VisualOdometry(std::string &config_path)
    : config_file_path_(config_path) {}

bool VisualOdometry::Init()
{
    // 读取配置文件
    // config为私有构造函数，为单例模式，可以直接调用Config::SetParameterFile
    if (Config::SetParameterFile(config_file_path_) == false)
    {
        return false;
    }
    LOG(INFO) << Config::Get<std::string>("dataset_dir");
    dataset_ = Dataset::Ptr(new Dataset(Config::Get<std::string>("dataset_dir"))); // 返回string类型的变量

    CHECK_EQ(dataset_->Init(), true); // CHECK_EQ 判断是否初始化成功

    // create components and links
    // 创建组件和链接
    frontend_ = Frontend::Ptr(new Frontend);
    backend_ = Backend::Ptr(new Backend);
    map_ = Map::Ptr(new Map);
    viewer_ = Viewer::Ptr(new Viewer);

    // 前端配置
    frontend_->SetBackend(backend_);                                       // 配置后端
    frontend_->SetMap(map_);                                               // 配置地图
    frontend_->SetViewer(viewer_);                                         // viewer
    frontend_->SetCameras(dataset_->GetCamera(0), dataset_->GetCamera(1)); // 配置相机

    // 后端配置
    backend_->SetMap(map_);                                               // 配置地图
    backend_->SetCameras(dataset_->GetCamera(0), dataset_->GetCamera(1)); // 配置相机

    // viewer配置
    viewer_->SetMap(map_); // 配置地图

    return true;
}

void VisualOdometry::Run()
{
    while (1)
    {
        LOG(INFO) << "VO is running";
        if (Step() == false)
        {
            break;
        }
    }
}

bool VisualOdometry::Step() {
    Frame::Ptr new_frame = dataset_->NextFrame();
    if (new_frame == nullptr) return false;

    auto t1 = std::chrono::steady_clock::now();
    bool success = frontend_->AddFrame(new_frame);
    auto t2 = std::chrono::steady_clock::now();
    auto time_used =
        std::chrono::duration_cast<std::chrono::duration<double>>(t2 - t1);
    LOG(INFO) << "VO cost time: " << time_used.count() << " seconds.";
    return true;
}