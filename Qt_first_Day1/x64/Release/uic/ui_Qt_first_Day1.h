/********************************************************************************
** Form generated from reading UI file 'Qt_first_Day1.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_QT_FIRST_DAY1_H
#define UI_QT_FIRST_DAY1_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Qt_first_Day1Class
{
public:
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QWidget *centralWidget;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *Qt_first_Day1Class)
    {
        if (Qt_first_Day1Class->objectName().isEmpty())
            Qt_first_Day1Class->setObjectName(QString::fromUtf8("Qt_first_Day1Class"));
        Qt_first_Day1Class->resize(600, 400);
        menuBar = new QMenuBar(Qt_first_Day1Class);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        Qt_first_Day1Class->setMenuBar(menuBar);
        mainToolBar = new QToolBar(Qt_first_Day1Class);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        Qt_first_Day1Class->addToolBar(mainToolBar);
        centralWidget = new QWidget(Qt_first_Day1Class);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        Qt_first_Day1Class->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(Qt_first_Day1Class);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        Qt_first_Day1Class->setStatusBar(statusBar);

        retranslateUi(Qt_first_Day1Class);

        QMetaObject::connectSlotsByName(Qt_first_Day1Class);
    } // setupUi

    void retranslateUi(QMainWindow *Qt_first_Day1Class)
    {
        Qt_first_Day1Class->setWindowTitle(QCoreApplication::translate("Qt_first_Day1Class", "Qt_first_Day1", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Qt_first_Day1Class: public Ui_Qt_first_Day1Class {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QT_FIRST_DAY1_H
