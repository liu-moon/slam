#pragma once

#include "myslam/common_include.h"
#include "myslam/mappoint.h"

class Map
{
public:
    EIGEN_MAKE_ALIGNED_OPERATOR_NEW;  // 内存对齐
    typedef std::shared_ptr<Map> Ptr; // 共享指针
    typedef std::unordered_map<unsigned long, MapPoint::Ptr> LandmarksType;
    typedef std::unordered_map<unsigned long, Frame::Ptr> KeyframesType;
    Map();

    void InsertMapPoint(MapPoint::Ptr map_point);
    void InsertKeyFrame(Frame::Ptr frame);

    /// 清理map中观测数量为零的点
    void CleanMap();

    /// 获取激活关键帧
    KeyframesType GetActiveKeyFrames()
    {
        std::unique_lock<std::mutex> lck(data_mutex_);
        return active_keyframes_;
    }

    /// 获取激活地图点
    LandmarksType GetActiveMapPoints()
    {
        std::unique_lock<std::mutex> lck(data_mutex_);
        return active_landmarks_;
    }

private:
    // 将旧的关键帧置为不活跃状态
    void RemoveOldKeyframe();

    std::mutex data_mutex_;

    LandmarksType landmarks_;        // all landmarks
    LandmarksType active_landmarks_; // active landmarks
    KeyframesType keyframes_;        // all key-frames
    KeyframesType active_keyframes_; // all key-frames

    Frame::Ptr current_frame_ = nullptr;

    int num_active_keyframes_ = 7; // 激活的关键帧数量
};