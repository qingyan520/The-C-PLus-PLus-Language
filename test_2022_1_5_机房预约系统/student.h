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
	//�˵�����
	virtual void operMenu();


	//�鿴�ҵ�ԤԼ
	void showMyOder();

	//����ԤԼ
	void applyOrder();

	//�鿴����ԤԼ
	void showAllOrder();

	//ȡ��ԤԼ
	void cancelOrder();

	int m_id;

};