#include "guiMain.hpp"

#include <QApplication>
#include "MainWindow.hpp"

int guiMain(int argc, char **argv)
{
    QApplication app(argc, argv);
    MainWindow mainWindow;
    mainWindow.show();
    return app.exec();
}
