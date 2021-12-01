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

    //���Ĭ�Ϲ��캯���͹��ܹ��캯��
    List(int s = 0) :size(s) {}
    //�������캯��
    List(const List& rhs) :size(rhs.size) {}
    /*����Ϊ�麯��*/
    //��Ϊ�̳еĻ������������һ��Ҫ�����
    virtual ~List() {}
    //��ͨ�ķ��麯��
    int getSize()const { return size; }
    /*����Ϊ���麯������û��ʵ��*/
    virtual void insert(int pos, int value) = 0;
    virtual void remove(int pos) = 0;
    virtual int at(int pos)const = 0;
    virtual void modify(int pos, int newValue) = 0;
    /*��Ĺ���������˴����disp����*/
    virtual void disp(ostream& os)const
    {

    }
};
#endif // _LIST_H_

//������������������

