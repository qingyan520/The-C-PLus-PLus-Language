#include<stdio.h>
#include<stdlib.h>

//定义链式队列节点域
typedef char QElemType;
typedef struct QNode {
    QElemType  data;//数据域
    struct QNode* next;//指向下一个节点的指针
} *QueuePtr;

typedef  struct {
    QueuePtr  front;//指向队列头部
    QueuePtr  rear;//指向队列尾部
}LinkQueue;//队列

//这里我们设计为带头不循环链表
//front指针为哨兵位的头结点，不存储数据，它的next节点存储真正的数据
//rear指针为尾指针，指向最后一个元素
//这样设计我们在插入元素时向队尾插入元素，即rear->next=new QNode;实现O(1)的时间复杂度
//出队列时只需要头删rear->next节点即可，这样我们就可以实现在O(1)的时间复杂度内完成队列的操作


void InitQueue(LinkQueue* q);         //初始化队列
void PushQueue(LinkQueue* q);         //入队列
void PopQueue(LinkQueue* q);          //出队列
QElemType FrontQueue(LinkQueue* q);   //取出队头元素
int EmptyQueue(LinkQueue* q);         //判断队列是否为空
void PrintQueue(LinkQueue* q);        //队列的遍历
void Destory(LinkQueue* q);           //队列的销毁

//初始化队列
void InitQueue(LinkQueue* q)
{
    q->front = (struct QNode*)malloc(sizeof(struct QNode));

    if (q->front == NULL)
    {
        printf("InitQueue Fail!");
        return;
    }

    //初始化队列头部哨兵位节点
    q->front->data = '\0';
    q->front->next = NULL;

    //让尾指针指向哨兵位节点
    q->rear = q->front;
}

//入队列，即向堆尾插入元素
void PushQueue(LinkQueue* q)
{
    printf("请输入要插入的元素:\n");
    QElemType val = 0;
    getchar();
    scanf("%c", &val);
    struct QNode* ptr = (struct QNode*)malloc(sizeof(struct QNode));
    //判断节点是否开辟成功
    if (ptr != NULL)
    {
        ptr->data = val;
        ptr->next = NULL;
    }
    else
    {
        printf("PushQueue::malloc fail!");
    }
    //让尾指针指向当前新开辟的节点
    q->rear->next = ptr;
    //尾指针进行后移
    q->rear = q->rear->next;
    printf("添加成功!\n");
}

//取出对头元素
QElemType FrontQueue(LinkQueue* q)
{
    if (q->front->next == NULL)
    {
        printf("队列为空无元素!");
        return -1;
    }

    //返回头结点下一个指针的数据域
    return q->front->next->data;
}


//出队列
void PopQueue(LinkQueue* q)
{
    if (q->front->next == NULL)
    {
        printf("队列为空，无元素可以出队列！");
        return;
    }
    //指向第一个节点
    struct QNode* next = q->front->next;
    q->front->next = next->next;
    free(next);
    //printf("出队列成功!\n");
}

//判断队列是否为空
int EmptyQueue(LinkQueue* q)
{
    return q->front->next == NULL;
}


//队列的遍历
void PrintQueue(LinkQueue*q)
{

    if (EmptyQueue(q))
    {
        printf("队列为空，无法遍历!");
        return;
    }
    while (!EmptyQueue(q))
    {
        QElemType val = FrontQueue(q);
        printf("%c ", val);
        PopQueue(q);
    }
    printf("\n");
}

//队列的销毁
void Destory(LinkQueue* q)
{
    free(q->front);
    free(q->rear);
    q->front = NULL;
    q->rear = NULL;
}

//主菜单界面
void menu()
{
    printf("\t\t1.入队列     \n");
    printf("\t\t2.出队列     \n");
    printf("\t\t3.队头元素   \n");
    printf("\t\t4.遍历队列   \n");
    printf("\t\t0.退出程序   \n");
}

int main()
{
    LinkQueue q;//创建队列
    InitQueue(&q);//初始化队列
    QElemType val = 0;//标记取出的对头元素
    int option = 0;//对应的选项
    while (1)
    {
        menu();
        printf("请输入对应选项:\n");
        scanf("%d", &option);
        switch (option)
        {
        case 1:
            PushQueue(&q);//入队列
            break;
        case 2:
            PopQueue(&q);//出队列
            break;
        case 3:
            val = FrontQueue(&q);//取出对头元素
            if (val != -1)
            {
                printf("对头元素为:%c\n", val);
            }
            break;
        case 4:
            PrintQueue(&q);
            break;
        case 0:
            exit(-1);//退出
            break;
        default:
            printf("输入错误，请重新输入!\n");
            break;
        }
    }
    Destory(&q);
}
