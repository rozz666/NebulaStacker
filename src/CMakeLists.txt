add_library(nebulastackercore
    Nebula/FrameAveragerFactory.cpp
    Nebula/FrameAverager.cpp
    Nebula/TiffImageWriter.cpp
    Nebula/StackerFactory.cpp
    Nebula/TiffImageReader.cpp
    Nebula/Stacker.cpp)

add_library(nebulastackergui
    Nebula/Gui/guiMain.cpp
    Nebula/Gui/MainWindow.cpp)

add_library(nebulastackerguidialogs
    Nebula/Gui/QFileDialog.cpp)

add_executable(nebulastacker main.cpp)

target_link_libraries(nebulastacker nebulastackergui nebulastackerguidialogs)

set_target_properties(nebulastackergui PROPERTIES AUTOMOC TRUE)

qt5_use_modules(nebulastackergui Widgets)
qt5_use_modules(nebulastackerguidialogs Widgets)