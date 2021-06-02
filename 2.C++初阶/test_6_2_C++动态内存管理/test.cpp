//#include<iostream>
//using namespace std;
//int main()
//{
//	////C语言动态申请空间
//	//int* p = (int*)malloc(sizeof(int));
//	////C++动态内存申请
//	//int* p = new int;
//	////C++在申请内存空间时可以对其进行初始化
//	//int* p = new int(10);//初始化这块申请的内存空间为10
//	////C语言对于动态数组的申请
//	//int* arr = (int*)malloc(sizeof(int) * 10);
//	////C++对于动态数组的申请
//	//int* arr = new int[10];
//	////C++在动态申请数组时还可以对齐进行初始化
//	//int* arr = new int[3]{ 1,2,3 };//对新开辟的int类型，大小为3的数组赋值为1，2，3
//	//int* p = (int*)malloc(sizeof(int));
//	//free(p);
//
//	//int* p = new int;
//	//delete p;
//
//	//int* arr = (int*)malloc(sizeof(int) * 4);
//	//free(arr);
//
//	//int* arr = new int[10];
//	//delete[]arr;
//	return 0;
//}


#include<iostream>
using namespace std;
class A
{
public:
	A(int a=10, int b=11)
	{
		_a = a;
		_b = b;
	}
	~A()
	{
		cout << "析构函数的调用" << endl;
	}
private:
	int _a;
	int _b;
};
int main()
{
	//C语言方式对自定义类型进行动态开辟
	A* p1 = (A*)malloc(sizeof(A));
	//C++方式对自定义类型进行动态分配
	A* p2 = new A;
	free(p1);
	delete p2;
	return 0;
}