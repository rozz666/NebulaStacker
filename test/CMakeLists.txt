find_package(Qt5Test)

include_directories(".")

add_library(gmock ${CMAKE_SOURCE_DIR}/gmock-1.6.0/fused-src/gmock-gtest-all.cc)

add_executable(nebulastacker_test
    Nebula/MainWindowTest.cpp
    Nebula/NebulaStackerTest.cpp
    Nebula/FrameAveragerTest.cpp
    Nebula/GilAlgorithmTest.cpp
    Nebula/NoiseFrameGeneratorTest.cpp
    Nebula/NoiseFrameGenerator.cpp
    Nebula/AutoremoveFiles.cpp
    Nebula/StarImageGeneratorTest.cpp
    Nebula/StarImageGenerator.cpp
    Nebula/FrameFiles.cpp
    Nebula/ApplicationFixture.cpp
    Nebula/stacking.cpp
    main.cpp)

target_link_libraries(nebulastacker_test nebulastackercore nebulastackergui gmock pthread tiff)

qt5_use_modules(nebulastacker_test Widgets Test)
