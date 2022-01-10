/********************************************************************************
** Form generated from reading UI file 'test_12_20.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TEST_12_20_H
#define UI_TEST_12_20_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QOpenGLWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_test_12_20Class
{
public:
    QPushButton *pushButton;
    QTextBrowser *textBrowser;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    QOpenGLWidget *openGLWidget;

    void setupUi(QWidget *test_12_20Class)
    {
        if (test_12_20Class->objectName().isEmpty())
            test_12_20Class->setObjectName(QString::fromUtf8("test_12_20Class"));
        test_12_20Class->resize(604, 406);
        pushButton = new QPushButton(test_12_20Class);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(160, 130, 93, 28));
        textBrowser = new QTextBrowser(test_12_20Class);
        textBrowser->setObjectName(QString::fromUtf8("textBrowser"));
        textBrowser->setGeometry(QRect(260, 200, 256, 192));
        scrollArea = new QScrollArea(test_12_20Class);
        scrollArea->setObjectName(QString::fromUtf8("scrollArea"));
        scrollArea->setGeometry(QRect(310, 90, 120, 87));
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QString::fromUtf8("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 118, 85));
        scrollArea->setWidget(scrollAreaWidgetContents);
        openGLWidget = new QOpenGLWidget(test_12_20Class);
        openGLWidget->setObjectName(QString::fromUtf8("openGLWidget"));
        openGLWidget->setGeometry(QRect(80, 30, 300, 200));

        retranslateUi(test_12_20Class);

        QMetaObject::connectSlotsByName(test_12_20Class);
    } // setupUi

    void retranslateUi(QWidget *test_12_20Class)
    {
        test_12_20Class->setWindowTitle(QCoreApplication::translate("test_12_20Class", "test_12_20", nullptr));
        pushButton->setText(QCoreApplication::translate("test_12_20Class", "\345\202\273\351\200\274", nullptr));
        textBrowser->setHtml(QCoreApplication::translate("test_12_20Class", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'SimSun'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">\351\242\235\344\274\201\351\271\2052\351\271\205\351\271\205\351\271\205we'we'w</p></body></html>", nullptr));
    } // retranslateUi

};

namespace Ui {
    class test_12_20Class: public Ui_test_12_20Class {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TEST_12_20_H
