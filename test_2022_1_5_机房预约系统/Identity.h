#pragma once
#include<iostream>
#include<string.h>
using namespace std;

class Identity
{
public:

	virtual void operMenu() = 0;
	string m_Name;
	string m_Pwd;
};
