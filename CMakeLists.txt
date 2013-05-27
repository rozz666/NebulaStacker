project(nebulastacker)
cmake_minimum_required(VERSION 2.6)

find_package(Boost REQUIRED)

include_directories(${Boost_INCLUDE_DIRS} "gmock-1.6.0/fused-src" "src")

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++0x -Wall")

add_library(gmock gmock-1.6.0/fused-src/gmock-gtest-all.cc)

add_executable(nebulastacker main.cpp)
add_executable(nebulastacker_test test/StarImageGenerator.cpp test/FrameFiles.cpp test/ApplicationFixture.cpp test/main.cpp test/stacking.cpp)

target_link_libraries(nebulastacker_test gmock pthread)