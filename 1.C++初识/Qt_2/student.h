#pragma once
#include <qobject.h>
class student :
    public QObject
{
    Q_OBJECT;
public:
    explicit student(QObject* parent = 0);
signals:

public slots:
    //自定义槽函数
    //高版本下可以写到public或者全局函数中去
    //槽函数需要声明，也需要实现
    //槽函数返回值 void
    //槽函数有参数，也可以发生重载
    void treat();
};

