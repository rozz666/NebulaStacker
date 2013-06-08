#include <gtest/gtest.h>
#include <Nebula/Gui/GuiApplicationFixture.hpp>
#include <Nebula/Gui/EnvironmentFixture.hpp>

namespace Nebula
{

struct MainWindowTest : testing::Test
{
    GuiApplicationFixture application;
    EnvironmentFixture environment;
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

}