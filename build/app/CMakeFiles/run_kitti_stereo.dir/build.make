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
include app/CMakeFiles/run_kitti_stereo.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include app/CMakeFiles/run_kitti_stereo.dir/compiler_depend.make

# Include the progress variables for this target.
include app/CMakeFiles/run_kitti_stereo.dir/progress.make

# Include the compile flags for this target's objects.
include app/CMakeFiles/run_kitti_stereo.dir/flags.make

app/CMakeFiles/run_kitti_stereo.dir/run_kitti_stereo.cpp.o: app/CMakeFiles/run_kitti_stereo.dir/flags.make
app/CMakeFiles/run_kitti_stereo.dir/run_kitti_stereo.cpp.o: /home/liuiu/桌面/slam/app/run_kitti_stereo.cpp
app/CMakeFiles/run_kitti_stereo.dir/run_kitti_stereo.cpp.o: app/CMakeFiles/run_kitti_stereo.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/liuiu/桌面/slam/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object app/CMakeFiles/run_kitti_stereo.dir/run_kitti_stereo.cpp.o"
	cd /home/liuiu/桌面/slam/build/app && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT app/CMakeFiles/run_kitti_stereo.dir/run_kitti_stereo.cpp.o -MF CMakeFiles/run_kitti_stereo.dir/run_kitti_stereo.cpp.o.d -o CMakeFiles/run_kitti_stereo.dir/run_kitti_stereo.cpp.o -c /home/liuiu/桌面/slam/app/run_kitti_stereo.cpp

app/CMakeFiles/run_kitti_stereo.dir/run_kitti_stereo.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/run_kitti_stereo.dir/run_kitti_stereo.cpp.i"
	cd /home/liuiu/桌面/slam/build/app && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/liuiu/桌面/slam/app/run_kitti_stereo.cpp > CMakeFiles/run_kitti_stereo.dir/run_kitti_stereo.cpp.i

app/CMakeFiles/run_kitti_stereo.dir/run_kitti_stereo.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/run_kitti_stereo.dir/run_kitti_stereo.cpp.s"
	cd /home/liuiu/桌面/slam/build/app && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/liuiu/桌面/slam/app/run_kitti_stereo.cpp -o CMakeFiles/run_kitti_stereo.dir/run_kitti_stereo.cpp.s

# Object files for target run_kitti_stereo
run_kitti_stereo_OBJECTS = \
"CMakeFiles/run_kitti_stereo.dir/run_kitti_stereo.cpp.o"

# External object files for target run_kitti_stereo
run_kitti_stereo_EXTERNAL_OBJECTS =

/home/liuiu/桌面/slam/bin/run_kitti_stereo: app/CMakeFiles/run_kitti_stereo.dir/run_kitti_stereo.cpp.o
/home/liuiu/桌面/slam/bin/run_kitti_stereo: app/CMakeFiles/run_kitti_stereo.dir/build.make
/home/liuiu/桌面/slam/bin/run_kitti_stereo: src/libmyslam.so
/home/liuiu/桌面/slam/bin/run_kitti_stereo: /usr/lib/x86_64-linux-gnu/libopencv_stitching.so.4.6.0
/home/liuiu/桌面/slam/bin/run_kitti_stereo: /usr/lib/x86_64-linux-gnu/libopencv_alphamat.so.4.6.0
/home/liuiu/桌面/slam/bin/run_kitti_stereo: /usr/lib/x86_64-linux-gnu/libopencv_aruco.so.4.6.0
/home/liuiu/桌面/slam/bin/run_kitti_stereo: /usr/lib/x86_64-linux-gnu/libopencv_barcode.so.4.6.0
/home/liuiu/桌面/slam/bin/run_kitti_stereo: /usr/lib/x86_64-linux-gnu/libopencv_bgsegm.so.4.6.0
/home/liuiu/桌面/slam/bin/run_kitti_stereo: /usr/lib/x86_64-linux-gnu/libopencv_bioinspired.so.4.6.0
/home/liuiu/桌面/slam/bin/run_kitti_stereo: /usr/lib/x86_64-linux-gnu/libopencv_ccalib.so.4.6.0
/home/liuiu/桌面/slam/bin/run_kitti_stereo: /usr/lib/x86_64-linux-gnu/libopencv_cvv.so.4.6.0
/home/liuiu/桌面/slam/bin/run_kitti_stereo: /usr/lib/x86_64-linux-gnu/libopencv_dnn_objdetect.so.4.6.0
/home/liuiu/桌面/slam/bin/run_kitti_stereo: /usr/lib/x86_64-linux-gnu/libopencv_dnn_superres.so.4.6.0
/home/liuiu/桌面/slam/bin/run_kitti_stereo: /usr/lib/x86_64-linux-gnu/libopencv_dpm.so.4.6.0
/home/liuiu/桌面/slam/bin/run_kitti_stereo: /usr/lib/x86_64-linux-gnu/libopencv_face.so.4.6.0
/home/liuiu/桌面/slam/bin/run_kitti_stereo: /usr/lib/x86_64-linux-gnu/libopencv_freetype.so.4.6.0
/home/liuiu/桌面/slam/bin/run_kitti_stereo: /usr/lib/x86_64-linux-gnu/libopencv_fuzzy.so.4.6.0
/home/liuiu/桌面/slam/bin/run_kitti_stereo: /usr/lib/x86_64-linux-gnu/libopencv_hdf.so.4.6.0
/home/liuiu/桌面/slam/bin/run_kitti_stereo: /usr/lib/x86_64-linux-gnu/libopencv_hfs.so.4.6.0
/home/liuiu/桌面/slam/bin/run_kitti_stereo: /usr/lib/x86_64-linux-gnu/libopencv_img_hash.so.4.6.0
/home/liuiu/桌面/slam/bin/run_kitti_stereo: /usr/lib/x86_64-linux-gnu/libopencv_intensity_transform.so.4.6.0
/home/liuiu/桌面/slam/bin/run_kitti_stereo: /usr/lib/x86_64-linux-gnu/libopencv_line_descriptor.so.4.6.0
/home/liuiu/桌面/slam/bin/run_kitti_stereo: /usr/lib/x86_64-linux-gnu/libopencv_mcc.so.4.6.0
/home/liuiu/桌面/slam/bin/run_kitti_stereo: /usr/lib/x86_64-linux-gnu/libopencv_quality.so.4.6.0
/home/liuiu/桌面/slam/bin/run_kitti_stereo: /usr/lib/x86_64-linux-gnu/libopencv_rapid.so.4.6.0
/home/liuiu/桌面/slam/bin/run_kitti_stereo: /usr/lib/x86_64-linux-gnu/libopencv_reg.so.4.6.0
/home/liuiu/桌面/slam/bin/run_kitti_stereo: /usr/lib/x86_64-linux-gnu/libopencv_rgbd.so.4.6.0
/home/liuiu/桌面/slam/bin/run_kitti_stereo: /usr/lib/x86_64-linux-gnu/libopencv_saliency.so.4.6.0
/home/liuiu/桌面/slam/bin/run_kitti_stereo: /usr/lib/x86_64-linux-gnu/libopencv_shape.so.4.6.0
/home/liuiu/桌面/slam/bin/run_kitti_stereo: /usr/lib/x86_64-linux-gnu/libopencv_stereo.so.4.6.0
/home/liuiu/桌面/slam/bin/run_kitti_stereo: /usr/lib/x86_64-linux-gnu/libopencv_structured_light.so.4.6.0
/home/liuiu/桌面/slam/bin/run_kitti_stereo: /usr/lib/x86_64-linux-gnu/libopencv_superres.so.4.6.0
/home/liuiu/桌面/slam/bin/run_kitti_stereo: /usr/lib/x86_64-linux-gnu/libopencv_surface_matching.so.4.6.0
/home/liuiu/桌面/slam/bin/run_kitti_stereo: /usr/lib/x86_64-linux-gnu/libopencv_tracking.so.4.6.0
/home/liuiu/桌面/slam/bin/run_kitti_stereo: /usr/lib/x86_64-linux-gnu/libopencv_videostab.so.4.6.0
/home/liuiu/桌面/slam/bin/run_kitti_stereo: /usr/lib/x86_64-linux-gnu/libopencv_viz.so.4.6.0
/home/liuiu/桌面/slam/bin/run_kitti_stereo: /usr/lib/x86_64-linux-gnu/libopencv_wechat_qrcode.so.4.6.0
/home/liuiu/桌面/slam/bin/run_kitti_stereo: /usr/lib/x86_64-linux-gnu/libopencv_xobjdetect.so.4.6.0
/home/liuiu/桌面/slam/bin/run_kitti_stereo: /usr/lib/x86_64-linux-gnu/libopencv_xphoto.so.4.6.0
/home/liuiu/桌面/slam/bin/run_kitti_stereo: /usr/local/g2o_debug/lib/libg2o_core_d.so
/home/liuiu/桌面/slam/bin/run_kitti_stereo: /usr/local/g2o_debug/lib/libg2o_stuff_d.so
/home/liuiu/桌面/slam/bin/run_kitti_stereo: /usr/local/glog/lib/libglog.so.0.8.0
/home/liuiu/桌面/slam/bin/run_kitti_stereo: /usr/lib/x86_64-linux-gnu/libopencv_phase_unwrapping.so.4.6.0
/home/liuiu/桌面/slam/bin/run_kitti_stereo: /usr/lib/x86_64-linux-gnu/libopencv_optflow.so.4.6.0
/home/liuiu/桌面/slam/bin/run_kitti_stereo: /usr/lib/x86_64-linux-gnu/libopencv_highgui.so.4.6.0
/home/liuiu/桌面/slam/bin/run_kitti_stereo: /usr/lib/x86_64-linux-gnu/libopencv_datasets.so.4.6.0
/home/liuiu/桌面/slam/bin/run_kitti_stereo: /usr/lib/x86_64-linux-gnu/libopencv_plot.so.4.6.0
/home/liuiu/桌面/slam/bin/run_kitti_stereo: /usr/lib/x86_64-linux-gnu/libopencv_text.so.4.6.0
/home/liuiu/桌面/slam/bin/run_kitti_stereo: /usr/lib/x86_64-linux-gnu/libopencv_ml.so.4.6.0
/home/liuiu/桌面/slam/bin/run_kitti_stereo: /usr/lib/x86_64-linux-gnu/libopencv_videoio.so.4.6.0
/home/liuiu/桌面/slam/bin/run_kitti_stereo: /usr/lib/x86_64-linux-gnu/libopencv_ximgproc.so.4.6.0
/home/liuiu/桌面/slam/bin/run_kitti_stereo: /usr/lib/x86_64-linux-gnu/libopencv_video.so.4.6.0
/home/liuiu/桌面/slam/bin/run_kitti_stereo: /usr/lib/x86_64-linux-gnu/libopencv_imgcodecs.so.4.6.0
/home/liuiu/桌面/slam/bin/run_kitti_stereo: /usr/lib/x86_64-linux-gnu/libopencv_objdetect.so.4.6.0
/home/liuiu/桌面/slam/bin/run_kitti_stereo: /usr/lib/x86_64-linux-gnu/libopencv_calib3d.so.4.6.0
/home/liuiu/桌面/slam/bin/run_kitti_stereo: /usr/lib/x86_64-linux-gnu/libopencv_dnn.so.4.6.0
/home/liuiu/桌面/slam/bin/run_kitti_stereo: /usr/lib/x86_64-linux-gnu/libopencv_features2d.so.4.6.0
/home/liuiu/桌面/slam/bin/run_kitti_stereo: /usr/lib/x86_64-linux-gnu/libopencv_flann.so.4.6.0
/home/liuiu/桌面/slam/bin/run_kitti_stereo: /usr/lib/x86_64-linux-gnu/libopencv_photo.so.4.6.0
/home/liuiu/桌面/slam/bin/run_kitti_stereo: /usr/lib/x86_64-linux-gnu/libopencv_imgproc.so.4.6.0
/home/liuiu/桌面/slam/bin/run_kitti_stereo: /usr/lib/x86_64-linux-gnu/libopencv_core.so.4.6.0
/home/liuiu/桌面/slam/bin/run_kitti_stereo: /usr/lib/x86_64-linux-gnu/libgflags.so.2.2.2
/home/liuiu/桌面/slam/bin/run_kitti_stereo: app/CMakeFiles/run_kitti_stereo.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=/home/liuiu/桌面/slam/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable /home/liuiu/桌面/slam/bin/run_kitti_stereo"
	cd /home/liuiu/桌面/slam/build/app && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/run_kitti_stereo.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
app/CMakeFiles/run_kitti_stereo.dir/build: /home/liuiu/桌面/slam/bin/run_kitti_stereo
.PHONY : app/CMakeFiles/run_kitti_stereo.dir/build

app/CMakeFiles/run_kitti_stereo.dir/clean:
	cd /home/liuiu/桌面/slam/build/app && $(CMAKE_COMMAND) -P CMakeFiles/run_kitti_stereo.dir/cmake_clean.cmake
.PHONY : app/CMakeFiles/run_kitti_stereo.dir/clean

app/CMakeFiles/run_kitti_stereo.dir/depend:
	cd /home/liuiu/桌面/slam/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/liuiu/桌面/slam /home/liuiu/桌面/slam/app /home/liuiu/桌面/slam/build /home/liuiu/桌面/slam/build/app /home/liuiu/桌面/slam/build/app/CMakeFiles/run_kitti_stereo.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : app/CMakeFiles/run_kitti_stereo.dir/depend

