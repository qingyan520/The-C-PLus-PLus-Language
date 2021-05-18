#include "widget.h"

#include <QApplication>


//teacher 老师类    student 学生类
//老师发出饿了信号  ，学生发生相应，请老师吃饭

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Widget w;
    w.show();
    return a.exec();
}
