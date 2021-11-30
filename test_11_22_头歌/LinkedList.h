#pragma once
#ifndef _LINKEDLIST_H_
#define _LINKEDLIST_H_
#include "List.h"
class LinkedList : public List {
public:
    //这是单链表节点的结构体
    struct Node {
        int data;
        Node* next;
        Node(int a = 0, Node* b = nullptr) :data(a), next(b) {}
    };
private:
    Node* head;//链表的头结点
public:
    //默认构造函数，构造一个逻辑为空的链表
    LinkedList();
    //拷贝构造函数，构造一个逻辑上与参数内容相同的链表
    LinkedList(const LinkedList& rhs);
    //原生数组构造函数，构造一个内容与给定数组相同的链表
    LinkedList(int const a[], int n);
    //填充构造函数，构造一个内容为n个value的链表
    LinkedList(int n, int value);
    //析构函数，一定要自行实现，否则有内存泄漏
    ~LinkedList();
    //子类当中须覆盖并实现父类中的纯虚函数
    void insert(int pos, int value);
    void remove(int pos);
    int at(int pos)const;
    void modify(int pos, int newValue);
    //对于父类中已实现的虚函数，可以选择覆盖或者不覆盖
    //对于LinkedList子类，必须重新实现disp函数
    void disp(ostream& os)const;
};
#endif // _LINKEDLIST_H_