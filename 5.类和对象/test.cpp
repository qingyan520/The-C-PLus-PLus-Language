//c++的三大特性:封装，继承，多态
//分装的意义：将属性和行为作为一个整体
//将属性和行为加以权限控制
//#include<iostream>
//using namespace std;
//const double PI = 3.14;
////设计一个圆类，求圆的周长：2*pI*r
////class 代表类，后面跟名称
//class Circle
//{
//	//访问权限
//	//公共权限
//public:
//	//属性；
//	int m_r;
//	//行为
//	//获取圆的周长
//	double calculate()
//	{
//		return 2 * PI * m_r;
//	}
//};
//int main()
//{
//	//通过圆类 创建具体的圆
//	//实例化：通过一个类，进行具体的行为
//	Circle cl;
//	cl.m_r = 10;
//	cout << "圆的周长:" << cl.calculate()<<endl;
//	system("pause");
//	return 0;
//}
//类的练习
//#include<iostream>
//using namespace std;
//const double PI = 3.14;
////首先封装一个类，类的关键字：class
//class Circle
//{
//	//类具有访问权限，属性，行为
//	//设置访问权限：公共的
//public:
//	int m_r;//属性：圆的基本特征
//	//行为：一般通过函数来实现
//	double claute()
//	{
//		return 2 * PI * m_r;
//	}
//
//
//};
//int main()
//{
//	Circle cl;
//	cl.m_r = 10;
//	cout << "圆的周长为：" << cl.claute() << endl;
//
//
//	system("pause");
//	return 0;
//}
//类的实例：设计一个学生类，属性有学生的姓名，学号，可以给学生的姓名，学号赋值，显示学生的姓名和学号
//#include<iostream>
//#include<string>
//using namespace std;
//class student
//{
//	//类中的行为和属性 我们统称为成员
//	//属性 成员属性 成员变量
//	//行为函数 成员方法
//	//公共权限
//public:
//	//属性
//	string name;
//	string i_number;
//	//行为
//	//显示姓名和学号
//	void show()
//	{
//		cout << name << endl;
//		cout << i_number << endl;
//	}
//	//通过行为赋值
//	void setname(string iname)
//	{
//		name = iname;
//	}
//	void seti_number(string ID)
//	{
//		i_number = ID;
//	}
//};
//int main()
//{
//	//实例化
//	student s1;
//	s1.name = "张三";
//	s1.setname("sssw");
//	s1.i_number = "12345";
//	s1.show();
//	student s2;
//	s2.name = "李四";
//	s2.i_number = "123456";
//	s2.show();
//	system("pause");
//	return 0;
//}



//封装的意义
//三种访问权限：
//公共权限   public        类内可以访问  类外也可以访问
//保护权限   protected     类内可以访问  类外不可以访问    儿子可以访问父亲中的保护内容
//私有权限   private       类内可以访问  类外不可以访问    儿子不可以访问父亲的私有内容
//#include<iostream>
//#include<string>
//using namespace std;
//class person
//{
//public:
//	string name;
//protected:
//	string my_car;
//private:
//	string password;
//public:
//	void test()
//	{
//		name = "张三";
//		my_car = "666";
//		password = "11111";
//	}
//};
//int main()
//{
//	person s;
//	s.name = "zhansan1";
//	//cout << s.test() << endl;
//	system("pause");
//	return 0;
//}

//c++中class和struct的区别：
//唯一的区别在于访问权限不同：
//struct默认权限是public
//class默认权限是私有private
//
//成员属性设置为私有
//优点1：成员属性设置为私有，可以自己控制读写权限
//优点2：对于写权限，我们可以检测数据的有效性
//#include<iostream>
//using namespace std;
//class person
//{
//public:
//	//设置姓名
//	void setname(string iname)
//	{
//		name = iname;
//	}
//	//读姓名
//	string getname()
//	{
//		return name;
//	}
//	//获取年龄
//	//改成0-100之内
//	void setage(int iage)
//	{
//		if (iage >= 0 && iage <= 100)
//		{
//			age = iage;
//			cout << age << endl;
//		}
//		else
//		{
//			age = 0;
//			cout << "年龄有问题" << endl;
//		}
//	}
//	int getage()
//	{
//		age = 10;
//		return age;
//	}
//	//只写情人
//	void setLover(string iLover)
//	{
//		Lover = iLover;
//		cout << Lover << endl;
//	}
//private:
//	//姓名：可读 可写
//	string name;
//	//年龄：只读
//	int age;
//	//情人：只写
//	string Lover;
//};
//int main()
//{
//	person s;
//	s.setname("张三");
//	cout << "显示姓名：" << s.getname() << endl;
//	cout << "显示年龄：" << s.getage() << endl;
//	s.setLover("李四");
//	s.setage(100);
//	system("pause");
//	return 0;
//}


//设计案例：设计立方体
//求出立方体的面积和体积
//分别用全局函数和成员函数判断两个立方体是否相等
//#include<iostream>
//using namespace std;
//class Cube
//{
//public:
//	//设置长
//	void setL(int l)
//	{
//		m_L = l;
//	 }
//
//	//获取长
//	
//	int getL()
//	{
//		return m_L;
//	}
//	
//	
//	//设置宽
//	void setW(int w)
//	{
//		m_W = w;
//	}
//	//获取宽 
//	int getW()
//	{
//		return m_W;
//	}
//	
//	//设置高
//	void setH(int h)
//	{
//		m_H = h;
//	}
//	
//	//获取高 
//
//	int getH()
//	{
//		return m_H;
//	}
//	//获取体积
//	int v()
//	{
//		return m_L * m_W * m_H;
//	}
//
//	//获取面积
//	int s()
//	{
//		return 2 * m_L * m_W + 2 * m_L * m_H + 2 * m_W * m_H;
//	}
//	bool isnamebyclass(Cube c)
//	{
//		if (m_L == c.getL() && m_W == c.getW() && m_H == c.getH())
//		{
//			return true;
//		}
//		return false;
//	}
//	//属性
//private:
//	int m_L;
//	int m_W;
//	int m_H;
//};
//bool isname(Cube &c1, Cube &c2)
//{
//	if (c1.getL() == c2.getL() && c1.getW() == c2.getW() && c1.getH() == c2.getH())
//	{
//		return true;
//	}
//	return false;
//}
//int main()
//{
//	Cube c1;
//	c1.setL(10);
//	c1.setW(10);
//	c1.setH(10);
//	cout << "c1的面积是：" << c1.s() << endl;
//	cout << "c1的体积是：" << c1.v ()<< endl;
//	//创建第二个立方体
//	Cube c2;
//	c2.setL(10);
//	c2.setW(10);
//	c2.setH(11);
//	bool ret = isname(c1, c2);
//	if (ret)
//	{
//		cout << "全局函数：c1,c2相等" << endl;
//	}
//	else
//	{
//		cout << "c1,c2不相等" << endl;
//	}
//	ret = c1.isnamebyclass(c2);
//	if (ret)
//	{
//		cout << "局部函数：c1,c2相等" << endl;
//	}
//	else
//	{
//		cout << "c1,c2不相等" << endl;
//	}
//	system;("pause");
//	return 0;
//}



//练习案例2：设计一个圆类，判断点个圆的位置关系
//判断点和圆的位置关系：判断圆心到点的距离与半径的关系
//#include<iostream>
//using namespace std;
////点类：
//class Point
//{
//public:
//	void setx(int x)
//	{
//		m_x = x;
//	}
//	int getx()
//	{
//		return m_x;
//	}
//	void sety(int y)
//	{
//		m_y = y;
//	}
//	int gety()
//	{
//		return m_y;
//	}
//private:
//	int m_x;
//	int m_y;
//};
//class circle
//{
//public:
//	//设置半径
//	void setR(int r)
//	{
//		m_r = r;
//	}
//	//获取半径
//	int getR()
//	{
//		return m_r;
//	}
//	//设置圆心
//	void setConter(Point Center)
//	{
//		m_Center = Center;
//	}
//	//获取圆心
//	Point getConter()
//	{
//		return m_Center;
//	}
//private:
//	int m_r;
//	//在类中可以让另一个类作为本类的成员
//	Point m_Center;//设置圆心
//};
////判断点和圆的位置关系
//void isInCircle(circle& c, Point& p)
//{
//	if (c.getR() * c.getR() == (p.getx() - c.getConter().getx()) * (p.getx() - c.getConter().getx()) + (p.gety() - c.getConter().gety()) * (p.gety() - c.getConter().gety()))
//	{
//		cout << "点在圆上" << endl;
//	}
//	if (c.getR() * c.getR() > (p.getx() - c.getConter().getx()) * (p.getx() - c.getConter().getx()) + (p.gety() - c.getConter().gety()) * (p.gety() - c.getConter().gety()))
//	{
//		cout << "点在圆内" << endl;
//	}
//	if (c.getR() * c.getR() < (p.getx() - c.getConter().getx()) * (p.getx() - c.getConter().getx()) + (p.gety() - c.getConter().gety()) * (p.gety() - c.getConter().gety()))
//	{
//		cout << "点在圆外" << endl;
//	}
//}
//using namespace std;
//int main()
//{
//	circle c;
//	c.setR(10);
//	Point center;
//	center.setx(10);
//	center.sety(0);
//	c.setConter(center);
//	Point P;
//	P.setx(8);
//	P.sety(0);
//	isInCircle(c, P);
//	
//	system("pause");
//	return 0;
//}


//复习:定义一个类，求点和圆的位置关系
//#include<iostream>
//using namespace std;
//class Point
//{
//public:
//	void setX(int X)
//	{
//		x = X;
//	}
//	int getX()
//	{
//		return x;
//	}
//	void setY(int Y)
//	{
//		y = Y;
//	}
//	int getY()
//	{
//		return y;
//	}
//private:
//	int x;
//	int y;
//};
//class circle
//{
//public :
//	void setm_R(int R)
//	{
//		m_R = R;
//	}
//	int getm_R()
//	{
//		return m_R;
//	}
//	void setCenter_X(int x1)
//	{
//		Center.setX(x1);
//	}
//	int getCenter_X()
//	{
//		return Center.getX();
//	}
//	void setCenter_Y(int Y1)
//	{
//		Center.setY(Y1);
//	}
//	int getCenter_Y()
//	{
//		return Center.getY();
//	}
//private:
//	int m_R;
//	Point Center;
//};
//int main()
//{
//	circle c;
//	c.setm_R(10);
//	c.setCenter_X(10);
//	c.setCenter_Y(0);
//	system("pause");
//	return 0;
//}





//4.2对对象的初始化和清理
//4.2.1构造函数和析构函数
//构造函数：主要作用在于创建对象时为对象的成员赋初始值，构造函数由编译器自动调用，完成对象初始化和清理工作
//析构函数：主要作用在于对对象的销毁前系统自动调用，执行一些清理工作
//构造函数语法：类名(){}
//1.构造函数没有返回值，也能不写void
//2.构造函数名称与类名相同
//3.构造函数可以有参数，因此可以发生重载
//4.程序在调用对象时会自动调用构造，无需手动调用一次

//析构函数语法：~类名(){}
//1.析构函数，没有返回值也不写void
//2.函数名称与类名相同，前面要加上符号~
//3.析构函数不可以有参数，因此不可以发生重载
//4.程序在销毁对象前会自动调用析构函数，无需手动调用，而且只会调用一次
//#include<iostream>
//using namespace std;
////1.构造函数：没有返回值，不写void
//
//class Person
//{
//public:
//	Person()
//	{
//		cout << "Person构造函数的调用" << endl;
//	}
//	
//
//	//2.析构函数  进行清理操作
//	~Person()
//	{
//		cout << "Person析构函数调用" << endl;
//	}
//
//
//};
////构造函数共和析构函数必须有，如果不写，编译器会提供一个空的构造和析构
//void test01()
//{
//	Person P;//在栈上的数据，test01执行完毕后，释放这个对象
//
//}
//int main()
//{
//	//test01();
//	Person P;
//	system("pause");
//	return 0;
//}


//4.2.2构造函数的分类和调用
//两种调用方式：
//按参数分类：有参构造和无参构造
//按类型构造：普通构造和拷贝构造
//三种调用方法：
//括号法
//显示法
//隐式转化法
#include<iostream>
using namespace std;
class Person
{
public:
	Person()
	{
		cout<< "构造函数的无参构造" <<endl;//默认调用函数
	}
	Person(int a)
	{
		age = a;
		cout << "构造函数的有参构造" << endl;
	}
	//拷贝构造函数
	Person(const Person &p)
	{
		//将传入人身上的所有属性，拷贝到我身上
		age = p.age;

		cout << "拷贝构造函数的调用" << endl;
	}
	~Person()
	{
		cout << "析构函数的调用" << endl;
	}
	int age;
};
void test01()
{
	//1.括号法
	Person p1;//默认构造函数调用
	Person p2(10);//有参构造函数
	Person p3(p2);//调用拷贝调用函数
	//注意事项
	//1.调用默认构造函数的时候不要加小括号
	//因为下面这行代码编译器会认为是函数体的声明,不会认为在创建对象
	//Person p1();
	//
	cout << "p2的年龄：" << p2.age << endl;
	cout << "p3的年龄：" << p3.age << endl;

	//2.显示法
	Person p4;//默认构造
	Person p5 = Person(10);//有参构造
	//Person(10)匿名对象 特点：当前行结束执行后系统会立即回收掉匿名对象
	Person p6 = Person(p5);
	Person(10);
	cout << "aaa0" << endl;
	//注意事项2
	//不要利用拷贝构造函数初始化匿名对象,编译器会认为Person(p5)==Person p5对象声明重定义
	//Person(p5);


	//3.隐式转化法
	Person p7 = 10;//相当于写了 Person p4=Person(10);
	Person p8 = p7;
}
int main()
{
	test01();
	system("pause");
	return 0;
}