#include<iostream>
using namespace std;
int main()
{
	auto x{ 2.f };
	cout << typeid(x).name()<< endl;
	cout << x << endl;

	int a{ 10 };
	char s{ 's' };
	int arr[]{ 1,2,3,4,5 };
	cout << static_cast<double>(1 / 2) << endl;
	return 0;
}