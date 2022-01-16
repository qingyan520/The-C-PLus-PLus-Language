#include "widget.h"
#include "ui_widget.h"
#include<QDebug>
Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    //点击设置到一半
    connect(ui->btnset,&QPushButton::clicked,[=](){
        ui->widget->setData(50);
    });
    //获取数据
    connect(ui->btnget,&QPushButton::clicked,[=](){
        qDebug()<<ui->widget->getData();
    });
}

Widget::~Widget()
{
    delete ui;
}

