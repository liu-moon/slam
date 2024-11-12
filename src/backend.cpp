#include "myslam/backend.h"

Backend::Backend()
{
   // todo
   backend_running_.store(true);
   backend_thread_ = std::thread(std::bind(&Backend::BackendLoop, this));
}

void Backend::BackendLoop() {
    while (backend_running_.load()) {

    }
}