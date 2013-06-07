#include "guiMain.hpp"

#include <QApplication>
#include "MainWindow.hpp"

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