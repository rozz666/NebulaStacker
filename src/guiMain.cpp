#include "guiMain.hpp"

#include <QtGui/QApplication>
#include "MainWindow.hpp"

int guiMain(int argc, char **argv)
{
    QApplication app(argc, argv);
    MainWindow mainWindow;
    mainWindow.show();
    return app.exec();
}
