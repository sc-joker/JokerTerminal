#ifndef SELECTSERIALWINDOW_H
#define SELECTSERIALWINDOW_H

#include <QWidget>

namespace Ui {
class SelectSerialWindow;
}

class SelectSerialWindow : public QWidget
{
    Q_OBJECT

public:
    explicit SelectSerialWindow(QStringList portList, QWidget *parent = 0);
    ~SelectSerialWindow();

    QString getPortName();
    QString getBaudRate();
    QString getDataBits();
    QString getStopBits();
    QString getParity();
    QString getFlowCtrl();

signals:
    void openAction();


private:
    Ui::SelectSerialWindow *ui;

private:

};

#endif // SELECTSERIALWINDOW_H
