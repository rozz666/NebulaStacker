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
