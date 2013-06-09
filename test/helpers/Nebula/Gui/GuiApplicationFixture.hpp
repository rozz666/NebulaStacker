#ifndef NEBULA_GUIAPPLICATIONFIXTURE_HPP
#define NEBULA_GUIAPPLICATIONFIXTURE_HPP
#include <Nebula/Gui/MainWindow.hpp>
#include <Nebula/CheckedPtr.hpp>

namespace Nebula {

class GuiApplicationFixture
{
public:
    void triggerAction(QString text);
    void assertActionDisabled(QString text);
    void open();
    void assertClosed();
private:
    MainWindow window;

    CheckedPtr<QAction> getAction(QString text);
    void getAction(QString text, CheckedPtr<QAction>& action);
};

}

#endif // NEBULA_GUIAPPLICATIONFIXTURE_HPP
