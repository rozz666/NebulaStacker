#include <Nebula/Gui/MainWindow.hpp>
#include <QAction>
#include <QMenuBar>
#include <Nebula/Gui/QFileDialog.hpp>
#include <Nebula/StackerFactory.hpp>

namespace Nebula
{

MainWindow::MainWindow() : stacker(StackerFactory().createStacker())
{
    setWindowTitle("NebulaStacker");

    auto openLightFrames = new QAction("Open light frames...", this);
    auto stack = new QAction("Stack...", this);
    auto quit = new QAction("Quit", this);

    connect(openLightFrames, SIGNAL(triggered()), SLOT(openLightFrames()));
    connect(stack, SIGNAL(triggered()), SLOT(stackFrames()));
    connect(quit, SIGNAL(triggered()), SLOT(close()));

    auto file = menuBar()->addMenu("File");
    file->addAction(openLightFrames);
    file->addAction(stack);
    file->addSeparator();
    file->addAction(quit);
}

void MainWindow::openLightFrames()
{
    auto files = QFileDialog::getOpenFileNames(this, "Open light frames", "", "16-bit TIFF images (*.tif *.tiff))");
    Strings list;
    for (auto f : files)
        list.push_back(f.toStdString());

    stacker->setLightFrames(list);
}

void MainWindow::stackFrames()
{
    QString outputFile = QFileDialog::getSaveFileName(this, "Save stacked image", "", "16-bit TIFF images (*.tif *.tiff))");
    stacker->stack(outputFile.toStdString());
}


}
