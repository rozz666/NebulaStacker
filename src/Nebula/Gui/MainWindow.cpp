#include <Nebula/Gui/MainWindow.hpp>
#include <QAction>
#include <QMenuBar>
#include <Nebula/Gui/QFileDialog.hpp>
#include <Nebula/StackerFactory.hpp>
#include <Nebula/Gui/toStrings.hpp>

namespace Nebula
{

MainWindow::MainWindow()
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
    frameFiles = QFileDialog::getOpenFileNames(this, "Open light frames", "", "16-bit TIFF images (*.tif *.tiff))");
}

void MainWindow::stackFrames()
{
    auto stacker = StackerFactory().createStacker();
    QString outputFile = QFileDialog::getSaveFileName(this, "Save stacked image", "", "16-bit TIFF images (*.tif *.tiff))");
    if (outputFile.isEmpty())
        return;
    stacker->setLightFrames(toStrings(frameFiles));
    stacker->stack(outputFile.toStdString());
}


}
