#pragma once

#include"Identity.h"
#include"globalFile.h"

class Manger :public Identity
{
public:

	Manger()
	{

	}

	Manger(string name, string pwd);

	virtual void operMenu();

	void addPerson();

	void showPerson();

	void showComputer();

	void cleanFile();
};