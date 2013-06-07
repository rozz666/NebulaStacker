#include "MainWindow.hpp"
#include <QAction>
#include <QMenuBar>

MainWindow::MainWindow()
{
    QAction* quit = new QAction("Quit", this);
    connect(quit, SIGNAL(triggered()), SLOT(close()));
    menuBar()->addMenu("File")->addAction(quit);
}
