#ifndef MAINWINDOW_HPP
#define MAINWINDOW_HPP

#include <QMainWindow>
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

    QAction* addMenuAction(QMenu* menu, const QString& title, const char* member);
};

}

#endif // MAINWINDOW_HPP
