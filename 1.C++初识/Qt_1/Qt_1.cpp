#include "Qt_1.h"
#include<qpushbutton.h>

Qt_1::Qt_1(QWidget *parent)
    : QMainWindow(parent)
{
    QPushButton* btn = new QPushButton;
    //设置父亲
   btn->setParent(this);
    //设置按钮大小
    btn->resize(100, 40);
    //设置文字
    btn->setText("Button");
    //设置窗口大小
    this->resize(1000, 800);
    //设置按钮位置
    btn->move(0, 0);

    //设置信号与槽：为按钮赋予功能
    //connect(信号的发送者，信号的接收者，)
    connect(btn, &QPushButton::clicked, this, &QWidget::close);

    ui.setupUi(this);
}
