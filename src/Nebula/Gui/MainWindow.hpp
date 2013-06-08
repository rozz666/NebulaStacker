#ifndef MAINWINDOW_HPP
#define MAINWINDOW_HPP

#include <QMainWindow>

namespace Nebula
{

class MainWindow : public QMainWindow
{
Q_OBJECT
public:
    MainWindow();

private slots:
    void openLightFrames();
};

}

#endif // MAINWINDOW_HPP
