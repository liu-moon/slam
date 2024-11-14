#pragma once

#include "myslam/common_include.h"
#include <opencv2/features2d.hpp>
#include "myslam/map.h"
#include "myslam/camera.h"
#include "myslam/frame.h"

enum class FrontendStatus { INITING, TRACKING_GOOD, TRACKING_BAD, LOST };

class Backend;
// class Map;
class Viewer;

class Frontend
{
public:
    EIGEN_MAKE_ALIGNED_OPERATOR_NEW;
    typedef std::shared_ptr<Frontend> Ptr;

    /**
     * @brief 前端构造函数
     * 
     */
    Frontend();

    /**
     * @brief 配置后端
     * 
     * @param backend 
     */
    void SetBackend(std::shared_ptr<Backend> backend) { backend_ = backend; }

    /**
     * @brief 配置地图
     * 
     * @param map 
     */
    void SetMap(Map::Ptr map) { map_ = map; }

    /**
     * @brief 配置viewer
     * 
     * @param viewer 
     */
    void SetViewer(std::shared_ptr<Viewer> viewer) { viewer_ = viewer; }

    /**
     * @brief 配置左右目相机
     * 
     * @param left 
     * @param right 
     */
    void SetCameras(Camera::Ptr left, Camera::Ptr right)
    {
        camera_left_ = left;
        camera_right_ = right;
    }

    
    bool AddFrame(Frame::Ptr frame);

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

    Camera::Ptr camera_left_ = nullptr;  // 左侧相机
    Camera::Ptr camera_right_ = nullptr; // 右侧相机

    // utilities
    cv::Ptr<cv::GFTTDetector> gftt_; // feature detector in opencv

    Frame::Ptr current_frame_ = nullptr;  // 当前帧
    Frame::Ptr last_frame_ = nullptr;     // 上一帧

    FrontendStatus status_ = FrontendStatus::INITING;

    bool StereoInit();

    bool Track();

    bool Reset();

    int DetectFeatures();

    int FindFeaturesInRight();

    bool BuildInitMap();
};