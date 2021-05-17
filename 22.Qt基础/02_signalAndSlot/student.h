#ifndef STUDENT_H
#define STUDENT_H

#include <QObject>
#include<QString>
#include<QDebug>

class Student : public QObject
{
    Q_OBJECT
public:
    explicit Student(QObject *parent = nullptr);

signals:
public slots:
    //  槽函数  写到public  slots下，或者public，全局函数，lambda
    //返回值void
    //需要声明，需要实现
    //可以有参数，可以重载
    void  treat();
   // void treat(QString foodName);

};

#endif // STUDENT_H
