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
    void disp(ostream&os)const;//�����������ֱ��ʹ�ø����е�ʵ��    
private:
    void setCapacity(int newCapa);
};
#endif // _ARRAYLIST_H_

/****************start from here**********************/


ArrayList::ArrayList()
{
    data = new int[1005];
    capacity = 0;
    size = 0;
}
ArrayList::~ArrayList()
{
    delete[] data;
}
ArrayList::ArrayList(const ArrayList& rhs)
{
    data = new int[1005];
    this->size = rhs.size;
    this->capacity = rhs.capacity;
    for (int i = 0; i < size; i++)
    {
        data[i] = rhs.data[i];
    }
}

ArrayList::ArrayList(const int a[], int n)
{
    data = new int[1005];
    size = n;
    capacity = n;
    for (int i = 0; i < n; i++)
    {
        data[i] = a[i];
    }
}

ArrayList::ArrayList(int n, int value)
{
    data = new int[1005];
    size = n;
    capacity = n;
    for (int i = 0; i < n; i++)
    {
        data[i] = value;
    }
}
//���൱���븲�ǲ�ʵ�ָ����еĴ��麯��
void ArrayList::insert(int pos, int value)
{
    data[pos] = value;
    capacity++;
    size++;
}
void ArrayList::remove(int pos)
{
    for (int i = 0; i < capacity; i++)
        data[i] = data[i + 1];
    capacity--;
    size--;
}
int ArrayList::at(int pos)const
{
    return data[pos];
}
void ArrayList::modify(int pos, int newValue)
{
    data[pos] = newValue;
}
void::ArrayList::disp(ostream& os)const
{
    for (int i = 0; i < size; i++)
    {
        os << data[i] << " ";
    }
   
}