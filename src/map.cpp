#include "myslam/map.h"

Map::Map()
{
}

void Map::InsertMapPoint(MapPoint::Ptr map_point)
{
    if (landmarks_.find(map_point->id_) == landmarks_.end())
    {                                                                   // 检查地图点是否已经存在
        landmarks_.insert(make_pair(map_point->id_, map_point));        // 插入新地图点
        active_landmarks_.insert(make_pair(map_point->id_, map_point)); // 插入激活地图点
    }
    else // 已经存在 说明某些信息可能发生了变化
    {
        landmarks_[map_point->id_] = map_point;        // 更新已有的地图点
        active_landmarks_[map_point->id_] = map_point; // 激活地图点
    }
}

void Map::InsertKeyFrame(Frame::Ptr frame)  // 将关键帧插入地图
{
    current_frame_ = frame; // 更新当前帧
    if (keyframes_.find(frame->keyframe_id_) == keyframes_.end())   // 检查关键帧是否已经存在
    {
        keyframes_.insert(make_pair(frame->keyframe_id_, frame));   // 插入关键帧
        active_keyframes_.insert(make_pair(frame->keyframe_id_, frame));    // 标记为活跃关键帧
    }
    else    // 更新已有关键帧
    {
        keyframes_[frame->keyframe_id_] = frame;
        active_keyframes_[frame->keyframe_id_] = frame;
    }

    if (active_keyframes_.size() > num_active_keyframes_)   // 控制活跃关键帧的数量
    {
        RemoveOldKeyframe();    // 目前没有移除的情况
    }
}

void Map::RemoveOldKeyframe()   // 从活跃关键帧中移除一个关键帧
{
    if (current_frame_ == nullptr)
        return;
    // 寻找与当前帧最近与最远的两个关键帧
    double max_dis = 0, min_dis = 9999;
    double max_kf_id = 0, min_kf_id = 0;
    auto Twc = current_frame_->Pose().inverse();
    for (auto &kf : active_keyframes_)
    {
        if (kf.second == current_frame_)
            continue;
        auto dis = (kf.second->Pose() * Twc).log().norm();
        if (dis > max_dis)
        {
            max_dis = dis;
            max_kf_id = kf.first;
        }
        if (dis < min_dis)
        {
            min_dis = dis;
            min_kf_id = kf.first;
        }
    }

    const double min_dis_th = 0.2; // 最近阈值
    Frame::Ptr frame_to_remove = nullptr;
    if (min_dis < min_dis_th)
    {
        // 如果存在很近的帧，优先删掉最近的
        frame_to_remove = keyframes_.at(min_kf_id);
    }
    else
    {
        // 删掉最远的
        frame_to_remove = keyframes_.at(max_kf_id);
    }

    LOG(INFO) << "remove keyframe " << frame_to_remove->keyframe_id_;
    // remove keyframe and landmark observation
    active_keyframes_.erase(frame_to_remove->keyframe_id_);
    for (auto feat : frame_to_remove->features_left_)
    {
        auto mp = feat->map_point_.lock();
        if (mp)
        {
            mp->RemoveObservation(feat);
        }
    }
    for (auto feat : frame_to_remove->features_right_)
    {
        if (feat == nullptr)
            continue;
        auto mp = feat->map_point_.lock();
        if (mp)
        {
            mp->RemoveObservation(feat);
        }
    }

    CleanMap();
}

void Map::CleanMap() {
    int cnt_landmark_removed = 0;
    for (auto iter = active_landmarks_.begin();
         iter != active_landmarks_.end();) {
        if (iter->second->observed_times_ == 0) {
            iter = active_landmarks_.erase(iter);
            cnt_landmark_removed++;
        } else {
            ++iter;
        }
    }
    LOG(INFO) << "Removed " << cnt_landmark_removed << " active landmarks";
}