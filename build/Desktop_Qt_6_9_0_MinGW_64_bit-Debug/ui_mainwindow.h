/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
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
        btnGetHandle->setGeometry(QRect(10, 10, 91, 31));
        txtInputAddress = new QLineEdit(centralwidget);
        txtInputAddress->setObjectName("txtInputAddress");
        txtInputAddress->setGeometry(QRect(10, 70, 141, 41));
        txtShowAddress = new QLabel(centralwidget);
        txtShowAddress->setObjectName("txtShowAddress");
        txtShowAddress->setGeometry(QRect(10, 40, 91, 31));
        btnRead = new QPushButton(centralwidget);
        btnRead->setObjectName("btnRead");
        btnRead->setGeometry(QRect(10, 120, 80, 31));
        btnWrite = new QPushButton(centralwidget);
        btnWrite->setObjectName("btnWrite");
        btnWrite->setGeometry(QRect(10, 160, 80, 31));
        txtOutput = new QLineEdit(centralwidget);
        txtOutput->setObjectName("txtOutput");
        txtOutput->setGeometry(QRect(10, 220, 141, 41));
        txtShowResult = new QLabel(centralwidget);
        txtShowResult->setObjectName("txtShowResult");
        txtShowResult->setGeometry(QRect(10, 190, 91, 31));
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
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
