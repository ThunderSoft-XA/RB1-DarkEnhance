# cmake needs this line
cmake_minimum_required(VERSION 3.4.1)

# Define project name
project(DarkEnhence)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_COMPILER aarch64-linux-gnu-g++)
#set(CMAKE_CXX_COMPILER g++)


set(CMAKE_LIBRARY_PATH /usr/lib/aarch64-linux-gnu)

#Thread related configuration
set(CMAKE_THREAD_LIBS_INIT "-lpthread")
set(CMAKE_HAVE_THREADS_LIBRARY 1)
set(CMAKE_USE_WIN32_THREADS_INIT 0)
set(CMAKE_USE_PTHREADS_INIT 1)
set(THREADS_PREFER_PTHREAD_FLAG ON)

#Path to the compiled opencv library
set(OpenCV_DIR "/home/thundersoft/dev_C++/opencv-aarch64/build")

find_package(OpenCV REQUIRED)
find_package(PythonInterp REQUIRED)

#Path to the compiled libtorch library
set(Torch_DIR /home/thundersoft/dev_C++/libtorch1.7-aarch64/share/cmake/Torch)  
find_package(Torch REQUIRED)	

# Declare the executable target built from your sources
add_executable(DarkEnhance EnhancePic.cpp)

# Link your application with OpenCV libraries
target_link_libraries(DarkEnhance ${OpenCV_LIBS} ${TORCH_LIBRARIES})
