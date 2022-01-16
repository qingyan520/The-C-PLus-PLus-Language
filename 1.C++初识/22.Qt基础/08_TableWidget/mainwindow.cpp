#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //this->tableWidget->setcolumncount(3);
    QStringList namelist;
    namelist<<"张飞"<<"赵云"<<"关羽"<<"刘备"<<"孙权";
    for(int i=0;i<5;i++)
    {
       // this->table
    }

}

MainWindow::~MainWindow()
{
    delete ui;
}

