//5.2
//�㷨����
//find      //����Ԫ��
//find_if   //����������Ԫ��
//adjacent_find    //���������ظ�Ԫ��
//binary_search    //���ֲ���
//count     //ͳ��Ԫ�ظ���
//count_if   //������ͳ��Ԫ�ظ���


//5.2.1 find
//����ָ��Ԫ�أ��ҵ�����ָ��Ԫ�صĵ������Ҳ������ص�����end()
//����ԭ�ͣ�
//find(iterator beg,iterator end,value);
//beg��ʼ������
//end����������
//value ���ҵ�Ԫ��
//#include<iostream>
//#include<vector>
//#include<algorithm>
//#include<string>
//using namespace std;
//void test01()
//{
//	vector<int>v;
//	for (int i = 0; i < 10; i++)
//	{
//		v.push_back(i);
//	}
//	vector<int>::iterator it=find(v.begin(), v.end(), 10);
//	if (it == v.end())
//	{
//		cout << "û�и�Ԫ��" << endl;
//	}
//	else
//	{
//		cout << *it << endl;
//	}
//}
//class person
//{
//public:
//	person(string name, int age)
//	{
//		this->name = name;
//		this->age = age;
//	}
//	bool operator==(const person& p)
//	{
//		if (this->age == p.age && this->name == p.name)
//		{
//			return true;
//		}
//		return false;
//	}
//	string name;
//	int age;
//};
//void test02()
//{
//	vector<person>v;
//	person p1("A", 10);
//	person p2("B", 20);
//	person p3("C", 30);
//	person p4("D", 40);
//	v.push_back(p1);
//	v.push_back(p2);
//	v.push_back(p3);
//	v.push_back(p4);
//	vector<person>::iterator it=find(v.begin(), v.end(), p2);
//	if (it != v.end())
//	{
//		cout << (*it).name << endl;
//		cout << (*it).age << endl;
//	}
//}
//int main()
//{
//	test02();
//	system("pause");
//	return 0;
//}


//5.2.2 find_if
//find_if(iterator beg,iterator end ,_pred)
//��ֵ����Ԫ�أ�����ָ��λ�õ��������Ҳ������ؽ���������λ��
//beg��ʼ������
//end����������
//����pred ��������ν��(����ֵΪbool�ķº���)
//#include<iostream>
//#include<algorithm>
//#include<vector>
//using namespace std;
//void test01()
//{
//	vector<int>v;
//	for (int i = 0; i < 10; i++)
//	{
//		v.push_back(i);
//	}
//
//
//}
//int main()
//{
//
//	test01();
//	system("pause");
//	return 0;
//}