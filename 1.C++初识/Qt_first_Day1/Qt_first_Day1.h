#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_Qt_first_Day1.h"

class Qt_first_Day1 : public QMainWindow  //�̳�QMainWindow
{
    Q_OBJECT  //Q_OBJECT�꣬д������꣬��֧��Qt�е��źźͲۻ���

public:
    Qt_first_Day1(QWidget *parent = Q_NULLPTR);  //���캯��

private:
    Ui::Qt_first_Day1Class ui;
};
