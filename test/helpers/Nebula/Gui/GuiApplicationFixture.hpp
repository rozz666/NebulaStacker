#ifndef NEBULA_GUIAPPLICATIONFIXTURE_HPP
#define NEBULA_GUIAPPLICATIONFIXTURE_HPP
#include <Nebula/Gui/MainWindow.hpp>
#include <Nebula/CheckedPtr.hpp>

namespace Nebula {

class GuiApplicationFixture
{
public:
    void triggerAction(std::string text);
    void assertActionDisabled(std::string text);
    void open();
    void assertClosed();
    void listBoxContains(std::string name, Strings items);
private:
    MainWindow window;

    CheckedPtr<QAction> getAction(std::string text);
    void getAction(QString text, CheckedPtr<QAction>& action);
};

}

#endif // NEBULA_GUIAPPLICATIONFIXTURE_HPP
