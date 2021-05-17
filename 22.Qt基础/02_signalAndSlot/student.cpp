#include "student.h"
#include<iostream>
using namespace std;
Student::Student(QObject *parent) : QObject(parent)
{

}
void Student::treat()
{

    cout<<"请老师吃饭";
}


//Qstring转为char*
//先调用toUtf-8转为QByteArray
//再调用data转为char

