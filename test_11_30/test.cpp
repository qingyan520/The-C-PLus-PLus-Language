#include<iostream>
#include<string.h>
#include<string>
using namespace std;
class A
{
public:
	 string temp;
	A()
	{
		for (int i = 1; temp.size() < INT_MAX; i++)
		{
			temp += to_string(i);
		}
	}
};
int main()
{
	cout << A().temp<< endl;
	return 0;
}