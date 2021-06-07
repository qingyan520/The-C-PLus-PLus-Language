//#include<iostream>
//#include<array>
//using namespace std;
//int main()
//{
//	array<int,2*sizeof(int)>arr;
//	arr[0] = 1;
//	arr[1] = 1;
//	for (int i = 0; i < 1; i++)
//	{
//		cout << arr[i] << endl;
//	}
//	cout << arr.size() << endl;
//	return 0;
//}



#include<iostream>
using namespace std;
int main()
{
	string s = "hello";
	for (string::iterator it = s.begin(); it != s.end(); it++)
		cout << *it << " " << endl;

	return 0;
}