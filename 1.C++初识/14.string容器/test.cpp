//1.string的构造函数
//string是c++风格的字符串，其本质是一个类
//string与char*的区别：
//char*是一个指针
//string是一个类，类内封装了char*,管理这个字符串，是一个char*的容器
//特点：
//string内封装了很多成员方法
//如：查找find，拷贝copy，删除delete，替换replace，插入insert
//string管理char*所分配的内存，不用担心复制越界和取值越界等，由类内部进行负责
//#include<iostream>
//#include<string>
//using namespace std;
//void test01()
//{
//	string s1;//默认构造
//	const char* str = "hello";
//	string s2(str);
//	cout << "s2=" << s2 << endl;
//	string s3(s2);
//	cout << "s3=" << s3 << endl;
//
//	string s4(10, 'a');
//	cout << "s4=" << s4 << endl;
//}
//int main()
//{
//	test01();
//	system("pause");
//	return 0;
//}

//2.string容器的复制操作
//#include<iostream>
//#include<string>
//using namespace std;
//void test01()
//{
//	string str1,str2,str3;
//	str1 = "hello world";
//	cout << "str1=" << str1 << endl;
//	str2 = str1;
//	cout << "str2=" << str2 << endl;
//	str3 = 'a';
//	cout << "str3=" << str3 << endl;
//	string str4;
//	str4.assign("hello c++");
//	cout << "str4=" << str4 << endl;
//	string str5;
//	str5.assign("hello worle", 5);
//	cout << "str5=" << str5 << endl;
//	string str6;
//	str6.assign(str5);
//	cout << "str6=" << str6<< endl;
//	string str7;
//	str7.assign(10, 'x');
//	cout << "str7=" << str7 << endl;
//}
//int main()
//{
//	test01();
//	system("pause");
//	return 0;
//}
//赋值方法有很多，一般用等号相连接

//3.字符串的拼接
//实现在字符串末尾拼接另一串字符串
//#include<iostream>
//#include<string>
//using namespace std;
//void test01()
//{
//	string str1 = "我";
//	str1 += "爱玩游戏";
//	cout << "str1=" << str1 << endl;
//	str1 += ':';
//	cout << "str1=" << str1 << endl;
//	string str2 = "LOL DNF";
//	str1 += str2;
//	cout << "str1=" << str1 << endl;
//	string str3 = "I ";
//	str3.append("Love ");
//	cout << "str3=" << str3 << endl;
//	str3.append("Game abcd", 4);
//	cout << "str3=" << str3 << endl;
//	str3.append(str2,3,4);//参数2代表要从哪个位置开始截取，参数3代表要截取字符的个数
//	cout << "str3=" << str3 << endl;
//
//}
//int main()
//{
//	test01();
//	system("pause");
//	return 0;
//}

//4.字符串的查找和替换
//查找：检查字符串是否存在
//替换：在指定的位置替换字符串
//#include<iostream>
//#include<string>
//using namespace std;
////查找
//void test01()
//{
//	string str = "abcdefg";
//	int pos=str.find("df");//查找字符串若存在返回该字符串的位置，如果不存在则返回-1
//	cout << "pos=" << pos << endl;
//	//rfind和find的区别：rfind从右往左查，find从左往右查
//
//}
////2.替换
//void test02()
//{
//	string str1 = "abcdef";
//	str1.replace(1, 3, "1111");
//	cout << "str1=" << str1 << endl;
//}
//int main()
//{
//	//test01();
//	test02();
//	system("pause");
//	return 0;
//}
//find查找是从左往右查找，rfind查找是从右往左查找
//find找到字符串后返回查找的第一个字符位置，找不到返回-1
//replace在替换时，要从指定的位置开始，有多少个字符，替换成什么样的字符串


//5.字符串之间的比较
//按照字符的ASCII码进行对比：
//=返回 0
//>返回 1
//<返回 -1
//函数原型：
//int compare(const string&s)const;//与字符串S进行比较
//int compare(const char*s)const;//与字符串S比较
//#include<iostream>
//using namespace std;
//void test01()
//{
//	string str1 = "zello";
//	string str2 = "hello";
//	if (str1.compare(str2) == 0)
//	{
//		cout << "str1==str2\n";
//	}
//	if (str1.compare(str2) == -1)
//	{
//		cout << "str1<str2\n";
//	}
//	if (str1.compare(str2) == 1)
//	{
//		cout << "str1>str2\n";
//	}
//
//}
//int main()
//{
//	test01();
//	system("pause");
//	return 0;
//}
//compare最大用处是比较两个字符串是否相等，判断谁大谁小没有什么意义


//6.string字符的存取4
//string中单个字符的存取方式有两种
//char operator[](int n);//通过[]方式取字符
//char&at(int n) //通过at方式获取字符
//#include<iostream>
//#include<string>
//using namespace std;
//void test01()
//{
//	string str = "hello world";
//	cout << str << endl;
//	//1.通过[]访问单个字符
//	for (int i = 0; i < str.size(); i++)
//	{
//		cout << str[i] << endl;
//	}
//	for (int i = 0; i < str.size(); i++)
//	{
//		cout << str.at(i) << " ";
//	}
//	cout << endl;
//	str[0] = 'q';
//	cout << str << endl;
//	str.at(1) = 'q';
//	cout << str << endl;
//}
//int main()
//{
//	test01();
//	system("pause");
//	return 0;
//}
//对单个字符进行访问和修改有两种方法：[](下标法)，.at(i)


//7.string的插入和删除
//对string字符串进行插入和删除字符操作
//#include<iostream>
//#include<string>
//using namespace std;
//void test01()
//{
//	string str1 = "hello";
//	str1.insert(1, "w");
//	cout << str1 << endl;
//	string str2 = " he";
//	str1.insert(1, str2);
//	cout << str1 << endl;
//	str1.insert(1,5, 'a');//从下标为1的地方插入5个字符a
//	cout << str1 << endl;
//	str1.erase(1, 6);//从下标为1的地方向后删除6个字符
//	cout << str1 << endl;
//}
//int main()
//{
//	test01();
//	system("pause");
//	return 0;
//}
//insert和erase都是从0下标开始


//8.string 子串
//从字符串中获取想要的子串
//substr(a,b):从下标为a的字符向后截取b个字符构成子串
#include<iostream>
using namespace std;
void test01()
{
	string str = "abcdef";
	string subStr = str.substr(1, 10);
	cout << subStr << endl;
}
//实用操作
void test02()
{
	string email = "zhangsan@sina.com";
	int pos = email.find("@");
	cout << pos << endl;
	string username = email.substr(0, pos);
	cout << username << endl;
}
int main()
{
	test02();
	system("pause");
	return 0;
}