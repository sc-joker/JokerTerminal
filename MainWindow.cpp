#include "MainWindow.h"
#include "ui_MainWindow.h"

#include <QDebug>
#include <QSharedPointer>
#include <QSerialPort>
#include <QSerialPortInfo>
#include <QMessageBox>

#include "SelectSerialWindow.h"
#include "SerialTerminal.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    mSelSerialWin(nullptr)
{
    ui->setupUi(this);

    this->setWindowTitle("JokerT");

    connect(ui->actionOpenSerial, SIGNAL(triggered(bool)), this, SLOT(selectSerialAction()));
    connect(ui->PauseButton, SIGNAL(clicked(bool)), this, SLOT(triggerPauseAction()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::selectSerialAction()
{
    if (nullptr == mSelSerialWin)
    {
        QStringList portList;
        foreach (const QSerialPortInfo &serInfo, QSerialPortInfo::availablePorts()) {
            portList.append(serInfo.portName());
        }
        qDebug() << portList;

        mSelSerialWin = new SelectSerialWindow(portList);
        connect(mSelSerialWin, SIGNAL(openAction()), this, SLOT(openNewSerialTerminalAction()));
    }

    mSelSerialWin->show();
}

void MainWindow::openNewSerialTerminalAction()
{
    qDebug() << "open a new terminal";
    mSelSerialWin->hide();

    QString portName = mSelSerialWin->getPortName();
    SerialTerminal *newSerTerm = new SerialTerminal(portName,
                                                    mSelSerialWin->getBaudRate(),
                                                    mSelSerialWin->getDataBits(),
                                                    mSelSerialWin->getStopBits(),
                                                    mSelSerialWin->getParity(),
                                                    mSelSerialWin->getFlowCtrl());
    if (portName.isEmpty() || !newSerTerm->open())
    {
        QString msg("Failed to open port: ");
        QMessageBox::warning(this, "Warning", msg + portName);
        delete newSerTerm;
        return;
    }

    ui->TerminalTab->addTab(newSerTerm, portName);
}

void MainWindow::triggerPauseAction()
{
    QWidget *curWid = ui->TerminalTab->currentWidget();
    SerialTerminal *serTerm = dynamic_cast<SerialTerminal *>(curWid);
    if (nullptr != serTerm)
    {
        qDebug() << "got the serial terminal";
//        serTerm->triggerPause();
    }
}
