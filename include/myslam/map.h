#pragma once

#include "myslam/common_include.h"

class Map {
   public:
    EIGEN_MAKE_ALIGNED_OPERATOR_NEW;    // 内存对齐
    typedef std::shared_ptr<Map> Ptr;   // 共享指针
    // typedef std::unordered_map<unsigned long, MapPoint::Ptr> LandmarksType; // 地标类型
    // typedef std::unordered_map<unsigned long, Frame::Ptr> KeyframesType;    // 关键帧类型

    Map();

//     /// 增加一个关键帧
//     void InsertKeyFrame(Frame::Ptr frame);
//     /// 增加一个地图顶点
//     void InsertMapPoint(MapPoint::Ptr map_point);

//     /// 获取所有地图点
//     LandmarksType GetAllMapPoints() {
//         std::unique_lock<std::mutex> lck(data_mutex_);
//         return landmarks_;
//     }
//     /// 获取所有关键帧
//     KeyframesType GetAllKeyFrames() {
//         std::unique_lock<std::mutex> lck(data_mutex_);
//         return keyframes_;
//     }

//     /// 获取激活地图点
//     LandmarksType GetActiveMapPoints() {
//         std::unique_lock<std::mutex> lck(data_mutex_);
//         return active_landmarks_;
//     }

//     /// 获取激活关键帧
//     KeyframesType GetActiveKeyFrames() {
//         std::unique_lock<std::mutex> lck(data_mutex_);
//         return active_keyframes_;
//     }

//     /// 清理map中观测数量为零的点
//     void CleanMap();

//    private:
//     // 将旧的关键帧置为不活跃状态
//     void RemoveOldKeyframe();

//     std::mutex data_mutex_; // 数据锁
//     LandmarksType landmarks_;         // all landmarks 所有的地标
//     LandmarksType active_landmarks_;  // active landmarks 激活的地标
//     KeyframesType keyframes_;         // all key-frames 所有的关键帧
//     KeyframesType active_keyframes_;  // active frames 激活的关键帧

//     Frame::Ptr current_frame_ = nullptr;    // 当前帧

//     // settings
//     int num_active_keyframes_ = 7;  // 激活的关键帧数量
};