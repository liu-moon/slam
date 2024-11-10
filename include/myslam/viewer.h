#pragma once

#include "myslam/common_include.h"
#include "myslam/map.h"

class Viewer
{
public:
    EIGEN_MAKE_ALIGNED_OPERATOR_NEW;
    typedef std::shared_ptr<Viewer> Ptr;

    Viewer();

    void SetMap(Map::Ptr map) { map_ = map; }

private:

    Map::Ptr map_ = nullptr;

};