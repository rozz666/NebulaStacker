#include <gtest/gtest.h>
#include <Nebula/Gui/GuiApplicationFixture.hpp>
#include <Nebula/Gui/EnvironmentFixture.hpp>
#include <Nebula/Strings.hpp>

namespace Nebula
{

struct MainWindowTest : testing::Test
{
    GuiApplicationFixture application;
    EnvironmentFixture environment;
    std::string OUTPUT_FILE = "out.tif";

};

TEST_F(MainWindowTest, quit)
{
    application.open();
    application.triggerAction("Quit");
    application.assertClosed();
}

TEST_F(MainWindowTest, add_frames)
{
    environment.expectOpenFiles();

    application.triggerAction("Open light frames...");
}

TEST_F(MainWindowTest, stacking_frames)
{
    auto FRAMES = environment.generateLightFrames(3);

    environment.expectOpenFiles(FRAMES);

    application.triggerAction("Open light frames...");

    environment.expectSaveFile(OUTPUT_FILE);

    application.triggerAction("Stack...");

    environment.assertFileExists(OUTPUT_FILE);
}

}