#include "SelectSerialWindow.h"
#include "ui_SelectSerialWindow.h"

SelectSerialWindow::SelectSerialWindow(QStringList portList, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::SelectSerialWindow)
{
    ui->setupUi(this);

    this->setWindowTitle("COM");

    ui->SerialListComboBox->addItems(portList);
    ui->BaudRateComboBox->setCurrentText("115200");
    ui->DataBisComboBox->setCurrentText("8");
    ui->StopBitsComboBox->setCurrentText("1");
    ui->ParityComboBox->setCurrentText("None");
    ui->FlowCtrlComboBox->setCurrentText("None");

    connect(ui->openPortButton, SIGNAL(clicked(bool)), this, SIGNAL(openAction()));
}

SelectSerialWindow::~SelectSerialWindow()
{
    delete ui;
}

QString SelectSerialWindow::getPortName()
{
    return ui->SerialListComboBox->currentText();
}

QString SelectSerialWindow::getBaudRate()
{
    return ui->BaudRateComboBox->currentText();
}

QString SelectSerialWindow::getDataBits()
{
    return ui->DataBisComboBox->currentText();
}

QString SelectSerialWindow::getStopBits()
{
    return ui->StopBitsComboBox->currentText();
}

QString SelectSerialWindow::getParity()
{
    return ui->ParityComboBox->currentText();
}

QString SelectSerialWindow::getFlowCtrl()
{
    return ui->FlowCtrlComboBox->currentText();
}
