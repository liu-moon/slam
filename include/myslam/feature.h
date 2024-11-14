#pragma once

#include "myslam/common_include.h"
#include "myslam/frame.h"

struct Frame;
struct MapPoint;

/**
 * @brief 2D 特征点类 todo：在三角化之后会被关联一个地图点
 * 
 */
struct Feature {
   public:
    EIGEN_MAKE_ALIGNED_OPERATOR_NEW;    // 内存对齐
    typedef std::shared_ptr<Feature> Ptr;   // 共享指针

    std::weak_ptr<Frame> frame_;         // 持有该feature的frame 避免shared_ptr产生的循环引用
    cv::KeyPoint position_;              // 2D提取位置
    std::weak_ptr<MapPoint> map_point_;  // 关联地图点

    bool is_outlier_ = false;       // 是否为异常点
    bool is_on_left_image_ = true;  // 标识是否提在左图，false为右图

   public:
    Feature() {}

    Feature(std::shared_ptr<Frame> frame, const cv::KeyPoint &kp)
        : frame_(frame), position_(kp) {}
};