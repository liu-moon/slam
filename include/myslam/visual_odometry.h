#pragma once


#include "myslam/common_include.h"
#include "myslam/dataset.h"
#include "myslam/frontend.h"
#include "myslam/backend.h"
#include "myslam/map.h"
#include "myslam/viewer.h"
#include "myslam/frame.h"

class VisualOdometry
{
public:
    EIGEN_MAKE_ALIGNED_OPERATOR_NEW;
    typedef std::shared_ptr<VisualOdometry> Ptr;

    /**
     * @brief VisualOdometry的构造函数
     * 用于设置配置文件的路径
     * 
     * @param config_path 
     */
    VisualOdometry(std::string &config_path);

    /**
     * @brief 读取配置文件并创建其他关联的类
     * 
     * @return true 
     * @return false 
     */
    bool Init();

    void Run();

    /**
     * @brief 取数据集中的下一帧
     * 
     * @return true 
     * @return false 
     */
    bool Step();

private:
    std::string config_file_path_;

    // dataset
    Dataset::Ptr dataset_ = nullptr;
    Frontend::Ptr frontend_ = nullptr;
    Backend::Ptr backend_ = nullptr;
    Map::Ptr map_ = nullptr;
    Viewer::Ptr viewer_ = nullptr;
};