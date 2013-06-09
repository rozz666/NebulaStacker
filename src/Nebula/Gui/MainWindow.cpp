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

    QMenu *file = menuBar()->addMenu("File");
    addMenuAction(file, "Open light frames...", SLOT(openLightFrames()));
    addMenuAction(file, "Stack...", SLOT(stackFrames()));
    file->addSeparator();
    addMenuAction(file, "Quit", SLOT(close()));
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

void MainWindow::addMenuAction(QMenu* menu, const QString& title, const char* member)
{
    auto action = new QAction(title, this);
    connect(action, SIGNAL(triggered()), member);
    menu->addAction(action);
}


}
