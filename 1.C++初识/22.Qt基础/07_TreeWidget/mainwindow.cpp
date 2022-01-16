#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //1.创建头标签
    ui->treeWidget->setHeaderLabels(QStringList()<<"英雄"<<"职业");
    //2.
    QTreeWidgetItem*liitem=new QTreeWidgetItem(QStringList()<<"力量");
    //添加顶层级别的item
    ui->treeWidget->addTopLevelItem(liitem);
    QTreeWidgetItem*miitem=new QTreeWidgetItem(QStringList()<<"敏捷");
    ui->treeWidget->addTopLevelItem(miitem);
    QTreeWidgetItem*zhiitem=new QTreeWidgetItem(QStringList()<<"伤害");
    ui->treeWidget->addTopLevelItem(zhiitem);
    //创建自Item，挂载到顶层的Item上
   QTreeWidgetItem*here1=new QTreeWidgetItem(QStringList()<<"张飞"<<"坦克");
   liitem->addChild(here1);
   QTreeWidgetItem*here2=new QTreeWidgetItem(QStringList()<<"貂蝉"<<"法师");
   miitem->addChild(here2);
   QTreeWidgetItem*here3=new QTreeWidgetItem(QStringList()<<"李白"<<"剑客");
   QTreeWidgetItem*here4=new QTreeWidgetItem(QStringList()<<"韩信"<<"打野");

   zhiitem->addChild(here3);
   zhiitem->addChild(here4);

}

MainWindow::~MainWindow()
{
    delete ui;
}

