#include "myslam/frontend.h"
#include <opencv2/opencv.hpp>
#include "myslam/config.h"

Frontend::Frontend()
{
  // todo
  // 在config/default.yaml中获取
  LOG(INFO) << "num_features:" << Config::Get<int>("num_features");
  gftt_ =
      cv::GFTTDetector::create(Config::Get<int>("num_features"), 0.01, 20);
  // GFTT 角点检测方法
  // maxCorners(最大角点数量) Config::Get<int>("num_features")
  // qualityLevel(角点质量的最低水平)：典型值为 0.01 ～ 0.1 设置较低的值会找到更多的角点  0.01
  // minDistance(角点之间的最小距离，单位为像素)  20

  num_features_init_ = Config::Get<int>("num_features_init"); // 特征点数量初始化 

  num_features_ = Config::Get<int>("num_features"); // 特征点数量 
  // todo 区别

};