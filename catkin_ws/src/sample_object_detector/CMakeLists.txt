# Copyright (c) 2016, NVIDIA CORPORATION.  All rights reserved.
cmake_minimum_required(VERSION 3.1)
project(sample_object_detector C CXX)

set (CMAKE_CXX_STANDARD 11)
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_CURRENT_SOURCE_DIR}/cmake")

find_package(CUDA REQUIRED)
find_package(Threads REQUIRED)
find_package(GLEW REQUIRED)
find_package(Driveworks REQUIRED)
#find_package(OpenCV REQUIRED )
#-------------------------------------------------------------------------------
# Project files
#-------------------------------------------------------------------------------
set(PUBLIC_DOCS
    README.md
)

set(SOURCES
    main.cpp
    DNNInference.cpp
)


# SET THESE VARIABLES TO YOUR DRIVEWORKS LOCATIONS
set(Driveworks_INCLUDE_DIR /usr/local/driveworks/include/)
set(Driveworks_LIBRARY /usr/local/driveworks-0.3/lib/)

link_directories(
  ${Driveworks_LIBRARY}
)

include_directories(
  ${Driveworks_INCLUDE_DIR}
  ${CUDA_INCLUDE_DIRS}
  ${CMAKE_CURRENT_SOURCE_DIR}/src
  ${GLEW_INCLUDE_DIR}
)

if(LINUX)
    list(APPEND LIBRARIES
        ${X11_LIBRARIES} ${X11_Xrandr_LIB}
        ${X11_Xcursor_LIB} ${X11_Xxf86vm_LIB}
        ${X11_Xinerama_LIB} ${X11_Xi_LIB}
        ${CMAKE_THREAD_LIBS_INIT}
    )
endif()
#-------------------------------------------------------------------------------
# Final target
#-------------------------------------------------------------------------------
add_executable(${PROJECT_NAME} ${SOURCES})
target_link_libraries(${PROJECT_NAME} PRIVATE ${LIBRARIES})
set_property(TARGET ${PROJECT_NAME} PROPERTY FOLDER "Samples")

# ------------------------------------------------------------------------------
# Install target
# ------------------------------------------------------------------------------
#sdk_install_samples(${PROJECT_NAME})
