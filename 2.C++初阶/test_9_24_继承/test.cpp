////继承的基本用法
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

//继承的基础语法：
//1.class 子类名称:基础方式(public,protected,private) 父类(基类)
//2.继承中private和protected的区别：
//在类里面private和protected几乎没什么区别，但是在继承里面二者有一定的区别
//在继承中，private继承的都不可见，但是protected方式继承的都可以看见
//1.基类的private成员在派生类中无论以什么方式继承都是不可见的，这里的不可见是指基类的私有成员还是被继承到了派生类对象中，但是语法上限制派生类对象不管在类里面还是类外面都是不能去访问它
//2.基类private成员在派生类中是不能被访问，如果基类成员不想再类外直接被访问，但需要在派生类中能访问，就定义为protected，可以看出保护成员限定夫是因为继承才出现的
//3.基类的其他成员在子类的访问方式=min(成员在基类中的访问限定符，继承方式)
//4.class 默认继承方式是private，struct默认继承方式位publuc


//2.基类和派生类的赋值转换
//派生类对象可以将派生类的对象/派生类的引用/派生类的指针给父类
//父类对象不可以赋值给派生类
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


//函数名或者成员变量名称相同构成隐藏
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





//派生类的默认构函数


//下面利用保护的方法写一下：
//#include<iostream>
//using namespace std;
//class Person
//{
//public:
//	//构造函数
//	Person(string _name="",int _age=0):
//		name(_name),
//		age(_age)
//	{
//		cout << "Person构造函数" << endl;
//	}
//
//	//拷贝构造函数
//	Person(const Person& s):
//		name(s.name),
//		age(s.age)
//	{
//		cout << "Person拷贝构造函数" << endl;
//	}
//
//	//赋值构造函数
//	Person& operator=(const Person& s)
//	{
//		if (this != &s)
//		{
//			name = s.name;
//			age = s.age;
//		}
//		cout << "Person=重载" << endl;
//		return *this;
//	}
//
//	//析构函数
//	~Person()
//	{
//		cout << "~Person析构函数" << endl;
//	}
//
//protected:
//	string name;
//	int age;
//};
//class Student :public Person
//{
//public:
//	//构造函数
//	Student(string name="",int age=0,int id=0):
//		Person(name,age),
//		_id(id)
//	{
//		cout << "Student构造函数" << endl;
//	}
//	
//	//拷贝构造函数
//	Student(const Student& p):
//		Person(p),
//		_id(p._id)
//	{
//		cout << "Student拷贝构造函数" << endl;
//	}
//
//	//=重载
//	Student& operator=(const Student& s)
//	{
//		if (this != &s)
//		{
//			Person::operator=(s);
//			_id = s._id;
//		}
//		cout << "Student=重载" << endl;
//		return *this;
//	}
//
//	//析构函数
//	~Student()
//	{
//		cout << "~Student析构函数" << endl;
//	}
//
//private:
//	int _id;
//
//
//};
//int main()
//{
//	Student s("校长", 26, 20101320);
//	Student t(s);
//	Student u;
//	u = s;
//	return 0;
//}
//
//


//继承与友元
//友元关系不可以被继承
//基类友元不能访问子类私有和保护成员
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

//继承与静态成员
//静态成员被继承后所有成员共享，同时占有一个空间
#include<iostream>
//using namespace std;
//class Person
//{
//public:
//	Person()
//	{
//		count++;
//	}
//	static int count;//静态成员变量在类内进行声明，类外进行初始化
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
////单继承，多继承，菱形继承
////单继承：一个子类只含有一个父类，
////多继承：一个子类继承与多个父类
//
////菱形继承
////危害：
////造成数据的重叠
////解决方法:虚继承


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