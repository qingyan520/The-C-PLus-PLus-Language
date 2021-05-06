#include "Qt_first_Day1.h"
#include <QtWidgets/QApplication>  //应用程序

//程序入口 argc命令行的变量数量，argv命令行变量数组
int main(int argc, char *argv[])
{
    //应用程序对象a，有且只有一个应用程序对象
    QApplication a(argc, argv);
    //创建一个对象w
    Qt_first_Day1 w;
    //窗口默认不会弹出，要弹出调用show()
    w.show();
    //a.exec()进入消息循环机制,阻塞功能
    return a.exec();
}
