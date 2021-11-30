#pragma once
#ifndef _LINKEDLIST_H_
#define _LINKEDLIST_H_
#include "List.h"
class LinkedList : public List {
public:
    //���ǵ�����ڵ�Ľṹ��
    struct Node {
        int data;
        Node* next;
        Node(int a = 0, Node* b = nullptr) :data(a), next(b) {}
    };
private:
    Node* head;//�����ͷ���
public:
    //Ĭ�Ϲ��캯��������һ���߼�Ϊ�յ�����
    LinkedList();
    //�������캯��������һ���߼��������������ͬ������
    LinkedList(const LinkedList& rhs);
    //ԭ�����鹹�캯��������һ�����������������ͬ������
    LinkedList(int const a[], int n);
    //��乹�캯��������һ������Ϊn��value������
    LinkedList(int n, int value);
    //����������һ��Ҫ����ʵ�֣��������ڴ�й©
    ~LinkedList();
    //���൱���븲�ǲ�ʵ�ָ����еĴ��麯��
    void insert(int pos, int value);
    void remove(int pos);
    int at(int pos)const;
    void modify(int pos, int newValue);
    //���ڸ�������ʵ�ֵ��麯��������ѡ�񸲸ǻ��߲�����
    //����LinkedList���࣬��������ʵ��disp����
    void disp(ostream& os)const;
};
#endif // _LINKEDLIST_H_