#include<iostream>
using namespace std;
class A
{
public:
	virtual void print();
	int a;
	int b;
};
  void A::print()
{

}
int main()
{
	//int* p = (int*)malloc(sizeof(int) * 10);
	//cout << sizeof(p) << endl;
	A* p = new A[10];
	cout << sizeof(p) << endl;
	return 0;
}