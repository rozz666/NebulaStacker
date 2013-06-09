#include <Nebula/Gui/guiMain.hpp>
#include <Nebula/Gui/MainWindow.hpp>
#include <QApplication>

namespace Nebula
{

int guiMain(int argc, char **argv)
{
    QApplication app(argc, argv);
    MainWindow mainWindow;
    mainWindow.show();
    return app.exec();
}

}