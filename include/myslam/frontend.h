#pragma once

#include "myslam/common_include.h"
#include <opencv2/features2d.hpp>

class Backend;

class Frontend
{
public:
    EIGEN_MAKE_ALIGNED_OPERATOR_NEW;
    typedef std::shared_ptr<Frontend> Ptr;

    Frontend();

    void SetBackend(std::shared_ptr<Backend> backend) { backend_ = backend; }


private:
    // params
    int num_features_ = 200;
    int num_features_init_ = 100;
    int num_features_tracking_ = 50;
    int num_features_tracking_bad_ = 20;
    int num_features_needed_for_keyframe_ = 80;

    std::shared_ptr<Backend> backend_ = nullptr;

    // utilities
    cv::Ptr<cv::GFTTDetector> gftt_;  // feature detector in opencv
};