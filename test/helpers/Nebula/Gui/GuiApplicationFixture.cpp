#include <Nebula/Gui/GuiApplicationFixture.hpp>
#include <gtest/gtest.h>
#include <boost/range/algorithm.hpp>
#include <QMenuBar>
#include <QAction>

namespace Nebula
{

void GuiApplicationFixture::triggerAction(QString text)
{
    auto action = getAction(text);
    ASSERT_TRUE(action->isEnabled());
    action->trigger();
}

void GuiApplicationFixture::assertActionDisabled(QString text)
{
    auto action = getAction(text);
    ASSERT_FALSE(action->isEnabled());
}

void GuiApplicationFixture::open()
{
    window.show();
}

void GuiApplicationFixture::assertClosed()
{
    ASSERT_FALSE(window.isVisible());
}

CheckedPtr<QAction> GuiApplicationFixture::getAction(QString text)
{
    CheckedPtr<QAction> action;
    getAction(text, action);
    return action;
}

void GuiApplicationFixture::getAction(QString text, CheckedPtr<QAction>& action)
{
    auto actions = window.findChildren<QAction *>();
    auto it = boost::find_if(actions, [=](QAction *a) { return a->text() == text; });
    if (it == actions.end())
        FAIL() << "Action [" << text.toStdString() << "] not found";
    action = *it;
}

}
