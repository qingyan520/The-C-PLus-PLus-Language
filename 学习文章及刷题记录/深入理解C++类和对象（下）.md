



# 深入理解C++类和对象（下）

[TOC]

### 1.const修饰的成员函数

类中的成员函数后加const称为const修饰的成员函数，在被const修饰后，类中的成员变量不可以被改变

被const修饰后，表面上修饰的是成员函数，实际上修饰的是成员函数默认参数的this指针，表示this指针指向的值不可以被修改

```c++
class Person
{
public:
	Person(int a, int b)
	{
		_a = a;
		_b = b;
	}
	void Modify()
	{
		_a = 100;
		_b = 200;
	}
	int _a;
	int _b;
};
```

上述代码我们在构造函数中进行初始化，然后又定义了一个函数去修改这个this指针指向的值，在不加const的情况下是可以的

![image-20210601111235214](C:\Users\史金伟\AppData\Roaming\Typora\typora-user-images\image-20210601111235214.png)

当加上const之后const修饰函数体中的this指针，使this指针指向的值不可以被改变，故会报错

```c++
class Person
{
public:
	Person(int a, int b)
	{
		_a = a;
		_b = b;
	}
	void Modify() const
	{
		_a = 100;
		_b = 200;
	}
	int _a;
	int _b;
};
```

运行截图如下：

![image-20210601111534650](C:\Users\史金伟\AppData\Roaming\Typora\typora-user-images\image-20210601111534650.png)

### 2.初始化列表

1.构造函数体赋值

如下所示：

```c++
class Person
{
public:
	Person(int a, int b)
	{
		_a = a;
		_b = b;
	}
	int _a;
	int _b;
};
```

通过在构造函数中对成员对象进行赋值叫做函数体赋值，但这种赋值方式只能叫做初赋值，不能叫做初始化，因为初始化只能进行一次，而初赋值可以进行多次，对成员函数进行初始化就要用到初始化列表，下面我们来看一下初始化列表

2.初始化列表

语法：类名（）：_a(a),_(b){}

例如：

```c++
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

上面就是最简单的初始化列表，它的实际效果看起来和构造函数在函数体内赋值没有什么区别，但是在下面这三种场景下就必须使用初始化列表而不能使用构造函数函数体进行赋值：

1.const修饰的成员变量

2.引用变量

3.自定义类型成员(该类中没有默认构造函数)

例如：

```
//1.const修饰的成员变量
class Person
{
public:
	Person(int i)
	{
		_i = i;
	}
	const int _i;
};
```

![image-20210601113551935](C:\Users\史金伟\AppData\Roaming\Typora\typora-user-images\image-20210601113551935.png)

```c++
//2.引用变量在类的成员函数中

class Person
{
public:
	Person(int i)
	{
		_i = i;
	}
		

	int& _i;

};

```

```c++
//3.自定义类型（没有默认构造函数）
class A
{
public:
	A(int a)
	{
		_a = a;
	}
	int _a;
};
class Person
{
public:
	Person(int a=10)
	{
		_a=10;
	}
		

	A _a;

};
```

![image-20210601143352480](C:\Users\史金伟\AppData\Roaming\Typora\typora-user-images\image-20210601143352480.png)

上述三种类型在定义时必须进行初始化，因此必须使用初始化列表

```c++
class A
{
public:
	A(int a)
	{
		_a = a;
	}
	int _a;
};
class Person
{
public:
	Person(int i=10,int p=10):
		_a(10),
		_i(i),
		_p(p)
	{
		

	}
		
	A _a;
	const int _i;
	int& _p;

};
```

![image-20210601144127217](C:\Users\史金伟\AppData\Roaming\Typora\typora-user-images\image-20210601144127217.png)

注意：

1.每个成员只能进行一次初始化

2.尽量使用初始化列表，对于自定义类型，一定会先使用初始化列表进行初始化

3.成员变量的声明次序就是初始化列表的初始化顺序，例：

```c++
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



![image-20210601145142927](C:\Users\史金伟\AppData\Roaming\Typora\typora-user-images\image-20210601145142927.png)

上面这段代码声明时先声明_a2,再声明__a1,故在初始化列表对它进行初始化时先对 _a2进行初始化，此时 _a1还是随机值，因此此时 _a2被初始化为随机值，之后对 _a1进行初始化， _a1(a)被初始化为1，故打印出来 _a1=1, _a2为随机值，这这里我们推荐声明和初始化列表的顺序一致，防止发生不必要的错误

3.C++11中成员变量初始化

```c++
//c++11中成员变量的初始化
#include<iostream>
using namespace std;
class Person
{
public:

	void Print()
	{
		cout << "_a=" << _a << endl;
		cout << "_b=" << _b << endl;
	
	}

private:
	int _a = 1;
	int _b = 1;

};
int main()
{
	Person p;
	p.Print();
	return 0;
}
```

![image-20210602142014450](C:\Users\史金伟\AppData\Roaming\Typora\typora-user-images\image-20210602142014450.png)



如上所示，我们并没有为其写构造函数或者初始化列表，而是在声明是直接进行赋初始值，这里不是进行初始化，而是给成员变量一个缺省值

### 3.static关键字

类的成员函数或者成员变量前面+static我们称为类的静态成员，被static修饰的成员变量称为类的静态成员变量，被static修饰的成员函数称为类的静态成员函数

![image-20210602142801394](C:\Users\史金伟\AppData\Roaming\Typora\typora-user-images\image-20210602142801394.png)

特点：

1.类的静态成员为类的所有类对象所共享

2.静态成员必须在类外进行定义，定义时不添加static关键字

3.类的静态成员可直接用类名：：类的静态成员来访问

4.类的静态成员函数没有this指针，因此不能访问类的成员变量

5.类的静态成员和普通成员一样也可以有返回值，访问权限

问题：

1.类的静态成员可以调用非静态成员函数吗？

不可以，类的静态成员函数那没有隐藏的this指针，不可以调用类的成员函数

2.非静态成员可以调用类的静态成员吗？

可以



### 4.友元

友元可以使类外的函数或者对象来访问类的私有成员

关键字：friend

1.友元函数

只需要在类里面写friend+函数定义，那么这个函数就能够访问这个类里面的私有成员了

例如：通过友元函数配合运算符重载实现自定义类型的打印

```
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

![image-20210601151645177](C:\Users\史金伟\AppData\Roaming\Typora\typora-user-images\image-20210601151645177.png)

2.友元类

让一个类成为另一个类的友元

语法：friend class +类名

```
class A
{
	friend class Person;
	A(int a)
	{
		_a = a;
	}
private:
	int _a;

};
class Person
{
public:

	Person(int a = 0)
	{
		_a = a;
	
	}

private:
	int _a;
	A a;
};
```

让Person类成为A的友元，那么Person类中的变量就可以访问A中的私有成员了

注意：

1.少用友元，友元会破坏封装性

2.友元不具有传递性，例如：A是B的友元，B是C的友元，不能说A是C的友元

3.友元是单向的，不具有传递性

### 5.内部类

如果一个类定义在另一个类的内部，那么这个内部的内就叫做内部类，此时内部类是一个独立的类，它不属于外部类，更不能通过外部类的对象去调用内部类，外部类对内部类没有任何优越的访问权限

注意：：内部类就是外部类的友元类。注意友元类的定义，内部类可以通过外部类的对象参数来访问外部类中
的所有成员。但是外部类不是内部类的友元

特性：

1. 内部类可以定义在外部类的public、protected、private都是可以的
2. 注意内部类可以直接访问外部类中的static、枚举成员，不需要外部类的对象/类名
3. 3sizeof(外部类)=外部类，和内部类没有任何关系

例如：

```
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

