#pragma once
#include<iostream>
using namespace std;
class List
{
public:
	List(int s = 0) :size(s)
	{

	}

	List(const List& rhs) :size(rhs.size)
	{

	}

	virtual ~List()
	{

	}

	virtual void insert(int pos, int value) = 0;
	virtual void remove(int pos) = 0;
	virtual void at(int pos) = 0;
	virtual void modify(int pos, int newValue) = 0;

protected:
	int size;
};
