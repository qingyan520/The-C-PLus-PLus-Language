#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    //listWidget使用
    QListWidgetItem*item=new QListWidgetItem("楚河");
    //设置对齐方式setTextAlignment(Qt::)
    //ALignHCenter:居中对齐
    //Align Lift：左对齐
    //AlignRight:右对齐
    item->setTextAlignment(Qt::AlignHCenter);
    ui->listWidget->addItem(item);
   // ui->listWidget->addItem(QStringList()<<"hehe");
    QStringList list;
    list<<"锄禾日当午"<<"汗滴禾下土"<<"谁知盘中餐"<<"粒粒皆辛苦";
   // QListWidgetItem*it=new QListWidgetItem();
    ui->listWidget->addItems(list);
}

Widget::~Widget()
{
    delete ui;
}

