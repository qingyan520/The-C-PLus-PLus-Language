//1.vector������������
//���ܣ�
//vector���ݽṹ������ǳ����ƣ�Ҳ����Ϊ��������
//vector����ͨ���������
//��֮ͬ�����������Ǿ�̬�ģ���vector�ǿ��Զ�̬��չ��
//��̬��չ��
//��������ԭ�ռ�֮����¿ռ䣬�����ҵ�������ڴ�ռ䣬Ȼ��ԭ�����ݿ������¿ռ䣬�ͷ�ԭ�ռ�


//2.vector���캯��
//#include<iostream>
//#include<string>
//#include<vector>
//using namespace std;
//void Print(vector<int>v)
//{
//	for (vector<int>::iterator it = v.begin(); it != v.end(); it++)
//	{
//		cout << (*it) << " ";
//	}
//	cout << endl;
//}
//void test01()
//{
//	vector<int>v1;//Ĭ�Ϲ��죬�޲�
//	for (int i = 0; i < 10; i++)
//	{
//		v1.push_back(i);
//	}
//	Print(v1);
//	//ͨ�����䷽ʽ���й���
//	vector<int>v2(v1.begin(), v1.end());
//	Print(v2);
//
//	//n��elem��ʽ����
//	vector<int>v3(10, 100);
//	Print(v3);
//	//��������
//	vector<int>v4(v3);
//	Print(v4);
//}
//int main()
//{
//	test01();
//	system("pause");
//	return 0;
//}


//3.vector������ֵ����
//1.ֱ���õȺŽ��и�ֵ
//2.��string���ƣ���assign(begin,end)//��[begin,end)�����е����ݿ�����ֵ������
//3.assign(n,elem)//��n��elem������ֵ���䱾��
//#include<iostream>
//#include<vector>
//using namespace std;
//void Print(vector<int>v)
//{
//	for (vector<int>::iterator it = v.begin(); it != v.end(); it++)
//	{
//		cout << *it << " ";
//	}
//	cout << endl;
//}
//void test01()
//{
//	vector<int>v1;
//	v1.push_back(1);
//	v1.push_back(2);
//	vector<int>v2;
//	v2 = v1;
//	Print(v1);
//	Print(v2);
//	vector<int>v3;
//	v3.assign(v2.begin(),v2.end());
//	Print(v3);
//	vector<int>v4;
//	v4.assign(2, 4);
//	Print(v4);
//
//}
//int main()
//{
//	test01();
//	system("pause");
//	return 0;
//}



//4.vector���������ʹ�С
//��vector�����������ʹ�С����
//����ԭ�ͣ�
//empty();  //�ж������Ƿ�Ϊ�� �շ���1�����շ���0
//capacity();   //����������
//size();   //����������Ԫ�ظ���
//resize(int num);  //����ָ�������ĳ���,��size�Ĵ�С����Ϊnum,�������䳤������Ĭ��ֵ���λ��
//                                          ��������̣���ĩβ�����������ȵ�Ԫ�ر�ɾ��
//#include<iostream>
//#include<vector>
//using namespace std;
//void Print(vector<int>& v)
//{
//	for (vector<int>::iterator it = v.begin(); it != v.end(); it++)
//	{
//		cout << *it << " ";
//	}
//	cout << endl;
//}
//void test01()
//{
//	vector<int>v1;
//	for (int i = 0; i < 10; i++)
//	{
//		v1.push_back(i);
//	}
//	Print(v1);
//	cout << "v1��������" << v1.capacity() << endl;
//	cout << "v1��Ԫ��������" << v1.size() << endl;
//	v1.resize(15, 6);
//	Print(v1);
//	cout << "v1��������" << v1.capacity() << endl;
//	cout << "v1��Ԫ��������" << v1.size() << endl;
//	v1.resize(5);
//	Print(v1);
//	cout << "v1��������" << v1.capacity() << endl;
//	cout << "v1��Ԫ��������" << v1.size() << endl;
//}
//int main()
//{
//	test01();
//	system("pause");
//	return 0;
//}


//5.vector�����Ĳ����ɾ��
//��vector�������в���ɾ������
//push_back(ele);   //������β����������ele
//pop_back();   //ɾ������β������
//insert(int pos,ele)  //���±�Ϊpos��λ�ò�������ele
//erase(pos);   //ɾ���±�Ϊposλ�õ�Ԫ��
//erase(v.begin(),v.end());  //ɾ��[begin,end)֮������Ԫ��
//clear();  //��ո�����
//#include<iostream>
//#include<vector>
//using namespace std;
//void Print(vector<int>& v)
//{
//	for (vector<int>::iterator it = v.begin(); it != v.end(); it++)
//	{
//		cout << *it << " ";
//	}
//	cout << endl;
//}
//void test01()
//{
//	vector<int>v1;
//	for (int i = 0; i < 10; i++)
//	{
//		v1.push_back(i);
//	}
//	Print(v1);
//	v1.pop_back();
//	Print(v1);
//	v1.insert(v1.begin(), 100);//��һ������Ϊ������
//	Print(v1);
//	v1.insert(v1.begin(), 2, 1000);
//	Print(v1);
//	v1.erase(v1.begin());
//	Print(v1);
//	v1.erase(v1.begin(), v1.end());
//	v1.clear();
//	Print(v1);
//}
//int main()
//{
//	test01();
//	system("pause");
//	return 0;
//}


//6.vector���ݻ�ȡ
//��vector�����е�Ԫ�ؽ��ж�ȡ����
//����ԭ�ͣ�
//at(int idx);   //�����±�Ϊidxλ�õ�����
//operator[idx];    //�����±�Ϊidxλ�õ�����
//front();      //����������һ������
//back();      //�����������һ��Ԫ��
//#include<iostream>
//#include<vector>
//using namespace std;
//void test01()
//{
//	vector<int>v;
//	for (int i = 0; i < 10; i++)
//	{
//		v.push_back(i);
//	}
//	cout << v.at(0) << endl;
//	cout << v[1] << endl;
//	cout << v.front()<< endl;
//	cout << v.back() << endl;
//}
//int main()
//{
//	test01();
//	system("pause");
//	return 0;
//}


//7.vector��������
//swap(vec):��vec�뱾���Ԫ�ػ���
//#include<iostream>
//#include<vector>
//using namespace std;
//void Print(vector<int>& v)
//{
//	for (vector<int>::iterator it = v.begin(); it != v.end(); it++)
//	{
//		cout << *it << " ";
//	}
//	cout << endl;
//}
//void test01()
//{
//	vector<int>v1;
//	vector<int>v2;
//	for (int i = 0; i < 10; i++)
//	{
//		v1.push_back(i);
//	}
//	for (int i = 10; i < 20; i++)
//	{
//		v2.push_back(i);
//	}
//	Print(v1);
//	Print(v2);
//	v1.swap(v2);
//	Print(v1);
//	Print(v2);
//
//}
////�������Լ���������
//int main()
//{
//	test01();
//	system("pause");
//	return 0;
//}


//8.vector������Ԥ��
//����vector�����Ķ�̬��չ����
//reserve(int len);//����Ԥ��lenԪ�س��ȣ�Ԥ��λ�ò���ʼ����Ԫ�ز����Է���
#include<iostream>
#include<vector>
using namespace std;
void test01()
{
	vector<int>v;
	v.reserve(10);
	cout << v.capacity() << endl;
	cout << v.size() << endl;
}
int main()
{
	test01();
	system("pause");
	return 0;
}