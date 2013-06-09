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

TEST_F(MainWindowTest, stacking_frames)
{
    auto FRAMES = environment.generateLightFrames(3);

    environment.expectOpenFiles(FRAMES);

    application.triggerAction("Open light frames...");

    environment.expectSaveFile(OUTPUT_FILE);

    application.triggerAction("Stack...");

    environment.assertFileExists(OUTPUT_FILE);
}

TEST_F(MainWindowTest, cancel_stacking)
{
    auto FRAMES = environment.generateLightFrames(3);

    environment.expectOpenFiles(FRAMES);

    application.triggerAction("Open light frames...");

    environment.expectSaveFileAndCancel();

    application.triggerAction("Stack...");
}

TEST_F(MainWindowTest, stacking_is_disabled_after_startup)
{
    application.assertActionDisabled("Stack...");
}

TEST_F(MainWindowTest, stacking_stays_disabled_after_canceling_adding_frames)
{
    environment.expectOpenFilesAndCancel();

    application.triggerAction("Open light frames...");

    application.assertActionDisabled("Stack...");
}

}