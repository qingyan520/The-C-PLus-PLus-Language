#include "widget.h"
Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    this->zt=new Teacher(this);
    this->st=new Student(this);

    //链接信号和槽
    connect(this->zt,&Teacher::hungry,this->st,&Student::treat);
   classisvoer();
}

Widget::~Widget()
{
}

   void Widget:: classisvoer()
   {
       //触发自定义信号
       emit this->zt->hungry();
   }
