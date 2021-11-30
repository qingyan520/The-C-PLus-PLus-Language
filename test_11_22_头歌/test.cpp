////#include <string>
////#include <iostream>
////
////using namespace std;
////
/////********* Begin *********/
////class Wolf
////{
////    //狼类成员的声明
////public:
////    void PrintState();
////
////public:
////    string Name;
////    int Shape;
////
////
////};
//////狼类成员的定义
////void Wolf::PrintState()
////{
////    cout << "姓名：" << this->Name << "爪子锋利程度：" << this->Shape << endl;
////}
////
////
////
////class Human
////{
////    //人类成员的声明
////public:
////    string Name;
////    int Intell;
////    void PrintState();
////
////
////};
//////人类成员的定义
////void Human::PrintState()
////{
////    cout << "姓名：" << this->Name << "智力：" << this->Intell << endl;
////}
////
////
////// 记得在这里写上要继承的类
////class Werewolf : public Human,Wolf
////{
////    //狼人类成员的声明
////public:
////    void SetName(string name);
////    void SetState(int Shape, int intell);
////    void PrintAllState();
////
////
////};
//////狼人类成员的定义
////void Werewolf::SetName(string name)
////{
////    
////    this->Wolf::Name = name;
////    this->Human::Name = name;
////}
////
////void Werewolf::SetState(int Shape, int intell)
////{
////    this->Wolf::Shape = Shape;
////    this->Intell = intell;
////
////}
////
////void Werewolf::PrintAllState()
////{
////    Wolf::PrintState();
////    Human::PrintState();
////}
//
///********* End *********/
//#include <iostream>
//#include "List.h"
//#include "ArrayList.h"
//#include "LinkedList.h"
//using namespace std;
//int A[1000];
//int main() {
//    //所有调用都通过基类的指针实现
//    //如无特殊要求，绝不定义派生类类型的变量
//    List* p = new ArrayList;
//    int n;
//    cin >> n;
//    for (int i = 0; i < n; ++i) {
//        cin >> A[i];
//        p->insert(p->getSize(), A[i]);
//    }
//    p->disp(cout);
//    for (int i = 0; i < 3 && p->getSize() != 0; ++i) {
//        p->remove(0);
//    }
//    p->disp(cout);
//    for (int i = 0; i < p->getSize(); i += 2) {
//        p->modify(i, p->at(i) * 10);
//    }
//    p->disp(cout);
//    delete p;
//    p = new LinkedList;
//    for (int i = 0; i < n; ++i) {
//        p->insert(p->getSize(), A[i]);
//    }
//    p->disp(cout);
//    for (int i = 0; i < 3; && p->getSize() != 0; ++i) {
//        p->remove(0);
//    }
//    p->disp();
//    for (int i = 0; i < p->getSize(); i += 2) {
//        p->modify(i, p->at(i) * 10);
//    }
//    p->disp(cout);
//    delete p;
//    return 0;
//}


#include<iostream>
using namespace std;
class A
{
	double a = 3.14;
	char s = 'a';
};
int main()
{
	A a;
	cout << &a << endl;
	printf("%c", a);
}