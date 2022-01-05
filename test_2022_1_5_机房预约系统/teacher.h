#pragma once

#include<iostream>
#include"Identity.h"
using namespace std;
class Teacher :public Identity
{
public:
	Teacher()
	{

	}

	Teacher(int empid, string name, string pwd);

	virtual void operMenu();

	void showAllOrder();

	void vailOrder();

	int m_Empid;

};
