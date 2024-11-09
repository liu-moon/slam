#pragma once


#include "myslam/common_include.h"
#include "myslam/dataset.h"

class VisualOdometry
{
public:
    EIGEN_MAKE_ALIGNED_OPERATOR_NEW;
    typedef std::shared_ptr<VisualOdometry> Ptr;

    /**
     * @brief VisualOdometry的构造函数
     * 用于设置配置文件的路径
     * 
     * @param config_path 
     */
    VisualOdometry(std::string &config_path);

    bool Init();

private:
    std::string config_file_path_;

    // dataset
    Dataset::Ptr dataset_ = nullptr;
};