#include <Nebula/Gui/MainWindow.hpp>
#include <gtest/gtest.h>
#include <QMenuBar>
#include <boost/range/algorithm.hpp>

namespace Nebula
{

struct MainWindowTest : testing::Test
{
    MainWindow window;

    void triggerAction(QString text)
    {
        auto actions = window.findChildren<QAction *>();
        auto action = boost::find_if(actions, [=](QAction *a) { return a->text() == text; });
        ASSERT_TRUE(action != actions.end());
        (*action)->trigger();
    }
};

TEST_F(MainWindowTest, quit)
{
    window.show();
    triggerAction("Quit");
    ASSERT_FALSE(window.isVisible());
}

}