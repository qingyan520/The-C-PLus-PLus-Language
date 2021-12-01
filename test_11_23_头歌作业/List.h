#pragma once
#ifndef _LIST_H_
#define _LIST_H_
#include <iostream>

using namespace std;
class List {
protected:
    int size;
public:
   // friend ostream operator << (ostream& os, const List& rhs);

    //兼具默认构造函数和功能构造函数
    List(int s = 0) :size(s) {}
    //拷贝构造函数
    List(const List& rhs) :size(rhs.size) {}
    /*以下为虚函数*/
    //作为继承的基类的析构函数一定要是虚的
    virtual ~List() {}
    //普通的非虚函数
    int getSize()const { return size; }
    /*以下为纯虚函数，即没有实现*/
    virtual void insert(int pos, int value) = 0;
    virtual void remove(int pos) = 0;
    virtual int at(int pos)const = 0;
    virtual void modify(int pos, int newValue) = 0;
    /*你的工作在这里：此处设计disp函数*/
    virtual void disp(ostream& os)const
    {

    }
};
#endif // _LIST_H_

//流输出运算符重载声明

