#include "Qt_2.h"
//需求：创建两个类 Teacher类    student类
//下课后  teacher类  zt  发出一个信号  饿了
//学生相应信号，处理信号的槽函数   请客吃饭

Qt_2::Qt_2(QWidget *parent)
    : QMainWindow(parent)
{
    zt = new Teacher;
    st = new student(this);
    //链接老师和学生
    connect(zt, &Teacher::hungary, st, &student::treat);
    ui.setupUi(this);
}
void Qt_2::classisover()
{
    //出发老师饿了的信号属于自定义信号，关键字为emit
    emit zt->hungary();
}
