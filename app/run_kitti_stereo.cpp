#include <gflags/gflags.h>
#include "myslam/visual_odometry.h"

DEFINE_string(config_file, "./config/default.yaml", "config file path");

int main(int argc, char **argv)
{
    google::ParseCommandLineFlags(&argc, &argv, true); // 解析命令行参数
    VisualOdometry::Ptr vo(
        new VisualOdometry(FLAGS_config_file));
    assert(vo->Init() == true);
    vo->Run();
    
    return 0;
}