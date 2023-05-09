#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include "SelectSerialWindow.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void selectSerialAction();
    void openNewSerialTerminalAction();
    void triggerPauseAction();

private:
    Ui::MainWindow *ui;

private:
    SelectSerialWindow *mSelSerialWin;
};

#endif // MAINWINDOW_H
