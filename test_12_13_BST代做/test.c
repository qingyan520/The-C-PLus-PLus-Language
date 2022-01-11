#include<stdio.h>
#include<stdlib.h>
#define N 1000

//定义节点类型
typedef struct TreeNode
{
	int data;
	struct TreeNode* left;
	struct TreeNode* right;
}Node;



//二叉搜索树的插入
void insert(Node** p, int x)
{
	
	Node* cur = (*p);
	//第一次插入的时候进行特殊处理
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


	//比当前节点大插入到右边，比当前节点小插入到左边
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
			printf("二叉搜索树不能插入重复元素！插入当前节点失败！\n");
			return;
		}
	}

	//开辟节点
	cur = (Node*)malloc(sizeof(Node));
	if (cur == NULL)
		return;
	cur->data = x;
	cur->left = NULL;
	cur->right = NULL;

	//判断左右位置
	if (parent!=NULL&&cur!=NULL&&cur->data > parent->data)
	{
		parent->right = cur;
	}
	

	if (parent != NULL && cur != NULL && cur->data < parent->data)
	{
		parent->left = cur;
	}
}



//二叉搜索树的中序遍历
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



//查找节点是否存在，存在返回当前节点，不存在返回NULL
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
			//找到了返回当前节点
			return cur;
		}
	}

	return NULL;
}


Node* erase(Node* root, int key)
{
	if (root == NULL)
		return NULL;
	if (root->data == key)                      //找到了需要删除的结点，开始删除结点操作
	{
		if (root->left == NULL && root->right == NULL) //需删除结点为叶子结点则返回NULL
			return NULL;
		else if (root->left == NULL)           //左子树为空则返回右子树
			return root->right;
		else if (root->right == NULL)          //右子树为空则返回左子树
			return root->left;
		else
		{
			Node* p = root->left;
			while (p->right != NULL)           //查找需删除结点左子树上的最大值
			{
				p = p->right;
			}
			p->right = root->right;           //将需删除结点的右子树插在找到的左子树最大值结点的右子树上
											//维持二叉搜索树的结构特性不变
			root = root->left;                //删除该结点
		}
	}
	else if (root->data > key)                  //key值小于根节点值，需删除结点在左子树上，递归查找左子树
		root->left = erase(root->left, key);
	else                                    //需删除结点在右子树上，递归查找右子树
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
	printf("\t\t1.插入元素\n");
	printf("\t\t2.寻找最大最小值\n");
	printf("\t\t3.中序遍历\n");
	printf("\t\t0.退出\n");
}
int main()
{
	int option;
	Node* root = NULL;
	int x;//插入或者删除的元素

	int Max = 0;
	int Min = 0;
	while (1)
	{
		menu();
		printf("输入选项:\n");
		scanf_s("%d", &option);


		switch (option)
		{
		case 0:
			exit(-1);

		case 1:
			printf("输入插入元素:\n");
			scanf_s("%d", &x);
			insert(&root, x);
			inorder(root);
			printf("\n\n");
			system("pause");
			system("cls");
			break;


		case 2:
			printf("输入查找元素:\n");
			scanf_s("%d", &x);
			if (find(root, x) == NULL)
			{
				printf("未找到%d元素\n", x);
			}
			else
			{
				 Max = Max_Data(find(root,x));
				 Min = Min_Data(find(root,x));
				printf("最大值为:%d\n最小值为:%d\n\n", Max, Min);
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
			printf("输入错误，重新输入\n");
			system("pause");
			system("cls");
			break;

		}
	}
}