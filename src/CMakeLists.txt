add_library(myslam SHARED
        visual_odometry.cpp
        config.cpp
        )

target_link_libraries(myslam
        ${THIRD_PARTY_LIBS})
