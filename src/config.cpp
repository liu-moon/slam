#include "myslam/config.h"

bool Config::SetParameterFile(const std::string &filename) {
    if (config_ == nullptr)
        config_ = std::shared_ptr<Config>(new Config);
    config_->file_ = cv::FileStorage(filename.c_str(), cv::FileStorage::READ);  // 以只读模式打开文件
    if (config_->file_.isOpened() == false) {
        LOG(ERROR) << "parameter file " << filename << " does not exist.";
        config_->file_.release();   // 释放文件资源
        return false;
    }
    return true;
}

Config::~Config() {
    if (file_.isOpened())
        file_.release();  // 释放文件资源
}

std::shared_ptr<Config> Config::config_ = nullptr;