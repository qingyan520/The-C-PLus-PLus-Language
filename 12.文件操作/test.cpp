//5.�ļ�����
//�ļ��ķ��ࣺ
//1.�ı��ļ�
//2.�������ļ�
//c++���ļ�����Ҫ��ͷ�ļ�<fstream>
//�ļ�������Ϊ3���ࣺ
//1.ofstream:д����
//2.ifstream:������
//3.fstream:��д����


//1.д�ļ�
//1.����ͷ�ļ�
//#include<fstream>
//2.����������
//ofstream ofs
//3.���ļ�
//ofs.open("�ļ�·��"��"�򿪷�ʽ")
//4.д����
//ofs<<"д������";
//5.�ر��ļ�
//ofs.close()
//ios::in Ϊ���ļ������ļ�
//ios::out Ϊд�ļ������ļ�
//ios::ate ��ʼλ�ã��ļ�β
//ios::app  ׷�ӷ�ʽд�ļ�
//ios::trunc ����ļ�������ɾ���ڴ���
//ios::binary �����Ʒ�ʽ
//ע�⣺�ļ��򿪷�ʽ�������ʹ�ã�����|������
//���磺�ö����Ƶķ�ʽд�ļ���ios::out|ios::binary
//#include<iostream>
//#include<fstream>
//using namespace std;
////�ı��ļ���д�ļ�
//void test01()
//{
//	//��������
//	ofstream ofs;
//	//ָ���򿪷�ʽ
//	ofs.open("data.txt", ios::out);
//	//д�ļ�
//	ofs << "��������ɽ" << endl;
//	ofs << "�Ա���" << endl;
//	ofs << "���䣺10" << endl;
//	ofs.close();
//}
//int main()
//{
//	test01();
//
//	system("pause");
//	return 0;
//}


////2.���ļ�
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
//		cout << "�ļ���ʧ��" << endl;
//		return;
//	}
//	//������
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
//�ļ��Ķ�ȡ�������ϰ
//#include<iostream>
//#include<fstream>
//#include<string>
//using namespace std;
//void test01()
//{
//	ofstream ofs;
//	ofs.open("text.txt", ios::out);
//	ofs << "ʷ��ΰ" << endl;
//	ofs << "20101320" << endl;
//	ifstream ifs;
//	ifs.open("text.txt", ios::in);
//	if (!ifs.is_open())
//	{
//		cout << "��ʧ��" << endl;
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



//�������ļ�
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
	person p = { "����",18 };
	//д�ļ�
	ofs.write((const char*) &p,sizeof(p));
	//�ر��ļ�
	ofs.close();
   //	���ļ�
	ifstream ifs;
	ifs.open("person.txt", ios::in|ios::binary);
	if (!ifs.is_open())
	{
		cout << "��ʧ��" << endl;
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