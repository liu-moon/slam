#pragma once

#include "myslam/common_include.h"

class Camera
{
public:
    EIGEN_MAKE_ALIGNED_OPERATOR_NEW;
    typedef std::shared_ptr<Camera> Ptr;

    double fx_ = 0, fy_ = 0, cx_ = 0, cy_ = 0,
           baseline_ = 0;  // Camera intrinsics
    SE3 pose_;             // extrinsic, from stereo camera to single camera
    SE3 pose_inv_;         // inverse of extrinsics

    Camera();

    Camera(double fx, double fy, double cx, double cy, double baseline,
           const SE3 &pose)
        : fx_(fx), fy_(fy), cx_(cx), cy_(cy), baseline_(baseline), pose_(pose) {
        pose_inv_ = pose_.inverse();
    }

    Vec2 world2pixel(const Vec3 &p_w, const SE3 &T_c_w);

    Vec3 world2camera(const Vec3 &p_w, const SE3 &T_c_w);

    Vec2 camera2pixel(const Vec3 &p_c);

    SE3 pose() const { return pose_; };

    Vec3 pixel2camera(const Vec2 &p_p, double depth = 1);
};