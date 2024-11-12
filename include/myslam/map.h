#pragma once

#include "myslam/common_include.h"

class Map {
   public:
    EIGEN_MAKE_ALIGNED_OPERATOR_NEW;    // 内存对齐
    typedef std::shared_ptr<Map> Ptr;   // 共享指针
    Map();
};