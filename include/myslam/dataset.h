#pragma once
#include "myslam/common_include.h"
#include "myslam/camera.h"

class Dataset
{
public:
    EIGEN_MAKE_ALIGNED_OPERATOR_NEW;
    typedef std::shared_ptr<Dataset> Ptr;

    Dataset(const std::string &dataset_path);

    bool Init();

private:
    std::string dataset_path_;
    int current_image_index_ = 0;
    std::vector<Camera::Ptr> cameras_;
};