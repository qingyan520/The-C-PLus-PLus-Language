#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QMenuBar>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    resize(600,400);


    //菜单栏  只有一个
    QMenuBar*bar=menuBar();

    //设置菜单栏到窗口中去
    this->setMenuBar(bar);

    //添加菜单
   QMenu*fileMenu= bar->addMenu("文件");

   //添加菜单项
  QAction*newAction= fileMenu->addAction("新建");

    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

