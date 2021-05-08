#pragma once
#include <qobject.h>
#include<qobject.h>
class Teacher :
    public QObject
{
    Q_OBJECT;
public:
  //  explicit Teacher(QObject* parent=0);
signals:
        //自定义信号，需要写到槽函数signals下、
    //返回类型必须是void
    //只需要声明，不需要实现
    //信号可以有参数
    //可以发生重载
    void hungary();
public slots:
};

