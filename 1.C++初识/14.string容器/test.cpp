//1.string�Ĺ��캯��
//string��c++�����ַ������䱾����һ����
//string��char*������
//char*��һ��ָ��
//string��һ���࣬���ڷ�װ��char*,��������ַ�������һ��char*������
//�ص㣺
//string�ڷ�װ�˺ܶ��Ա����
//�磺����find������copy��ɾ��delete���滻replace������insert
//string����char*��������ڴ棬���õ��ĸ���Խ���ȡֵԽ��ȣ������ڲ����и���
//#include<iostream>
//#include<string>
//using namespace std;
//void test01()
//{
//	string s1;//Ĭ�Ϲ���
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

//2.string�����ĸ��Ʋ���
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
//��ֵ�����кܶ࣬һ���õȺ�������

//3.�ַ�����ƴ��
//ʵ�����ַ���ĩβƴ����һ���ַ���
//#include<iostream>
//#include<string>
//using namespace std;
//void test01()
//{
//	string str1 = "��";
//	str1 += "������Ϸ";
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
//	str3.append(str2,3,4);//����2����Ҫ���ĸ�λ�ÿ�ʼ��ȡ������3����Ҫ��ȡ�ַ��ĸ���
//	cout << "str3=" << str3 << endl;
//
//}
//int main()
//{
//	test01();
//	system("pause");
//	return 0;
//}

//4.�ַ����Ĳ��Һ��滻
//���ң�����ַ����Ƿ����
//�滻����ָ����λ���滻�ַ���
//#include<iostream>
//#include<string>
//using namespace std;
////����
//void test01()
//{
//	string str = "abcdefg";
//	int pos=str.find("df");//�����ַ��������ڷ��ظ��ַ�����λ�ã�����������򷵻�-1
//	cout << "pos=" << pos << endl;
//	//rfind��find������rfind��������飬find�������Ҳ�
//
//}
////2.�滻
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
//find�����Ǵ������Ҳ��ң�rfind�����Ǵ����������
//find�ҵ��ַ����󷵻ز��ҵĵ�һ���ַ�λ�ã��Ҳ�������-1
//replace���滻ʱ��Ҫ��ָ����λ�ÿ�ʼ���ж��ٸ��ַ����滻��ʲô�����ַ���


//5.�ַ���֮��ıȽ�
//�����ַ���ASCII����жԱȣ�
//=���� 0
//>���� 1
//<���� -1
//����ԭ�ͣ�
//int compare(const string&s)const;//���ַ���S���бȽ�
//int compare(const char*s)const;//���ַ���S�Ƚ�
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
//compare����ô��ǱȽ������ַ����Ƿ���ȣ��ж�˭��˭Сû��ʲô����


//6.string�ַ��Ĵ�ȡ4
//string�е����ַ��Ĵ�ȡ��ʽ������
//char operator[](int n);//ͨ��[]��ʽȡ�ַ�
//char&at(int n) //ͨ��at��ʽ��ȡ�ַ�
//#include<iostream>
//#include<string>
//using namespace std;
//void test01()
//{
//	string str = "hello world";
//	cout << str << endl;
//	//1.ͨ��[]���ʵ����ַ�
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
//�Ե����ַ����з��ʺ��޸������ַ�����[](�±귨)��.at(i)


//7.string�Ĳ����ɾ��
//��string�ַ������в����ɾ���ַ�����
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
//	str1.insert(1,5, 'a');//���±�Ϊ1�ĵط�����5���ַ�a
//	cout << str1 << endl;
//	str1.erase(1, 6);//���±�Ϊ1�ĵط����ɾ��6���ַ�
//	cout << str1 << endl;
//}
//int main()
//{
//	test01();
//	system("pause");
//	return 0;
//}
//insert��erase���Ǵ�0�±꿪ʼ


//8.string �Ӵ�
//���ַ����л�ȡ��Ҫ���Ӵ�
//substr(a,b):���±�Ϊa���ַ�����ȡb���ַ������Ӵ�
#include<iostream>
using namespace std;
void test01()
{
	string str = "abcdef";
	string subStr = str.substr(1, 10);
	cout << subStr << endl;
}
//ʵ�ò���
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