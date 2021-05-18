#include "Qt_first_Day1.h"
#include<qpushbutton.h>
//Qt命名规范，类名首字母大写  单词与单词之间首字母大写
//函数  变量  首字母小写   单词与单词之间首字母大写
//运行  ctrl+R
//编译  ctrl+B
//查找  ctrl+F
//帮助文档 F1
//字体缩放  ctrl+鼠标
//自动对齐  ctrl+i
//整行移动  ctrl+shift+上/下
//同名之间的.h,.cpp切换 F4


Qt_first_Day1::Qt_first_Day1(QWidget *parent)
    : QMainWindow(parent) //初始化列表
{
    //按钮
    QPushButton* brn = new QPushButton;
   // brn->show(); //show用顶层方式弹出，如果想在Qt_first_Day1窗口弹出，就需要·1以来Qt_first_Day1窗口
    //设置父亲
    brn->setParent(this);
    //设置文字
    brn->setText("hello world");  //将char*隐式类型转换为QString
    

    //创建按钮第二种方式
    QPushButton* btn2 = new QPushButton("ceww   ", this);
    //重置窗口大小
    this->resize(1600, 400);
    //移动第二个按钮
    btn2->move(100, 100);
    brn->move(0, 0);

    //按钮大小重置
    brn->resize(100, 100);

    //重置窗口标题
    brn->setWindowTitle("Qt第一个窗口");

    //设置固定窗口
    setFixedSize(1600, 400);

    //7.Qt中的对象树
    //一定程度上简化了内存回收机制
    //创建对象树，关闭时会自动从其父对象列表中删除


    //8.Qt中的坐标：x为右侧正向，y为左下为正方向



    //9.Qt中的信号和槽
    //点击按钮->窗口关闭
    //两个事情进行链接connect(信号的发送者，发送的信号，信号的接收者，处理的函数(槽函数));\
    //参数1：信号的发送者 brn
    //参数2：发送的信号 &
    //参数3
    connect(brn, &QPushButton::clicked,this,&QWidget::close);


    ui.setupUi(this);
}
