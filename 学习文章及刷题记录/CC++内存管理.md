# C/C++内存管理

### 1.内存四区

1.栈区：用来存储局部变量，函数的形参

栈自上向下生长的

2.堆区：用于存储程序运行时动态开辟的内存，一般由程序员自己动态申请与释放，如果没有释放就会造成内存泄露

3.静态区：用来存储静态变量，全局变量

4.代码区(常量区)：用来存储代码段，只读变量

### 2.C语言中内存管理的方式

C语言中通过malloc/calloc/realloc动态申请内存空间，而用free来释放这块内存，这里我们不在对malloc/calloc/realloc展开详细的讲解，感兴趣的可以去看看我前面的文章，这里我们就简单复习一下malloc/calloc/realloc的区别

相同点：

malloc/calloc/realloc三者都用来动态申请内存空间

区别：

malloc：只申请空间

calloc:申请一块空间之后并将其初始化为0

realloc:对原来malloc/realloc申请的内存空间进行扩容，如果原来那块内存空间还有剩余空间，就将剩余空间接到原来空间上，如果原来的空间不够那么就重新找一块空间开辟

### 3.C++动态内存管理的方法

C语言中通过malloc/calloc/realloc动态申请内存空间，而用free来释放这块内存，C++利用new来动态申请空间，delete来释放空间

相较于C语言中的malloc/calloc/realloc/free,C++中的new/delete闲的更加方便

```cpp
//C语言动态申请空间
int* p = (int*)malloc(sizeof(int));
//C++动态内存申请
int* p = new int;
//C++在申请内存空间时可以对其进行初始化
int* p = new int(10);//初始化这块申请的内存空间为10
```

在C语言中我们要进行强制类型转化，还要写要申请的内存空间的大小，而C++new后面跟的是数据类型，显得跟加方便

C语言和C++中对于动态数组的申请

	//C语言对于动态数组的申请
	int* arr = (int*)malloc(sizeof(int) * 10);


​	
​	//C++对于动态数组的申请
​	int* arr = new int[10];


​	
​	//C++在动态申请数组时还可以对齐进行初始化
​	int* arr = new int[3]{ 1,2,3 };//对新开辟的int类型，大小为3的数组赋值为1，2，3

需要注意的是，上面我们申请了内存空间，在程序结束时一定要记得手动释放这块内存空间，不然会产生内存泄漏

```cpp
int* p = (int*)malloc(sizeof(int));
free(p);

int* p = new int;
delete p;

int* arr = (int*)malloc(sizeof(int) * 4);
free(arr);

int* arr = new int[10];
delete[]arr;
//用new动态申请数组，释放时要写delete[]数组名，不然程序在运行时会奔溃
```

上面是对内置数据类型的申请，在对内置数据类型去的申请与释放上，new/delete与malloc/free的功能是一致的，但是在自定义数据类型的申请上二者还是具有一些差距的，例如·：

```cpp
#include<iostream>
using namespace std;
class A
{
public:
	A(int a=10, int b=11)
	{
		_a = a;
		_b = b;
	}
private:
	int _a;
	int _b;
};
int main()
{
	//C语言方式对自定义类型进行动态开辟
	A* p1 = (A*)malloc(sizeof(A));
	//C++方式对自定义类型进行动态分配
	A* p2 = new A;
    free(p1);
    delete p2;
	return 0;
}
```

![image-20210602211213882](https://raw.githubusercontent.com/qingyan520/Cloud_img/master/img/image-20210602211213882.png)

![image-20210602211311613](https://raw.githubusercontent.com/qingyan520/Cloud_img/master/img/image-20210602211311613.png)

如上所示，在自定义类型中，C++中new在动态申请一块内存空间之后会调用这个自定义类型的构造函数，对类里面的成员函数进行初始化，在函数结束时候delete会调用这个自定义类的析构函数，实现对对象的清理，而malloc只开辟了这块内存空间，并不会对这块内存空间进行初始化操作，也不会调用析构函数

在C++中更加推荐用new，这对于自定义类型来说非常友好

malloc/free与new/delete的区别：

1.malloc/free是函数，而new/delete是操作符

2.new/delete在申请与释放空间是会自动调用其构造函数和析构函数

3.malloc申请的空间不会进行初始化，而new申请的空间会进行初始化

3.malloc函数的返回值是void*，在使用时必须进行强制类型转换，new后面直接跟类型，不需要强制类型转换

4.malloc后面必须注明要申请内存块的大小，new后面只需要跟类型

5.malloc申请失败返回NULL，而new申请失败不会返回NULL，通常需要利用异常来捕获

6.在自定义类型中，new申请空间时会自动调用这个自定义对象的构造函数，delete在释放对象时会自动调用析构函数，而malloc只会开辟空间

### 4.operator new 和operator delete

new和delete是用户用来申请和释放空间的，operator new和operator delete是系统提供的全局函数，new在底层调用operator new全局函数来申请空间，delete在底层调用operator delete函数来释放空间

operator new底层通过malloc来申请内存空间，但是它与malloc又又点不同，malloc内存申请失败后会返回NULL，operator new申请内存失败会抛异常

operator delete底层通过free来实现内存的释放

### 5.new的delete的实现原理

##### 1.内置类型

对于内置类型的申请new/delete与malloc/delete基本上是一致的，不同：new/delete申请的是单块的空间，而new[]/delete[]申请与释放的是连续的空间，而new在申请失败时会抛异常，malloc在申请失败时会返回NULL

##### 2.自定义类型

###### new的原理:

1.通过operator new来申请内存空间

2.在申请空间的同时调用对应的构造函数

###### delete的原理：

1.通过operator delete来释放对应的内存空间

2.在释放空间的同时调用对应的析构函数

###### new[N]的原理：

1.通过operator new[]来完成空间的申请，在operator new[]中调用operator new实现对N个对象空间的申请

2.申请空间是时同时调用N次构造函数

###### delete[]的原理：

1.通过operator delete[]来完成空间的释放

2.释放空间时同时调用N次析构函数

### 6.内存泄露

什么是内存泄漏：内存泄漏指因为疏忽或错误造成程序未能释放已经不再使用的内存的情况。内存泄漏并不是指内存在物理上的消失，而是应用程序分配某段内存后，因为设计错误，失去了对该段内存的控制，因而造成了内存的浪费。内存泄漏的危害：长期运行的程序出现内存泄漏，影响很大，如操作系统、后台服务等等，出现内存泄漏会导致响应越来越慢，最终卡死

内存泄露的分类：

1.内存申请了忘记释放

2.异常安全问题

3.堆内存泄露

4.系统资源泄露

注意：每次申请空间之后一定要记得手动释放这块空间，不然会产生内存泄露

