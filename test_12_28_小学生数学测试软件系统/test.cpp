//Сѧ����ѧ�������ϵͳ
//1.��ѡ�����ͣ�+��-��*��/
//2.��ѡ��ÿ�δ���ĸ���
//3.���������������������
//4.ÿ��������𰸺�Ӧ�ж϶Դ�������Ӧ������ȷ��
//5.���������������ĸ���
#include<iostream>
#include<time.h>
#include<string.h>
#include<string>
#include<vector>
#include<stack>
#define N 100
using namespace std;



//�˵�����
void menu()
{
	cout<<"\t\t ----------------------------"<<endl;
	cout << "\t\t|        Сѧ����ѧ����ϵͳ  |" << endl;
	cout << "\t\t|            1.�ӷ�����      |"<<endl;
	cout << "\t\t|            2.��������      |"<< endl;;
	cout << "\t\t|            3.�˷�����      |" << endl;
	cout << "\t\t|            4.��������      |" << endl;
	cout << "\t\t|            5.��ϼӼ�����  |" << endl;
	cout << "\t\t|            6.�������      |" << endl;
	cout << "\t\t|            7.��λ���ӷ�    |" << endl;
	cout << "\t\t|            8.��λ������    |" << endl;
	cout << "\t\t|            9.��λ���˷�    |" << endl;
	cout << "\t\t|            10.��λ������   |" << endl;
	cout << "\t\t|            0.�˳�          |" << endl;
	cout << "\t\t ----------------------------" << endl;
}


//�ɼ�ͳ��
void Count_Score(int n, int count)
{
	cout << endl;
	cout << "��" << n << "����Ŀ,�������" << count << "��" << endl;
	cout << "���������ܷ�:" << count << endl;
}


//�ӷ���ϰ
void Addition_Practice()
{
	int n = 0;
	cout << "������Ҫ��ϰ�Ĵ���:" << endl;
	cin >> n;
	int m = n;
	cout << "��ӭ����" << endl << endl;
	int count = 0;
	vector<string>s;
	while (n--)
	{
		string temp;//��¼�������Ŀ
		int x = rand() % N;
		int y = rand() % N;
		int ret = 0;
		printf("%d + %d = \n", x, y);
		cout << "�������:" << endl;
		cin >> ret;
		if (ret == x + y)
		{
			cout << "��ϲ��,�ش���ȷ" << endl;
			count++;
		}
		else
		{
			cout << "������˼���ش������ȷ��Ϊ:" << x + y << endl;
			temp = to_string(x) + " + "+to_string(y);
			s.push_back(temp);
		}
	}

	//�ɼ�ͳ��
	Count_Score(m, count);
	cout << "��������ĿΪ:\n";
	for (int i = 0; i < s.size(); i++)
	{
		cout << s[i] << endl;
	}
	system("pause");
	system("cls");


}

void Subtraction_practice()
{
	int n = 0;
	cout << "������Ҫ��ϰ�Ĵ���:" << endl;
	cin >> n;
	int m = n;
	cout << "��ӭ����" << endl << endl;
	int count = 0;
	vector<string>s;
	while (n--)
	{
		string temp;
		int x = rand() % N;
		int y = rand() % N;
		int ret = 0;
		printf("%d - %d = \n", x, y);
		cout << "�������:" << endl;
		cin >> ret;
		if (ret == x - y)
		{
			cout << "��ϲ��,�ش���ȷ" << endl;
			count++;
		}
		else
		{
			cout << "������˼���ش������ȷ��Ϊ:" << x -y << endl;
			temp = to_string(x) + " - " + to_string(y);
			s.push_back(temp);
		}
	}


	//�ɼ�ͳ��
	Count_Score(m, count);


	cout << "��������ĿΪ:" << endl;
	for (int i = 0; i < s.size(); i++)
	{
		cout << s[i] << endl;
	}
	system("pause");
	system("cls");
}



//�˷�����
void Multiplication_practice()
{
	int n = 0;
	cout << "������Ҫ��ϰ�Ĵ���:" << endl;
	cin >> n;
	int m = n;
	cout << "��ӭ����" << endl << endl;
	int count = 0;
	vector<string>s;
	while (n--)
	{
		string temp;
		int x = rand() % N;
		int y = rand() % N;
		int ret = 0;
		printf("%d * %d = \n", x, y);
		cout << "�������:" << endl;
		cin >> ret;
		if (ret == x * y)
		{
			cout << "��ϲ��,�ش���ȷ" << endl;
			count++;
		}
		else
		{
			cout << "������˼���ش������ȷ��Ϊ:" << x * y << endl;

			temp = to_string(x) + " * " + to_string(y);
			s.push_back(temp);
		}
	}

	//�ɼ�ͳ��
	Count_Score(m, count);
	cout << "��������ĿΪ:\n";

	for (int i = 0; i < s.size(); i++)
	{
		cout << s[i] << endl;
	}
	system("pause");
	system("cls");
}


//������ϰ
void Division_practice()
{
	int n = 0;
	cout << "������Ҫ��ϰ�Ĵ���:" << endl;
	cin >> n;
	int m = n;
	cout << "��ӭ����" << endl << endl;
	int count = 0;
	vector<string>s;
	while (n--)
	{
		string temp;
		int x = rand() % N;
		int y = rand() % N;
		while (y == 0)
		{
			y = rand() % N;
		}
		float ret = 0;
		printf("%d / %d = \n", x, y);
		cout << "�������:" << endl;
		cin >> ret;
		if (abs(((float)ret-(float)x/(float)y))<0.00001)
		{
			cout << "��ϲ��,�ش���ȷ" << endl;
			count++;
		}
		else
		{
			cout << "������˼���ش������ȷ��Ϊ:" << (float)x /(float) y << endl;

			temp = to_string(x) + " / " + to_string(y);
			s.push_back(temp);
		}
	}

	//�ɼ�ͳ��
	Count_Score(m, count);

	//������Ŀ��ӡ
	cout << "��������ĿΪ:\n";
	for (int i = 0; i < s.size(); i++)
	{
		cout << s[i] << endl;
	}

	system("pause");
	system("cls");
}



//5.�������
int priority(char c) {
	switch (c)
	{
	case '+':
		return 1;
	case '-':
		return 1;
	case '*':
		return 2;
	case '/':
		return 2;
	default:
		return 0;
	}
}

template<class T>
string printStack(stack<T> stack) {
	string result = "";
	while (!stack.empty())
	{
		result = stack.top() + result;
		stack.pop();
	}
	return result;
}

string reversePolish(string inputStr) {
	stack<char> polish;
	stack<char> opStack;
	bool lastIsNum = false;
	for (int i = 0; i < inputStr.length(); i++) {
		char curChar = inputStr.at(i);
		//���������
		if (curChar >= '0' && curChar <= '9') {
			if (!lastIsNum)
				polish.push(' ');
			polish.push(curChar);
			lastIsNum = true;
			continue;
		}
		//����Ϊ������
		else if (curChar == '(') {
			opStack.push(curChar);
		}
		else if (!opStack.empty() && curChar == ')') {
			while (opStack.top() != '(')
			{
				polish.push(opStack.top());
				opStack.pop();
			}
			opStack.pop();
		}
		else {
			if (!opStack.empty() && opStack.top() == '(') {
				opStack.push(curChar);
			}
			else {
				if (!opStack.empty() && priority(curChar) > priority(opStack.top())) {
					opStack.push(curChar);
				}
				else {
					while (!opStack.empty())
					{
						if (opStack.top() == '(')
							break;
						if (priority(curChar) <= priority(opStack.top())) {
							polish.push(opStack.top());
							opStack.pop();
						}
						else {
							break;
						}
					}
					opStack.push(curChar);
				}
			}
		}
		lastIsNum = false;
	}

	while (!opStack.empty()) {
		polish.push(opStack.top());
		opStack.pop();
	}
	return printStack(polish);
}

int simpleCalculate(int opA, int opB, char op) {
	switch (op)
	{
	case '+':
		return opB + opA;
	case '-':
		return opB - opA;
	case '*':
		return opB * opA;
	case '/':
		return opB / opA;
	default:
		return 0;
	}
}

//������ʽ��ֵ
int calculate(string polish) {
	stack<int> values;
	bool lastIsNum = false;
	for (int i = 0; i < polish.length(); i++) {
		char c = polish.at(i);
		if (c == ' ') {
			lastIsNum = false;
			continue;
		}
		else if (c >= '0' && c <= '9') {
			if (lastIsNum) {
				int last = values.top();
				values.pop();
				last = last * 10 + (c - '0');
				values.push(last);
			}
			else {
				values.push(c - '0');
				lastIsNum = true;
			}
		}
		else {
			lastIsNum = false;
			int opA = values.top();
			values.pop();
			int opB = values.top();
			values.pop();
			int calResult = simpleCalculate(opA, opB, c);
			values.push(calResult);
		}
	}
	return values.top();
}


void Mixed_practice()
{
	int n = 0;
	cout << "������Ҫ��ϰ�Ĵ���:" << endl;
	cin >> n;
	int m = n;
	cout << "��ӭ����" << endl << endl;
	int count = 0;
	vector<string>s;
	while (n--)
	{
		int x = rand() % N;
		int y = rand() % N;
		int z= rand() % N;
		int a= rand() % N;
		int b = rand() % N;
		while (b == 0)
		{
			b=rand() % N;
		}
		int c= rand() % N;
		string str = "(" + to_string(x) + "+" + to_string(y) + ")" + "*" + to_string(z) + "+" + to_string(a) + "/"+to_string(b)+"+" + to_string(c);

		//����׺���ʽת��Ϊ�沨�����ʽ�������
		//�沨�����ʽ��һ�ֺ�׺���ʽ����ν��׺����ָ���д�ں��档
		//	ƽ��ʹ�õ���ʽ����һ����׺���ʽ����(1 + 2)* (3 + 4) ��
		//	����ʽ���沨�����ʽд��Ϊ((1 2 + ) (3 4 + )*) ��
		//	�沨�����ʽ��Ҫ�����������ŵ㣺
		//	ȥ�����ź���ʽ�����壬��ʽ����д�� 1 2 + 3 4 + *Ҳ�������ݴ���������ȷ�����
		//	�ʺ���ջ�������㣺������������ջ�����������ȡ��ջ���������ֽ��м��㣬�������ѹ��ջ�С�
		string temp = reversePolish(str);
		int ret = 0;
		cout << str << "=" << endl;
		cout << "�������:" << endl;
		cin >> ret;
		if (ret == calculate(temp))
		{
			cout << "��ϲ��,�ش���ȷ" << endl;
			count++;
		}
		else
		{
			cout << "������˼���ش������ȷ��Ϊ:" << x * y << endl;
			s.push_back(str);
		}
	}

	//�ɼ�ͳ��
	Count_Score(m, count);
	cout << "��������ĿΪ:\n";

	for (int i = 0; i < s.size(); i++)
	{
		cout << s[i] << endl;
	}
	system("pause");
	system("cls");
}



void Mixed()
{
	int n = 0;
	cout << "������Ҫ��ϰ�Ĵ���:" << endl;
	cin >> n;
	int m = n;
	cout << "��ӭ����" << endl << endl;
	int count = 0;
	vector<string>s;
	char str[4] = "+-*";
	while (n--)
	{
		string temp;//��¼�������Ŀ
		int x = rand() % N;
		int y = rand() % N;
		int ret = 0;
		int i = rand() % 3;
		printf("%d %c %d = \n", x,str[i] ,y);
		cout << "�������:" << endl;
		cin >> ret;
		int ans = 0;
		if (str[i] == '+')
		{
			ans = x + y;
		}
		else if (str[i] == '-')
		{
			ans = x - y;
		}
		else
		{
			ans = x * y;
		}

		if (ret == ans)
		{
			cout << "��ϲ��,�ش���ȷ" << endl;
			count++;
		}
		else
		{
			cout << "������˼���ش������ȷ��Ϊ:" << ans << endl;
			temp = to_string(x) + str[i] + to_string(y);
			s.push_back(temp);
		}
	}

	//�ɼ�ͳ��
	Count_Score(m, count);
	cout << "��������ĿΪ:\n";
	for (int i = 0; i < s.size(); i++)
	{
		cout << s[i] << endl;
	}
	system("pause");
	system("cls");
}



//��λ���ӷ�
void Multidigit_addition()
{
	int n = 0;
	cout << "������Ҫ��ϰ�Ĵ���:" << endl;
	cin >> n;
	int m = n;
	cout << "��ӭ����" << endl << endl;
	int count = 0;
	vector<string>s;


	//����һ�����������ʾÿ��Ҫ���ĸ���
	//
	while (n--)
	{
		int z = rand() % 5 + 1;//�������[1��5]��������������λ��
		int x = rand() % N;//���������
		string temp;
		temp += to_string(x);
		while (z--)
		{
			int y = rand() % N;
			x += y;
			temp += ("+" + to_string(y));
		}

		cout << temp << "=" << endl;
		cout << "�������:" << endl;
		int ret = 0;
		cin >> ret;
		if (ret == x)
		{
			cout << "��ϲ�����ش���ȷ" << endl;
			count++;
		}
		else
		{
			cout << "������˼���ش������ȷ��Ϊ:" << x << endl;
			s.push_back(temp);
		}

	}

	//�ɼ�ͳ��
	Count_Score(m, count);
	cout << "��������ĿΪ:\n";

	for (int i = 0; i < s.size(); i++)
	{
		cout << s[i] << endl;
	}
	system("pause");
	system("cls");
}


void Multidigit_subtraction()
{
	int n = 0;
	cout << "������Ҫ��ϰ�Ĵ���:" << endl;
	cin >> n;
	int m = n;
	cout << "��ӭ����" << endl << endl;
	int count = 0;
	vector<string>s;


	//����һ�����������ʾÿ��Ҫ���ĸ���
	//
	while (n--)
	{
		int z = rand() % 5 + 1;//�������[1��5]��������������λ��
		int x = rand() % N;//���������
		string temp;
		temp += to_string(x);
		while (z--)
		{
			int y = rand() % N;
			x -= y;
			temp += ("-" + to_string(y));
		}

		cout << temp << "=" << endl;
		cout << "�������:" << endl;
		int ret = 0;
		cin >> ret;
		if (ret == x)
		{
			cout << "��ϲ�����ش���ȷ" << endl;
			count++;
		}
		else
		{
			cout << "������˼���ش������ȷ��Ϊ:" << x << endl;
			s.push_back(temp);
		}

	}

	//�ɼ�ͳ��
	Count_Score(m, count);
	cout << "��������ĿΪ:\n";

	for (int i = 0; i < s.size(); i++)
	{
		cout << s[i] << endl;
	}
	system("pause");
	system("cls");
}

void Multidigit_multiplication()
{
	int n = 0;
	cout << "������Ҫ��ϰ�Ĵ���:" << endl;
	cin >> n;
	int m = n;
	cout << "��ӭ����" << endl << endl;
	int count = 0;
	vector<string>s;


	//����һ�����������ʾÿ��Ҫ���ĸ���
	//
	while (n--)
	{
		int z = rand() % 5 + 1;//�������[1��5]��������������λ��
		int x = rand() % N;//���������
		string temp;
		temp += to_string(x);
		while (z--)
		{
			int y = rand() % N;
			x *= y;
			temp += ("*" + to_string(y));
		}

		cout << temp << "=" << endl;
		cout << "�������:" << endl;
		int ret = 0;
		cin >> ret;
		if (ret == x)
		{
			cout << "��ϲ�����ش���ȷ" << endl;
			count++;
		}
		else
		{
			cout << "������˼���ش������ȷ��Ϊ:" << x << endl;
			s.push_back(temp);
		}

	}

	//�ɼ�ͳ��
	Count_Score(m, count);
	cout << "��������ĿΪ:\n";

	for (int i = 0; i < s.size(); i++)
	{
		cout << s[i] << endl;
	}
	system("pause");
	system("cls");
}


void Multi_digit_division()
{
	int n ;
	cout << "������Ҫ��ϰ�Ĵ���:" << endl;
	cin >> n;
	int m = n;
	cout << "��ӭ����" << endl << endl;
	int count = 0;
	vector<string>s;


	//����һ�����������ʾÿ��Ҫ���ĸ���
	//
	while (n--)
	{
		int z = rand() % 5 + 1;//�������[1��5]��������������λ��
		int x = rand() % N;//���������
		string temp;
		temp += to_string(x);
		double w = (double)x;
		while (z--)
		{
			int y = rand() % N+1;
			w /= (double)y;
			temp += ("/" + to_string(y));
		}

		cout << temp << "=" << endl;
		cout << "�������:" << endl;
		double ret = 0;
		cin >> ret;
		if (abs(ret-w)<0.0000000001)
		{
			cout << "��ϲ�����ش���ȷ" << endl;
			count++;
		}
		else
		{
			cout << "������˼���ش������ȷ��Ϊ:" << w << endl;
			s.push_back(temp);
		}

	}

	//�ɼ�ͳ��
	Count_Score(m, count);
	cout << "��������ĿΪ:\n";

	for (int i = 0; i < s.size(); i++)
	{
		cout << s[i] << endl;
	}
	system("pause");
	system("cls");
}

int main()
{
	string str = "+-*/";
	srand((unsigned int)time(NULL));
	int option ;
	while (1)
	{
		menu();
		cin >> option;
		switch (option)
		{
		case 1:
			//�ӷ���ϰ
			Addition_Practice();
			break;

		case 2:
			//������ϰ
			Subtraction_practice();
			break;

		case 3:

			//�˷���ϰ
			Multiplication_practice();
			break;

		case 4:
			//������ϰ
			Division_practice();
			break;
		case 5:
			//�������
			Mixed_practice();
			break;
		case 6:
			Mixed();
			break;
		case 7:
			//��λ���ӷ�
			Multidigit_addition();
			break;
		case 8:
			//��λ������
			Multidigit_subtraction();
			break;
		case 9:
			//��λ���˷�
			Multidigit_multiplication();
			break;
		case 10:
			//��λ������
			Multi_digit_division();
			break;
		case 0:
			exit(-1);
			break;

		default:
			printf("���������������\n");
			break;

		}
	}


}