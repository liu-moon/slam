#include "myslam/backend.h"

Backend::Backend()
{
    // todo
    backend_running_.store(true);
    backend_thread_ = std::thread(std::bind(&Backend::BackendLoop, this));
}

void Backend::BackendLoop()
{
    while (backend_running_.load())
    {
    }
}

void Backend::UpdateMap() // 通知后端线程地图数据已经更新，需要对地图进行进一步处理或优化
{
    std::unique_lock<std::mutex> lock(data_mutex_);
    map_update_.notify_one(); // 向等待地图更新的后端线程发出信号，告知其地图数据已更新。
}