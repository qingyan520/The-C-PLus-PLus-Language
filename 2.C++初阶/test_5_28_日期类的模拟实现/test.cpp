#include"Date.h"
void test01()
{
	Date d1(2021,5,28);
	Date d2(2021, 4,29);
	//cin >> d1;
	//cout <<(d1==d2)<< endl;
	//cout << d1 << endl;
	cout << (d1-d2)<< endl;
	//cout << true << endl;

}
int main()
{
	test01();
	return 0;
}