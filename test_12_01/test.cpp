#include<iostream>
using namespace std;
namespace a
{
	int b = 1;
}
namespace a
{
	int c = 2;
	int b = 1;
}
int main()
{
	cout << a::b<<" " << a::c << endl;
	cout << a::b << endl;
	return 0;
}