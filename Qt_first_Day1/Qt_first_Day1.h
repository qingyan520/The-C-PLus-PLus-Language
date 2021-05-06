#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_Qt_first_Day1.h"

class Qt_first_Day1 : public QMainWindow  //继承QMainWindow
{
    Q_OBJECT  //Q_OBJECT宏，写了这个宏，就支持Qt中的信号和槽机制

public:
    Qt_first_Day1(QWidget *parent = Q_NULLPTR);  //构造函数

private:
    Ui::Qt_first_Day1Class ui;
};
