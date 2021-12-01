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
private:
    Node* advance(int pos)const;
};
#endif // _LINKEDLIST_H_

/****************start from here**********************/

LinkedList::LinkedList() {
    head = NULL;
    size = 0;
}
LinkedList::~LinkedList()
{
    Node* temp;
    for (int i = 0; i < size; i++)
    {
        temp = head;
        head = head->next;
        delete temp;
    }
}
void LinkedList::insert(int pos, int value)
{
    int index = 1;
    Node* temp = head;
    Node* node = new Node(value);
    if (size == 0)
    {
        node->next = temp;
        head = node;
        size++;
        return;
    }
    while (index < pos && temp != NULL)
    {
        temp = temp->next;
        index++;
    }
    node->next = temp->next;
    temp->next = node;
    size++;
    return;
}
void LinkedList::remove(int pos)
{
    if (pos == 0)
    {
        head = head->next;
        size--;
        return;
    }
    int index = 1;
    Node* temp = head;
    while (index < pos)
    {
        temp = temp->next;
        index++;
    }
    temp->next = temp->next->next;
    size--;
    return;
}
int LinkedList::at(int pos)const
{
    Node* temp = head;
    int index = 0;
    while (temp != NULL)
    {
        if (index == pos)
        {
            return temp->data;
        }
        temp = temp->next;
        index++;
    }
    return -1;
}
void LinkedList::modify(int pos, int newValue)
{
    Node* temp = head;
    int index = 0;
    while (temp != NULL)
    {
        if (index == pos)
        {
            break;
        }
        temp = temp->next;
        index++;
    }
    temp->data = newValue;
    return;
}
void  LinkedList::disp(ostream& os)const
{
    Node* temp = head;
    int index = 0;
    while (temp != NULL)
    {
        os << temp->data << " ";
        temp = temp->next;
        index++;
    }
 
    return;
}

class IList
{
public:
    virtual void insert(int pos, int value) = 0;
    virtual void remove(int pos) = 0;
    virtual int at(int pos)const = 0;
    virtual void modify(int pos, int newValue) = 0;
    virtual void disp(ostream& os)const
    {

    }

    virtual ~IList()
    {

    }
};