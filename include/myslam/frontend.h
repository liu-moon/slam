#pragma once

#include "myslam/common_include.h"
#include <opencv2/features2d.hpp>
#include "myslam/map.h"

class Backend;
// class Map;
class Viewer;

class Frontend
{
public:
    EIGEN_MAKE_ALIGNED_OPERATOR_NEW;
    typedef std::shared_ptr<Frontend> Ptr;

    Frontend();

    void SetBackend(std::shared_ptr<Backend> backend) { backend_ = backend; }

    void SetMap(Map::Ptr map) { map_ = map; }

    void SetViewer(std::shared_ptr<Viewer> viewer) { viewer_ = viewer; }


private:
    // params
    int num_features_ = 200;
    int num_features_init_ = 100;
    int num_features_tracking_ = 50;
    int num_features_tracking_bad_ = 20;
    int num_features_needed_for_keyframe_ = 80;

    std::shared_ptr<Backend> backend_ = nullptr;
    Map::Ptr map_ = nullptr;
    std::shared_ptr<Viewer> viewer_ = nullptr;

    // utilities
    cv::Ptr<cv::GFTTDetector> gftt_;  // feature detector in opencv
};