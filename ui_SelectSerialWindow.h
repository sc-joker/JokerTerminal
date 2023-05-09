/********************************************************************************
** Form generated from reading UI file 'SelectSerialWindow.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SELECTSERIALWINDOW_H
#define UI_SELECTSERIALWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_SelectSerialWindow
{
public:
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label;
    QSpacerItem *horizontalSpacer;
    QComboBox *SerialListComboBox;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *openPortButton;
    QWidget *layoutWidget1;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label_2;
    QComboBox *BaudRateComboBox;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_3;
    QComboBox *DataBisComboBox;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_4;
    QComboBox *StopBitsComboBox;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_5;
    QComboBox *ParityComboBox;
    QHBoxLayout *horizontalLayout_6;
    QLabel *label_6;
    QComboBox *FlowCtrlComboBox;

    void setupUi(QWidget *SelectSerialWindow)
    {
        if (SelectSerialWindow->objectName().isEmpty())
            SelectSerialWindow->setObjectName(QStringLiteral("SelectSerialWindow"));
        SelectSerialWindow->resize(420, 330);
        SelectSerialWindow->setMinimumSize(QSize(420, 330));
        SelectSerialWindow->setMaximumSize(QSize(420, 330));
        layoutWidget = new QWidget(SelectSerialWindow);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(20, 30, 371, 61));
        horizontalLayout_2 = new QHBoxLayout(layoutWidget);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(layoutWidget);
        label->setObjectName(QStringLiteral("label"));
        QFont font;
        font.setFamily(QStringLiteral("Ubuntu Mono"));
        font.setPointSize(14);
        label->setFont(font);

        horizontalLayout_2->addWidget(label);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);

        SerialListComboBox = new QComboBox(layoutWidget);
        SerialListComboBox->setObjectName(QStringLiteral("SerialListComboBox"));
        QFont font1;
        font1.setFamily(QStringLiteral("Ubuntu Mono"));
        font1.setPointSize(14);
        font1.setStyleStrategy(QFont::NoAntialias);
        SerialListComboBox->setFont(font1);

        horizontalLayout_2->addWidget(SerialListComboBox);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_2);

        openPortButton = new QPushButton(layoutWidget);
        openPortButton->setObjectName(QStringLiteral("openPortButton"));
        openPortButton->setFont(font);

        horizontalLayout_2->addWidget(openPortButton);

        horizontalLayout_2->setStretch(0, 3);
        horizontalLayout_2->setStretch(1, 1);
        horizontalLayout_2->setStretch(2, 10);
        horizontalLayout_2->setStretch(3, 1);
        horizontalLayout_2->setStretch(4, 3);
        layoutWidget1 = new QWidget(SelectSerialWindow);
        layoutWidget1->setObjectName(QStringLiteral("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(40, 100, 281, 211));
        verticalLayout = new QVBoxLayout(layoutWidget1);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label_2 = new QLabel(layoutWidget1);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setFont(font);
        label_2->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout->addWidget(label_2);

        BaudRateComboBox = new QComboBox(layoutWidget1);
        BaudRateComboBox->setObjectName(QStringLiteral("BaudRateComboBox"));
        BaudRateComboBox->setFont(font);

        horizontalLayout->addWidget(BaudRateComboBox);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        label_3 = new QLabel(layoutWidget1);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setFont(font);
        label_3->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout_3->addWidget(label_3);

        DataBisComboBox = new QComboBox(layoutWidget1);
        DataBisComboBox->setObjectName(QStringLiteral("DataBisComboBox"));
        DataBisComboBox->setFont(font);

        horizontalLayout_3->addWidget(DataBisComboBox);


        verticalLayout->addLayout(horizontalLayout_3);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        label_4 = new QLabel(layoutWidget1);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setFont(font);
        label_4->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout_4->addWidget(label_4);

        StopBitsComboBox = new QComboBox(layoutWidget1);
        StopBitsComboBox->setObjectName(QStringLiteral("StopBitsComboBox"));
        StopBitsComboBox->setFont(font);

        horizontalLayout_4->addWidget(StopBitsComboBox);


        verticalLayout->addLayout(horizontalLayout_4);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        label_5 = new QLabel(layoutWidget1);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setFont(font);
        label_5->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout_5->addWidget(label_5);

        ParityComboBox = new QComboBox(layoutWidget1);
        ParityComboBox->setObjectName(QStringLiteral("ParityComboBox"));
        ParityComboBox->setFont(font);

        horizontalLayout_5->addWidget(ParityComboBox);


        verticalLayout->addLayout(horizontalLayout_5);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        label_6 = new QLabel(layoutWidget1);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setFont(font);
        label_6->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout_6->addWidget(label_6);

        FlowCtrlComboBox = new QComboBox(layoutWidget1);
        FlowCtrlComboBox->setObjectName(QStringLiteral("FlowCtrlComboBox"));
        FlowCtrlComboBox->setFont(font);

        horizontalLayout_6->addWidget(FlowCtrlComboBox);


        verticalLayout->addLayout(horizontalLayout_6);


        retranslateUi(SelectSerialWindow);

        QMetaObject::connectSlotsByName(SelectSerialWindow);
    } // setupUi

    void retranslateUi(QWidget *SelectSerialWindow)
    {
        SelectSerialWindow->setWindowTitle(QApplication::translate("SelectSerialWindow", "Form", Q_NULLPTR));
        label->setText(QApplication::translate("SelectSerialWindow", "Serial", Q_NULLPTR));
        openPortButton->setText(QApplication::translate("SelectSerialWindow", "Open", Q_NULLPTR));
        label_2->setText(QApplication::translate("SelectSerialWindow", "Baud Rate", Q_NULLPTR));
        BaudRateComboBox->clear();
        BaudRateComboBox->insertItems(0, QStringList()
         << QApplication::translate("SelectSerialWindow", "1200", Q_NULLPTR)
         << QApplication::translate("SelectSerialWindow", "2400", Q_NULLPTR)
         << QApplication::translate("SelectSerialWindow", "4800", Q_NULLPTR)
         << QApplication::translate("SelectSerialWindow", "9600", Q_NULLPTR)
         << QApplication::translate("SelectSerialWindow", "19200", Q_NULLPTR)
         << QApplication::translate("SelectSerialWindow", "38400", Q_NULLPTR)
         << QApplication::translate("SelectSerialWindow", "57600", Q_NULLPTR)
         << QApplication::translate("SelectSerialWindow", "115200", Q_NULLPTR)
         << QApplication::translate("SelectSerialWindow", "460800", Q_NULLPTR)
         << QApplication::translate("SelectSerialWindow", "921600", Q_NULLPTR)
         << QApplication::translate("SelectSerialWindow", "230400", Q_NULLPTR)
        );
        label_3->setText(QApplication::translate("SelectSerialWindow", "Data Bits", Q_NULLPTR));
        DataBisComboBox->clear();
        DataBisComboBox->insertItems(0, QStringList()
         << QApplication::translate("SelectSerialWindow", "5", Q_NULLPTR)
         << QApplication::translate("SelectSerialWindow", "6", Q_NULLPTR)
         << QApplication::translate("SelectSerialWindow", "7", Q_NULLPTR)
         << QApplication::translate("SelectSerialWindow", "8", Q_NULLPTR)
        );
        label_4->setText(QApplication::translate("SelectSerialWindow", "Stop Bits", Q_NULLPTR));
        StopBitsComboBox->clear();
        StopBitsComboBox->insertItems(0, QStringList()
         << QApplication::translate("SelectSerialWindow", "1", Q_NULLPTR)
         << QApplication::translate("SelectSerialWindow", "2", Q_NULLPTR)
        );
        label_5->setText(QApplication::translate("SelectSerialWindow", "Parity", Q_NULLPTR));
        ParityComboBox->clear();
        ParityComboBox->insertItems(0, QStringList()
         << QApplication::translate("SelectSerialWindow", "None", Q_NULLPTR)
         << QApplication::translate("SelectSerialWindow", "Odd", Q_NULLPTR)
         << QApplication::translate("SelectSerialWindow", "Even", Q_NULLPTR)
         << QApplication::translate("SelectSerialWindow", "Mark", Q_NULLPTR)
         << QApplication::translate("SelectSerialWindow", "Space", Q_NULLPTR)
        );
        label_6->setText(QApplication::translate("SelectSerialWindow", "Flow Ctrl", Q_NULLPTR));
        FlowCtrlComboBox->clear();
        FlowCtrlComboBox->insertItems(0, QStringList()
         << QApplication::translate("SelectSerialWindow", "None", Q_NULLPTR)
         << QApplication::translate("SelectSerialWindow", "Xon/Xoff", Q_NULLPTR)
         << QApplication::translate("SelectSerialWindow", "Rts/Cts", Q_NULLPTR)
         << QApplication::translate("SelectSerialWindow", "Dsr/Dtr", Q_NULLPTR)
        );
    } // retranslateUi

};

namespace Ui {
    class SelectSerialWindow: public Ui_SelectSerialWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SELECTSERIALWINDOW_H
