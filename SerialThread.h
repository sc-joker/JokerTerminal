#ifndef SERIALTHREAD_H
#define SERIALTHREAD_H

#include <QMutex>
#include <QThread>
#include <QSerialPort>

class SerialThread : public QThread
{
    Q_OBJECT
public:
    SerialThread(QString &portName);
    ~SerialThread();

    bool open();
    void run() override;

    void setSerialBaudRate(QString &baudRate);
    void setSerialDataBits(QString &dataBits);
    void setSerialStopBits(QString &stopBits);
    void setSerialParity(QString &parity);
    void setSerialFlowCtrl(QString &flowCtrl);

    QString getSerialData();
    void sendSerialData(QString &data);

private:
    void updateSerialData(QString &data);

signals:
    void serialDataUpdated();

private:
    QSerialPort mSerialPort;

    QString mPortName;
    QSerialPort::BaudRate mBaudRate;
    QSerialPort::DataBits mDataBits;
    QSerialPort::StopBits mStopBits;
    QSerialPort::Parity mParity;
    QSerialPort::FlowControl mFlowCtrl;

    QString mSerialData;
    QMutex mDataMutex;
};

#endif // SERIALTHREAD_H
