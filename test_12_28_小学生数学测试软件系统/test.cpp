//小学生数学测试软件系统
//1.可选择题型：+，-，*，/
//2.可选择每次答题的个数
//3.随机生成两个数进行运算
//4.每次在输入答案后应判断对错，若错误应输入正确答案
//5.最后给出作对题数的个数
#include<iostream>
#include<time.h>
#include<string.h>
#include<string>
#include<vector>
#include<stack>
#define N 100
using namespace std;



//菜单功能
void menu()
{
	cout<<"\t\t ----------------------------"<<endl;
	cout << "\t\t|        小学生数学测试系统  |" << endl;
	cout << "\t\t|            1.加法计算      |"<<endl;
	cout << "\t\t|            2.减法计算      |"<< endl;;
	cout << "\t\t|            3.乘法计算      |" << endl;
	cout << "\t\t|            4.除法计算      |" << endl;
	cout << "\t\t|            5.混合加减计算  |" << endl;
	cout << "\t\t|            6.混合运算      |" << endl;
	cout << "\t\t|            7.多位数加法    |" << endl;
	cout << "\t\t|            8.多位数减法    |" << endl;
	cout << "\t\t|            9.多位数乘法    |" << endl;
	cout << "\t\t|            10.多位数除法   |" << endl;
	cout << "\t\t|            0.退出          |" << endl;
	cout << "\t\t ----------------------------" << endl;
}


//成绩统计
void Count_Score(int n, int count)
{
	cout << endl;
	cout << "共" << n << "道题目,您答对了" << count << "道" << endl;
	cout << "本次做题总分:" << count << endl;
}


//加法练习
void Addition_Practice()
{
	int n = 0;
	cout << "请输入要练习的次数:" << endl;
	cin >> n;
	int m = n;
	cout << "欢迎答题" << endl << endl;
	int count = 0;
	vector<string>s;
	while (n--)
	{
		string temp;//记录做错的题目
		int x = rand() % N;
		int y = rand() % N;
		int ret = 0;
		printf("%d + %d = \n", x, y);
		cout << "请输入答案:" << endl;
		cin >> ret;
		if (ret == x + y)
		{
			cout << "恭喜你,回答正确" << endl;
			count++;
		}
		else
		{
			cout << "不好意思，回答错误，正确答案为:" << x + y << endl;
			temp = to_string(x) + " + "+to_string(y);
			s.push_back(temp);
		}
	}

	//成绩统计
	Count_Score(m, count);
	cout << "您答错的题目为:\n";
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
	cout << "请输入要练习的次数:" << endl;
	cin >> n;
	int m = n;
	cout << "欢迎答题" << endl << endl;
	int count = 0;
	vector<string>s;
	while (n--)
	{
		string temp;
		int x = rand() % N;
		int y = rand() % N;
		int ret = 0;
		printf("%d - %d = \n", x, y);
		cout << "请输入答案:" << endl;
		cin >> ret;
		if (ret == x - y)
		{
			cout << "恭喜你,回答正确" << endl;
			count++;
		}
		else
		{
			cout << "不好意思，回答错误，正确答案为:" << x -y << endl;
			temp = to_string(x) + " - " + to_string(y);
			s.push_back(temp);
		}
	}


	//成绩统计
	Count_Score(m, count);


	cout << "您打错的题目为:" << endl;
	for (int i = 0; i < s.size(); i++)
	{
		cout << s[i] << endl;
	}
	system("pause");
	system("cls");
}



//乘法运算
void Multiplication_practice()
{
	int n = 0;
	cout << "请输入要练习的次数:" << endl;
	cin >> n;
	int m = n;
	cout << "欢迎答题" << endl << endl;
	int count = 0;
	vector<string>s;
	while (n--)
	{
		string temp;
		int x = rand() % N;
		int y = rand() % N;
		int ret = 0;
		printf("%d * %d = \n", x, y);
		cout << "请输入答案:" << endl;
		cin >> ret;
		if (ret == x * y)
		{
			cout << "恭喜你,回答正确" << endl;
			count++;
		}
		else
		{
			cout << "不好意思，回答错误，正确答案为:" << x * y << endl;

			temp = to_string(x) + " * " + to_string(y);
			s.push_back(temp);
		}
	}

	//成绩统计
	Count_Score(m, count);
	cout << "您答错的题目为:\n";

	for (int i = 0; i < s.size(); i++)
	{
		cout << s[i] << endl;
	}
	system("pause");
	system("cls");
}


//除法练习
void Division_practice()
{
	int n = 0;
	cout << "请输入要练习的次数:" << endl;
	cin >> n;
	int m = n;
	cout << "欢迎答题" << endl << endl;
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
		cout << "请输入答案:" << endl;
		cin >> ret;
		if (abs(((float)ret-(float)x/(float)y))<0.00001)
		{
			cout << "恭喜你,回答正确" << endl;
			count++;
		}
		else
		{
			cout << "不好意思，回答错误，正确答案为:" << (float)x /(float) y << endl;

			temp = to_string(x) + " / " + to_string(y);
			s.push_back(temp);
		}
	}

	//成绩统计
	Count_Score(m, count);

	//错误题目打印
	cout << "您答错的题目为:\n";
	for (int i = 0; i < s.size(); i++)
	{
		cout << s[i] << endl;
	}

	system("pause");
	system("cls");
}



//5.混合运算
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
		//如果是数字
		if (curChar >= '0' && curChar <= '9') {
			if (!lastIsNum)
				polish.push(' ');
			polish.push(curChar);
			lastIsNum = true;
			continue;
		}
		//否则为操作符
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

//计算表达式的值
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
	cout << "请输入要练习的次数:" << endl;
	cin >> n;
	int m = n;
	cout << "欢迎答题" << endl << endl;
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

		//将中缀表达式转换为逆波兰表达式进行求解
		//逆波兰表达式是一种后缀表达式，所谓后缀就是指算符写在后面。
		//	平常使用的算式则是一种中缀表达式，如(1 + 2)* (3 + 4) 。
		//	该算式的逆波兰表达式写法为((1 2 + ) (3 4 + )*) 。
		//	逆波兰表达式主要有以下两个优点：
		//	去掉括号后表达式无歧义，上式即便写成 1 2 + 3 4 + *也可以依据次序计算出正确结果。
		//	适合用栈操作运算：遇到数字则入栈；遇到算符则取出栈顶两个数字进行计算，并将结果压入栈中。
		string temp = reversePolish(str);
		int ret = 0;
		cout << str << "=" << endl;
		cout << "请输入答案:" << endl;
		cin >> ret;
		if (ret == calculate(temp))
		{
			cout << "恭喜你,回答正确" << endl;
			count++;
		}
		else
		{
			cout << "不好意思，回答错误，正确答案为:" << x * y << endl;
			s.push_back(str);
		}
	}

	//成绩统计
	Count_Score(m, count);
	cout << "您答错的题目为:\n";

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
	cout << "请输入要练习的次数:" << endl;
	cin >> n;
	int m = n;
	cout << "欢迎答题" << endl << endl;
	int count = 0;
	vector<string>s;
	char str[4] = "+-*";
	while (n--)
	{
		string temp;//记录做错的题目
		int x = rand() % N;
		int y = rand() % N;
		int ret = 0;
		int i = rand() % 3;
		printf("%d %c %d = \n", x,str[i] ,y);
		cout << "请输入答案:" << endl;
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
			cout << "恭喜你,回答正确" << endl;
			count++;
		}
		else
		{
			cout << "不好意思，回答错误，正确答案为:" << ans << endl;
			temp = to_string(x) + str[i] + to_string(y);
			s.push_back(temp);
		}
	}

	//成绩统计
	Count_Score(m, count);
	cout << "您答错的题目为:\n";
	for (int i = 0; i < s.size(); i++)
	{
		cout << s[i] << endl;
	}
	system("pause");
	system("cls");
}



//多位数加法
void Multidigit_addition()
{
	int n = 0;
	cout << "请输入要练习的次数:" << endl;
	cin >> n;
	int m = n;
	cout << "欢迎答题" << endl << endl;
	int count = 0;
	vector<string>s;


	//创建一个数字随机表示每次要减的个数
	//
	while (n--)
	{
		int z = rand() % 5 + 1;//随机生成[1，5]个数代表算数的位数
		int x = rand() % N;//最初的数字
		string temp;
		temp += to_string(x);
		while (z--)
		{
			int y = rand() % N;
			x += y;
			temp += ("+" + to_string(y));
		}

		cout << temp << "=" << endl;
		cout << "请输入答案:" << endl;
		int ret = 0;
		cin >> ret;
		if (ret == x)
		{
			cout << "恭喜您，回答正确" << endl;
			count++;
		}
		else
		{
			cout << "不好意思，回答错误，正确答案为:" << x << endl;
			s.push_back(temp);
		}

	}

	//成绩统计
	Count_Score(m, count);
	cout << "您答错的题目为:\n";

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
	cout << "请输入要练习的次数:" << endl;
	cin >> n;
	int m = n;
	cout << "欢迎答题" << endl << endl;
	int count = 0;
	vector<string>s;


	//创建一个数字随机表示每次要减的个数
	//
	while (n--)
	{
		int z = rand() % 5 + 1;//随机生成[1，5]个数代表算数的位数
		int x = rand() % N;//最初的数字
		string temp;
		temp += to_string(x);
		while (z--)
		{
			int y = rand() % N;
			x -= y;
			temp += ("-" + to_string(y));
		}

		cout << temp << "=" << endl;
		cout << "请输入答案:" << endl;
		int ret = 0;
		cin >> ret;
		if (ret == x)
		{
			cout << "恭喜您，回答正确" << endl;
			count++;
		}
		else
		{
			cout << "不好意思，回答错误，正确答案为:" << x << endl;
			s.push_back(temp);
		}

	}

	//成绩统计
	Count_Score(m, count);
	cout << "您答错的题目为:\n";

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
	cout << "请输入要练习的次数:" << endl;
	cin >> n;
	int m = n;
	cout << "欢迎答题" << endl << endl;
	int count = 0;
	vector<string>s;


	//创建一个数字随机表示每次要减的个数
	//
	while (n--)
	{
		int z = rand() % 5 + 1;//随机生成[1，5]个数代表算数的位数
		int x = rand() % N;//最初的数字
		string temp;
		temp += to_string(x);
		while (z--)
		{
			int y = rand() % N;
			x *= y;
			temp += ("*" + to_string(y));
		}

		cout << temp << "=" << endl;
		cout << "请输入答案:" << endl;
		int ret = 0;
		cin >> ret;
		if (ret == x)
		{
			cout << "恭喜您，回答正确" << endl;
			count++;
		}
		else
		{
			cout << "不好意思，回答错误，正确答案为:" << x << endl;
			s.push_back(temp);
		}

	}

	//成绩统计
	Count_Score(m, count);
	cout << "您答错的题目为:\n";

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
	cout << "请输入要练习的次数:" << endl;
	cin >> n;
	int m = n;
	cout << "欢迎答题" << endl << endl;
	int count = 0;
	vector<string>s;


	//创建一个数字随机表示每次要减的个数
	//
	while (n--)
	{
		int z = rand() % 5 + 1;//随机生成[1，5]个数代表算数的位数
		int x = rand() % N;//最初的数字
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
		cout << "请输入答案:" << endl;
		double ret = 0;
		cin >> ret;
		if (abs(ret-w)<0.0000000001)
		{
			cout << "恭喜您，回答正确" << endl;
			count++;
		}
		else
		{
			cout << "不好意思，回答错误，正确答案为:" << w << endl;
			s.push_back(temp);
		}

	}

	//成绩统计
	Count_Score(m, count);
	cout << "您答错的题目为:\n";

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
			//加法练习
			Addition_Practice();
			break;

		case 2:
			//减法练习
			Subtraction_practice();
			break;

		case 3:

			//乘法练习
			Multiplication_practice();
			break;

		case 4:
			//除法练习
			Division_practice();
			break;
		case 5:
			//混合运算
			Mixed_practice();
			break;
		case 6:
			Mixed();
			break;
		case 7:
			//多位数加法
			Multidigit_addition();
			break;
		case 8:
			//多位数减法
			Multidigit_subtraction();
			break;
		case 9:
			//多位数乘法
			Multidigit_multiplication();
			break;
		case 10:
			//多位数除法
			Multi_digit_division();
			break;
		case 0:
			exit(-1);
			break;

		default:
			printf("输入错误，重新输入\n");
			break;

		}
	}


}