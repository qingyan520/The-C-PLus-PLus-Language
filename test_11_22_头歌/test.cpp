////#include <string>
////#include <iostream>
////
////using namespace std;
////
/////********* Begin *********/
////class Wolf
////{
////    //�����Ա������
////public:
////    void PrintState();
////
////public:
////    string Name;
////    int Shape;
////
////
////};
//////�����Ա�Ķ���
////void Wolf::PrintState()
////{
////    cout << "������" << this->Name << "צ�ӷ����̶ȣ�" << this->Shape << endl;
////}
////
////
////
////class Human
////{
////    //�����Ա������
////public:
////    string Name;
////    int Intell;
////    void PrintState();
////
////
////};
//////�����Ա�Ķ���
////void Human::PrintState()
////{
////    cout << "������" << this->Name << "������" << this->Intell << endl;
////}
////
////
////// �ǵ�������д��Ҫ�̳е���
////class Werewolf : public Human,Wolf
////{
////    //�������Ա������
////public:
////    void SetName(string name);
////    void SetState(int Shape, int intell);
////    void PrintAllState();
////
////
////};
//////�������Ա�Ķ���
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
//    //���е��ö�ͨ�������ָ��ʵ��
//    //��������Ҫ�󣬾����������������͵ı���
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