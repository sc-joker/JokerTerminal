#include "SerialTerminal.h"

#include <QTextCodec>
#include <QKeyEvent>
#include <QDebug>

SerialTerminal::SerialTerminal(QString portName, QString baudRate, QString dataBits, QString stopBits, QString parity, QString flowCtrl) :
    mSerialThread(portName),
    mIsPause(false)
{
    mSerialThread.setSerialBaudRate(baudRate);
    mSerialThread.setSerialDataBits(dataBits);
    mSerialThread.setSerialStopBits(stopBits);
    mSerialThread.setSerialParity(parity);
    mSerialThread.setSerialFlowCtrl(flowCtrl);

    QFont font;
    font.setFamily("Ubuntu Mono");
    font.setPointSize(14);
    this->setFont(font);

    this->setAutoFormatting(QTextEdit::AutoAll);

    connect(&mSerialThread, SIGNAL(serialDataUpdated()), this, SLOT(slotUpdateText()));

}

SerialTerminal::~SerialTerminal()
{

}

bool SerialTerminal::open()
{
    qDebug() << this->styleSheet();
    return mSerialThread.open();
}

void SerialTerminal::triggerPause()
{
    mIsPause = !mIsPause;

    if (mIsPause)
    {
        connect(&mSerialThread, SIGNAL(serialDataUpdated()), this, SLOT(slotUpdateText()));
    }
    else
    {
        disconnect(&mSerialThread, SIGNAL(serialDataUpdated()), this, SLOT(slotUpdateText()));
    }
}

void SerialTerminal::keyPressEvent(QKeyEvent *ev)
{
    mInputText = mInputText + ev->text();
//    qDebug() << mInputText << ev->key();

    if (ev->key() == Qt::Key_Enter || ev->key() == Qt::Key_Return)
    {
        mSerialThread.sendSerialData(mInputText);
        mInputText.clear();
        return;
    }

    this->moveCursor(QTextCursor::End);
    QTextEdit::keyPressEvent(ev);
}

void SerialTerminal::slotUpdateText()
{
    this->clear();
//    this->setText(mSerialThread.getSerialData());
    this->setPlainText(mSerialThread.getSerialData().toHtmlEscaped());
    this->moveCursor(QTextCursor::End);
}
