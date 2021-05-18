#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QDebug>
#include<QDialog>
#include<QMessageBox>
#include<QColorDialog>
#include<QFontDialog>
#include<QFileDialog>
#include<QString>
//点击新建，弹出对话框
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //信号与槽
    //connect（信号发送者，）
    connect(ui->actionnew,&QAction::triggered,[=](){
        //对话框分为：
        //1.模态对话框   不可以对其他窗口进行操作
        //2.非模态对话框   可以对其他窗口进行操作，不会阻塞


        //创建模态对话框
       // QDialog dlg(this);
        //dlg.exec();


        //非模态对话框
       // QDialog* dl=new QDialog(this);
        //dl->resize(300,100);
        //dl->show();
        //设置属性 55
        //dl->setAttribute(Qt::WA_DeleteOnClose);
          //  qDebug()<<"弹出对话框";
        //消息对话框MessageBox
        //错误提示
        //QMessageBox::critical(this,"critical","错误!");
        //信息提示
        //QMessageBox::information(this,"Information","信息提示");
        //询问提示
        //参数1  父窗口   参数2  标题    参数3  中间显示文本    参数4  按键类型    参数5   关联回车键
        //if(QMessageBox::Save==QMessageBox::question(this,"question","询问",QMessageBox::Save|QMessageBox::Cancel,QMessageBox::Cancel))
        //{
          //  qDebug()<<"选择的是保存";
        //}
        //else
        //{
          //  qDebug()<<"选择的是取消";
        //}
        //警告提示
        //QMessageBox::warning(this,"警告","程序出现问题");

        //颜色对话框
     //  QColor color=QColorDialog ::getColor(QColor(255,0,0));
      // qDebug()<<color.red()<<color.green()<<color.blue();

        //字体对话框
       // bool ok;
        //QFont font=QFontDialog ::getFont(&ok,QFont("陈静的字完整版",66));
        //qDebug()<<"字体："<<font.family()<<"字号："<<font.pointSize()

             //  <<"加粗："<<font.bold()<<"倾斜："<<font.italic();
        //文件对话框
       //QString str= QFileDialog::getOpenFileName(this,"打开文件","C:\\Users\\史金伟\\Desktop","(*.html  *.docx)");
       //qDebug()<<str;

    });
}

MainWindow::~MainWindow()
{
    delete ui;
}

