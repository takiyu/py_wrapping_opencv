cmake_minimum_required(VERSION 3.7)

project(boost_cv_sample CXX C)
set (CMAKE_CXX_STANDARD 11)  # C++ 11

# cmake modules
list(APPEND CMAKE_MODULE_PATH ${CMAKE_SOURCE_DIR}/cmake)

# Set output directories
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

set(CMAKE_CXX_FLAGS  "${CMAKE_CXX_FLAGS} -Wdeprecated-declarations -fpermissive")

# External libraries
find_package(OpenCV REQUIRED)
find_package(Boost REQUIRED COMPONENTS python3)
find_package(PythonLibs 3 REQUIRED)
find_package(PythonInterp 3 REQUIRED)
find_package(NumPy REQUIRED)
include_directories(${OpenCV_INCLUDE_DIRS} ${Boost_INCLUDE_DIRS}
                    ${PYTHON_INCLUDE_DIRS} ${NUMPY_INCLUDE_DIR})
set(EXTRA_LIBS ${OpenCV_LIBS} ${Boost_LIBRARIES} ${PYTHON_LIBRARIES})

# Building libraries
add_library(boost_cv_sample SHARED boost_cv_sample.cpp)
target_link_libraries(boost_cv_sample ${EXTRA_LIBS})
