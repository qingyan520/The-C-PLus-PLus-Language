/********************************************************************************
** Form generated from reading UI file 'Qt_QMainWindow.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_QT_QMAINWINDOW_H
#define UI_QT_QMAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Qt_QMainWindowClass
{
public:
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QWidget *centralWidget;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *Qt_QMainWindowClass)
    {
        if (Qt_QMainWindowClass->objectName().isEmpty())
            Qt_QMainWindowClass->setObjectName(QString::fromUtf8("Qt_QMainWindowClass"));
        Qt_QMainWindowClass->resize(600, 400);
        menuBar = new QMenuBar(Qt_QMainWindowClass);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        Qt_QMainWindowClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(Qt_QMainWindowClass);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        Qt_QMainWindowClass->addToolBar(mainToolBar);
        centralWidget = new QWidget(Qt_QMainWindowClass);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        Qt_QMainWindowClass->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(Qt_QMainWindowClass);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        Qt_QMainWindowClass->setStatusBar(statusBar);

        retranslateUi(Qt_QMainWindowClass);

        QMetaObject::connectSlotsByName(Qt_QMainWindowClass);
    } // setupUi

    void retranslateUi(QMainWindow *Qt_QMainWindowClass)
    {
        Qt_QMainWindowClass->setWindowTitle(QCoreApplication::translate("Qt_QMainWindowClass", "Qt_QMainWindow", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Qt_QMainWindowClass: public Ui_Qt_QMainWindowClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QT_QMAINWINDOW_H
