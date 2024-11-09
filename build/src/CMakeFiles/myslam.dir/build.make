# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.28

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:

#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:

# Disable VCS-based implicit rules.
% : %,v

# Disable VCS-based implicit rules.
% : RCS/%

# Disable VCS-based implicit rules.
% : RCS/%,v

# Disable VCS-based implicit rules.
% : SCCS/s.%

# Disable VCS-based implicit rules.
% : s.%

.SUFFIXES: .hpux_make_needs_suffix_list

# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s

#Suppress display of executed commands.
$(VERBOSE).SILENT:

# A target that is always out of date.
cmake_force:
.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/liuiu/桌面/slam

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/liuiu/桌面/slam/build

# Include any dependencies generated for this target.
include src/CMakeFiles/myslam.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include src/CMakeFiles/myslam.dir/compiler_depend.make

# Include the progress variables for this target.
include src/CMakeFiles/myslam.dir/progress.make

# Include the compile flags for this target's objects.
include src/CMakeFiles/myslam.dir/flags.make

src/CMakeFiles/myslam.dir/visual_odometry.cpp.o: src/CMakeFiles/myslam.dir/flags.make
src/CMakeFiles/myslam.dir/visual_odometry.cpp.o: /home/liuiu/桌面/slam/src/visual_odometry.cpp
src/CMakeFiles/myslam.dir/visual_odometry.cpp.o: src/CMakeFiles/myslam.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/liuiu/桌面/slam/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object src/CMakeFiles/myslam.dir/visual_odometry.cpp.o"
	cd /home/liuiu/桌面/slam/build/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT src/CMakeFiles/myslam.dir/visual_odometry.cpp.o -MF CMakeFiles/myslam.dir/visual_odometry.cpp.o.d -o CMakeFiles/myslam.dir/visual_odometry.cpp.o -c /home/liuiu/桌面/slam/src/visual_odometry.cpp

src/CMakeFiles/myslam.dir/visual_odometry.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/myslam.dir/visual_odometry.cpp.i"
	cd /home/liuiu/桌面/slam/build/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/liuiu/桌面/slam/src/visual_odometry.cpp > CMakeFiles/myslam.dir/visual_odometry.cpp.i

src/CMakeFiles/myslam.dir/visual_odometry.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/myslam.dir/visual_odometry.cpp.s"
	cd /home/liuiu/桌面/slam/build/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/liuiu/桌面/slam/src/visual_odometry.cpp -o CMakeFiles/myslam.dir/visual_odometry.cpp.s

# Object files for target myslam
myslam_OBJECTS = \
"CMakeFiles/myslam.dir/visual_odometry.cpp.o"

# External object files for target myslam
myslam_EXTERNAL_OBJECTS =

src/libmyslam.so: src/CMakeFiles/myslam.dir/visual_odometry.cpp.o
src/libmyslam.so: src/CMakeFiles/myslam.dir/build.make
src/libmyslam.so: /usr/lib/x86_64-linux-gnu/libopencv_stitching.so.4.6.0
src/libmyslam.so: /usr/lib/x86_64-linux-gnu/libopencv_alphamat.so.4.6.0
src/libmyslam.so: /usr/lib/x86_64-linux-gnu/libopencv_aruco.so.4.6.0
src/libmyslam.so: /usr/lib/x86_64-linux-gnu/libopencv_barcode.so.4.6.0
src/libmyslam.so: /usr/lib/x86_64-linux-gnu/libopencv_bgsegm.so.4.6.0
src/libmyslam.so: /usr/lib/x86_64-linux-gnu/libopencv_bioinspired.so.4.6.0
src/libmyslam.so: /usr/lib/x86_64-linux-gnu/libopencv_ccalib.so.4.6.0
src/libmyslam.so: /usr/lib/x86_64-linux-gnu/libopencv_cvv.so.4.6.0
src/libmyslam.so: /usr/lib/x86_64-linux-gnu/libopencv_dnn_objdetect.so.4.6.0
src/libmyslam.so: /usr/lib/x86_64-linux-gnu/libopencv_dnn_superres.so.4.6.0
src/libmyslam.so: /usr/lib/x86_64-linux-gnu/libopencv_dpm.so.4.6.0
src/libmyslam.so: /usr/lib/x86_64-linux-gnu/libopencv_face.so.4.6.0
src/libmyslam.so: /usr/lib/x86_64-linux-gnu/libopencv_freetype.so.4.6.0
src/libmyslam.so: /usr/lib/x86_64-linux-gnu/libopencv_fuzzy.so.4.6.0
src/libmyslam.so: /usr/lib/x86_64-linux-gnu/libopencv_hdf.so.4.6.0
src/libmyslam.so: /usr/lib/x86_64-linux-gnu/libopencv_hfs.so.4.6.0
src/libmyslam.so: /usr/lib/x86_64-linux-gnu/libopencv_img_hash.so.4.6.0
src/libmyslam.so: /usr/lib/x86_64-linux-gnu/libopencv_intensity_transform.so.4.6.0
src/libmyslam.so: /usr/lib/x86_64-linux-gnu/libopencv_line_descriptor.so.4.6.0
src/libmyslam.so: /usr/lib/x86_64-linux-gnu/libopencv_mcc.so.4.6.0
src/libmyslam.so: /usr/lib/x86_64-linux-gnu/libopencv_quality.so.4.6.0
src/libmyslam.so: /usr/lib/x86_64-linux-gnu/libopencv_rapid.so.4.6.0
src/libmyslam.so: /usr/lib/x86_64-linux-gnu/libopencv_reg.so.4.6.0
src/libmyslam.so: /usr/lib/x86_64-linux-gnu/libopencv_rgbd.so.4.6.0
src/libmyslam.so: /usr/lib/x86_64-linux-gnu/libopencv_saliency.so.4.6.0
src/libmyslam.so: /usr/lib/x86_64-linux-gnu/libopencv_shape.so.4.6.0
src/libmyslam.so: /usr/lib/x86_64-linux-gnu/libopencv_stereo.so.4.6.0
src/libmyslam.so: /usr/lib/x86_64-linux-gnu/libopencv_structured_light.so.4.6.0
src/libmyslam.so: /usr/lib/x86_64-linux-gnu/libopencv_superres.so.4.6.0
src/libmyslam.so: /usr/lib/x86_64-linux-gnu/libopencv_surface_matching.so.4.6.0
src/libmyslam.so: /usr/lib/x86_64-linux-gnu/libopencv_tracking.so.4.6.0
src/libmyslam.so: /usr/lib/x86_64-linux-gnu/libopencv_videostab.so.4.6.0
src/libmyslam.so: /usr/lib/x86_64-linux-gnu/libopencv_viz.so.4.6.0
src/libmyslam.so: /usr/lib/x86_64-linux-gnu/libopencv_wechat_qrcode.so.4.6.0
src/libmyslam.so: /usr/lib/x86_64-linux-gnu/libopencv_xobjdetect.so.4.6.0
src/libmyslam.so: /usr/lib/x86_64-linux-gnu/libopencv_xphoto.so.4.6.0
src/libmyslam.so: /usr/local/g2o_debug/lib/libg2o_core_d.so
src/libmyslam.so: /usr/local/g2o_debug/lib/libg2o_stuff_d.so
src/libmyslam.so: /usr/local/glog/lib/libglog.so.0.8.0
src/libmyslam.so: /usr/lib/x86_64-linux-gnu/libopencv_highgui.so.4.6.0
src/libmyslam.so: /usr/lib/x86_64-linux-gnu/libopencv_datasets.so.4.6.0
src/libmyslam.so: /usr/lib/x86_64-linux-gnu/libopencv_plot.so.4.6.0
src/libmyslam.so: /usr/lib/x86_64-linux-gnu/libopencv_text.so.4.6.0
src/libmyslam.so: /usr/lib/x86_64-linux-gnu/libopencv_ml.so.4.6.0
src/libmyslam.so: /usr/lib/x86_64-linux-gnu/libopencv_phase_unwrapping.so.4.6.0
src/libmyslam.so: /usr/lib/x86_64-linux-gnu/libopencv_optflow.so.4.6.0
src/libmyslam.so: /usr/lib/x86_64-linux-gnu/libopencv_ximgproc.so.4.6.0
src/libmyslam.so: /usr/lib/x86_64-linux-gnu/libopencv_video.so.4.6.0
src/libmyslam.so: /usr/lib/x86_64-linux-gnu/libopencv_videoio.so.4.6.0
src/libmyslam.so: /usr/lib/x86_64-linux-gnu/libopencv_imgcodecs.so.4.6.0
src/libmyslam.so: /usr/lib/x86_64-linux-gnu/libopencv_objdetect.so.4.6.0
src/libmyslam.so: /usr/lib/x86_64-linux-gnu/libopencv_calib3d.so.4.6.0
src/libmyslam.so: /usr/lib/x86_64-linux-gnu/libopencv_dnn.so.4.6.0
src/libmyslam.so: /usr/lib/x86_64-linux-gnu/libopencv_features2d.so.4.6.0
src/libmyslam.so: /usr/lib/x86_64-linux-gnu/libopencv_flann.so.4.6.0
src/libmyslam.so: /usr/lib/x86_64-linux-gnu/libopencv_photo.so.4.6.0
src/libmyslam.so: /usr/lib/x86_64-linux-gnu/libopencv_imgproc.so.4.6.0
src/libmyslam.so: /usr/lib/x86_64-linux-gnu/libopencv_core.so.4.6.0
src/libmyslam.so: /usr/lib/x86_64-linux-gnu/libgflags.so.2.2.2
src/libmyslam.so: src/CMakeFiles/myslam.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=/home/liuiu/桌面/slam/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX shared library libmyslam.so"
	cd /home/liuiu/桌面/slam/build/src && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/myslam.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
src/CMakeFiles/myslam.dir/build: src/libmyslam.so
.PHONY : src/CMakeFiles/myslam.dir/build

src/CMakeFiles/myslam.dir/clean:
	cd /home/liuiu/桌面/slam/build/src && $(CMAKE_COMMAND) -P CMakeFiles/myslam.dir/cmake_clean.cmake
.PHONY : src/CMakeFiles/myslam.dir/clean

src/CMakeFiles/myslam.dir/depend:
	cd /home/liuiu/桌面/slam/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/liuiu/桌面/slam /home/liuiu/桌面/slam/src /home/liuiu/桌面/slam/build /home/liuiu/桌面/slam/build/src /home/liuiu/桌面/slam/build/src/CMakeFiles/myslam.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : src/CMakeFiles/myslam.dir/depend

