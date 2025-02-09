cmake_minimum_required(VERSION 3.10)
project(OpenCVProject)

# Set the OpenCV directory
set(OpenCV_DIR "C:/OpenCV/opencv/build/x64/vc16/lib")

# Find OpenCV
find_package(OpenCV REQUIRED)

# Debugging: Display OpenCV details
message(STATUS "OpenCV Version: ${OpenCV_VERSION}")
message(STATUS "OpenCV Include Directory: ${OpenCV_INCLUDE_DIRS}")
message(STATUS "OpenCV Libraries: ${OpenCV_LIBS}")

# Add the executable
add_executable(OpenCVTest src/main.cpp "src/functions/encoder.cpp" "src/functions/decoder.cpp"  "src/functions/encoder.h" "src/functions/decoder.h")

# Link OpenCV libraries
target_include_directories(OpenCVTest PRIVATE ${OpenCV_INCLUDE_DIRS})
target_link_libraries(OpenCVTest PRIVATE ${OpenCV_LIBS})
