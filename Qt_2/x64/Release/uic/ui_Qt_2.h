/********************************************************************************
** Form generated from reading UI file 'Qt_2.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_QT_2_H
#define UI_QT_2_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Qt_2Class
{
public:
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QWidget *centralWidget;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *Qt_2Class)
    {
        if (Qt_2Class->objectName().isEmpty())
            Qt_2Class->setObjectName(QString::fromUtf8("Qt_2Class"));
        Qt_2Class->resize(600, 400);
        menuBar = new QMenuBar(Qt_2Class);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        Qt_2Class->setMenuBar(menuBar);
        mainToolBar = new QToolBar(Qt_2Class);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        Qt_2Class->addToolBar(mainToolBar);
        centralWidget = new QWidget(Qt_2Class);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        Qt_2Class->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(Qt_2Class);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        Qt_2Class->setStatusBar(statusBar);

        retranslateUi(Qt_2Class);

        QMetaObject::connectSlotsByName(Qt_2Class);
    } // setupUi

    void retranslateUi(QMainWindow *Qt_2Class)
    {
        Qt_2Class->setWindowTitle(QCoreApplication::translate("Qt_2Class", "Qt_2", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Qt_2Class: public Ui_Qt_2Class {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QT_2_H
