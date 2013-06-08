#include <Nebula/Gui/MainWindow.hpp>
#include <gtest/gtest.h>
#include <QMenuBar>
#include <boost/range/algorithm.hpp>
#include <Nebula/Gui/QFileDialogMock.hpp>

using namespace testing;

namespace Nebula
{

struct MainWindowTest : testing::Test
{
    MainWindow window;

    MainWindowTest()
    {
        QFileDialogMock::setUp();
    }

    ~MainWindowTest()
    {
        QFileDialogMock::tearDown();
    }

    void triggerAction(QString text)
    {
        auto actions = window.findChildren<QAction *>();
        auto action = boost::find_if(actions, [=](QAction *a) { return a->text() == text; });
        ASSERT_TRUE(action != actions.end()) << "Action [" << text.toStdString() << "] not found";
        (*action)->trigger();
    }

    void expectOpenFiles()
    {
        EXPECT_CALL(QFileDialogMock::get(), getOpenFileNames(&window, _, _, _, _, _))
            .WillOnce(Return(QStringList()));
    }
};

TEST_F(MainWindowTest, quit)
{
    window.show();
    triggerAction("Quit");
    ASSERT_FALSE(window.isVisible());
}

TEST_F(MainWindowTest, add_frames)
{
    expectOpenFiles();

    triggerAction("Open light frames...");
}

}