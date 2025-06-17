/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QPushButton *btnGetHandle;
    QLineEdit *txtInputAddress;
    QLabel *txtShowAddress;
    QPushButton *btnRead;
    QPushButton *btnWrite;
    QLineEdit *txtOutput;
    QLabel *txtShowResult;
    QComboBox *boxDataType;
    QLabel *txtShowAddress_2;
    QLabel *txtShowAddress_3;
    QLineEdit *txtGameName;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(588, 347);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        btnGetHandle = new QPushButton(centralwidget);
        btnGetHandle->setObjectName("btnGetHandle");
        btnGetHandle->setGeometry(QRect(10, 70, 91, 31));
        txtInputAddress = new QLineEdit(centralwidget);
        txtInputAddress->setObjectName("txtInputAddress");
        txtInputAddress->setGeometry(QRect(10, 130, 171, 41));
        txtShowAddress = new QLabel(centralwidget);
        txtShowAddress->setObjectName("txtShowAddress");
        txtShowAddress->setGeometry(QRect(10, 100, 91, 31));
        btnRead = new QPushButton(centralwidget);
        btnRead->setObjectName("btnRead");
        btnRead->setGeometry(QRect(10, 180, 80, 31));
        btnWrite = new QPushButton(centralwidget);
        btnWrite->setObjectName("btnWrite");
        btnWrite->setGeometry(QRect(10, 220, 80, 31));
        txtOutput = new QLineEdit(centralwidget);
        txtOutput->setObjectName("txtOutput");
        txtOutput->setGeometry(QRect(10, 280, 171, 41));
        txtShowResult = new QLabel(centralwidget);
        txtShowResult->setObjectName("txtShowResult");
        txtShowResult->setGeometry(QRect(10, 250, 91, 31));
        boxDataType = new QComboBox(centralwidget);
        boxDataType->addItem(QString());
        boxDataType->addItem(QString());
        boxDataType->addItem(QString());
        boxDataType->addItem(QString());
        boxDataType->setObjectName("boxDataType");
        boxDataType->setGeometry(QRect(100, 220, 81, 31));
        txtShowAddress_2 = new QLabel(centralwidget);
        txtShowAddress_2->setObjectName("txtShowAddress_2");
        txtShowAddress_2->setGeometry(QRect(100, 180, 81, 31));
        txtShowAddress_3 = new QLabel(centralwidget);
        txtShowAddress_3->setObjectName("txtShowAddress_3");
        txtShowAddress_3->setGeometry(QRect(10, 0, 91, 31));
        txtGameName = new QLineEdit(centralwidget);
        txtGameName->setObjectName("txtGameName");
        txtGameName->setGeometry(QRect(10, 30, 171, 41));
        MainWindow->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        btnGetHandle->setText(QCoreApplication::translate("MainWindow", "Handle", nullptr));
        txtShowAddress->setText(QCoreApplication::translate("MainWindow", "Address: Hex", nullptr));
        btnRead->setText(QCoreApplication::translate("MainWindow", "Read", nullptr));
        btnWrite->setText(QCoreApplication::translate("MainWindow", "Write", nullptr));
        txtShowResult->setText(QCoreApplication::translate("MainWindow", "Output/Input:", nullptr));
        boxDataType->setItemText(0, QCoreApplication::translate("MainWindow", "int", nullptr));
        boxDataType->setItemText(1, QCoreApplication::translate("MainWindow", "float", nullptr));
        boxDataType->setItemText(2, QCoreApplication::translate("MainWindow", "double", nullptr));
        boxDataType->setItemText(3, QCoreApplication::translate("MainWindow", "pointer", nullptr));

        txtShowAddress_2->setText(QCoreApplication::translate("MainWindow", "Datatype:", nullptr));
        txtShowAddress_3->setText(QCoreApplication::translate("MainWindow", "Game Name:", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
