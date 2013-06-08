#ifndef NEBULA_GUIAPPLICATIONFIXTURE_HPP
#define NEBULA_GUIAPPLICATIONFIXTURE_HPP
#include <Nebula/Gui/MainWindow.hpp>

namespace Nebula {

class GuiApplicationFixture
{
public:
    void triggerAction(QString text);
    void open();
    void assertClosed();
private:
    MainWindow window;
};

}

#endif // NEBULA_GUIAPPLICATIONFIXTURE_HPP
