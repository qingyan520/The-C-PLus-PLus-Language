//#include <iostream>
//using namespace std;
//
///********* Begin *********/
//class Complex
//{
//    // friend ostream& operator<<(ostream& cout,const Complex& c);
//     //�����������
//public:
//    Complex(float _r = 0, float _i = 0) :
//        r(_r),
//        i(_i)
//
//    {
//
//    }
//
//    Complex(const Complex& c):
//        r(c.r)
//        ,i(c.i)
//    {
//
//    }
//
//    void Print();
//
//    Complex operator+ (const Complex& c);
//
//    Complex operator-(const Complex& c);
//
//    Complex operator *(const Complex& c);
//
//private:
//    float r;
//    float i;
//
//
//};
////������Ķ���
//Complex Complex::operator+(const Complex& c)
//{
//    Complex temp;
//    temp.i = this->i + c.i;
//    temp.r = this->r + c.r;
//    return temp;
//}
//
//Complex Complex::operator-(const Complex& c)
//{
//    Complex temp;
//    temp.i = this->i -c.i;
//    temp.r = this->r - c.r;
//    return temp;
//}
//
//Complex Complex::operator*(const Complex& c)
//{
//    Complex temp;
//    temp.r = this->r * c.r - this->i * c.i;
//    temp.i = this->r * c.i + c.r * this->i;
//    return temp;
//}
//
//void Complex::Print()
//{
//    if (this->i >= 0)
//    {
//        cout << this->r << "+" << this->i << "i" << endl;
//    }
//    else
//    {
//        cout << this->r  << this->i << "i" << endl;
//    }
//}
///********* End *********/
//int main()
//{
//    Complex c1(1, 1);
//    Complex c2(2, 2);
//    Complex c3;
//    c3 = c1 * c2;
//    c3.Print();
//    c1.Print();
//}
//
//#include <iostream>
//#include <string>
//using namespace std;
//
///********* Begin *********/
//// ǰ������ Teacher ��
//class Teacher;
//
//class Student
//{
//    friend Teacher;
//public:
//    //ѧ���������
//    Student(int _num, string _name, string _sex) :
//        number(_num),
//        name(_name),
//        sex(_sex)
//    {
//
//    }
//    void Print();
//
//private:
//    int number;
//    string name;
//    string sex;
//};
////ѧ����Ķ���
//void Student::Print()
//{
//    cout << "ѧ����" << this->name << "����ţ�" << this->number << "���Ա�" << this->sex << endl;
//
//}
//
//
//
//class Teacher
//{
//    //��ʦ�������
//public:
//    Teacher(const Student& s)
//    {
//        number = s.number;
//        name = s.name;
//        sex = s.sex;
//    }
//    void Print();
//
//private:
//    int number;
//    string name;
//    string sex;
//
//};
////��ʦ��Ķ���
//
//void Teacher::Print()
//{
//    cout << "��ʦ��" << this->name << "����ţ�" << this->number << "���Ա�" << this->sex << endl;
//}
//
///********* End *********/


#include <iostream>
#include <string>
#include<vector>
using namespace std;

/********* Begin *********/
class Matrix
{
    friend  Matrix operator+(Matrix& m1, Matrix& m2);
    friend  Matrix operator-(Matrix& m1, Matrix& m2);
    friend  Matrix operator*(Matrix& m1, Matrix& m2);
    //�����������
public:
    Matrix(const int &r,const int &c):
        _r(r),
        _c(c)
    {
        
        arr.resize(r);
        for (int i = 0; i < r; i++)
        {
            arr[i].resize(c);
        }
    }

    void Fill(int value);
    void Set(int r, int c, int value);
    int Get(int r, int c);
    void Print();
private:
    vector<vector<int>>arr;
    int _r;
    int _c;


};
//������Ķ���
void Matrix::Fill(int value)
{
    for (int i = 0; i < arr.size(); i++)
    {
        for (int j = 0; j < arr[i].size(); j++)
        {
            arr[i][j] = value;
        }
    }
}

void Matrix::Set(int r, int c, int value)
{
    arr[r][c] = value;
}

int Matrix::Get(int r, int c)
{
    return arr[r][c];
}

void Matrix::Print()
{
    for (int i = 0; i < arr.size(); i++)
    {
        for (int j = 0; j < arr[i].size(); j++)
        {
            cout << arr[i][j] << "_";
        }
        cout << endl;
    }
}


Matrix operator+(Matrix& m1, Matrix& m2)
{
    //ʵ�־���ӷ�
    Matrix temp(m1._r,m1._c);
    for (int i = 0; i < m1._r; i++)
    {
        for (int j = 0; j < m1._c; j++)
        {
            temp.arr[i][j] = m1.arr[i][j] + m2.arr[i][j];
        }
    }
    return temp;




}

Matrix operator-(Matrix& m1, Matrix& m2)
{
    //ʵ�־������
    Matrix temp(m1._r, m1._c);
    for (int i = 0; i < m1._r; i++)
    {
        for (int j = 0; j < m1._c; j++)
        {
            temp.arr[i][j] = m1.arr[i][j] - m2.arr[i][j];
        }
    }
    return temp;


}

Matrix operator*(Matrix& m1, Matrix& m2)
{
    //ʵ�־���˷�

    Matrix temp(m1._r, m2._c);
    for (int i = 0; i < m1._r; i++)
    {
        for (int j = 0; j < m1._r; j++)
        {
            int sum = 0;
            for (int m = 0; m< m1._c; m++)
            {
                sum += m1.arr[i][m] * m2.arr[m][j];
            }
            temp.arr[i][j] = sum;
        }
    }
    return temp;

}