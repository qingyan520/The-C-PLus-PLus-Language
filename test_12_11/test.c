////�ж�ջ��ѹ���뵯������
//
//
//#include<stdio.h>
//#include<string.h>
//#include<stdbool.h>
//#include<stdlib.h>
//
//#define N 100
//#define START 100
//#define ADD 100
//
////ģ��ʵ��һ��ջ
//typedef char T;
//typedef struct Stack
//{
//    int size;
//    T* data;
//    int top;
//}Stack;
////�ж�ջ�Ƿ�Ϊ��
//bool IsEmpty(Stack* S)
//{
//    return S->top == 0;
//}
////��ʼ��ջ
//void InitStack(Stack* S)
//{
//    S->size = START;
//    S->data = (T*)malloc((S->size) * sizeof(T));
//    S->top = 0;
//}
////ջ����������
//void StackPush(Stack* S, T mii)
//{
//    //����������������
//    if (S->top == S->size)
//    {
//        S->size += ADD;
//        if (S->data != NULL)
//            S->data = (T*)realloc(S->data, (S->size) * sizeof(T));
//    }
//    //�������
//    S->data[(S->top)++] = mii;
//}
////ɾ��ջ��Ԫ��
//int StackPop(Stack* S)
//{
//    if (!IsEmpty(S))
//    {
//        return S->data[--(S->top)];
//    }
//    else
//    {
//        return 0;
//    }
//}
//
////����ջ��Ԫ��
//int StackTop(Stack* s)
//{
//    if (s->top == 0)
//    {
//        return -1;
//    }
//    return s->data[s->top-1];
//}
//
////����ջ
//void DestroyStack(Stack* S)
//{
//    free(S->data);
//    S->data = NULL;
//    S->top = 0;
//    S->size = 0;
//}
//
//
////�ж�ջ��ѹ���뵯�������Ƿ�һ��
//bool validateStackSequences(T* pushed, int m, T* popped, int n)
//{
//    if (m != n)
//    {
//        return false;
//    }
//    int i = 0; 
//    int j = 0;
//    //����һ��ջ
//    Stack s;
//    InitStack(&s);
//    //ѭ������������pushed���������
//    while (i < m)
//    {
//        //ÿ�ν�pushed[i]����ջ��
//        StackPush(&s, pushed[i]);
//        //�жϸս���ջ��Ԫ�أ���ջ��Ԫ���Ƿ���popped[j]��ȣ����st.pop(),j++
//        while (!IsEmpty(&s) && StackTop(&s) == popped[j])
//        {
//            StackPop(&s);
//            j++;
//        }
//        //ֱ��st,top()��popped[j]�����֮��++i;
//        i++;
//    }
//
//    DestroyStack(&s);
//    //�ж��Ƿ�Ϊջ��ѹ���뵯��ֻ��Ҫ�ж�popped�����Ƿ�������
//    return j == n;
//}
//
//int main()
//{
//    char str1[N];//��������str1����ջ��ѹ������
//    char str2[N];//��������str2����ջ�ĵ�������
//    printf("������ջ���У�");
//    scanf("%s", str1);
//
//    while (1)
//    {
//        printf("�����ջ���У�");
//        scanf("%s", &str2);
//
//        if (validateStackSequences(str1, strlen(str1), str2, strlen(str2)))
//        {
//            printf("�������ǿ��ܵĳ�ջ����\n");
//        }
//        else
//        {
//            printf("�������ǲ����ܵĳ�ջ����\n");
//        }
//    }
//	return 0;
//}


//����ʵ�ִ������
//��123+456Ϊ�����������Ƚ�����λ���ֵ�ÿһλ�洢�������У��������������ӣ�
//3-->2-->1-->NULL
//6-->5-->4-->NULL
//Ȼ���Ӧλ�����Ȼ��ת�����ɣ�
//9-->7-->5
//��ת����
//5-->7-->9
//��Ϊ������

//��Ȼ�������Ǽ����ӣ�ʵ������л��п��ܳ��ֽ�λ���⣬��199+9Ϊ������˵��
//9-->9-->1
//9
//���
//��һ����Ӻ�8--->1
//Ȼ��
//8-->1
//    9--->1
//8-->0-->2
//����ǰλ��=(List1->val+List2->val+��λ)%10;
//��һ��λ�õĽ�λ=(List1->val+List2->val+��λ)/10;
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define N 100
typedef struct ListNode
{
	int val;
	struct ListNode* next;
}ListNode;


//������ת��Ϊ����
ListNode* Number_To_List(char*str)
{
	//����ͷָ��
	ListNode* p1 = NULL;
	//βָ��tail1ָ��p1,ÿ�ζ���tail1����ߣ�p1����������ͷ���Ա��ڷ���ͷ�ڵ�
	ListNode* tail1 = p1;

	//���㴫����ַ�������
	int n = strlen(str);

	//�����һ���ַ���ʼ��ÿһ��Ԫ����ӵ�������
	int i = n - 1;
	while (i>=0)
	{
		//������ʱ�ڵ㱣��Ҫ�洢������
		ListNode* temp = (ListNode*)malloc(sizeof(ListNode));
		if (temp == NULL)
			break;
		
		//ע�⽫�ַ�ת��Ϊ����
		temp->val = str[i]-'0';
		i--;
		temp->next = NULL;

		//���ͷ�ڵ�p1ΪNULL˵���ǲ����һ��Ԫ�أ���ô��temp����ͷ�ڵ㣬βָ��tail1Ҳָ��p1
		if (p1 == NULL)
		{
			p1 = temp;
			tail1 = p1;
		}

		//ͷָ�벻Ϊ��˵��tail1���ǵ�ǰ��������һ��λ�ã�������tail1->next=temp��������һ���ڵ㣬Ȼ��βָ��tail1����ƶ�
		else
		{
			tail1->next = temp;
			tail1 = tail1->next;

		}
	}

	//���������ͷָ��
	return p1;

}


//ʵ�����������������
ListNode* Add_Numbers(ListNode* p1, ListNode* p2)
{
	//�����������Ľڵ㶼Ϊ�վͲ���Ҫ���к������ֱ�ӷ���NULL
	if (p1 == NULL && p2 == NULL)
		return NULL;

	//retΪ���շ��ص�ָ��
	ListNode* ret = NULL;
	ListNode* tail = ret;

	//next��ʾҪ��λ
	//����9+9=18����ǰλ�ô洢9����Ҫ��ǰ��1�������next���Ǳ��������λ��
	int next = 0;

	//p1��p2ֻҪ��һ����Ϊ�վͿ�����ǰ�ߣ��������δ����
	while (p1 != NULL || p2 != NULL)
	{
		//val��������ǰ���������Ӧλ�����ݵļӺͣ�ע��ӵ�ʱ��Ҫ���Ͻ�λ
		int val = 0;
		//����Ҫ���ǵ�p1��p2��ǰλ���Ƿ�������
		//��Ϊ���������
		//p1��p2��ǰλ�ö�������
		//ֻ��p1��ǰλ��������
		//ֻ��p2��ǰλ��������

		if (p1 != NULL && p2 != NULL)
		{
			val += (p1->val + p2->val+next);
			p1 = p1->next;
			p2 = p2->next;
		}
		else if (p1 != NULL)
		{
			val += p1->val+next;
			p1 = p1->next;
		}
		else
		{
			val += p2->val + next;
			p2 = p2->next;
		}


		//���¾ͺ�������һ�����������ˣ�����׸��
		ListNode* temp = (ListNode*)malloc(sizeof(ListNode));
		if (temp == NULL)
			return NULL;
		//��ǰ�ڵ��ֵҪ%10,����val=18,��ǰλ��ֻ�ܴ�8����λΪ1
		//��temp->val = val % 10;
		//��λnext = val / 10;
		temp->val = val % 10;
		next = val / 10;
		temp->next = NULL;

		//���������
		if (ret == NULL)
		{
			ret = temp;
			tail = ret;
		}
		else
		{
			tail->next = temp;
			tail = tail->next;
		}
	}

	//next������0���������һ����ӵ�ʱ���ֲ����˽�λ����ô���ǵð������λ�������������β��
	if (next != 0)
	{
		ListNode* temp = (ListNode*)malloc(sizeof(ListNode));
		if (temp != NULL)
		{
			temp->val = next;
			temp->next = NULL;
			tail->next = temp;
			tail = tail->next;
		}
	}

	//����ͷָ��
	return ret;


}


//��ת����
 ListNode* reverse(struct ListNode* head)
{
	 //head����ͷָ�룬�������û��Ԫ�ػ���ֻ��һ��Ԫ�ؾͷ��ص�ǰ�ڵ�
	if (!head || !head->next) return head;

	//�ݹ���õ�ǰ����
	struct ListNode* p = reverse(head->next);
	head->next->next = head;
	head->next = NULL;
	return p;
}



int main()
{
	char str1[N];
	char str2[N];
	printf("������������:\n");
	scanf("%s", str1);
	scanf("%s", str2);
	
	ListNode* p = Number_To_List(str1);//����һ����ת��Ϊ����
	ListNode* q = Number_To_List(str2);//���ڶ�����ת��Ϊ����
	ListNode* p1 = Add_Numbers(p, q);//�õ���Ӻ�Ľ��
	p1 = reverse(p1);//��ת����

	//��ӡ���ս��
	printf("���Ϊ:\n");
	while (p1 != NULL)
	{
		printf("%d", p1->val);
		p1 = p1->next;
	}

}

