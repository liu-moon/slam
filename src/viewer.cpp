#include "myslam/viewer.h"

Viewer::Viewer() {
    // todo
    viewer_thread_ = std::thread(std::bind(&Viewer::ThreadLoop, this));
}

void Viewer::ThreadLoop() {
    
}