# 指定 CMake 的最低版本要求为 3.20.0
cmake_minimum_required(VERSION 3.20.0)

project(myslam CXX)

set(CMAKE_CXX_STANDARD 17)
# set(CMAKE_CXX_FLAGS "-std=c++17 -O3")

set(CMAKE_BUILD_TYPE "Debug")

# 只在 Debug 模式下使用 no optimization (-O0)
set(CMAKE_CXX_FLAGS_DEBUG "-O0 -g")


# --------------------------------
list(APPEND CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/cmake_modules)

# EIGEN
find_package(Eigen3 REQUIRED)
include_directories(${EIGEN3_INCLUDE_DIRS})
message(WARNING "EIGEN3 include directories: ${EIGEN3_INCLUDE_DIRS}")

# G2O
find_package(G2O REQUIRED)
include_directories(${G2O_INCLUDE_DIRS})
message(WARNING "G2O include directories: ${G2O_INCLUDE_DIRS}")

# OpenCV
find_package(OpenCV REQUIRED)
include_directories(${OpenCV_INCLUDE_DIRS})
message(WARNING "OpenCV include directories: ${OpenCV_INCLUDE_DIRS}")

# Glog
find_package(Glog REQUIRED)
include_directories(${GLOG_INCLUDE_DIRS})
message(WARNING "GLOG_LIBRARIES include directories: ${GLOG_LIBRARIES}")

set(THIRD_PARTY_LIBS 
        ${OpenCV_LIBS}
        ${G2O_CORE_LIBRARY}
        ${G2O_STUFF_LIBRARY}
        glog::glog
        )
# --------------------------------



include_directories(${PROJECT_SOURCE_DIR}/include)
add_subdirectory(src)
add_subdirectory(test)
add_subdirectory(app)