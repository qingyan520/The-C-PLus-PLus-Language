//#include<iostream>
//#include<string>
//using namespace std;
//int main()
//{
//	string s("hello");
//	return 0;
//}

//#include<string>
//#include<iostream>
//using namespace std;
//int main()
//{
//	string s1("hello");
//	string s2(s1);
//	return 0;
//}

//#include<string>
//#include<iostream>
//using namespace std;
//int main()
//{
//	string s1 = "hello";
//	return 0;
//}

//#include<iostream>
//#include<string>
//using namespace std;
//int main()
//{
//	string s1 = "hello";
//	string s2;
//	s2 = s1;
//	cout << s1 << endl;
//	cout << s2 << endl;
//	return 0;
//}


//1.支持与数组下标一样的访问方式
//#include<iostream>
//using namespace std;
//int main()
//{
//	string s1 = "hello";
//	for (int i = 0; i < s1.size(); i++)
//	{
//		cout <<s1.at(i)<< " ";
//	}
//	cout << endl;
//	return 0;
//}


//基于C++11的循环遍历方式
//#include<iostream>
//using namespace std;
//int main()
//{
//	string s1 = "hello";
//	for (auto &x : s1)
//	{
//		x++;
//		cout << x << " ";
//	}
//	cout << endl;
//	cout<<s1 << endl;
//	return 0;
//}


//3.基于迭代器的遍历
//3.基于迭代器的遍历
//#include<iostream>
//using namespace std;
//int main()
//{
//	string s = "hello";
//	for (string::iterator it = s.begin(); it != s.end(); it++)
//	{
//		cout << *it << " ";
//	}
//	cout << endl;
//	return 0;
//}

//设置反向迭代器反向遍历整个容器
//#include<iostream>
//using namespace std;
//int main()
//{
//	string s = "hello";
//	for (string::reverse_iterator it = s.rbegin(); it != s.rend(); it++)
//	{
//		cout << *it << " ";
//	}
//	cout << endl;
//	return 0;
//}



//常见插入接口
#include<iostream>
using namespace std;
int main()
{
	string s = "hello";
	s.append(" world");
	string s2;
	s2.append(5,'a');
	cout << s2 << endl;
	return 0;
}