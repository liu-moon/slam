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

    void AddCurrentFrame(Frame::Ptr current_frame);

    void UpdateMap();

private:
    Map::Ptr map_ = nullptr;

    std::thread viewer_thread_;

    void ThreadLoop();

    std::mutex viewer_data_mutex_;

    Frame::Ptr current_frame_ = nullptr;

    std::unordered_map<unsigned long, Frame::Ptr> active_keyframes_;

    std::unordered_map<unsigned long, MapPoint::Ptr> active_landmarks_;

    bool map_updated_ = false; // 地图更新状态
};