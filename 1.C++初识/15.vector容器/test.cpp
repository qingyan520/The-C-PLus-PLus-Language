//1.vector容器基本概念
//功能：
//vector数据结构和数组非常相似，也称因为单端数组
//vector和普通数组的区别：
//不同之处在于数组是静态的，而vector是可以动态扩展的
//动态扩展：
//并不是在原空间之后接新空间，而是找到更大的内存空间，然后将原来数据拷贝到新空间，释放原空间


//2.vector构造函数
//#include<iostream>
//#include<string>
//#include<vector>
//using namespace std;
//void Print(vector<int>v)
//{
//	for (vector<int>::iterator it = v.begin(); it != v.end(); it++)
//	{
//		cout << (*it) << " ";
//	}
//	cout << endl;
//}
//void test01()
//{
//	vector<int>v1;//默认构造，无参
//	for (int i = 0; i < 10; i++)
//	{
//		v1.push_back(i);
//	}
//	Print(v1);
//	//通过区间方式进行构造
//	vector<int>v2(v1.begin(), v1.end());
//	Print(v2);
//
//	//n个elem方式构造
//	vector<int>v3(10, 100);
//	Print(v3);
//	//拷贝构造
//	vector<int>v4(v3);
//	Print(v4);
//}
//int main()
//{
//	test01();
//	system("pause");
//	return 0;
//}


//3.vector容器赋值操作
//1.直接用等号进行赋值
//2.与string类似，用assign(begin,end)//将[begin,end)区间中的数据拷贝赋值给本身
//3.assign(n,elem)//将n个elem拷贝赋值给其本身
//#include<iostream>
//#include<vector>
//using namespace std;
//void Print(vector<int>v)
//{
//	for (vector<int>::iterator it = v.begin(); it != v.end(); it++)
//	{
//		cout << *it << " ";
//	}
//	cout << endl;
//}
//void test01()
//{
//	vector<int>v1;
//	v1.push_back(1);
//	v1.push_back(2);
//	vector<int>v2;
//	v2 = v1;
//	Print(v1);
//	Print(v2);
//	vector<int>v3;
//	v3.assign(v2.begin(),v2.end());
//	Print(v3);
//	vector<int>v4;
//	v4.assign(2, 4);
//	Print(v4);
//
//}
//int main()
//{
//	test01();
//	system("pause");
//	return 0;
//}



//4.vector容器容量和大小
//对vector容器的容量和大小操作
//函数原型：
//empty();  //判断容器是否为空 空返回1，不空返回0
//capacity();   //容器的容量
//size();   //返回容器中元素个数
//resize(int num);  //重新指定容器的长度,即size的大小调整为num,若容器变长，则以默认值填充位置
//                                          若容器变短，则末尾超出容器长度的元素被删除
//#include<iostream>
//#include<vector>
//using namespace std;
//void Print(vector<int>& v)
//{
//	for (vector<int>::iterator it = v.begin(); it != v.end(); it++)
//	{
//		cout << *it << " ";
//	}
//	cout << endl;
//}
//void test01()
//{
//	vector<int>v1;
//	for (int i = 0; i < 10; i++)
//	{
//		v1.push_back(i);
//	}
//	Print(v1);
//	cout << "v1的容量：" << v1.capacity() << endl;
//	cout << "v1的元素数量：" << v1.size() << endl;
//	v1.resize(15, 6);
//	Print(v1);
//	cout << "v1的容量：" << v1.capacity() << endl;
//	cout << "v1的元素数量：" << v1.size() << endl;
//	v1.resize(5);
//	Print(v1);
//	cout << "v1的容量：" << v1.capacity() << endl;
//	cout << "v1的元素数量：" << v1.size() << endl;
//}
//int main()
//{
//	test01();
//	system("pause");
//	return 0;
//}


//5.vector容器的插入和删除
//对vector容器进行插入删除操作
//push_back(ele);   //在容器尾部插入数据ele
//pop_back();   //删除容器尾部数据
//insert(int pos,ele)  //在下表为pos的位置插入数据ele
//erase(pos);   //删除下表为pos位置的元素
//erase(v.begin(),v.end());  //删除[begin,end)之间所有元素
//clear();  //清空该容器
//#include<iostream>
//#include<vector>
//using namespace std;
//void Print(vector<int>& v)
//{
//	for (vector<int>::iterator it = v.begin(); it != v.end(); it++)
//	{
//		cout << *it << " ";
//	}
//	cout << endl;
//}
//void test01()
//{
//	vector<int>v1;
//	for (int i = 0; i < 10; i++)
//	{
//		v1.push_back(i);
//	}
//	Print(v1);
//	v1.pop_back();
//	Print(v1);
//	v1.insert(v1.begin(), 100);//第一个参数为迭代器
//	Print(v1);
//	v1.insert(v1.begin(), 2, 1000);
//	Print(v1);
//	v1.erase(v1.begin());
//	Print(v1);
//	v1.erase(v1.begin(), v1.end());
//	v1.clear();
//	Print(v1);
//}
//int main()
//{
//	test01();
//	system("pause");
//	return 0;
//}


//6.vector数据获取
//对vector容器中的元素进行读取操作
//函数原型：
//at(int idx);   //返回下标为idx位置的数据
//operator[idx];    //返回下标为idx位置的数据
//front();      //返回容器第一个数据
//back();      //返回容器最后一个元素
//#include<iostream>
//#include<vector>
//using namespace std;
//void test01()
//{
//	vector<int>v;
//	for (int i = 0; i < 10; i++)
//	{
//		v.push_back(i);
//	}
//	cout << v.at(0) << endl;
//	cout << v[1] << endl;
//	cout << v.front()<< endl;
//	cout << v.back() << endl;
//}
//int main()
//{
//	test01();
//	system("pause");
//	return 0;
//}


//7.vector互换容器
//swap(vec):将vec与本身的元素互换
//#include<iostream>
//#include<vector>
//using namespace std;
//void Print(vector<int>& v)
//{
//	for (vector<int>::iterator it = v.begin(); it != v.end(); it++)
//	{
//		cout << *it << " ";
//	}
//	cout << endl;
//}
//void test01()
//{
//	vector<int>v1;
//	vector<int>v2;
//	for (int i = 0; i < 10; i++)
//	{
//		v1.push_back(i);
//	}
//	for (int i = 10; i < 20; i++)
//	{
//		v2.push_back(i);
//	}
//	Print(v1);
//	Print(v2);
//	v1.swap(v2);
//	Print(v1);
//	Print(v2);
//
//}
////交换可以减少数据量
//int main()
//{
//	test01();
//	system("pause");
//	return 0;
//}


//8.vector容器的预留
//减少vector容器的动态扩展次数
//reserve(int len);//容器预留len元素长度，预留位置不初始化，元素不可以访问
#include<iostream>
#include<vector>
using namespace std;
void test01()
{
	vector<int>v;
	v.reserve(10);
	cout << v.capacity() << endl;
	cout << v.size() << endl;
}
int main()
{
	test01();
	system("pause");
	return 0;
}