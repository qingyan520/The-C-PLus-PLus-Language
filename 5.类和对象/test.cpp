//c++����������:��װ���̳У���̬
//��װ�����壺�����Ժ���Ϊ��Ϊһ������
//�����Ժ���Ϊ����Ȩ�޿���
//#include<iostream>
//using namespace std;
//const double PI = 3.14;
////���һ��Բ�࣬��Բ���ܳ���2*pI*r
////class �����࣬���������
//class Circle
//{
//	//����Ȩ��
//	//����Ȩ��
//public:
//	//���ԣ�
//	int m_r;
//	//��Ϊ
//	//��ȡԲ���ܳ�
//	double calculate()
//	{
//		return 2 * PI * m_r;
//	}
//};
//int main()
//{
//	//ͨ��Բ�� ���������Բ
//	//ʵ������ͨ��һ���࣬���о������Ϊ
//	Circle cl;
//	cl.m_r = 10;
//	cout << "Բ���ܳ�:" << cl.calculate()<<endl;
//	system("pause");
//	return 0;
//}
//�����ϰ
//#include<iostream>
//using namespace std;
//const double PI = 3.14;
////���ȷ�װһ���࣬��Ĺؼ��֣�class
//class Circle
//{
//	//����з���Ȩ�ޣ����ԣ���Ϊ
//	//���÷���Ȩ�ޣ�������
//public:
//	int m_r;//���ԣ�Բ�Ļ�������
//	//��Ϊ��һ��ͨ��������ʵ��
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
//	cout << "Բ���ܳ�Ϊ��" << cl.claute() << endl;
//
//
//	system("pause");
//	return 0;
//}
//���ʵ�������һ��ѧ���࣬������ѧ����������ѧ�ţ����Ը�ѧ����������ѧ�Ÿ�ֵ����ʾѧ����������ѧ��
//#include<iostream>
//#include<string>
//using namespace std;
//class student
//{
//	//���е���Ϊ������ ����ͳ��Ϊ��Ա
//	//���� ��Ա���� ��Ա����
//	//��Ϊ���� ��Ա����
//	//����Ȩ��
//public:
//	//����
//	string name;
//	string i_number;
//	//��Ϊ
//	//��ʾ������ѧ��
//	void show()
//	{
//		cout << name << endl;
//		cout << i_number << endl;
//	}
//	//ͨ����Ϊ��ֵ
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
//	//ʵ����
//	student s1;
//	s1.name = "����";
//	s1.setname("sssw");
//	s1.i_number = "12345";
//	s1.show();
//	student s2;
//	s2.name = "����";
//	s2.i_number = "123456";
//	s2.show();
//	system("pause");
//	return 0;
//}



//��װ������
//���ַ���Ȩ�ޣ�
//����Ȩ��   public        ���ڿ��Է���  ����Ҳ���Է���
//����Ȩ��   protected     ���ڿ��Է���  ���ⲻ���Է���    ���ӿ��Է��ʸ����еı�������
//˽��Ȩ��   private       ���ڿ��Է���  ���ⲻ���Է���    ���Ӳ����Է��ʸ��׵�˽������
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
//		name = "����";
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

//c++��class��struct������
//Ψһ���������ڷ���Ȩ�޲�ͬ��
//structĬ��Ȩ����public
//classĬ��Ȩ����˽��private
//
//��Ա��������Ϊ˽��
//�ŵ�1����Ա��������Ϊ˽�У������Լ����ƶ�дȨ��
//�ŵ�2������дȨ�ޣ����ǿ��Լ�����ݵ���Ч��
//#include<iostream>
//using namespace std;
//class person
//{
//public:
//	//��������
//	void setname(string iname)
//	{
//		name = iname;
//	}
//	//������
//	string getname()
//	{
//		return name;
//	}
//	//��ȡ����
//	//�ĳ�0-100֮��
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
//			cout << "����������" << endl;
//		}
//	}
//	int getage()
//	{
//		age = 10;
//		return age;
//	}
//	//ֻд����
//	void setLover(string iLover)
//	{
//		Lover = iLover;
//		cout << Lover << endl;
//	}
//private:
//	//�������ɶ� ��д
//	string name;
//	//���䣺ֻ��
//	int age;
//	//���ˣ�ֻд
//	string Lover;
//};
//int main()
//{
//	person s;
//	s.setname("����");
//	cout << "��ʾ������" << s.getname() << endl;
//	cout << "��ʾ���䣺" << s.getage() << endl;
//	s.setLover("����");
//	s.setage(100);
//	system("pause");
//	return 0;
//}


//��ư��������������
//������������������
//�ֱ���ȫ�ֺ����ͳ�Ա�����ж������������Ƿ����
//#include<iostream>
//using namespace std;
//class Cube
//{
//public:
//	//���ó�
//	void setL(int l)
//	{
//		m_L = l;
//	 }
//
//	//��ȡ��
//	
//	int getL()
//	{
//		return m_L;
//	}
//	
//	
//	//���ÿ�
//	void setW(int w)
//	{
//		m_W = w;
//	}
//	//��ȡ�� 
//	int getW()
//	{
//		return m_W;
//	}
//	
//	//���ø�
//	void setH(int h)
//	{
//		m_H = h;
//	}
//	
//	//��ȡ�� 
//
//	int getH()
//	{
//		return m_H;
//	}
//	//��ȡ���
//	int v()
//	{
//		return m_L * m_W * m_H;
//	}
//
//	//��ȡ���
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
//	//����
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
//	cout << "c1������ǣ�" << c1.s() << endl;
//	cout << "c1������ǣ�" << c1.v ()<< endl;
//	//�����ڶ���������
//	Cube c2;
//	c2.setL(10);
//	c2.setW(10);
//	c2.setH(11);
//	bool ret = isname(c1, c2);
//	if (ret)
//	{
//		cout << "ȫ�ֺ�����c1,c2���" << endl;
//	}
//	else
//	{
//		cout << "c1,c2�����" << endl;
//	}
//	ret = c1.isnamebyclass(c2);
//	if (ret)
//	{
//		cout << "�ֲ�������c1,c2���" << endl;
//	}
//	else
//	{
//		cout << "c1,c2�����" << endl;
//	}
//	system;("pause");
//	return 0;
//}



//��ϰ����2�����һ��Բ�࣬�жϵ��Բ��λ�ù�ϵ
//�жϵ��Բ��λ�ù�ϵ���ж�Բ�ĵ���ľ�����뾶�Ĺ�ϵ
//#include<iostream>
//using namespace std;
////���ࣺ
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
//	//���ð뾶
//	void setR(int r)
//	{
//		m_r = r;
//	}
//	//��ȡ�뾶
//	int getR()
//	{
//		return m_r;
//	}
//	//����Բ��
//	void setConter(Point Center)
//	{
//		m_Center = Center;
//	}
//	//��ȡԲ��
//	Point getConter()
//	{
//		return m_Center;
//	}
//private:
//	int m_r;
//	//�����п�������һ������Ϊ����ĳ�Ա
//	Point m_Center;//����Բ��
//};
////�жϵ��Բ��λ�ù�ϵ
//void isInCircle(circle& c, Point& p)
//{
//	if (c.getR() * c.getR() == (p.getx() - c.getConter().getx()) * (p.getx() - c.getConter().getx()) + (p.gety() - c.getConter().gety()) * (p.gety() - c.getConter().gety()))
//	{
//		cout << "����Բ��" << endl;
//	}
//	if (c.getR() * c.getR() > (p.getx() - c.getConter().getx()) * (p.getx() - c.getConter().getx()) + (p.gety() - c.getConter().gety()) * (p.gety() - c.getConter().gety()))
//	{
//		cout << "����Բ��" << endl;
//	}
//	if (c.getR() * c.getR() < (p.getx() - c.getConter().getx()) * (p.getx() - c.getConter().getx()) + (p.gety() - c.getConter().gety()) * (p.gety() - c.getConter().gety()))
//	{
//		cout << "����Բ��" << endl;
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


//��ϰ:����һ���࣬����Բ��λ�ù�ϵ
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





//4.2�Զ���ĳ�ʼ��������
//4.2.1���캯������������
//���캯������Ҫ�������ڴ�������ʱΪ����ĳ�Ա����ʼֵ�����캯���ɱ������Զ����ã���ɶ����ʼ����������
//������������Ҫ�������ڶԶ��������ǰϵͳ�Զ����ã�ִ��һЩ������
//���캯���﷨������(){}
//1.���캯��û�з���ֵ��Ҳ�ܲ�дvoid
//2.���캯��������������ͬ
//3.���캯�������в�������˿��Է�������
//4.�����ڵ��ö���ʱ���Զ����ù��죬�����ֶ�����һ��
//
//���������﷨��~����(){}
//1.����������û�з���ֵҲ��дvoid
//2.����������������ͬ��ǰ��Ҫ���Ϸ���~
//3.���������������в�������˲����Է�������
//4.���������ٶ���ǰ���Զ��������������������ֶ����ã�����ֻ�����һ��
//#include<iostream>
//using namespace std;
////1.���캯����û�з���ֵ����дvoid
//class Person
//{
//public:
//	Person()
//	{
//		cout << "Person���캯���ĵ���" << endl;
//	}
//	
//
//	//2.��������  �����������
//	~Person()
//	{
//		cout << "Person������������" << endl;
//	}
//
//
//};
////���캯�������������������У������д�����������ṩһ���յĹ��������
//void test01()
//{
//	Person P;//��ջ�ϵ����ݣ�test01ִ����Ϻ��ͷ��������
//
//}
//int main()
//{
//	//test01();
//	Person P;
//	system("pause");
//	return 0;
//}


//4.2.2���캯���ķ���͵���
//���ֵ��÷�ʽ��
//���������ࣺ�вι�����޲ι���
//�����͹��죺��ͨ����Ϳ�������
//���ֵ��÷�����
//���ŷ�
//��ʾ��
//��ʽת����
//#include<iostream>
//using namespace std;
//class Person
//{
//public:
//	Person()
//	{
//		cout<< "���캯�����޲ι���" <<endl;//Ĭ�ϵ��ú���
//	}
//	Person(int a)
//	{
//		age = a;
//		cout << "���캯�����вι���" << endl;
//	}
//	//�������캯��
//	Person(const Person &p)
//	{
//		//�����������ϵ��������ԣ�������������
//		age = p.age;
//
//		cout << "�������캯���ĵ���" << endl;
//	}
//	~Person()
//	{
//		cout << "���������ĵ���" << endl;
//	}
//	int age;
//};
//void test01()
//{
//	//1.���ŷ�
//	Person p1;//Ĭ�Ϲ��캯������
//	Person p2(10);//�вι��캯��
//	Person p3(p2);//���ÿ������ú���
//	//ע������
//	//1.����Ĭ�Ϲ��캯����ʱ��Ҫ��С����
//	//��Ϊ�������д������������Ϊ�Ǻ����������,������Ϊ�ڴ�������
//	//Person p1();
//	//
//	cout << "p2�����䣺" << p2.age << endl;
//	cout << "p3�����䣺" << p3.age << endl;
//
//	//2.��ʾ��
//	Person p4;//Ĭ�Ϲ���
//	Person p5 = Person(10);//�вι���
//	//Person(10)�������� �ص㣺��ǰ�н���ִ�к�ϵͳ���������յ���������
//	Person p6 = Person(p5);
//	Person(10);
//	cout << "aaa0" << endl;
//	//ע������2
//	//��Ҫ���ÿ������캯����ʼ����������,����������ΪPerson(p5)==Person p5���������ض���
//	//Person(p5);
//
//
//	//3.��ʽת����
//	Person p7 = 10;//�൱��д�� Person p4=Person(10);
//	Person p8 = p7;
//}
//int main()
//{
//	test01();
//	system("pause");
//	return 0;
//}


//4.2.3�������ú����ĵ���ʱ��
//c++�п������캯�����û���ͨ���������������
//1.ʹ��һ���Ѿ�������ϵĶ�������ʼ��һ���¶���
//2.ֵ���ݵķ�ʽ������������ֵ
//3.��ֵ��ʽ���ؾֲ�����
//#include<iostream>
//using namespace std;
//class Person
//{
//public :
//	Person()
//	{
//		cout << "PersonĬ�Ϲ��캯���ĵ���" << endl;
//	}
//	Person(int iage)
//	{
//		cout << "Person�вι��캯���ĵ���" << endl;
//		age = iage;
//	}
//	Person(const Person& P)
//	{
//		cout << "Person�������캯���ĵ���" << endl;
//		age = P.age;
//
//	}
//	~Person()
//	{
//		cout << "Person���������ĵ���" << endl;
//	}
//private:
//	int age;
//
//};
////1.ʹ��һ���Ѿ�������ϵĶ�������ʼ��һ���¶���
//void test01()
//{
//	Person p1(20);
//	Person p2(p1);
//}
////2.ֵ���ݵķ�ʽ������������ֵ
//void dowork(Person P)
//{
//
//}
//void test02()
//{
//	Person p;
//	dowork(p);
//}
////3.��ֵ��ʽ���ؾֲ�����
//Person dowork2()
//{
//	Person p1;
//	return p1;
//}
//void test03()
//{
//	Person p = dowork2();
//}
//int main()
//{
//	//test01();
//	//test02();
//	test03();
//	system("pause");
//	return 0;
//}


//4.2.4���캯���ĵ��ù���
//#include<iostream>
//using namespace std;
////1.����һ���࣬c++�滭��ÿ������������Ĭ�Ϻ�����Ĭ�Ϲ��캯����������������������
//class person
//{
//public:
//	person()
//	{
//		cout << "person Ĭ�Ϲ��캯������" << endl;
//	}
//	person(int age)
//	{
//		cout << "person���вι��캯������" << endl;
//		m_age = age;
//	}
//	person(const person& p)
//	{
//		cout << "person�Ŀ������캯������" << endl;
//		m_age = p.m_age;
//	}
//	~person()
//	{
//		cout << "person�����������ĵ���" << endl;
//	}
//public:
//	int m_age;
//};
//void test01()
//{
//	person p;
//	p.m_age = 18;
//	person p2(p);
//	cout << "p2�����䣺" << p2.m_age << endl;
//
//}
////2.�������д���вι��캯�����������Ͳ��ٻ��ṩĬ�Ϲ��캯����������Ȼ�ṩ�������캯��
////3.�������д�˿������캯�����������Ͳ��ٻ��ṩ�������캯��
//int main()
//{
//	test01();
//	system("pause");
//	return 0;
//}


//4.2.5�����ǳ����
//#include<iostream>
//using namespace std;
//class person
//{
//public:
//	person()
//	{
//		cout << "person Ĭ�Ϲ��캯���ĵ���" << endl;
//	}
//	person(int age,int height)
//	{
//		cout << "person�������вι��캯���ĵ���" << endl;
//		m_age = age;
//		mHeight = new int(height);
//	}
//	
//
//	~person()
//	{
//		//�������ٵ����ݽ����ͷ�
//		cout << "person�����������ĵ���" << endl;
//	}  
//	int m_age;
//	int* mHeight;
//};
//void test01()
//{
//	person p1(18,10);
//	cout << p1.m_age << endl;
//	person p2(p1);
//}
//int main()
//{
//	system("pause");
//	return 0;
//}
//ǳ��������������ڴ��ظ��ͷ�
//����������Խ��


//4.2.6 ��ʼ���б�
//�﷨�����캯������������1��ֵ1��������2��ֵ2��....{}
//#include<iostream>
//using namespace std;
//class person
//{
//public:
//	//person(int a, int b, int c)
//	//{
//	//	m_A = a;
//	//	m_B = b;
//	//	m_C = c;
//	//}
//
//	//��ʼ���б���ʼ������
//	person(int a,int b,int c) :m_A(a), m_B(b), m_C(c)
//	{
//
//	}
//	int m_A;
//	int m_B;
//	int m_C;
//};
//void test01()
//{
//	//person p1(10, 20, 30);
//	person p1(30,20,10);
//	cout << p1.m_A << endl;
//	cout << p1.m_B << endl;
//	cout << p1.m_C << endl;
//}
//int main()
//{
//	test01();
//	system("pause");
//	return 0;
//}


//4.2.7�������Ϊ���Ա
//#include<iostream>
//using namespace std;
//class phone
//{
//public:
//	phone(string name)
//	{
//		p_name = name;
//	}
//	string p_name;
//};
//class person
//{
//public:
//	person(string my_name,string phone_name) :m_name(my_name), m_phone(phone_name)
//	{
//
//	}
//	//����
//	string m_name;
//
//	//�ֻ�
//	phone m_phone;
//};
//void test01()
//{
//	person p("ռɽ", "sdw");
//
//}
//int main()
//{
//	system("pause");
//	return 0;
//}


//4.2.8��̬��Ա
//��̬��Ա��Ϊ���־�̬��Ա�����;�̬��Ա����
//��̬��Ա��������Ա����ǰ��static
//1.����׶γ�ʼ���ڴ�2
//2.���г�Ա����һ������
//3.���ڽ�������������
//4.Ҳ�з���Ȩ��
//#include<iostream>
//using namespace std;
//class A
//{
//public :
//	static int m_a;//������̬��Ա����
//
//private:
//	static int m_b;
//};
//int A::m_a = 10;
//int A::m_b = 10;
////��̬��Ա�����ķ���
//void test01()
//{
//	//1.ͨ��������з���
//	A c;
//	cout << c.m_a << endl;
//	c.m_a = 100;
//	//���ݽ��й���
//	cout << c.m_a << endl;
//	A p;
//	cout << p.m_a << endl;
//	//2.�����������з���
//	cout <<  A::m_a << endl;
//	//˽�ж��󲻿��Է���
//	//cout << A::m_b << endl;
//}
//int main()
//{
//	test01();
//	system("pause");
//	return 0;
//}

//��̬��Ա����������ǰ��static
//1.���ж��󹲷���һ������
//2.��̬����ֻ�ܷ��ʾ�̬��Ա����
//#include<iostream>
//using namespace std;
//class person
//{
//public:
//	static void func()
//	{
//		cout << "��������" << endl;
//	}
//};
//void test01()
//{
//	//1.ͨ������
//	person p;
//	p.func();
//	//2.ͨ������
//	person::func;
//}
//int main()
//{
//	test01();
//	system("pause");
//	return 0;
//}