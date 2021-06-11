# C++常见面试题目及重难点解析

### 初识C++

###### 1.指针和应用的区别：

> 1.引用必须进行初始化，而指针不用进行初始化
> 2.引用自增增加的是源数据本身，而指针自增为增加源数据大小的步长
> 3.指针可以为空，引用不可以为空
> 4.指针和引用的大小不同，指针的大小只与操作系统有关，32为系统下为4字节，64位系统下位8字节，而引用的大小为源数据的大小
> 5.有多级指针，但是没有多级引用
> 6.访问实体方式不同，指针需要解引用，而引用编译器自动处理
> 7.引用在初始化一个实体之后就不能再引用其他实体，而指针可以指向任意同类型实体
> 8.引用比指针更加安全

###### 2.为为什么不推荐使用宏函数

> 1.使用宏函数不支持调试
> 2.宏语法复杂，容易出错，代码可读性差，维护性差
> 3.宏常量没有类型
> c++中那些技术替代了宏函数
> 1.常量定义利用const修饰
> 2.函数定义为内联函数

###### 3.那么内联函数这么好用，要不要每个函数都加inline函数使之变成内联函数呢，答案是否定的

> 1.inline是一种以空间换时间的做法，省去调用函数数额开销，所以代码过长
> 或者有循环/递归时不推荐使用内联函数
> 2.inline对编译器来说只是一个建议，编译器会自动进行优化，如果函数体内代码过长或者使用循环/递归
> 编译器会自动忽略内联
> 3.inline不建议声明与定义分开，分离会导致链接错误，因为inline被展开
> 就没有函数地址了，链接1就会出现错位找不到

###### 4.auto自动变量注意事项



> 1.必须进行初始化
> 2.一行可以定义多个变量，但是一行定义的多个变量类型要一样
> 3.auto在声明指针时与auto*没有区别
> 4.auto在使用引用类型时必须加&
> 5.auto不可以用来定义数组
> 6.auto不可以当作函数形参来使用
>
> 7.auto在实际中最常见的优势用法就是跟以后会讲到的C++11提供的新式for循环，还有lambda表达式等
> 进行配合使用



```c++
//基于范围的for循环
#include<iostream>
using namespace std;
int main()
{
	int arr[] = { 1,2,3,4,5 };
	for (auto e : arr)
	{
		cout << e << " " << endl;
	}
}
```



### 类和对象（上）



###### 1.在C++中class和struct的区别

> 解答：C++需要兼容C语言，所以C++中struct可以当成结构体去使用。另外C++中struct还可以用来定义类。
> 和class是定义类是一样的，区别是struct的成员默认访问方式是public，class是的成员默认访问方式是
> private。

###### 2.类的访问限定符

> 1. public修饰的成员在类外可以直接被访问
> 2. protected和private修饰的成员在类外不能直接被访问(此处protected和private是类似的)
> 3. 访问权限作用域从该访问限定符出现的位置开始直到下一个访问限定符出现时为止
> 4. class的默认访问权限为private，struct为public(因为struct要兼容C)
> 5. 注意：访问限定符只在编译时有用，当数据映射到内存后，没有任何访问限定符上的

###### 3.面对对象的三大特性

>  面向对象的三大特性：封装、继承、多态。

> 在类和对象阶段，我们只研究类的封装特性，那什么是封装呢？
>
> 封装：将数据和操作数据的方法进行有机结合，隐藏对象的属性和实现细节，仅对外公开接口来和对象进行交

###### 4.类的大小的计算

> 类的大小计算符合内存对齐规则，与C语言计算结构体的大小基本一致
> 结构体内存对齐规则：
>
> 1. 第一个成员在与结构体偏移量为0的地址处。
> 2. 其他成员变量要对齐到某个数字（对齐数）的整数倍的地址处。
>    注意：对齐数 = 编译器默认的一个对齐数 与 该成员大小的较小值。
>    VS中默认的对齐数为8
> 3. 结构体总大小为：最大对齐数（所有变量类型最大者与默认对齐参数取最小）的整数倍。
> 4. 如果嵌套了结构体的情况，嵌套的结构体对齐到自己的最大对齐数的整数倍处，结构体的整体大小就是
>    所有最大对齐数（含嵌套结构体的对齐数）的整数倍。
>
> 注意：类的大小不包括成员函数与静态成员变量，即类的大小为所有非静态成员变量大小之和
>
> 面试题：
>
> 1.为什么要内存对齐
>
> 2.指定内存对齐方式
>
> 3.什么是大小端，如何判断·机器是大段还是小段
>
> ###### 5.this指针

> C++编译器给每个“非静态的成员函数“增加了一个隐藏的指针参
> 数，让该指针指向当前对象(函数运行时调用该函数的对象)，在函数体中所有成员变量的操作，都是通过该
> 指针去访问。只不过所有的操作对用户是透明的，即用户不需要来传递，编译器自动完成

>  this指针的特性：
> 1. this指针的类型：类类型* const
> 2. 只能在“成员函数”的内部使用
> 3. this指针本质上其实是一个成员函数的形参，是对象调用成员函数时，将对象地址作为实参传递给this
> 形参。所以对象中不存储this指针。
> 4. this指针是成员函数第一个隐含的指针形参，一般情况由编译器通过ecx寄存器自动传递，不需要用户
> 传递

> 【面试题】
>
> 1. this指针存在哪里？
> 2. this指针可以为空吗？以为空吗？

```c++
// 1.下面程序能编译通过吗？
// 2.下面程序会崩溃吗？在哪里崩溃
class A
{ 
public:
	 void PrintA() 
 	{
 		cout<<_a<<endl;
 	}

	 void Show()
     {
         cout<<"Show()"<<endl;
 	 }
private:
 	int _a;
};
int main()
{
 	A* p = nullptr;
	p->PrintA(); 
	p->Show();
}
```

> 上述代码创建了一个空的对象，在传参时默认会传一个变量的地址（用户自己不能传，不然会报错，打印this指针为地址），此时p为空指针，不能进行解引用访问成员变量操作，调用p->PrintA()函数它会自动调用里面的成员变量_a，故会报错，而p->Show()不会对this指针进行操作，故不会报错

###### 5.构造函数

> 1.函数名与类名相同
>
> 2.没有返回值，也不写void
>
> 3.对象实例化时编译器会自动调用对应的构造函数
>
> 4.构造函数可以重载
>
> 5.如果类中没有显式定义构造函数，则C++编译器会自动生成一个默认的构造函数，一旦用户显式定义了编译器就不会自动生成

```
 #include<iostream>
 using namespace std;
 class Person
 {
 public:    
	 //1.编译器提供的默认构造函数，什么都不做   
 	Person()    
	 {            
 	 }
 	//2.带参数的默认构造函数   
	 Person(string name,int age )   
	 {       
		 this->_name = name;        
 		this->_age = age;  
 	 }    
 void Print()   
 {       
 	cout << "姓名：" << this->_name << "  " << "年龄：" << this->_age << endl;   
 }
 private:    
	 string _name;   
 	 int _age;
 };
 int main()
 {    
	 Person P1("小王",16);  
   	 P1.Print();  
 	 Person P2;   
 	 P2.Print;  
  	 system("pause"); 
 	 return 0;
 }


```

###### 6.析构函数

> 1.析构函数名是在类名前面加上字符~
>
> 2.无参数，没有返回值，不写void
>
> 3.一个类有且只有一个析构函数，系统会自动生成默认的析构函数
>
> 4.对象生命周期结束时，C++编译系统自动调用析构函数
>
> 5.如果有成员变量是在堆区创建出来的，我们要在析构函数中手动释放

```
#include<iostream>
using namespace std;
class Person
{
public:
	Person()
	{
		arr = (int*)malloc(sizeof(int) * 1);
	}
	~Person()
	{
		

	free(arr);
	cout << "Person的析构函数的调用" << endl;

}
int* arr;

};
int main()
{
	Person p;
	return 0;
}
```

###### 7.拷贝构造函数

> 1.拷贝构造函数是构造函数的一个重载形式
>
> 2.拷贝构造函数的参数有且只有一个必须使用引用传参，使用传值方式会引发无穷递归调用
>
> 3.若显示定义，系统生成默认的拷贝构造函数，默认的拷贝构造函数对象按内存存储字节序完成拷贝，这种拷贝我们称为浅拷贝，或者值拷贝
>
> 4.编译器提供的构造函数是按照字节序进行拷贝的，因此又叫做值拷贝或者浅拷贝

```
Person(const Person& p)
	{
		this->_a = p._a;
	}
```

> 注意拷贝构造函数传参时要用引用传递，不然会引起无线递归使程序奔溃

> Ps:注意深浅拷贝问题

###### 8.运算符重载

> C++为了增强代码的可读性引入了运算符重载，运算符重载是具有特殊函数名的函数，也具有返回值类型，函数名及其参数列表，其返回值类型与参数列表与普通的函数类似
>
> 函数名字：关键字operator+操作符+（参数列表）
>
> 函数原型：返回值类型 operator+操作符+（参数列表）

> 注意：
>
> 1.不能通过连接其它符号创建新的操作符
>
> 2.重载操作符必须有一个类类型或者枚举类型的操作数
>
> 3.用于内置类型的操作数，其含义不能改变，例如：+，不能改变其含义
>
> 4.作为类成员的重载函数时，其形式看起来比操作数数目少1的成员函数的操作符有一个默认的形参this，限定为第一个参数
>
> 5.*  、. 、 ：：、sizeof、   ?  :、 注意以上5个运算符不能重载

> 1.赋值运算符重载：

> 注意要点：
>
> 1.参数类型
>
> 2.返回值
>
> 3.检测是否自己给自己赋值
>
> 4.返回*this
>
> 5.一个类如果没有显示定义赋值运算符，编译器也会自动生成一个，完成对象按字节序的值拷贝

```c++
Person& operator=(const Person& p)
	{
		if (this != &p)
		{
			this->m_num = p.m_num;
		}
		return *this;
	}
```

> 2.前置与后置++运算符重载

```c++
前置++运算符重载：

//假设类中只有一个数字m_num,实现对num的前置++
person &operator++()
{c
		this->m_num++;
		return *this;
}
//重载前置++运算符，返回引用是为了一直对一个数据进行递增
```

```c++
后置++运算符重载
person operator++(int)//int为占位参数，为了与前面的前置运算++区分开
{
	person temp;
	temp.m_num =this->m_num;
	this->m_num++;
	return temp;
}
//重载后置++运算符，int代表占位参数，用来区分前置与后置递增
//后置递增返回值，前置递增返回引用
```

> 3.前置与后置--运算符重载：

```c++
前置--运算符重载

//前置--，先-之后直接返回结果，用引用的方式返回
person& operator--()
{
	this->m_num--;
	return *this;
}
```

```c++
后置--运算符重载

//后置--，先返回值，后减减，直接返回
//其中int为函数重载，防止命名冲突
person operator--(int)
{
	person temp = *this;//这里必须是*this，不然会报错
	this->m_num--;
	return temp;
}
```

> 4.逻辑运算符重载：

```c++
==运算符重载

bool operator==(person& p)
{
		if (this->m_num==p->m_num)
		{
			return true;
		}
		return false;
}
```

```c++
！=运算符重载

bool operator==(person& p)
{
		if (this->m_num!=p->m_num)
		{
			return true;
		}
		return false;
}
```

> 5.左移运算符重载

> 左移运算符重载配合友元可实现自定义数据类型的输出

```c++
//左移运算符配合友元可以实现自定义数据类型的输出，如下所示实现了Person类型数据的输出
#include<iostream>
using namespace std;
class Person
{
public:
	friend ostream& operator<<(ostream& cout, const Person& p);
	Person(int num)
	{
		m_num = num;
	}
private:
	int m_num;
}; 
ostream& operator<<(ostream& cout, const Person& p)
{
	cout << p.m_num << endl;
	return cout;
}
int main()
{
	Person P1(10);
	cout << P1 << endl;
}
```



###### 9.&操作符重载及const修饰的&操作符重载

> 1.const修饰类的成员函数
>
> 将const修饰的类成员函数称之为const成员函数，const修饰类成员函数，实际修饰该成员函数中的this指针，表明该成员函数中不能对类的任何成员进行修改

> 2.&及const取地址操作符重载
>
> 这两个默认成员函数一般不用重新定义，编译器会默认生成
>
> 这两个运算符一般不需要重载，使用编译器生成的默认取地址的宠爱即可，只有特殊情况，才需要重载，比如想让别人获取到指定的内容

10.综合案例：日期类的实现

```c++
Date.h:
#pragma once
#include<iostream>
using namespace std;
class Date
{
public:
	friend ostream& operator <<(ostream& cout, const Date& p);
	friend istream& operator >>(istream& cin, Date& p);

	//检查每个月天数是否合法
	inline int GetMonthDay(int year, int month)
	{
		int day[] = { 0, 31,28,31,30,31,30,31,31,30,31,30,31 };
		int ret = day[month];
		if (month == 2 && ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)))
		{
			ret += 1;
		}
		return ret;
	}


	//构造函数初始化日期
	Date(int year = 1900, int month = 1, int day = 1)
	{
		if (year < 0 || month <= 0 || month>12 || day <= 0 || day > GetMonthDay(year, month))
		{
			cout << "非法日期" << endl;
			exit(-1);
		}
		else
		{
			this->_year = year;
			this->_month = month;
			this->_day = day;
		}
	}


	//日期+=day
	Date& operator+=(int day);
	
	//日期+day
	Date operator+(int day);
	
	//日期-=day
	Date& operator-=(int day);
	
	//日期-day
	Date operator-(int day);
	
	//前置++
	Date &operator ++();
	
	//后置++
	Date operator++(int);
	
	//前置--
	Date& operator--();
	
	//后置--
	Date operator--(int);
	
	//==
	bool operator==(const Date& p);
	
	//!=
	bool operator!=(const Date& p);
	
	//d1>d2
	bool operator>(const Date& p);
	
	//>=
	bool operator>=(const Date& p);


	//<
	bool operator<(const Date& p);
	
	//<=
	bool operator<=(const Date& p);


​	


	//日期-日期，求出两个日期之间的差距
	int operator-(const Date& p);



private:
	int _year;
	int _month;
	int _day;
};


//友元+重载左移运算符实现自定义数据类型的输出
ostream& operator <<(ostream& cout, const Date& p);

//友元+重载右移运算符实现自定义数据类型的输入
istream& operator >>(istream& cin, Date& p);
```

```c++
#include"Date.h"



ostream& operator <<(ostream& cout, const Date& p)
{
	cout << p._year << "-" << p._month << "-" << p._day << endl;
	return cout;
}

//右移运算符重载
istream& operator >>(istream& cin, Date& p)
{
	cin >> p._year >> p._month >> p._day;
	return cin;
}


//日期+=day
Date& Date::operator+=(int day)
{
	//要是加一个负数，相当于-=
	if (day < 0)
	{
		 return *this -= -day;
	}

	else
	{
		this->_day += day;
		while (this->_day > this->GetMonthDay(_year, _month))
		{
			_day -= GetMonthDay(_year, _month);
			_month++;
			if (_month > 12)
			{
				_year++;
				_month = 1;
			}
		}
		return *this;
	}

}


//日期+day
Date Date:: operator+(int day)
{
	//创建临时变量
	Date temp(*this);
	temp += day;
	return temp;
}


Date& Date::operator-=(int day)
{
	if (day < 0)
	{
		return *this += -day;
	}
	else
	{
		this->_day -= day;
		while (this->_day <= 0)
		{

			_month--;
			if (_month == 0)
			{
				--_year;
				_month == 12;
			}
			_day += GetMonthDay(_year, _month);
		}
		return *this;
	}

}

//日期-day
Date Date::operator-(int day)
{
	Date temp(*this);
	temp-= day;
	return temp;
}


//前置++运算符重载
Date& Date::operator++()
{
	return *this += 1;
}

//后置++运算符重载
Date Date::operator++(int)
{
	Date temp(*this);
	*this += 1;
	return temp;
}

//前置--运算符重载
Date& Date::operator--()
{
	return *this -= 1;
}

//后置--运算符重载
Date Date::operator--(int)
{
	Date temp(*this);
	*this -= 1;
	return temp;
}




//==运算符重载
bool Date::operator==(const Date& p)
{
	return (_year == p._year) &&
		(_month == p._month) &&
		(_day == p._day);
}


//>重载
bool Date::operator>(const Date& p)
{
	if (_year > p._year)
	{
		return true;
	}
	else if (_year == p._year)
	{
		if (_month > p._month)
		{
			return true;
		}
		else if (_month == p._month)
		{
			if (_day > p._day)
			{
				return true;
			}
		}
	}
	return false;
}

//!=重载
bool Date::operator !=(const Date& p)
{
	return !(*this == p);
}

//>=重载
bool Date::operator>=(const Date& p)
{
	return (*this > p) || (*this == p);
}


//<号重载
bool Date::operator<(const Date& p)
{
	return !(*this > p);
}

//<=重载
bool Date::operator<=(const Date& p)
{
	return *this < p || *this == p;
}

//日期-日期  返回两个日期之间的差距
int Date::operator -(const Date& p)
{
	Date Max = *this;
	Date Min = p;
	int flag= 1;
	int n = 0;
	if (*this < p)
	{
		Max = p;
		Min = *this;
		flag = -1;
	}
	while (Min != Max)
	{
		++Min;
		n++;
	}
	return n * flag;
}


```

### 类和对象（下）

###### 1.const修饰的成员函数

> 在c++中在成员函数后面加const修饰称为const修饰的成员函数成员函数在被const修饰之后，其this指针指向的值就不能被修改
> 实际上被修饰的是this指针，表面该类中成员不可以被修改

> 面试题：
>
> 1. const对象可以调用非const成员函数吗？
>  不可以，相当于权限的放大
> 2. 非const对象可以调用const成员函数吗？
>      可以，权限缩小
> 3. const成员函数内可以调用其它的非const成员函数吗？
>      不可以，相当于权限的放大
> 4. 非const成员函数内可以调用其它的const成员函数吗
>     可以，相当于权限的缩小



###### 2.友元

> 友元技术可以让类外函数访问类中的私有成员
> 关键字：friend;
> 分类：类友元 ，函数友元
> 友元配合左移运算符可以实现自定义数据类型的输出
> 友元配合右移运算符可以实现自定义数据类型的输入

```c++
//友元配合运算符重载实现自定义数据类型的输入与输出

#include<iostream>
using namespace std;
class Date
{
public:
	Date(int year=0, int month =0,int day=0)
	{
		this->_year = year;
		this->_month = month;
		this->_day = day;
	}
	friend istream& operator>>(istream& cin, Date p);

	//友元配合左移运算符可以实现自定义数据类型的输出
	friend ostream& operator<<(ostream& cout,  Date p);

private:
	int _year;
	int _month;
	int _day;
};
//友元配合右移运算符实现自定义数据类型的输入
istream& operator>>(istream& cin, Date p)
{
	cin >> p._year >> p._month >> p._year;
	return cin;
}
//友元配合左移运算符可以实现自定义数据类型的输出
ostream& operator<<(ostream& cout, Date p)
{
	cout << p._year << "-" << p._month << "-" << p._day;
	return cout;
}
int main()
{
	Date p;
	cin >> p;
	cout << p;
	return 0;
}
```

###### 3.初始化列表

```cpp
class Person
{
public:
	Person(int a, int b) :
		_a(a),
		_b(b)
	{
	

	}
	int _a;
	int _b;

};
```

> 以下三种情况必须使用初始化列表：
>
> 1.const修饰的成员变量
>
> 2.引用变量
>
> 3.自定义类型成员(该类中没有默认构造函数)

> 注意：
>
> 1.每个成员只能进行一次初始化
>
> 2.尽量使用初始化列表，对于自定义类型，一定会先使用初始化列表进行初始化
>
> 3.成员变量的声明次序就是初始化列表的初始化顺序，例：

```cpp
#include<iostream>
using namespace std;
class Person
{
public:
	Person(int a = 1) :
		_a1(a),
		_a2(_a1)
	{

	}
	void Print()
	{
		cout << "_a1=" << _a1 << " " << "_a2=" << _a2 << endl;
	}
	int _a2;
	int _a1;

};
int main()
{
	Person p;
	p.Print();
	return 0;
}
```

> 上面这段代码声明时先声明_a2,再声明__a1,故在初始化列表对它进行初始化时先对 _a2进行初始化，此时 _a1还是随机值，因此此时 _a2被初始化为随机值，之后对 _a1进行初始化， _a1(a)被初始化为1，故打印出来 _a1=1, _a2为随机值，这这里我们推荐声明和初始化列表的顺序一致，防止发生不必要的错误

> C++11中成员变量初始化

```cpp
private:
	int _a = 1;
	int _b = 1;
```

> 如上所示，我们并没有为其写构造函数或者初始化列表，而是在声明是直接进行赋初始值，这里不是进行初始化，而是给成员变量一个缺省值

###### 4.static关键字

> 类的成员函数或者成员变量前面+static我们称为类的静态成员，被static修饰的成员变量称为类的静态成员变量，被static修饰的成员函数称为类的静态成员函数

> 特点：
>
> 1.类的静态成员为类的所有类对象所共享
>
> 2.静态成员必须在类外进行定义，定义时不添加static关键字
>
> 3.类的静态成员可直接用类名：：类的静态成员来访问
>
> 4.类的静态成员函数没有this指针，因此不能访问类的成员变量
>
> 5.类的静态成员和普通成员一样也可以有返回值，访问权限

> 问题：
>
> 1.类的静态成员可以调用非静态成员函数吗？
>
> 不可以，类的静态成员函数那没有隐藏的this指针，不可以调用类的成员函数
>
> 2.非静态成员可以调用类的静态成员吗？
>
> 可以
>

###### 5.友元

> 友元可以使类外的函数或者对象来访问类的私有成员
>
> 关键字：friend
>
> 1.友元函数
>
> 只需要在类里面写friend+函数定义，那么这个函数就能够访问这个类里面的私有成员了

```cpp
//运算符重载配合左移运算符实现自定义数据类型的输出
#include<iostream>
using namespace std;
class Person
{
public:
	//声明该函数为该类的友元，可以自由访问该类中私有成员
	friend ostream& operator<<(ostream &cout, const Person p);
	Person(int a = 0)
	{
		_a = a;
	}
private:
	int _a;
};
ostream& operator<<(ostream &cout, const Person p)
{
	cout << p._a;
	return cout;

}
int main()
{
	Person p;
	cout << p;
	return 0;
}
```

> 2.友元类
>
> 让一个类成为另一个类的友元
>
> 语法：friend class +类名

> 注意：
>
> 1.少用友元，友元会破坏封装性
>
> 2.友元不具有传递性，例如：A是B的友元，B是C的友元，不能说A是C的友元
>
> 3.友元是单向的，不具有传递性

###### 6.内部类

> 如果一个类定义在另一个类的内部，那么这个内部的内就叫做内部类，此时内部类是一个独立的类，它不属于外部类，更不能通过外部类的对象去调用内部类，外部类对内部类没有任何优越的访问权限
>
> 注意：：内部类就是外部类的友元类。注意友元类的定义，内部类可以通过外部类的对象参数来访问外部类中
> 的所有成员。但是外部类不是内部类的友元
>
> 特性：
>
> 1. 内部类可以定义在外部类的public、protected、private都是可以的
> 2. 注意内部类可以直接访问外部类中的static、枚举成员，不需要外部类的对象/类名
> 3. 3sizeof(外部类)=外部类，和内部类没有任何关系

```cpp
#include<iostream>
using namespace std;
class Person
{
public:
	class A
	{
	public:
		int b;
	};
	static int a;

};
int Person::a = 10;
int main()
{
	cout << Person::a << endl;
}
```

### C/C++内存管理

###### 1.内存四区

> 1.栈区：用来存储局部变量，函数的形参
>
> 栈自上向下生长的
>
> 2.堆区：用于存储程序运行时动态开辟的内存，一般由程序员自己动态申请与释放，如果没有释放就会造成内存泄露
>
> 3.静态区：用来存储静态变量，全局变量
>
> 4.代码区(常量区)：用来存储代码段，只读变量

###### 2.C语言动态内存申请：malloc/calloc/realloc三者之间的差别

> malloc/calloc/realloc三者都用来动态申请内存空间
>
> 区别：
>
> malloc：只申请空间
>
> calloc:申请一块空间之后并将其初始化为0
>
> realloc:对原来malloc/realloc申请的内存空间进行扩容，如果原来那块内存空间还有剩余空间，就将剩余空间接到原来空间上，如果原来的空间不够那么就重新找一块空间开辟

###### 3.C++内存管理方式

> C++通过new/delete操作符来实现动态内存的管理

```cpp
//C++动态内存申请
int* p = new int;

//C++在申请内存空间时可以对其进行初始化
int* p = new int(10);//初始化这块申请的内存空间为10
	
//C++对于动态数组的申请
int* arr = new int[10];

//C++在动态申请数组时还可以对齐进行初始化
int* arr = new int[3]{ 1,2,3 };//对新开辟的int类型，大小为3的数组赋值为1，2，3

int* arr = new int[10];
delete[]arr;
```

> C++中new在动态申请一块内存空间之后会调用这个自定义类型的构造函数，对类里面的成员函数进行初始化，在函数结束时候delete会调用这个自定义类的析构函数，实现对对象的清理，而malloc只开辟了这块内存空间，并不会对这块内存空间进行初始化操作，也不会调用析构函数

###### 4.malloc与new的区别

> 1.malloc/free是函数，而new/delete是操作符
>
> 2.new/delete在申请与释放空间是会自动调用其构造函数和析构函数
>
> 3.malloc申请的空间不会进行初始化，而new申请的空间会进行初始化
>
> 3.malloc函数的返回值是void*，在使用时必须进行强制类型转换，new后面直接跟类型，不需要强制类型转换
>
> 4.malloc后面必须注明要申请内存块的大小，new后面只需要跟类型
>
> 5.malloc申请失败返回NULL，而new申请失败不会返回NULL，通常需要利用异常来捕获
>
> 6.在自定义类型中，new申请空间时会自动调用这个自定义对象的构造函数，delete在释放对象时会自动调用析构函数，而malloc只会开辟空间

###### 5.operator new/operator delete

> new和delete是用户用来申请和释放空间的，operator new和operator delete是系统提供的全局函数，new在底层调用operator new全局函数来申请空间，delete在底层调用operator delete函数来释放空间
>
> operator new底层通过malloc来申请内存空间，但是它与malloc又又点不同，malloc内存申请失败后会返回NULL，operator new申请内存失败会抛异常
>
> operator delete底层通过free来实现内存的释放

###### 6.new/delete实现原理

> new的原理:
>
> 1.通过operator new来申请内存空间
>
> 2.在申请空间的同时调用对应的构造函数
>
> delete的原理：
>
> 1.通过operator delete来释放对应的内存空间
>
> 2.在释放空间的同时调用对应的析构函数
>
> new[N]的原理：
>
> 1.通过operator new[]来完成空间的申请，在operator new[]中调用operator new实现对N个对象空间的申请
>
> 2.申请空间是时同时调用N次构造函数
>
> delete[]的原理：
>
> 1.通过operator delete[]来完成空间的释放
>
> 2.释放空间时同时调用N次析构函数

###### 6.内存泄露

> 什么是内存泄漏：内存泄漏指因为疏忽或错误造成程序未能释放已经不再使用的内存的情况。内存泄漏并不是指内存在物理上的消失，而是应用程序分配某段内存后，因为设计错误，失去了对该段内存的控制，因而造成了内存的浪费。内存泄漏的危害：长期运行的程序出现内存泄漏，影响很大，如操作系统、后台服务等等，出现内存泄漏会导致响应越来越慢，最终卡死
>

> 内存泄露的分类：
>
> 1.内存申请了忘记释放
>
> 2.异常安全问题
>
> 3.堆内存泄露
>
> 4.系统资源泄露
>
> 注意：每次申请空间之后一定要记得手动释放这块空间，不然会产生内存泄露

