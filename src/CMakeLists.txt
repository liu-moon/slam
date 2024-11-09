add_library(myslam SHARED
        visual_odometry.cpp
        config.cpp
        dataset.cpp
        camera.cpp
        frontend.cpp
        backend.cpp
        map.cpp
        )

target_link_libraries(myslam
        ${THIRD_PARTY_LIBS})
