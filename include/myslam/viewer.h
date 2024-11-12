#pragma once

#include "myslam/common_include.h"
#include "myslam/map.h"

/**
 * @brief 可视化
 *
 */
class Viewer
{
public:
    EIGEN_MAKE_ALIGNED_OPERATOR_NEW;
    typedef std::shared_ptr<Viewer> Ptr;

    Viewer();

    /**
     * @brief 配置地图
     * 
     * @param map 
     */
    void SetMap(Map::Ptr map) { map_ = map; }

private:
    Map::Ptr map_ = nullptr;

    std::thread viewer_thread_;

    void ThreadLoop();
};