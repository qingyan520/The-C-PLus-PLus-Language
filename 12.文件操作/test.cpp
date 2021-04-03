//5.文件操作
//文件的分类：
//1.文本文件
//2.二进制文件
//c++中文件操作要加头文件<fstream>
//文件操作分为3大类：
//1.ofstream:写操作
//2.ifstream:读操作
//3.fstream:读写操作


//1.写文件
//1.包含头文件
//#include<fstream>
//2.创建流对象
//ofstream ofs
//3.打开文件
//ofs.open("文件路径"，"打开方式")
//4.写数据
//ofs<<"写入数据";
//5.关闭文件
//ofs.close()
//ios::in 为读文件而打开文件
//ios::out 为写文件而打开文件
//ios::ate 初始位置：文件尾
//ios::app  追加方式写文件
//ios::trunc 如果文件存在先删除在创建
//ios::binary 二进制方式
//注意：文件打开放式可以配合使用，利用|操作符
//例如：用二进制的方式写文件：ios::out|ios::binary
//#include<iostream>
//#include<fstream>
//using namespace std;
////文本文件，写文件
//void test01()
//{
//	//创建对象
//	ofstream ofs;
//	//指定打开方式
//	ofs.open("data.txt", ios::out);
//	//写文件
//	ofs << "姓名：张山" << endl;
//	ofs << "性别：男" << endl;
//	ofs << "年龄：10" << endl;
//	ofs.close();
//}
//int main()
//{
//	test01();
//
//	system("pause");
//	return 0;
//}


////2.读文件
//#include<iostream>
//#include<fstream>
//#include<string>
//using namespace std;
//void test01()
//{
//	ifstream ifs;
//	ifs.open("data.txt", ios::in);
//	if (!ifs.is_open())
//	{
//		cout << "文件打开失败" << endl;
//		return;
//	}
//	//读数据
//	//1.
//	/*char buf[1024] = { 0 };
//	while (ifs >> buf)
//	{
//		cout << buf << endl;
//	}*/
//	//2.
//	/*char buf[1024] = { 0 };
//	while (ifs.getline(buf, 1024))
//	{
//		cout << buf << endl;
//	}*/
//	//3.
//	/*string buf;
//	while (getline(ifs, buf))
//	{
//		cout << buf << endl;
//	}*/
//	//4.
//	char c;
//	while ((c=ifs.get())!=EOF)
//	{
//		cout << c ;
//	}
//	ifs.close();
//
//}
//int main()
//{
//	test01();
//	system("pause");
//	return 0;
//}
//文件的读取与访问练习
//#include<iostream>
//#include<fstream>
//#include<string>
//using namespace std;
//void test01()
//{
//	ofstream ofs;
//	ofs.open("text.txt", ios::out);
//	ofs << "史金伟" << endl;
//	ofs << "20101320" << endl;
//	ifstream ifs;
//	ifs.open("text.txt", ios::in);
//	if (!ifs.is_open())
//	{
//		cout << "打开失败" << endl;
//	}
//	/*char buf[1024] = { 0 };
//	while (ifs>>buf)
//	{
//		cout << buf << endl;
//	}*/
//	/*char arr[1024] = { 0 };
//	while (ifs.getline(arr, 1024))
//	{
//		cout << arr << endl;
//	}*/
//	/*string str;
//	while (getline(ifs, str))
//	{
//		cout << str << endl;
//	}*/
//
//}
//int main()
//{
//	test01();
//	system("pause");
//	return 0;
//}



//二进制文件
#include<iostream>
#include<string>
#include<fstream>
using namespace std;
class person
{
public:
	char m_name[64];
	int m_age;
};
void test01()
{
	ofstream ofs;
	ofs.open("person.txt", ios::out | ios::binary);
	person p = { "张三",18 };
	//写文件
	ofs.write((const char*) &p,sizeof(p));
	//关闭文件
	ofs.close();
   //	读文件
	ifstream ifs;
	ifs.open("person.txt", ios::in|ios::binary);
	if (!ifs.is_open())
	{
		cout << "打开失败" << endl;
		return;
	}
	person ps;
	ifs.read((char*)&ps, sizeof(ps));
	cout << p.m_name << endl;
	cout << p.m_age << endl;
	ifs.close();
}
int main()
{
	test01();
	system("pause");
}