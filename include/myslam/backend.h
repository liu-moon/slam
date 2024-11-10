#pragma once

#include "myslam/common_include.h"
#include "myslam/map.h"
#include "myslam/camera.h"

// class Map;

class Backend
{
public:
    EIGEN_MAKE_ALIGNED_OPERATOR_NEW;
    typedef std::shared_ptr<Backend> Ptr;

    Backend();

    void SetMap(std::shared_ptr<Map> map) { map_ = map; }

    void SetCameras(Camera::Ptr left, Camera::Ptr right)
    {
        cam_left_ = left;
        cam_right_ = right;
    }

private:
    std::shared_ptr<Map> map_;

    Camera::Ptr cam_left_ = nullptr, cam_right_ = nullptr;
};