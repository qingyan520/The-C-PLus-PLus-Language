//#include<iostream>
//using namespace std;
//class A
//{
//public:
//	virtual inline void Print()
//	{
//		cout << "Hello A_Print" << endl;
//	}
//};
//class B :public A
//{
//	void Print()
//	{
//		cout << "Hello B_Print" << endl;
//	}
//};
//int main()
//{
//	A* p = new B;
//	p->Print();
//	A* q = new A;
//	q->Print();
//	return 0;
//}


//1.基于函数重载，写四种具有相同的名称不同的功能的函数MAX（），分别可以带两个int参数，两个char参数，
//两个float参数，以及两个double参数，并得到他们的最大值。最后，在主程序里面测试它们。
//#include<iostream>
//using namespace std;
//char MAX(char a, char b)
//{
//	return a>b? a : b;
//}
//int MAX(int a, int b)
//{
//	return a > b ? a : b;
//}
//float MAX(float a, float b)
//{
//	return a > b ? a : b;
//}
//double MAX(double a, double b)
//{
//	return a > b ? a : b;
//}
//
//int main()
//{
//	char a, b;
//	int c, d;
//	float e, f;
//	double g, h;
//	cin >> a >> b;
//	cin >> c >> d;
//	cin >> e >> f;
//	cin >> g >> h;
//	cout << MAX(a, b) << endl;
//	cout << MAX(c, d) << endl;
//	cout << MAX(e, f) << endl;
//	cout << MAX(g, h) << endl;
//	return 0;
//}
//
//
//#include<iostream>
//#include<string.h>
//using namespace std;
//void display(const string &str = "hello")
//{
//	cout << str << endl;
//}
//int main()
//{
//	string s;
//	cin >> s;
//	display(s);
//	display();
//}


//#include<iostream>
//using namespace std;
//const float pi = 3.14;
//float Area(float r, float a = 360)
//{
//	return  pi * r * r * (a / 360.0);
//}
//int main()
//{
//	float r;
//	float a;
//	cin >> r;
//	cin >> a;
//	cout << Area(r,a) << endl;
//}


//#include<iostream>
//using namespace std;
//class Rectangle
//{
//public:
//	void Init(const float &Widht, const float &Height)
//	{
//		this->Width = Widht;
//		this->Height=Height;
//	}
//
//	void SetWidet(const float& Width)
//	{
//		this->Width = Width;
//	}
//
//	void SetHeight(const float& Height)
//	{
//		this->Height = Height;
//	}
//
//	float GetWidth()const
//	{
//		return this->Width;
//	}
//
//	float GetHeight()const
//	{
//		return this->Width;
//	}
//
//	float Area()const
//	{
//		return this->Width * this->Height;
//	}
//
//	void DispInfo()
//	{
//		cout << "Width:" << this->Width << " Height:" << this->Height << " Area:" << this->Area() << endl;
//	}
//
//private:
//	float Width;
//	float Height;
//};
//int main()
//{
//	float w = 1;
//	float h = 2;
//	Rectangle r;
//	r.Init(1, 2);
//	r.DispInfo();
//	return 0;
//}


//#include<iostream>
//using namespace std;
//class Circle
//{
//public:
//	Circle(float r = 0):
//		_r(r)
//	{
//
//	}
//
//	float Area()const
//	{
//		return 3.14 * _r * _r;
//	}
//
//	float L()const
//	{
//		return 3.14 * 2 * _r;
//	}
//private:
//	float _r;
//};
//int main()
//{
//	float r;
//	cin >> r;
//	Circle c(r);
//	cout << "面积：" << c.Area() << endl;
//	cout << "周长：" << c.L() << endl;
//	return 0;
//}


//#include<iostream>
//using namespace std;
//class Rectangle
//{
//public:
//	Rectangle(float _Width = 0, float _Height=0)
//	{
//		if (_Height==0)
//		{
//			this->Width = _Width;
//			this->Height = _Width;
//		}
//		else
//		{
//			this->Width = _Width;
//			this->Height = _Height;
//		}
//	}
//
//	float Area()const
//	{
//		return Width * Height;
//	}
//
//	void Print()const
//	{
//		cout << "Width:" << this->Width << "  Height:" << this->Height << "  Area:" << this->Area() << endl;
//	}
//
//private:
//	float Width;
//	float Height;
//};
//int main()
//{
//	Rectangle r(1);
//	r.Print();
//	Rectangle c(1, 2);
//	c.Print();
//	return 0;
//}


//#include<iostream>
//#include<vector>
//using namespace std;
//class Martix
//{
//
//};
//int main()
//{
//
//}

#include<iostream>
using namespace std;
class A
{
public:
	void Print()
	{
		cout << "A_Print()" << endl;
	}
};
class B :public A
{
public:
	int  Print()
	{
		cout << "B_Print()" << endl;
		return 1;
	}
};
int main()
{
	B b;
	b.Print();
	return 0;
}