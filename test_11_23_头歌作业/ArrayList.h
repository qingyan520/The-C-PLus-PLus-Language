#ifndef _ARRAYLIST_H_
#define _ARRAYLIST_H_
#include "List.h"
class ArrayList : public List {
private:
    int* data;   //真正保存数据的地方
    int capacity;//容量
public:
    //默认构造函数，构造一个逻辑为空的顺序表
    ArrayList();
    //拷贝构造函数，构造一个逻辑上与参数内容相同的顺序表
    ArrayList(const ArrayList& rhs);
    //原生数组构造函数，构造一个内容与给定数组相同的顺序表
    ArrayList(int const a[], int n);
    //填充构造函数，构造一个内容为n个value的顺序表
    ArrayList(int n, int value);
    //析构函数，一定要自行实现，否则有内存泄漏
    ~ArrayList();
    //子类当中须覆盖并实现父类中的纯虚函数
    void insert(int pos, int value);
    void remove(int pos);
    int at(int pos)const;
    void modify(int pos, int newValue);
    //对于父类中已实现的虚函数，可以选择覆盖或者不覆盖
    void disp(ostream&os)const;//这个函数可以直接使用父类中的实现    
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
//子类当中须覆盖并实现父类中的纯虚函数
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