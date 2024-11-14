#include "myslam/viewer.h"
#include "myslam/frame.h"

Viewer::Viewer()
{
    // todo
    viewer_thread_ = std::thread(std::bind(&Viewer::ThreadLoop, this));
}

void Viewer::ThreadLoop()
{
}

void Viewer::AddCurrentFrame(Frame::Ptr current_frame) // 将传入的 current_frame 设置为 Viewer 类的当前帧 current_frame_
{
    std::unique_lock<std::mutex> lck(viewer_data_mutex_);
    current_frame_ = current_frame;
}

void Viewer::UpdateMap()
{
    std::unique_lock<std::mutex> lck(viewer_data_mutex_);
    assert(map_ != nullptr);
    active_keyframes_ = map_->GetActiveKeyFrames(); // 获取活跃关键帧
    active_landmarks_ = map_->GetActiveMapPoints(); // 获取活跃地图点
    map_updated_ = true; // 标记地图更新状态
}