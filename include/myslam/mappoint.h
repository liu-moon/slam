#pragma once

#include "myslam/common_include.h"
#include "myslam/feature.h"

struct MapPoint {
   public:
    EIGEN_MAKE_ALIGNED_OPERATOR_NEW;    // 内存对齐
    typedef std::shared_ptr<MapPoint> Ptr;  // 共享指针
    unsigned long id_ = 0;  // 地图点id
    bool is_outlier_ = false;   // 是否为异常点
    Vec3 pos_ = Vec3::Zero();  // Position in world 世界坐标系中位置
    std::mutex data_mutex_;    // 数据锁
    int observed_times_ = 0;  // 被特征匹配算法观察到的次数
    std::list<std::weak_ptr<Feature>> observations_;    // 该地图点被哪些特征观测

    MapPoint() {}

    MapPoint(long id, Vec3 position);

    Vec3 Pos() {
        std::unique_lock<std::mutex> lck(data_mutex_);
        return pos_;
    }

    void SetPos(const Vec3 &pos) {  // 设置三维坐标
        std::unique_lock<std::mutex> lck(data_mutex_);  // 函数退出自动解锁
        pos_ = pos;
    };

    void AddObservation(std::shared_ptr<Feature> feature) { // 添加观测
        std::unique_lock<std::mutex> lck(data_mutex_);
        observations_.push_back(feature);
        observed_times_++;
    }

    void RemoveObservation(std::shared_ptr<Feature> feat);  // 特征可能outlier

    std::list<std::weak_ptr<Feature>> GetObs() {
        std::unique_lock<std::mutex> lck(data_mutex_);
        return observations_;
    }

    // factory function
    static MapPoint::Ptr CreateNewMappoint();
};