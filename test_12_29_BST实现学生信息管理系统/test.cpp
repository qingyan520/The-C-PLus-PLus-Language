#include<iostream>
#include<string.h>
using namespace std;

//学生信息
struct Student_Data
{
	int number=-1;//学号
	string name="";//姓名
	string sex="";//性别
	string tele="";//电话

	Student_Data()
	{

	}


	Student_Data(const Student_Data& s):
		number(s.number),
		name(s.name),
		sex(s.sex),
		tele(s.tele)
	{

	}

};


//二叉树节点定义
struct TreeNode
{
	Student_Data _data;//节点数据存储学生信息
	TreeNode* _left;//左孩子
	TreeNode* _right;//右孩子


	//默认构造函数
	TreeNode(const Student_Data& data) :
		_data(data),
		_left(nullptr),
		_right(nullptr)
	{

	}
};


class BTree
{
	typedef TreeNode Node;
public:

	//默认构造函数
	BTree() :_root(nullptr)
	{

	}

	//析构函数
	~BTree()
	{
		Destory(_root);
	}


	//插入数据
	bool Insert(const Student_Data& data)
	{
		if (_root == nullptr)
		{
			_root = new Node(data);
			cout << "添加成功" << endl;
			return true;
		}
		Node* cur = _root;
		Node* parent = nullptr;
		while (cur)
		{
			if (cur->_data.number > data.number)
			{
				parent = cur;
				cur = cur->_left;
			}
			else if (cur->_data.number < data.number)
			{
				parent = cur;
				cur = cur->_right;
			}
			else
			{
				cout << "学号重复,添加失败" << endl;
				return false;
			}
		}
		cur = new Node(data);
		if (parent!=nullptr&&data.number > parent->_data.number)
		{
			parent->_right = cur;
		}
		else
		{
			if(parent!=nullptr)
			parent->_left = cur;
		}
		cout << "添加成功" << endl;
		return true;
	}

	//按照学号查询同学信息
	Node* Find_Number(const int&num)
	{
		if (_root == nullptr)
			return nullptr;
		Node* cur = _root;
		while (cur)
		{
			if (cur->_data.number > num)
			{
				cur = cur->_left;
			}
			else if (cur->_data.number < num)
			{
				cur = cur->_right;
			}
			else
			{
				return cur;
			}
		}
		return nullptr;
	}


	//按照姓名进行查找
	Node* Find_Name(const string& name)
	{
		return _Find_Name(_root, name);
	}


	//按照电话号进行查找
	Node* Find_Tele(const string& tele)
	{
		return _Find_Tele(_root, tele);
	}


	//按照学号修改信息
	void Modify_Number()
	{
		int number;
		cout << "请输入修改的学号:" << endl;
		cin >> number;
		Node* p = Find_Number(number);
		if (p == nullptr)
		{
			cout << "未找到该学号!" << endl;
			return;
		}
		else
		{

			//想要修改先删除
			Student_Data s(p->_data);
			Erase(p->_data.number);
			//然后重新插入即可
			cout << "请输入要修改的学号:" << endl;
			cin >> s.number;
			this->Insert(s);
			cout << "修改成功" << endl;
		}
	}


	//根据姓名修改信息
	void Modify_Name()
	{
		string name;
		cout << "请输入修改的姓名:" << endl;
		cin >> name;
		Node* p = Find_Name(name);
		if (p == nullptr)
		{
			cout << "未找到该姓名!" << endl;
			return;
		}
		else
		{

			//想要修改先删除
			Student_Data s(p->_data);
			Erase(p->_data.number);
			//然后重新插入即可
			cout << "请输入要修改的姓名:" << endl;
			cin >> s.name;
			this->Insert(s);
			cout << "修改成功" << endl;
		}
	}


	//根据电话号码修改信息
	void Modify_Tele()
	{
		string tele;
		cout << "请输入修改的电话号码:" << endl;
		cin >> tele;
		Node* p = Find_Tele(tele);
		if (p == nullptr)
		{
			cout << "未找到该电话号码!" << endl;
			return;
		}
		else
		{

			//想要修改先删除
			Student_Data s(p->_data);
			Erase(p->_data.number);
			//然后重新插入即可
			cout << "请输入要修改的电话号码:" << endl;
			cin >> s.tele;
			this->Insert(s);
			cout << "修改成功" << endl;
		}
	}


	//根据学号删除信息
	bool Erase(const int& number)
	{
		return _Erase(_root, number);
	}


	//根据名字删除信息
	void Erase_Name()
	{
		string name;
		cout << "请输入要删除的名字:" << endl;
		cin >> name;
		Node* p = Find_Name(name);
		if (p == nullptr)
		{
			cout << "未找到该成员!" << endl;
			return;
		}
		else
		{
			Erase(p->_data.number);
			cout << "删除成功" << endl;
			return;
		}
	}


	//根据电话号码删除信息
	void Erase_Tele()
	{
		string tele;
		cout << "请输入要删除的电话号码:" << endl;
		cin >> tele;
		Node* p = Find_Tele(tele);
		if (p == nullptr)
		{
			cout << "未找到该成员!" << endl;
			return;
		}
		else
		{
			Erase(p->_data.number);
			cout << "删除成功" << endl;
			return;
		}
	}


	void Print()
	{
		printf("%-10s\t%-10s\t%-10s\t%-15s\n", "学号", "姓名", "性别", "电话号码");
		_Print(_root);
	}




	//查找：
	//根据学号查找
	void Search_Number()
	{
		int number;
		cout << "输入要查找的学号:" << endl;
		cin >> number;
		Node* p = Find_Number(number);
		if (p == nullptr)
		{
			cout << "未找到给该成员" << endl;
			return;
		}
		else
		{
			printf("%-10s\t%-10s\t%-10s\t%-15s\n", "学号", "姓名", "性别", "电话号码");
			printf("%-10d\t%-10s\t%-10s\t%-15s\n", p->_data.number, p->_data.name.c_str(), p->_data.sex.c_str(), p->_data.tele.c_str());
		}
	}


	//根据姓名查找
	void Search_Name()
	{
		string name;
		cout << "输入要查找的姓名:" << endl;
		cin >> name;
		Node* p = Find_Name(name);
		if (p == nullptr)
		{
			cout << "未找到给该成员" << endl;
			return;
		}
		else
		{
			//cout << p->_data.number << " " << p->_data.name << " " << p->_data.sex << " " << p->_data.tele << endl;
			printf("%-10s\t%-10s\t%-10s\t%-15s\n", "学号", "姓名", "性别", "电话号码");
			printf("%-10d\t%-10s\t%-10s\t%-15s\n", p->_data.number, p->_data.name.c_str(), p->_data.sex.c_str(), p->_data.tele.c_str());
		}
	}


	void Search_Tele()
	{
		string tele;
		cout << "输入要查找的电话号码:" << endl;
		cin >> tele;
		Node* p = Find_Tele(tele);
		if (p == nullptr)
		{
			cout << "未找到给该成员" << endl;
			return;
		}
		else
		{
			//cout << p->_data.number << " " << p->_data.name << " " << p->_data.sex << " " << p->_data.tele << endl;
			printf("%-10s\t%-10s\t%-10s\t%-15s\n", "学号", "姓名", "性别", "电话号码");
			printf("%-10d\t%-10s\t%-10s\t%-15s\n", p->_data.number, p->_data.name.c_str(), p->_data.sex.c_str(), p->_data.tele.c_str());
		}
	}
private:

	//销毁二叉树
	void Destory(Node* root)
	{
		if (root == nullptr)
			return;
		Destory(root->_left);
		Destory(root->_right);
		delete root;
	}

	//打印信息
	void _Print(Node* root)
	{
		if (root == nullptr)
			return;
		_Print(root->_left);
		//cout << root->_data.number << " " << root->_data.name << " " << root->_data.sex << " " << root->_data.tele << endl;
		printf("%-10d\t%-10s\t%-10s\t%-15s\n",root->_data.number,root->_data.name.c_str(), root->_data.sex.c_str(), root->_data.tele.c_str());
		_Print(root->_right);
	}


	//按照姓名进行搜索
	Node* _Find_Name(Node* root, const string& name)
	{
		if (root == nullptr)
			return nullptr;
		if(root->_left)
		return _Find_Name(root->_left, name);
		if (root->_data.name == name)
			return root;
		if(root->_right)
		return _Find_Name(root->_right, name);

		return nullptr;
	}


	//按照电话号码进行查找
	Node* _Find_Tele(Node* root, const string& tele)
	{
		if (root == nullptr)
			return nullptr;
		if (root->_left)
			return _Find_Tele(root->_left, tele);
		if (root->_data.tele == tele)
			return root;
		if (root->_right)
			return _Find_Tele(root->_right, tele);
		return nullptr;
	}


	//所有的删除本质上都是按照number进行删除
	bool _Erase(Node* &root, const int& number)
	{
		if (root == nullptr)
			return false;
		if (number > root->_data.number)
		{
			return _Erase(root->_right, number);
		}
		else if (number < root->_data.number)
		{
			return _Erase(root->_left, number);
		}
		else
		{
			if (root->_left == nullptr)
			{
				Node* del = root;
				root = root->_right;
				delete del;
			}
			else if (root->_right == nullptr)
			{
				Node* del = root;
				root = root->_left;
			}
			else
			{
				Node* Min_Right = root->_right;
				while (Min_Right->_left != nullptr)
				{
					Min_Right = Min_Right->_left;
				}
				//再次调用递归函数删掉Min_Right->val,然后使得——root->val=Min_Right->val
				int  min_val = Min_Right->_data.number;
				Student_Data min_ = Min_Right->_data;
				this->_Erase(root->_right, min_val);
				root->_data = min_;
			}
		}

	}


	Node* _root;
};




void menu()
{
	cout << "\t\t1.添加学生信息" << endl;
	cout << "\t\t2.根据学号查询信息" << endl;
	cout << "\t\t3.根据姓名查询信息" << endl;
	cout << "\t\t4.根据电话号码查询信息" << endl;
	cout << "\t\t5.根据学号修改信息" << endl;
	cout << "\t\t6.根据姓名修改信息" << endl;
	cout << "\t\t7.根据电话修改信息" << endl;
	cout << "\t\t8.根据姓名删除信息" << endl;
	cout << "\t\t9.根据电话号码删除信息" << endl;
	cout << "\t\t10.显示信息" << endl;
	cout << "\t\t0.退出" << endl;
}


int main()
{
	BTree b;
	int option = 0;
	while (1)
	{
		menu();
		cout << "请输入对应选项:" << endl;
		cin >> option;
		switch (option)
		{
		case 1:
		{
			//添加信息
			Student_Data s;
			cout << "请输入学号:" << endl;
			cin >> s.number;
			cout << "请输入姓名:" << endl;
			cin >> s.name;
			cout << "请输入性别:" << endl;
			cin >> s.sex;
			cout << "请输入电话号码:" << endl;
			cin >> s.tele;
			b.Insert(s);
		}
			system("pause");
			system("cls");
			break;
		case 2:
			b.Search_Number();
			system("pause");
			system("cls");
			break;
		case 3:
			b.Search_Name();
			system("pause");
			system("cls");
			break;
		case 4:
			b.Search_Tele();
			system("pause");
			system("cls");
			break;
		case 5:
			b.Modify_Number();
			system("pause");
			system("cls");
			break;
		case 6:
			b.Modify_Name();
			system("pause");
			system("cls");
			break;
		case 7:
			b.Modify_Tele();
			system("pause");
			system("cls");
			break;
		case 8:
			b.Erase_Name();
			break;
		case 9:
			b.Erase_Tele();
			system("pause");
			system("cls");
			break;
		case 10:
			b.Print();
			system("pause");
			system("cls");
			break;
		case 0:
			exit(-1);
			break;
		default:
			cout << "输入错误，请重新输入" << endl;
			system("pause");
			system("cls");
			break;
		}

	}
	return 0;
}