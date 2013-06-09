#include <Nebula/Gui/MainWindow.hpp>
#include <QAction>
#include <QMenuBar>
#include <QListWidget>
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
    stackFramesAction = addMenuAction(file, "Stack...", SLOT(stackFrames()));
    stackFramesAction->setEnabled(false);
    file->addSeparator();
    addMenuAction(file, "Quit", SLOT(close()));

    lightFrameList = new QListWidget(this);
    lightFrameList->setObjectName("lightFrameList");
    setCentralWidget(lightFrameList);
}

void MainWindow::openLightFrames()
{
    frameFiles = QFileDialog::getOpenFileNames(this, "Open light frames", "", "16-bit TIFF images (*.tif *.tiff)");
    if (frameFiles.empty())
        return;
    fillLightFrameList();
    stackFramesAction->setEnabled(true);
}

void MainWindow::stackFrames()
{
    auto stacker = StackerFactory().createStacker();
    QString outputFile = QFileDialog::getSaveFileName(this, "Save stacked image", "", "16-bit TIFF images (*.tif *.tiff)");
    if (outputFile.isEmpty())
        return;
    stacker->setLightFrames(toStrings(frameFiles));
    stacker->stack(outputFile.toStdString());
}

QAction* MainWindow::addMenuAction(QMenu* menu, const QString& title, const char* member)
{
    auto action = new QAction(title, this);
    connect(action, SIGNAL(triggered()), member);
    menu->addAction(action);
    return action;
}

void MainWindow::fillLightFrameList()
{
    for (auto f : frameFiles)
        lightFrameList->addItem(f);
}


}
