# 添加可执行文件
add_executable(myslam main.cpp)

target_link_libraries(myslam
        ${THIRD_PARTY_LIBS})