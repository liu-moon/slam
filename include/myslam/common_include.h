#pragma once

// define the commonly included file to avoid a long include list
#include <Eigen/Core>
#include <Eigen/Geometry>
#include <iostream>
#include <memory>

// for cv
#include <opencv2/core/core.hpp>

// using cv::Mat;


// glog
#include <glog/logging.h>

// for Sophus
#include <sophus/se3.hpp>
#include <sophus/so3.hpp>

typedef Sophus::SE3d SE3;
typedef Sophus::SO3d SO3;


typedef Eigen::Matrix<double, 3, 3> Mat33;
typedef Eigen::Matrix<double, 3, 1> Vec3;