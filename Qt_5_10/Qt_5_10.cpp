#include "Qt_5_10.h"
#include<qpushbutton.h>
Qt_5_10::Qt_5_10(QWidget *parent)
    : QMainWindow(parent)
{
    QPushButton* btn = new QPushButton;
    //btn->setParent(this);
    //btn->setText("hello");

    ui.setupUi(this);
}
