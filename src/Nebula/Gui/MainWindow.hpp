#ifndef NEBULA_MAINWINDOW_HPP
#define NEBULA_MAINWINDOW_HPP

#include <QMainWindow>
#include <QListWidget>
#include <Nebula/Stacker.hpp>

namespace Nebula
{

class MainWindow : public QMainWindow
{
Q_OBJECT
public:
    MainWindow();

private slots:
    void openLightFrames();
    void stackFrames();
    
private:
    QStringList frameFiles;
    QAction *stackFramesAction;
    QListWidget *lightFrameList;

    QAction* addMenuAction(QMenu* menu, const QString& title, const char* member);
    void fillLightFrameList();
};

}

#endif // NEBULA_MAINWINDOW_HPP
