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
    std::string OPEN_LIGHT_FRAMES = "Open light frames...";
    std::string STACK_FRAMES = "Stack...";
    std::string QUIT = "Quit";
};

TEST_F(MainWindowTest, quit)
{
    application.open();
    application.triggerAction(QUIT);
    application.assertClosed();
}

TEST_F(MainWindowTest, stacking_frames)
{
    auto FRAMES = environment.generateLightFrames(3);

    environment.expectOpenFiles(FRAMES);

    application.triggerAction(OPEN_LIGHT_FRAMES);

    environment.expectSaveFile(OUTPUT_FILE);

    application.triggerAction(STACK_FRAMES);

    environment.assertFileExists(OUTPUT_FILE);
}

TEST_F(MainWindowTest, cancel_stacking)
{
    auto FRAMES = environment.generateLightFrames(3);

    environment.expectOpenFiles(FRAMES);

    application.triggerAction(OPEN_LIGHT_FRAMES);

    environment.expectSaveFileAndCancel();

    application.triggerAction(STACK_FRAMES);
}

TEST_F(MainWindowTest, stacking_is_disabled_after_startup)
{
    application.assertActionDisabled(STACK_FRAMES);
}

TEST_F(MainWindowTest, stacking_stays_disabled_after_canceling_adding_frames)
{
    environment.expectOpenFilesAndCancel();

    application.triggerAction(OPEN_LIGHT_FRAMES);

    application.assertActionDisabled(STACK_FRAMES);
}

}