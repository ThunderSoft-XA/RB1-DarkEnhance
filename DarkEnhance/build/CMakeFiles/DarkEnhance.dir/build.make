# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.18

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
CMAKE_COMMAND = /usr/local/bin/cmake

# The command to remove a file.
RM = /usr/local/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/thundersoft/dev_C++/RB1-DarkEenhance/DarkEnhance

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/thundersoft/dev_C++/RB1-DarkEenhance/DarkEnhance/build

# Include any dependencies generated for this target.
include CMakeFiles/DarkEnhance.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/DarkEnhance.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/DarkEnhance.dir/flags.make

CMakeFiles/DarkEnhance.dir/EnhancePic.cpp.o: CMakeFiles/DarkEnhance.dir/flags.make
CMakeFiles/DarkEnhance.dir/EnhancePic.cpp.o: ../EnhancePic.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/thundersoft/dev_C++/RB1-DarkEenhance/DarkEnhance/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/DarkEnhance.dir/EnhancePic.cpp.o"
	aarch64-linux-gnu-g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/DarkEnhance.dir/EnhancePic.cpp.o -c /home/thundersoft/dev_C++/RB1-DarkEenhance/DarkEnhance/EnhancePic.cpp

CMakeFiles/DarkEnhance.dir/EnhancePic.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/DarkEnhance.dir/EnhancePic.cpp.i"
	aarch64-linux-gnu-g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/thundersoft/dev_C++/RB1-DarkEenhance/DarkEnhance/EnhancePic.cpp > CMakeFiles/DarkEnhance.dir/EnhancePic.cpp.i

CMakeFiles/DarkEnhance.dir/EnhancePic.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/DarkEnhance.dir/EnhancePic.cpp.s"
	aarch64-linux-gnu-g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/thundersoft/dev_C++/RB1-DarkEenhance/DarkEnhance/EnhancePic.cpp -o CMakeFiles/DarkEnhance.dir/EnhancePic.cpp.s

# Object files for target DarkEnhance
DarkEnhance_OBJECTS = \
"CMakeFiles/DarkEnhance.dir/EnhancePic.cpp.o"

# External object files for target DarkEnhance
DarkEnhance_EXTERNAL_OBJECTS =

DarkEnhance: CMakeFiles/DarkEnhance.dir/EnhancePic.cpp.o
DarkEnhance: CMakeFiles/DarkEnhance.dir/build.make
DarkEnhance: /home/thundersoft/dev_C++/opencv-aarch64/build/lib/libopencv_gapi.so.4.8.0
DarkEnhance: /home/thundersoft/dev_C++/opencv-aarch64/build/lib/libopencv_highgui.so.4.8.0
DarkEnhance: /home/thundersoft/dev_C++/opencv-aarch64/build/lib/libopencv_ml.so.4.8.0
DarkEnhance: /home/thundersoft/dev_C++/opencv-aarch64/build/lib/libopencv_objdetect.so.4.8.0
DarkEnhance: /home/thundersoft/dev_C++/opencv-aarch64/build/lib/libopencv_photo.so.4.8.0
DarkEnhance: /home/thundersoft/dev_C++/opencv-aarch64/build/lib/libopencv_stitching.so.4.8.0
DarkEnhance: /home/thundersoft/dev_C++/opencv-aarch64/build/lib/libopencv_video.so.4.8.0
DarkEnhance: /home/thundersoft/dev_C++/opencv-aarch64/build/lib/libopencv_videoio.so.4.8.0
DarkEnhance: /home/thundersoft/dev_C++/libtorch1.7-aarch64/lib/libtorch.so
DarkEnhance: /home/thundersoft/dev_C++/libtorch1.7-aarch64/lib/libc10.so
DarkEnhance: /home/thundersoft/dev_C++/opencv-aarch64/build/lib/libopencv_imgcodecs.so.4.8.0
DarkEnhance: /home/thundersoft/dev_C++/opencv-aarch64/build/lib/libopencv_dnn.so.4.8.0
DarkEnhance: /home/thundersoft/dev_C++/opencv-aarch64/build/lib/libopencv_calib3d.so.4.8.0
DarkEnhance: /home/thundersoft/dev_C++/opencv-aarch64/build/lib/libopencv_features2d.so.4.8.0
DarkEnhance: /home/thundersoft/dev_C++/opencv-aarch64/build/lib/libopencv_flann.so.4.8.0
DarkEnhance: /home/thundersoft/dev_C++/opencv-aarch64/build/lib/libopencv_imgproc.so.4.8.0
DarkEnhance: /home/thundersoft/dev_C++/opencv-aarch64/build/lib/libopencv_core.so.4.8.0
DarkEnhance: /home/thundersoft/dev_C++/libtorch1.7-aarch64/lib/libc10.so
DarkEnhance: CMakeFiles/DarkEnhance.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/thundersoft/dev_C++/RB1-DarkEenhance/DarkEnhance/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable DarkEnhance"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/DarkEnhance.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/DarkEnhance.dir/build: DarkEnhance

.PHONY : CMakeFiles/DarkEnhance.dir/build

CMakeFiles/DarkEnhance.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/DarkEnhance.dir/cmake_clean.cmake
.PHONY : CMakeFiles/DarkEnhance.dir/clean

CMakeFiles/DarkEnhance.dir/depend:
	cd /home/thundersoft/dev_C++/RB1-DarkEenhance/DarkEnhance/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/thundersoft/dev_C++/RB1-DarkEenhance/DarkEnhance /home/thundersoft/dev_C++/RB1-DarkEenhance/DarkEnhance /home/thundersoft/dev_C++/RB1-DarkEenhance/DarkEnhance/build /home/thundersoft/dev_C++/RB1-DarkEenhance/DarkEnhance/build /home/thundersoft/dev_C++/RB1-DarkEenhance/DarkEnhance/build/CMakeFiles/DarkEnhance.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/DarkEnhance.dir/depend

