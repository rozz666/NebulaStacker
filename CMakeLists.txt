project(nebulastacker)
cmake_minimum_required(VERSION 2.8.8)
find_package(Qt5Widgets)
include(ExternalProject)

ExternalProject_Add(
    libtiff
    SOURCE_DIR ${CMAKE_SOURCE_DIR}/tiff-4.0.3
    CONFIGURE_COMMAND ${CMAKE_SOURCE_DIR}/tiff-4.0.3/configure --prefix=${CMAKE_BINARY_DIR}/tiff-4.0.3
    PREFIX ${CMAKE_BINARY_DIR}/tiff-4.0.3
    BUILD_COMMAND make
)

include_directories("boost_1_53_0" "gmock-1.6.0/fused-src" "src" ${CMAKE_BINARY_DIR}/tiff-4.0.3/include "gil_extensions")
link_directories(${CMAKE_BINARY_DIR}/tiff-4.0.3/lib)

if(CMAKE_COMPILER_IS_GNUCXX)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -Wall")
else(CMAKE_COMPILER_IS_GNUCXX)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -stdlib=libc++ -Wall -DGTEST_USE_OWN_TR1_TUPLE=1")
endif(CMAKE_COMPILER_IS_GNUCXX)

add_subdirectory(src)
add_subdirectory(test)
