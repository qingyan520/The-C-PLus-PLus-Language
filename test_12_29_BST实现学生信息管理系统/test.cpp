#include<iostream>
#include<string.h>
using namespace std;

//ѧ����Ϣ
struct Student_Data
{
	int number=-1;//ѧ��
	string name="";//����
	string sex="";//�Ա�
	string tele="";//�绰

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


//�������ڵ㶨��
struct TreeNode
{
	Student_Data _data;//�ڵ����ݴ洢ѧ����Ϣ
	TreeNode* _left;//����
	TreeNode* _right;//�Һ���


	//Ĭ�Ϲ��캯��
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

	//Ĭ�Ϲ��캯��
	BTree() :_root(nullptr)
	{

	}

	//��������
	~BTree()
	{
		Destory(_root);
	}


	//��������
	bool Insert(const Student_Data& data)
	{
		if (_root == nullptr)
		{
			_root = new Node(data);
			cout << "��ӳɹ�" << endl;
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
				cout << "ѧ���ظ�,���ʧ��" << endl;
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
		cout << "��ӳɹ�" << endl;
		return true;
	}

	//����ѧ�Ų�ѯͬѧ��Ϣ
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


	//�����������в���
	Node* Find_Name(const string& name)
	{
		return _Find_Name(_root, name);
	}


	//���յ绰�Ž��в���
	Node* Find_Tele(const string& tele)
	{
		return _Find_Tele(_root, tele);
	}


	//����ѧ���޸���Ϣ
	void Modify_Number()
	{
		int number;
		cout << "�������޸ĵ�ѧ��:" << endl;
		cin >> number;
		Node* p = Find_Number(number);
		if (p == nullptr)
		{
			cout << "δ�ҵ���ѧ��!" << endl;
			return;
		}
		else
		{

			//��Ҫ�޸���ɾ��
			Student_Data s(p->_data);
			Erase(p->_data.number);
			//Ȼ�����²��뼴��
			cout << "������Ҫ�޸ĵ�ѧ��:" << endl;
			cin >> s.number;
			this->Insert(s);
			cout << "�޸ĳɹ�" << endl;
		}
	}


	//���������޸���Ϣ
	void Modify_Name()
	{
		string name;
		cout << "�������޸ĵ�����:" << endl;
		cin >> name;
		Node* p = Find_Name(name);
		if (p == nullptr)
		{
			cout << "δ�ҵ�������!" << endl;
			return;
		}
		else
		{

			//��Ҫ�޸���ɾ��
			Student_Data s(p->_data);
			Erase(p->_data.number);
			//Ȼ�����²��뼴��
			cout << "������Ҫ�޸ĵ�����:" << endl;
			cin >> s.name;
			this->Insert(s);
			cout << "�޸ĳɹ�" << endl;
		}
	}


	//���ݵ绰�����޸���Ϣ
	void Modify_Tele()
	{
		string tele;
		cout << "�������޸ĵĵ绰����:" << endl;
		cin >> tele;
		Node* p = Find_Tele(tele);
		if (p == nullptr)
		{
			cout << "δ�ҵ��õ绰����!" << endl;
			return;
		}
		else
		{

			//��Ҫ�޸���ɾ��
			Student_Data s(p->_data);
			Erase(p->_data.number);
			//Ȼ�����²��뼴��
			cout << "������Ҫ�޸ĵĵ绰����:" << endl;
			cin >> s.tele;
			this->Insert(s);
			cout << "�޸ĳɹ�" << endl;
		}
	}


	//����ѧ��ɾ����Ϣ
	bool Erase(const int& number)
	{
		return _Erase(_root, number);
	}


	//��������ɾ����Ϣ
	void Erase_Name()
	{
		string name;
		cout << "������Ҫɾ��������:" << endl;
		cin >> name;
		Node* p = Find_Name(name);
		if (p == nullptr)
		{
			cout << "δ�ҵ��ó�Ա!" << endl;
			return;
		}
		else
		{
			Erase(p->_data.number);
			cout << "ɾ���ɹ�" << endl;
			return;
		}
	}


	//���ݵ绰����ɾ����Ϣ
	void Erase_Tele()
	{
		string tele;
		cout << "������Ҫɾ���ĵ绰����:" << endl;
		cin >> tele;
		Node* p = Find_Tele(tele);
		if (p == nullptr)
		{
			cout << "δ�ҵ��ó�Ա!" << endl;
			return;
		}
		else
		{
			Erase(p->_data.number);
			cout << "ɾ���ɹ�" << endl;
			return;
		}
	}


	void Print()
	{
		printf("%-10s\t%-10s\t%-10s\t%-15s\n", "ѧ��", "����", "�Ա�", "�绰����");
		_Print(_root);
	}




	//���ң�
	//����ѧ�Ų���
	void Search_Number()
	{
		int number;
		cout << "����Ҫ���ҵ�ѧ��:" << endl;
		cin >> number;
		Node* p = Find_Number(number);
		if (p == nullptr)
		{
			cout << "δ�ҵ����ó�Ա" << endl;
			return;
		}
		else
		{
			printf("%-10s\t%-10s\t%-10s\t%-15s\n", "ѧ��", "����", "�Ա�", "�绰����");
			printf("%-10d\t%-10s\t%-10s\t%-15s\n", p->_data.number, p->_data.name.c_str(), p->_data.sex.c_str(), p->_data.tele.c_str());
		}
	}


	//������������
	void Search_Name()
	{
		string name;
		cout << "����Ҫ���ҵ�����:" << endl;
		cin >> name;
		Node* p = Find_Name(name);
		if (p == nullptr)
		{
			cout << "δ�ҵ����ó�Ա" << endl;
			return;
		}
		else
		{
			//cout << p->_data.number << " " << p->_data.name << " " << p->_data.sex << " " << p->_data.tele << endl;
			printf("%-10s\t%-10s\t%-10s\t%-15s\n", "ѧ��", "����", "�Ա�", "�绰����");
			printf("%-10d\t%-10s\t%-10s\t%-15s\n", p->_data.number, p->_data.name.c_str(), p->_data.sex.c_str(), p->_data.tele.c_str());
		}
	}


	void Search_Tele()
	{
		string tele;
		cout << "����Ҫ���ҵĵ绰����:" << endl;
		cin >> tele;
		Node* p = Find_Tele(tele);
		if (p == nullptr)
		{
			cout << "δ�ҵ����ó�Ա" << endl;
			return;
		}
		else
		{
			//cout << p->_data.number << " " << p->_data.name << " " << p->_data.sex << " " << p->_data.tele << endl;
			printf("%-10s\t%-10s\t%-10s\t%-15s\n", "ѧ��", "����", "�Ա�", "�绰����");
			printf("%-10d\t%-10s\t%-10s\t%-15s\n", p->_data.number, p->_data.name.c_str(), p->_data.sex.c_str(), p->_data.tele.c_str());
		}
	}
private:

	//���ٶ�����
	void Destory(Node* root)
	{
		if (root == nullptr)
			return;
		Destory(root->_left);
		Destory(root->_right);
		delete root;
	}

	//��ӡ��Ϣ
	void _Print(Node* root)
	{
		if (root == nullptr)
			return;
		_Print(root->_left);
		//cout << root->_data.number << " " << root->_data.name << " " << root->_data.sex << " " << root->_data.tele << endl;
		printf("%-10d\t%-10s\t%-10s\t%-15s\n",root->_data.number,root->_data.name.c_str(), root->_data.sex.c_str(), root->_data.tele.c_str());
		_Print(root->_right);
	}


	//����������������
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


	//���յ绰������в���
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


	//���е�ɾ�������϶��ǰ���number����ɾ��
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
				//�ٴε��õݹ麯��ɾ��Min_Right->val,Ȼ��ʹ�á���root->val=Min_Right->val
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
	cout << "\t\t1.���ѧ����Ϣ" << endl;
	cout << "\t\t2.����ѧ�Ų�ѯ��Ϣ" << endl;
	cout << "\t\t3.����������ѯ��Ϣ" << endl;
	cout << "\t\t4.���ݵ绰�����ѯ��Ϣ" << endl;
	cout << "\t\t5.����ѧ���޸���Ϣ" << endl;
	cout << "\t\t6.���������޸���Ϣ" << endl;
	cout << "\t\t7.���ݵ绰�޸���Ϣ" << endl;
	cout << "\t\t8.��������ɾ����Ϣ" << endl;
	cout << "\t\t9.���ݵ绰����ɾ����Ϣ" << endl;
	cout << "\t\t10.��ʾ��Ϣ" << endl;
	cout << "\t\t0.�˳�" << endl;
}


int main()
{
	BTree b;
	int option = 0;
	while (1)
	{
		menu();
		cout << "�������Ӧѡ��:" << endl;
		cin >> option;
		switch (option)
		{
		case 1:
		{
			//�����Ϣ
			Student_Data s;
			cout << "������ѧ��:" << endl;
			cin >> s.number;
			cout << "����������:" << endl;
			cin >> s.name;
			cout << "�������Ա�:" << endl;
			cin >> s.sex;
			cout << "������绰����:" << endl;
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
			cout << "�����������������" << endl;
			system("pause");
			system("cls");
			break;
		}

	}
	return 0;
}