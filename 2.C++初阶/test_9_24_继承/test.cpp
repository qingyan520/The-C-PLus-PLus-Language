////�̳еĻ����÷�
//#include<iostream>
//using namespace std;
//class Person
//{
//public:
//private:
//	string name = "Peter";
//	int age = 18;
//};
//class Student :public Person
//{
//public:
//	
//	void Print()
//	{
//		cout << "Name=" <<Person::name<< endl;
//		cout << "Age=" << age << endl;
//		cout << "id=" << id << endl;
//	}
//	int id;
//};
//int main()
//{
//	Student s;
//	//s.Person::Print();
//	s.id = 20101320;
//	s.Print();
//	system("Pause");
//	return 0;
//}

//�̳еĻ����﷨��
//1.class ��������:������ʽ(public,protected,private) ����(����)
//2.�̳���private��protected������
//��������private��protected����ûʲô���𣬵����ڼ̳����������һ��������
//�ڼ̳��У�private�̳еĶ����ɼ�������protected��ʽ�̳еĶ����Կ���
//1.�����private��Ա����������������ʲô��ʽ�̳ж��ǲ��ɼ��ģ�����Ĳ��ɼ���ָ�����˽�г�Ա���Ǳ��̳е�������������У������﷨��������������󲻹��������滹�������涼�ǲ���ȥ������
//2.����private��Ա�����������ǲ��ܱ����ʣ���������Ա����������ֱ�ӱ����ʣ�����Ҫ�����������ܷ��ʣ��Ͷ���Ϊprotected�����Կ���������Ա�޶�������Ϊ�̳вų��ֵ�
//3.�����������Ա������ķ��ʷ�ʽ=min(��Ա�ڻ����еķ����޶������̳з�ʽ)
//4.class Ĭ�ϼ̳з�ʽ��private��structĬ�ϼ̳з�ʽλpubluc


//2.�����������ĸ�ֵת��
//�����������Խ�������Ķ���/�����������/�������ָ�������
//������󲻿��Ը�ֵ��������
//#include<iostream>
//using namespace std;
//class Person
//{
//public:
//	string name = "Peter";
//	int age = 18;
//};
//class Student :public Person
//{
//public:
//	int id=0;
//};
//int main()
//{
//	Student s;
//	s.name = "Hello";
//	s.age = 10;
//	s.id = 20101320;
//	Person p;
//	p = s;
//	Person* prt = &s;
//	Person& inference = p;
//
//	return 0;
//}


//���������߳�Ա����������ͬ��������
//#include<iostream>
//using namespace std;
//class person
//{
//public:
//	int _age = 15;
//};
//class student :public person
//{
//public:
//	int _age = 25;
//};
//int main()
//{
//	student s;
//	cout << s.person::_age << endl;
//	return 0;
//}


//#include<iostream>
//using namespace std;
//class Person
//{
//public:
//	void fun()
//	{
//		cout << "Person::fun" << endl;
//	}
//};
//class Student :public Person
//{
//public:
//	void fun()
//	{
//		cout << "Student::fun" << endl;
//	}
//};
//int main()
//{
//	Student s;
//	s.fun();
//	s.Person::fun();
//
//	return 0;
//}





//�������Ĭ�Ϲ�����


//�������ñ����ķ���дһ�£�
//#include<iostream>
//using namespace std;
//class Person
//{
//public:
//	//���캯��
//	Person(string _name="",int _age=0):
//		name(_name),
//		age(_age)
//	{
//		cout << "Person���캯��" << endl;
//	}
//
//	//�������캯��
//	Person(const Person& s):
//		name(s.name),
//		age(s.age)
//	{
//		cout << "Person�������캯��" << endl;
//	}
//
//	//��ֵ���캯��
//	Person& operator=(const Person& s)
//	{
//		if (this != &s)
//		{
//			name = s.name;
//			age = s.age;
//		}
//		cout << "Person=����" << endl;
//		return *this;
//	}
//
//	//��������
//	~Person()
//	{
//		cout << "~Person��������" << endl;
//	}
//
//protected:
//	string name;
//	int age;
//};
//class Student :public Person
//{
//public:
//	//���캯��
//	Student(string name="",int age=0,int id=0):
//		Person(name,age),
//		_id(id)
//	{
//		cout << "Student���캯��" << endl;
//	}
//	
//	//�������캯��
//	Student(const Student& p):
//		Person(p),
//		_id(p._id)
//	{
//		cout << "Student�������캯��" << endl;
//	}
//
//	//=����
//	Student& operator=(const Student& s)
//	{
//		if (this != &s)
//		{
//			Person::operator=(s);
//			_id = s._id;
//		}
//		cout << "Student=����" << endl;
//		return *this;
//	}
//
//	//��������
//	~Student()
//	{
//		cout << "~Student��������" << endl;
//	}
//
//private:
//	int _id;
//
//
//};
//int main()
//{
//	Student s("У��", 26, 20101320);
//	Student t(s);
//	Student u;
//	u = s;
//	return 0;
//}
//
//


//�̳�����Ԫ
//��Ԫ��ϵ�����Ա��̳�
//������Ԫ���ܷ�������˽�кͱ�����Ա
//#include<iostream>
//using namespace std;
//class Student;
//class Person
//{
//	friend void Print(Person& p, Student& s);
//public:
//protected:
//	int num=10;
//};
//class Student :public Person
//{
//public:
//	friend void Print(Person& p, Student& s);
//protected:
//	int _num = 20;
//};
//void Print(Person& p, Student& s)
//{
//	cout <<p.num << endl;
//	cout << s._num << endl;
//}
//int main()
//{
//	Person p;
//	Student s;
//	Print(p, s);
//
//	return 0;
//}

//�̳��뾲̬��Ա
//��̬��Ա���̳к����г�Ա����ͬʱռ��һ���ռ�
#include<iostream>
//using namespace std;
//class Person
//{
//public:
//	Person()
//	{
//		count++;
//	}
//	static int count;//��̬��Ա���������ڽ���������������г�ʼ��
//
//};
//int Person::count = 0;
//class Student :public Person
//{
//public:
//
//};
//int main()
//{
//	Student s1;
//	Student s2;
//	Student s3;
//	Student s4;
//	cout << Person::count << endl;
//
//	return 0;
//}
//
////���̳У���̳У����μ̳�
////���̳У�һ������ֻ����һ�����࣬
////��̳У�һ������̳���������
//
////���μ̳�
////Σ����
////������ݵ��ص�
////�������:��̳�


#include<iostream>
using namespace std;
class Person
{
public:
	string _name;
};
class Student :virtual public Person
{
protected:
	int  _num;
};
class Teacher :virtual public Person
{
protected:
	int _id;
};
class Assitstant :public Student, public Teacher
{
protected:
	string _majorCourse;
};
int main()
{
	Assitstant a;
	a._name = "Peter";

	return 0;
}