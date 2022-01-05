#pragma once
#include"Identity.h"

class Student :public Identity
{
public:
	Student()
	{

	}

	Student(int id, string name, string pwd)
	{
	}
	//菜单界面
	virtual void operMenu();


	//查看我的预约
	void showMyOder();

	//申请预约
	void applyOrder();

	//查看所有预约
	void showAllOrder();

	//取消预约
	void cancelOrder();

	int m_id;

};