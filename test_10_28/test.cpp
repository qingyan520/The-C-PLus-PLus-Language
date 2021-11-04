#include<iostream>
using namespace std;
class Coordinate
{
	friend ostream& operator<<(ostream& cout, const Coordinate& coor);
	//friend Coordinate operator+(const Coordinate& c1, const Coordinate& c2);
public:
	Coordinate(int x=0,int y=0):
		m_iX(x),
		m_iY(y)
	{

	}

	int getX()const 
	{
		return this->m_iX;
	}

	//
	Coordinate operator +(const Coordinate& c)
	{
		Coordinate temp;
		temp.m_iX = c.m_iX + this->m_iX;
		temp.m_iY = c.m_iY + this->m_iY;
		return temp;
	}

	int getY()const
	{
		return this->m_iY;
	}
private:
	int m_iX; 
	int m_iY;
};

ostream& operator<<(ostream& cout, const Coordinate& coor)
{
	cout << "X:" << coor.getX() << " Y:" << coor.getY() << endl;
	return cout;
}

//全局函数实现+运算符重载
//Coordinate operator+(const Coordinate& c1, const Coordinate& c2)
//{
//	Coordinate temp;
//	temp.m_iX = c1.m_iX + c2.m_iX;
//	temp.m_iY = c1.m_iY + c2.m_iY;
//	return temp;
//}

int main()
{
	Coordinate s(1, 1);
	cout << s;
	Coordinate s2(1, 2);
	cout << s2;
	Coordinate s3;
	s3 = s + s2;
	cout << s3;
	return 0;
}