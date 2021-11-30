#pragma once
#ifndef _ARRAYLIST_H_
#define _ARRAYLIST_H_
#include "List.h"
class ArrayList : public List {
private:
    int* data;   //�����������ݵĵط�
    int capacity;//����
   
public:
    //Ĭ�Ϲ��캯��������һ���߼�Ϊ�յ�˳���
    ArrayList();
    //�������캯��������һ���߼��������������ͬ��˳���
    ArrayList(const ArrayList& rhs);
    //ԭ�����鹹�캯��������һ�����������������ͬ��˳���
    ArrayList(int const a[], int n);
    //��乹�캯��������һ������Ϊn��value��˳���
    ArrayList(int n, int value);
    //����������һ��Ҫ����ʵ�֣��������ڴ�й©
    ~ArrayList();
    //���൱���븲�ǲ�ʵ�ָ����еĴ��麯��
    void insert(int pos, int value);
    void remove(int pos);
    int at(int pos)const;
    void modify(int pos, int newValue);
    //���ڸ�������ʵ�ֵ��麯��������ѡ�񸲸ǻ��߲�����
    //void disp(ostream&os)const;//�����������ֱ��ʹ�ø����е�ʵ��
};
#endif // _ARRAYLIST_H_

ArrayList::ArrayList():
    data(nullptr),
    capacity(0)
{

}

ArrayList::ArrayList(const ArrayList& rhs)
{
    this->capacity = rhs.capacity;
    data = new int[capacity];
    for (int i = 0; i < capacity; i++)
    {
        data[i] = rhs.data[i];
    }
}

ArrayList::ArrayList(int const a[], int n)
{
    this->capacity = n;
    data = new int[n];
    for (int i = 0; i < n; i++)
    {
        data[i] = a[i];
    }
}

