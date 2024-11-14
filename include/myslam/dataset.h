#pragma once
#include "myslam/common_include.h"
#include "myslam/camera.h"
#include "myslam/frame.h"

class Dataset
{
public:
    EIGEN_MAKE_ALIGNED_OPERATOR_NEW;
    typedef std::shared_ptr<Dataset> Ptr;

    /**
     * @brief 构造函数，设置数据集路径
     * 
     * @param dataset_path 
     */
    Dataset(const std::string &dataset_path);

    /**
     * @brief 读取多个相机的内参外参，并将相机存储到相机向量中
     * 
     * @return true 
     * @return false 
     */
    bool Init();


    Frame::Ptr NextFrame();

    /**
     * @brief 根据相机的id获取相机类
     * 
     * @param camera_id 
     * @return Camera::Ptr 
     */
    Camera::Ptr GetCamera(int camera_id) const
    {
        return cameras_.at(camera_id);
    }

private:
    std::string dataset_path_;  // 数据集路径
    int current_image_index_ = 0;   // 当前图像索引
    std::vector<Camera::Ptr> cameras_;  // 相机向量
};