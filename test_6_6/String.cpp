//String��ļ�ʵ�֣�ʵ�ֻ����Ĺ��캯���������������������캯������ֵ���� 
#include<iostream>
using namespace std;
class String
{
public:
	//���ظ�ֵ�����ʵ���Զ����������͵����
	friend ostream& operator<<(ostream& cout, const String& str);
	String(const char* str = 0);//���캯��
	String(const String& str);//�������캯��
	String& operator=(const String& str);//��ֵ����
	~String();

private:
	char* m_date;
};


//���캯����ʵ��
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

//�������캯����ʵ��
String::String(const String& str)
{
	//ֱ�ӿ��ٿռ䣬���и�ֵ
	m_date = new char[strlen(str.m_date) + 1];
	strcpy(m_date, str.m_date);

}


//��ֵ����������
String& String::operator=(const String& str)
{
	//���ȵ�һ������ǲ����Լ����Լ���ֵ
	if (this == &str)
	{
		return *this;
	}
	delete[]m_date;
	m_date = new char[strlen(str.m_date) + 1];
	strcpy(m_date, str.m_date);
	return *this;
}


//���������ĵ���
String::~String()
{
	delete[]m_date;
}

//���ظ�ֵ�����ʵ���Զ����������͵����
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