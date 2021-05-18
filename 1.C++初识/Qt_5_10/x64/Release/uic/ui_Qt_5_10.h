/********************************************************************************
** Form generated from reading UI file 'Qt_5_10.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_QT_5_10_H
#define UI_QT_5_10_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Qt_5_10Class
{
public:
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QWidget *centralWidget;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *Qt_5_10Class)
    {
        if (Qt_5_10Class->objectName().isEmpty())
            Qt_5_10Class->setObjectName(QString::fromUtf8("Qt_5_10Class"));
        Qt_5_10Class->resize(600, 400);
        menuBar = new QMenuBar(Qt_5_10Class);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        Qt_5_10Class->setMenuBar(menuBar);
        mainToolBar = new QToolBar(Qt_5_10Class);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        Qt_5_10Class->addToolBar(mainToolBar);
        centralWidget = new QWidget(Qt_5_10Class);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        Qt_5_10Class->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(Qt_5_10Class);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        Qt_5_10Class->setStatusBar(statusBar);

        retranslateUi(Qt_5_10Class);

        QMetaObject::connectSlotsByName(Qt_5_10Class);
    } // setupUi

    void retranslateUi(QMainWindow *Qt_5_10Class)
    {
        Qt_5_10Class->setWindowTitle(QCoreApplication::translate("Qt_5_10Class", "Qt_5_10", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Qt_5_10Class: public Ui_Qt_5_10Class {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QT_5_10_H
