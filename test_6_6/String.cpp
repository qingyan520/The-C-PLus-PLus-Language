//String类的简单实现，实现基本的构造函数，析构函数，拷贝构造函数，赋值函数 
#include<iostream>
using namespace std;
class String
{
public:
	//重载赋值运算符实现自定义数据类型的输出
	friend ostream& operator<<(ostream& cout, const String& str);
	String(const char* str = 0);//构造函数
	String(const String& str);//拷贝构造函数
	String& operator=(const String& str);//赋值函数
	~String();

private:
	char* m_date;
};


//构造函数的实现
String::String(const char* str )
{
	if (str != nullptr)
	{
		m_date = new char[strlen(str) + 1];
		strcpy(m_date, str);
	}
	else
	{
		m_date = new char[1];
		*m_date = '\0';
	}
}

//拷贝构造函数的实现
String::String(const String& str)
{
	//直接开辟空间，进行赋值
	m_date = new char[strlen(str.m_date) + 1];
	strcpy(m_date, str.m_date);

}


//赋值操作符重载
String& String::operator=(const String& str)
{
	//首先第一步检查是不是自己给自己赋值
	if (this == &str)
	{
		return *this;
	}
	delete[]m_date;
	m_date = new char[strlen(str.m_date) + 1];
	strcpy(m_date, str.m_date);
	return *this;
}


//析构函数的调用
String::~String()
{
	delete[]m_date;
}

//重载赋值运算符实现自定义数据类型的输出
ostream& operator<<(ostream& cout, const String& str)
{
	cout << str.m_date << endl;
	return cout;
}
int main()
{
	String s1("hello");
	String s2(s1);
	cout << s1 << endl;
	cout << s2 << endl;
	String s3;
	s3 = s2;
	cout << s3;
	return 0;
}