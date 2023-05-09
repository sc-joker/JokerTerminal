#include "SerialThread.h"

#include <QTextCodec>
#include <QMap>
#include <QRegExp>
#include <QRegularExpression>
#include <QDebug>

static int64_t gTerminalMaxSize = 10 * 1024 * 1024;

SerialThread::SerialThread(QString &portName) :
    mPortName(portName),
    mBaudRate(QSerialPort::Baud115200),
    mDataBits(QSerialPort::Data8),
    mStopBits(QSerialPort::OneStop),
    mParity(QSerialPort::NoParity),
    mFlowCtrl(QSerialPort::NoFlowControl)
{

}

SerialThread::~SerialThread()
{
    if (mSerialPort.isOpen())
    {
        mSerialPort.close();
    }
}

bool SerialThread::open()
{
    mSerialPort.setPortName(mPortName);
    bool ret = mSerialPort.open(QIODevice::ReadWrite);
    if (!ret)
    {
        qDebug() << "Failed to open serial: " << mPortName;
        return ret;
    }

    mSerialPort.setBaudRate(mBaudRate);
    mSerialPort.setDataBits(mDataBits);
    mSerialPort.setStopBits(mStopBits);
    mSerialPort.setParity(mParity);
    mSerialPort.setFlowControl(mFlowCtrl);

    this->start();
    return true;
}

void SerialThread::run()
{
    QTextCodec *tc = QTextCodec::codecForName("GBK");
    while (mSerialPort.isOpen())
    {
        QByteArray byDt = mSerialPort.readAll();
        QString data = tc->toUnicode(byDt);
        if (data.isEmpty())
        {
            msleep(1);
            continue;
        }

        updateSerialData(data);
    }
}

void SerialThread::setSerialBaudRate(QString &baudRate)
{
    QSerialPort::BaudRate setBaudRate = QSerialPort::Baud115200;
    int intBaudRate = baudRate.toInt();
    switch (intBaudRate)
    {
        case 1200: setBaudRate = QSerialPort::Baud1200; break;
        case 2400: setBaudRate = QSerialPort::Baud2400; break;
        case 4800: setBaudRate = QSerialPort::Baud4800; break;
        case 9600: setBaudRate = QSerialPort::Baud9600; break;
        case 19200: setBaudRate = QSerialPort::Baud19200; break;
        case 38400: setBaudRate = QSerialPort::Baud38400; break;
        case 57600: setBaudRate = QSerialPort::Baud57600; break;
        case 115200: setBaudRate = QSerialPort::Baud115200; break;
        default:
            break;
    }

    mBaudRate = setBaudRate;
}

void SerialThread::setSerialDataBits(QString &dataBits)
{
    QSerialPort::DataBits setDataBitsValue = QSerialPort::Data8;

    int intDataBits = dataBits.toInt();
    switch (intDataBits)
    {
        case 5: setDataBitsValue = QSerialPort::Data5; break;
        case 6: setDataBitsValue = QSerialPort::Data6; break;
        case 7: setDataBitsValue = QSerialPort::Data7; break;
        case 8: setDataBitsValue = QSerialPort::Data8; break;
    }


    mDataBits = setDataBitsValue;
}

void SerialThread::setSerialStopBits(QString &stopBits)
{
    QSerialPort::StopBits setStopBitsValue = QSerialPort::OneStop;

    int intStopBits = stopBits.toInt();
    switch (intStopBits)
    {
        case 1: setStopBitsValue = QSerialPort::OneStop; break;
        case 2: setStopBitsValue = QSerialPort::TwoStop; break;
        case 3: setStopBitsValue = QSerialPort::OneAndHalfStop; break;
    }


    mStopBits = setStopBitsValue;
}

void SerialThread::setSerialParity(QString &parity)
{
    QSerialPort::Parity setParityValue = QSerialPort::NoParity;

    QMap<QString, QSerialPort::Parity> parityMapping = {
        {"None", QSerialPort::NoParity},
        {"Even", QSerialPort::EvenParity},
        {"Odd", QSerialPort::OddParity},
        {"Space", QSerialPort::SpaceParity},
        {"Mark", QSerialPort::MarkParity}
    };

    if (parityMapping.contains(parity))
    {
        setParityValue = parityMapping[parity];
    }


    mParity = setParityValue;
}

void SerialThread::setSerialFlowCtrl(QString &flowCtrl)
{
    QSerialPort::FlowControl setFlowCtrlValue = QSerialPort::NoFlowControl;

    QMap<QString, QSerialPort::FlowControl> flowCtrlMapping = {
        {"None", QSerialPort::NoFlowControl},
        {"Xon/Xoff", QSerialPort::SoftwareControl},
        {"Rts/Cts", QSerialPort::HardwareControl}
    };

    if (flowCtrlMapping.contains(flowCtrl))
    {
        setFlowCtrlValue = flowCtrlMapping[flowCtrl];
    }


    mFlowCtrl = setFlowCtrlValue;
}

QString SerialThread::getSerialData()
{
    mDataMutex.lock();
    QString dt = mSerialData;
    mDataMutex.unlock();
    return dt;
}

void SerialThread::sendSerialData(QString &data)
{
    if (mSerialPort.isOpen())
    {
        mSerialPort.write(data.toUtf8());
    }
}

void SerialThread::updateSerialData(QString &data)
{
    mDataMutex.lock();
    if (mSerialData.size() >= gTerminalMaxSize)
    {
        mSerialData.remove(0, data.size());
    }

    mSerialData.append(data);


    QRegularExpression regEx("\u001B\\\[.*?[HABCDEFGnsulhXKJMP@LSTm]", QRegularExpression::MultilineOption);
    mSerialData = mSerialData.remove(regEx);
    mDataMutex.unlock();

    emit serialDataUpdated();
}
