#include "widget.h"
#include "ui_widget.h"
#include<QDebug>
Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    connect(ui->RadBut_man,&QRadioButton::clicked,[=](){
        this->sex=true;


    });
    connect(ui->RadBat_women,&QRadioButton::clicked,[=](){
        this->sex=false;
    });
    connect(ui->pushButton_3,&QPushButton::clicked,[=](){
        if(this->sex)
            qDebug()<<"选择了男的";
        else
        {
            qDebug()<<"选择了女的";
        }
    });
}

Widget::~Widget()
{
    delete ui;
}

