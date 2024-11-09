#pragma once


#include "myslam/common_include.h"

class VisualOdometry
{
public:
    EIGEN_MAKE_ALIGNED_OPERATOR_NEW;
    typedef std::shared_ptr<VisualOdometry> Ptr;

    /// 构造函数
    VisualOdometry(std::string &config_path);

private:
    std::string config_file_path_;
};