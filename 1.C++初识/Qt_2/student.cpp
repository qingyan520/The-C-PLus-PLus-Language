#include "student.h"
#include<iostream>
using namespace std;
student::student(QObject* parent) :QObject(parent)
{

}
void student::treat()
{
	cout << "����ʦ�Է�" << endl;
}