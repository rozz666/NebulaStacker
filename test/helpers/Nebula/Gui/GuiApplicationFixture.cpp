#include <Nebula/Gui/GuiApplicationFixture.hpp>
#include <gtest/gtest.h>
#include <boost/range/algorithm.hpp>
#include <QMenuBar>
#include <QAction>
#include <QListWidget>

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

void GuiApplicationFixture::listBoxContains(std::string name, Nebula::Strings items)
{
    auto list = window.findChild<QListWidget *>(QString::fromUtf8(name.c_str()));
    ASSERT_TRUE(list != nullptr) << "QListWidget named [" << name << "] does not exist";

    ASSERT_EQ(int(items.size()), list->count());

    for (int i = 0; i < list->count(); ++i)
        EXPECT_EQ(items[i], list->item(i)->text().toStdString()) << "item " << i;
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
