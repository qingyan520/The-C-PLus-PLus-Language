#include<stdio.h>
#include<stdlib.h>
#define N 1000

//����ڵ�����
typedef struct TreeNode
{
	int data;
	struct TreeNode* left;
	struct TreeNode* right;
}Node;



//�����������Ĳ���
void insert(Node** p, int x)
{
	
	Node* cur = (*p);
	//��һ�β����ʱ��������⴦��
	if (cur == NULL)
	{
		cur = (Node*)malloc(sizeof(Node));
		if (cur)
		{
			cur->data = x;
			cur->left = NULL;
			cur->right = NULL;
			*p = cur;
			return;
		}
	}


	//�ȵ�ǰ�ڵ����뵽�ұߣ��ȵ�ǰ�ڵ�С���뵽���
	Node* parent = (*p);
	while (cur != NULL)
	{
		if (x > cur->data)
		{
			parent = cur;
			cur = cur->right;
		}
		else if (x < cur->data)
		{
			parent = cur;
			cur = cur->left;
		}
		else
		{
			printf("�������������ܲ����ظ�Ԫ�أ����뵱ǰ�ڵ�ʧ�ܣ�\n");
			return;
		}
	}

	//���ٽڵ�
	cur = (Node*)malloc(sizeof(Node));
	if (cur == NULL)
		return;
	cur->data = x;
	cur->left = NULL;
	cur->right = NULL;

	//�ж�����λ��
	if (parent!=NULL&&cur!=NULL&&cur->data > parent->data)
	{
		parent->right = cur;
	}
	

	if (parent != NULL && cur != NULL && cur->data < parent->data)
	{
		parent->left = cur;
	}
}



//�������������������
void inorder(Node* p)
{
	if(p == NULL)
	{
		return;
	}
	if(p!=NULL)
	inorder(p->left);
	if(p!=NULL)
	printf("%d ", p->data);
	inorder(p->right);
}



//���ҽڵ��Ƿ���ڣ����ڷ��ص�ǰ�ڵ㣬�����ڷ���NULL
Node* find(Node* p, int x)
{
	if (p == NULL)
		return NULL;
	Node* cur = p;
	while (cur != NULL)
	{
		if (x > cur->data)
		{
			cur = cur->right;
		}
		else if (x < cur->data)
		{
			cur = cur->left;
		}
		else
		{
			//�ҵ��˷��ص�ǰ�ڵ�
			return cur;
		}
	}

	return NULL;
}


Node* erase(Node* root, int key)
{
	if (root == NULL)
		return NULL;
	if (root->data == key)                      //�ҵ�����Ҫɾ���Ľ�㣬��ʼɾ��������
	{
		if (root->left == NULL && root->right == NULL) //��ɾ�����ΪҶ�ӽ���򷵻�NULL
			return NULL;
		else if (root->left == NULL)           //������Ϊ���򷵻�������
			return root->right;
		else if (root->right == NULL)          //������Ϊ���򷵻�������
			return root->left;
		else
		{
			Node* p = root->left;
			while (p->right != NULL)           //������ɾ������������ϵ����ֵ
			{
				p = p->right;
			}
			p->right = root->right;           //����ɾ�����������������ҵ������������ֵ������������
											//ά�ֶ����������Ľṹ���Բ���
			root = root->left;                //ɾ���ý��
		}
	}
	else if (root->data > key)                  //keyֵС�ڸ��ڵ�ֵ����ɾ��������������ϣ��ݹ����������
		root->left = erase(root->left, key);
	else                                    //��ɾ��������������ϣ��ݹ����������
		root->right = erase(root->right, key);
	return root;
}

int Max_Data(Node* root)
{
	if (root == NULL)
		return -1;
	Node* Max_Right = root->right;
	if (Max_Right == NULL)
		return root->data;

	while (Max_Right!=NULL&&Max_Right->right)
	{
		Max_Right = Max_Right->right;
	}
	return Max_Right->data;
}


int Min_Data(Node* root)
{
	if (root == NULL)
		return -1;
	Node* Min_Left = root->left;
	if (Min_Left == NULL)
		return root->data;
	while (Min_Left && Min_Left->left != NULL)
	{
		Min_Left = Min_Left->left;
	}

	return Min_Left->data;
}




void menu()
{
	printf("\t\t1.����Ԫ��\n");
	printf("\t\t2.Ѱ�������Сֵ\n");
	printf("\t\t3.�������\n");
	printf("\t\t0.�˳�\n");
}
int main()
{
	int option;
	Node* root = NULL;
	int x;//�������ɾ����Ԫ��

	int Max = 0;
	int Min = 0;
	while (1)
	{
		menu();
		printf("����ѡ��:\n");
		scanf_s("%d", &option);


		switch (option)
		{
		case 0:
			exit(-1);

		case 1:
			printf("�������Ԫ��:\n");
			scanf_s("%d", &x);
			insert(&root, x);
			inorder(root);
			printf("\n\n");
			system("pause");
			system("cls");
			break;


		case 2:
			printf("�������Ԫ��:\n");
			scanf_s("%d", &x);
			if (find(root, x) == NULL)
			{
				printf("δ�ҵ�%dԪ��\n", x);
			}
			else
			{
				 Max = Max_Data(find(root,x));
				 Min = Min_Data(find(root,x));
				printf("���ֵΪ:%d\n��СֵΪ:%d\n\n", Max, Min);
			}
			system("pause");
			system("cls");
			break;


		case 3:
			inorder(root);
			printf("\n\n");
			system("pause");
			system("cls");
			break;


		default:
			printf("���������������\n");
			system("pause");
			system("cls");
			break;

		}
	}
}