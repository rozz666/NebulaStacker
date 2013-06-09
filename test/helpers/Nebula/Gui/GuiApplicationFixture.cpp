#include <Nebula/Gui/GuiApplicationFixture.hpp>
#include <gtest/gtest.h>
#include <boost/range/algorithm.hpp>
#include <QMenuBar>
#include <QAction>

namespace Nebula
{

void GuiApplicationFixture::triggerAction(std::string text)
{
    auto action = getAction(text);
    ASSERT_TRUE(action->isEnabled());
    action->trigger();
}

void GuiApplicationFixture::assertActionDisabled(std::string text)
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

CheckedPtr<QAction> GuiApplicationFixture::getAction(std::string text)
{
    CheckedPtr<QAction> action;
    getAction(QString::fromUtf8(text.c_str()), action);
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
