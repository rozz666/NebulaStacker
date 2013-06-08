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
    StackerPtr stacker;
};

}

#endif // MAINWINDOW_HPP
