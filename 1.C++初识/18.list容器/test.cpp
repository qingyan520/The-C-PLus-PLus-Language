//list����
//1.list������������
//��������������ɣ��������ָ����
//���ܣ������ݽ�����ʽ�洢
//������һ������洢��Ԫ�ϵķ������Ĵ洢�ṹ������Ԫ�ص��߼�˳����ͨ�������е�ָ������ʵ�ֵ�
//�������ɣ���һϵ�еĽڵ����
//�ڵ����ɣ�һ���Ǵ洢����Ԫ�ص���������һ���Ǵ洢��һ���ڵ��ַ��ָ����
//STL�е�������һ��˫��ѭ������
//�ŵ㣺���Զ�����λ�ý��п��ٲ���ɾ��Ԫ��
//ȱ�㣺���������ٶ�û������죬ռ�ÿռ�������


//2.list�Ĺ��캯��
//list<T>lst;   //list����ģ����ʵ�֣������Ĭ�Ϲ�����ʽ
//list(begin,end); //���캯����(begin,end)����֮�ڵ�Ԫ�ؿ���������
//list(n,elem);  //��n��elem����������
//list(const list &lst);// �������캯��
//#include<iostream>
//#include<list>
//using namespace std;
//void test01()
//{
//	list<int>l1;
//	l1.push_back(1);
//	cout<<l1.size()<<endl;
//
//}
//int main()
//{
//	test01();
//	system("pause");
//	return 0;
//}

//3.list�ĸ�ֵ�뽻������
//1.��ֵ��
//1.=ֱ�Ӹ�ֵ
//2.assigal(begin,end);
//3.assigal(n,elem)
//4.l2(l1);
//2.swap������
//l1.swap(l2);//����l1,l2��ֵ



//4.list������С����
//1.empty:�ж������Ƿ�Ϊ�գ���Ϊ�գ�����1�����գ�����0
//2.size:�ж������Ĵ�С
//3.resize():����ָ����С����ɾ����С��ɾ��


//5.list�����Ĳ����ɾ��
//push_back(elem):������β������һ��Ԫ��
//pop_back():ɾ�����������һ��Ԫ��
//push_front(elem):��������ͷ����һ��Ԫ��
//pop_front():��������ͷɾ��һ��Ԫ��
//insert(pos,elem):��posλ�ü���elem,�����������ݵ�λ��
//insert(pos,begin(),end()):��posλ�ò���[begin,end)�����ϵ����ݣ��޷���ֵ
//insert(pos,n,elem):��posλ�ò���n��elem
//clear():�������
//erase(begin(),end())�������[begin,end)֮������ݣ�����
//remove(elem):ɾ������Ԫ��elem
//#include<list>
//#include<iostream>
//using namespace std;
//void Print(const list<int>lst)
//{
//	for (list<int>::const_iterator it = lst.begin(); it != lst.end(); it++)
//	{
//		cout << *it << " ";
//	}
//	cout << endl;
//}
//void test01()
//{
//	list<int>lst;
//	lst.push_back(10);
//	lst.push_back(20);
//	lst.push_back(30);
//	lst.push_back(40);
//	Print(lst);
//	lst.push_front(100);
//	Print(lst);
//
//}
//int main()
//{
//	test01();
//	system("pause");
//	return 0;
//}

//6.list���������ݴ�ȡ
//front():���ص�һ��Ԫ��
//back():�������һ��Ԫ��
//list�����������������������Կռ�洢���ݣ�������Ҳ��֧���������
//#include<list>
//#include<iostream>
//using namespace std;
//void test01()
//{
//	list<int>lst;
//	lst.push_back(10);
//	lst.push_back(20);
//	lst.push_back(30);
//	lst.push_back(40);
//	cout << lst.front() << endl;
//	cout << lst.back() << endl;
//}
//int main()
//{
//	test01();
//	system("pause");
//	return 0;
//)


//7.list��ת������
//reverse();��ת����
//sort();��������
//���в�֧��������ʵĵ�������֧�ֱ�׼�㷨
//�ڲ����ṩһЩ��Ա�ڲ��ĺ���
//#include<iostream>
//#include<list>
//#include<algorithm>
//using namespace std;
//void Print(const list<int>lst)
//{
//	for (list<int>::const_iterator it = lst.begin(); it != lst.end(); it++)
//	{
//		cout << *it << " ";
//	}
//	cout << endl;
//}
//bool compare(int v1, int v2)
//{
//	return v1 > v2;
//}
//void test01()
//{
//	list<int>lst;
//	lst.push_back(5);
//	lst.push_back(1);
//	lst.push_back(4);
//	lst.push_back(2);
//	lst.push_back(3);
//	Print(lst);
//	lst.reverse();
//	Print(lst);
//	lst.sort();
//	Print(lst);
//	lst.sort(compare);
//	Print(lst);
//}
//int main()
//{
//	test01();
//	system("pause");
//	return 0;
//}



//8.������
//������������person���Զ����������ͽ�������person�����������֣����䣬����
//������򣺰��������������������ͬ�������߽�������
#include<string>
#include<list>
#include<iostream>
using namespace std;
class person
{
public:
	person(string name, int age, int height)
	{
		this->name = name;
		this->age = age;
		this->height = height;
	}
public:
	string name;
	int age;
	int height;
};
//ָ���������
bool comparePerson(person& p1, person& p2)
{
	if (p1.age == p2.age)
	{
		return p1.height > p2.height;
	}
	return p1.age < p2.age;
}
void test01()
{
	list<person>lst;
	person p1("A", 15, 140);
	person p2("B", 16, 185);
	person p3("C",10,166);
	person p4("D", 15, 111);
	lst.push_back(p1);
	lst.push_back(p2);
	lst.push_back(p3);
	lst.push_back(p4);
	lst.sort(comparePerson);
	for (list<person>::iterator it = lst.begin(); it != lst.end(); it++)
	{
		cout << "������" << (*it).name << "  " << "���䣺" << (*it).age<< "  " << "��ߣ�" << (*it).height << endl;
	}
}
int main()
{
	test01();
	system("pause");
	return 0;
}

