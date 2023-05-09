#ifndef SERIALTERMINAL_H
#define SERIALTERMINAL_H

#include <QObject>
#include <QTextEdit>
#include <QThread>

#include "SerialThread.h"

class SerialTerminal : public QTextEdit
{
    Q_OBJECT
public:
    explicit SerialTerminal(QString portName, QString baudRate, QString dataBits, QString stopBits, QString parity, QString flowCtrl);
    ~SerialTerminal();

    bool open();

    void triggerPause();

protected:
    void keyPressEvent(QKeyEvent *ev);

private slots:
    void slotUpdateText();

private:
    SerialThread mSerialThread;

    QString mInputText;

    bool mIsPause;
};

#endif // SERIALTERMINAL_H
