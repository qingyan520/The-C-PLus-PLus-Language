#ifndef TEACHER_H
#define TEACHER_H

#include <QObject>
#include <QWidget>
#include<QString>
class Teacher : public QObject
{
    Q_OBJECT
public:
    explicit Teacher(QObject *parent = nullptr);
    //自定义信号  写到signals下
    //1.返回值是void
    //2.只需要声明，不需要实现
    //3.可以有参数，可以发生重载
    //4.发生重载要用函数指针


signals:
    void hungry();

};

#endif // TEACHER_H
