find_package(Qt5Test)

include_directories("helpers" "unit")

add_library(gmock ${CMAKE_SOURCE_DIR}/gmock-1.6.0/fused-src/gmock-gtest-all.cc)

add_library(nebulastackerguidialogsmock
    helpers/Nebula/Gui/QFileDialogMock.cpp)

add_executable(nebulastacker_test
    helpers/Nebula/NoiseFrameGenerator.cpp
    helpers/Nebula/AutoremoveFiles.cpp
    helpers/Nebula/StarImageGenerator.cpp
    helpers/Nebula/FrameFiles.cpp
    helpers/Nebula/ApplicationFixture.cpp

    unit/Nebula/NebulaStackerTest.cpp
    unit/Nebula/FrameAveragerTest.cpp
    unit/Nebula/GilAlgorithmTest.cpp
    unit/Nebula/NoiseFrameGeneratorTest.cpp
    unit/Nebula/StarImageGeneratorTest.cpp

    module/stacking.cpp

    integration/MainWindowTest.cpp

    main.cpp)

target_link_libraries(nebulastacker_test
    nebulastackercore
    nebulastackergui
    nebulastackerguidialogsmock
    gmock
    pthread
    tiff)

qt5_use_modules(nebulastackerguidialogsmock Widgets Test)
qt5_use_modules(nebulastacker_test Widgets Test)
