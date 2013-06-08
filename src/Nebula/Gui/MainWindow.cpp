#include <Nebula/Gui/MainWindow.hpp>
#include <QAction>
#include <QMenuBar>
#include <Nebula/Gui/QFileDialog.hpp>

namespace Nebula
{

MainWindow::MainWindow()
{
    auto openLightFrames = new QAction("Open light frames...", this);
    auto quit = new QAction("Quit", this);
    connect(openLightFrames, SIGNAL(triggered()), SLOT(openLightFrames()));
    connect(quit, SIGNAL(triggered()), SLOT(close()));
    auto file = menuBar()->addMenu("File");
    file->addAction(openLightFrames);
    file->addAction(quit);
}

void MainWindow::openLightFrames()
{
    QFileDialog::getOpenFileNames(this);
}

}
