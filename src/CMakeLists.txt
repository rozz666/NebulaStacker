add_library(nebulastackercore
    Nebula/FrameAveragerFactory.cpp
    Nebula/FrameAverager.cpp
    Nebula/TiffImageWriter.cpp
    Nebula/NebulaStackerFactory.cpp
    Nebula/TiffImageReader.cpp
    Nebula/NebulaStacker.cpp)

add_library(nebulastackergui
    Nebula/Gui/guiMain.cpp
    Nebula/Gui/MainWindow.cpp)

add_executable(nebulastacker main.cpp)

target_link_libraries(nebulastacker nebulastackergui)

set_target_properties(nebulastackergui PROPERTIES AUTOMOC TRUE)

qt5_use_modules(nebulastackergui Widgets)
