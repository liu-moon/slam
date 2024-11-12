#pragma once

#include "myslam/common_include.h"

class Config {
private:
  static std::shared_ptr<Config> config_;   // 静态成员变量
  cv::FileStorage file_; // cv::FileStorage：读写配置文件的类

  /**
   * @brief 私有构造函数创建单例模式
   *
   */
  Config() {}

public:
  /**
   * @brief 析构函数释放文件资源
   *
   */
  ~Config();

  /**
   * @brief 加载指定的配置文件
   * 
   * @param filename 
   * @return true 文件存在
   * @return false 文件不存在
   */
  static bool SetParameterFile(const std::string &filename);

  
  /**
   * @brief 获取对应的配置参数
   * 
   * @tparam T 
   * @param key 
   * @return T 
   */
  template <typename T> static T Get(const std::string &key) {
    return T(Config::config_->file_[key]);
  }
};