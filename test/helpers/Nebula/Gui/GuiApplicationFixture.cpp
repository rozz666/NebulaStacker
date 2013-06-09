#include <Nebula/Gui/GuiApplicationFixture.hpp>
#include <gtest/gtest.h>
#include <boost/range/algorithm.hpp>
#include <QMenuBar>
#include <QAction>

namespace Nebula
{

void GuiApplicationFixture::triggerAction(QString text)
{
    auto actions = window.findChildren<QAction *>();
    auto action = boost::find_if(actions, [=](QAction *a) { return a->text() == text; });
    ASSERT_TRUE(action != actions.end()) << "Action [" << text.toStdString() << "] not found";
    ASSERT_TRUE((*action)->isEnabled());
    (*action)->trigger();
}

void GuiApplicationFixture::assertActionDisabled(QString text)
{
    auto actions = window.findChildren<QAction *>();
    auto action = boost::find_if(actions, [=](QAction *a) { return a->text() == text; });
    ASSERT_TRUE(action != actions.end()) << "Action [" << text.toStdString() << "] not found";
    ASSERT_FALSE((*action)->isEnabled());
}

void GuiApplicationFixture::open()
{
    window.show();
}

void GuiApplicationFixture::assertClosed()
{
    ASSERT_FALSE(window.isVisible());
}


}
