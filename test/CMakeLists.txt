# 添加可执行文件
add_executable(test_g2o test_g2o.cpp)
add_executable(test_glog test_glog.cpp)

target_link_libraries(test_g2o
        ${THIRD_PARTY_LIBS})

target_link_libraries(test_glog
        ${THIRD_PARTY_LIBS})

