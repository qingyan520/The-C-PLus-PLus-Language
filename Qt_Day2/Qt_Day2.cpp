#include "Qt_Day2.h"
#include<qpushbutton.h>
Qt_Day2::Qt_Day2(QWidget *parent)
    : QDialog(parent)
{
    //建立新窗口
    QPushButton* but = new QPushButton;
    //设置父亲
    but->setParent(this);
    //设置窗口文字
    but->setText("QtButton");
    //设置窗口大小
    this->resize(1000, 500);
    //设置按钮大小
    but->resize(100, 50);
    //移动按钮
    but->move(0, 0);
    //固定窗口大小
    this->setFixedSize(1000, 500);
    //设置窗口标题
    this->setWindowTitle("QtWindows");
    ui.setupUi(this);
}
