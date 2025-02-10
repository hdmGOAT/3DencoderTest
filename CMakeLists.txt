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
add_executable(OpenCVTest 
    src/main.cpp 
    src/functions/basics/encoder.cpp 
    src/functions/basics/decoder.cpp
    src/functions/pix-stack/pstack.cpp
)




# Link ALL libraries
target_include_directories(OpenCVTest PRIVATE 
    ${OpenCV_INCLUDE_DIRS}
    ${CMAKE_SOURCE_DIR}/src/functions
    ${CMAKE_SOURCE_DIR}/src/functions/basics
    ${CMAKE_SOURCE_DIR}/src/functions/pix-stack
)
target_link_libraries(OpenCVTest PRIVATE ${OpenCV_LIBS})
