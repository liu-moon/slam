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

    /**
     * @brief 构造函数，创建线程标志并创建后端线程
     * 
     */
    Backend();

    /**
     * @brief 配置地图
     * 
     * @param map 
     */
    void SetMap(std::shared_ptr<Map> map) { map_ = map; }

    /**
     * @brief 配置相机
     * 
     * @param left 
     * @param right 
     */
    void SetCameras(Camera::Ptr left, Camera::Ptr right)
    {
        cam_left_ = left;
        cam_right_ = right;
    }

private:
    
    /**
     * @brief 后端函数
     * 
     */
    void BackendLoop();

    std::shared_ptr<Map> map_;

    Camera::Ptr cam_left_ = nullptr, cam_right_ = nullptr;

    std::atomic<bool> backend_running_; // atomic 实现线程的安全操作，确保变量进行操作时是原子，不可分割，避免多线程竞争
                                        // 通过load()方法读取值 通过store()赋值
    std::thread backend_thread_;        // 线程
};