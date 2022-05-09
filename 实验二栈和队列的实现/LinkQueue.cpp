#include<stdio.h>
#include<stdlib.h>

//������ʽ���нڵ���
typedef char QElemType;
typedef struct QNode {
    QElemType  data;//������
    struct QNode* next;//ָ����һ���ڵ��ָ��
} *QueuePtr;

typedef  struct {
    QueuePtr  front;//ָ�����ͷ��
    QueuePtr  rear;//ָ�����β��
}LinkQueue;//����

//�����������Ϊ��ͷ��ѭ������
//frontָ��Ϊ�ڱ�λ��ͷ��㣬���洢���ݣ�����next�ڵ�洢����������
//rearָ��Ϊβָ�룬ָ�����һ��Ԫ��
//������������ڲ���Ԫ��ʱ���β����Ԫ�أ���rear->next=new QNode;ʵ��O(1)��ʱ�临�Ӷ�
//������ʱֻ��Ҫͷɾrear->next�ڵ㼴�ɣ��������ǾͿ���ʵ����O(1)��ʱ�临�Ӷ�����ɶ��еĲ���


void InitQueue(LinkQueue* q);         //��ʼ������
void PushQueue(LinkQueue* q);         //�����
void PopQueue(LinkQueue* q);          //������
QElemType FrontQueue(LinkQueue* q);   //ȡ����ͷԪ��
int EmptyQueue(LinkQueue* q);         //�ж϶����Ƿ�Ϊ��
void PrintQueue(LinkQueue* q);        //���еı���
void Destory(LinkQueue* q);           //���е�����

//��ʼ������
void InitQueue(LinkQueue* q)
{
    q->front = (struct QNode*)malloc(sizeof(struct QNode));

    if (q->front == NULL)
    {
        printf("InitQueue Fail!");
        return;
    }

    //��ʼ������ͷ���ڱ�λ�ڵ�
    q->front->data = '\0';
    q->front->next = NULL;

    //��βָ��ָ���ڱ�λ�ڵ�
    q->rear = q->front;
}

//����У������β����Ԫ��
void PushQueue(LinkQueue* q)
{
    printf("������Ҫ�����Ԫ��:\n");
    QElemType val = 0;
    getchar();
    scanf("%c", &val);
    struct QNode* ptr = (struct QNode*)malloc(sizeof(struct QNode));
    //�жϽڵ��Ƿ񿪱ٳɹ�
    if (ptr != NULL)
    {
        ptr->data = val;
        ptr->next = NULL;
    }
    else
    {
        printf("PushQueue::malloc fail!");
    }
    //��βָ��ָ��ǰ�¿��ٵĽڵ�
    q->rear->next = ptr;
    //βָ����к���
    q->rear = q->rear->next;
    printf("��ӳɹ�!\n");
}

//ȡ����ͷԪ��
QElemType FrontQueue(LinkQueue* q)
{
    if (q->front->next == NULL)
    {
        printf("����Ϊ����Ԫ��!");
        return -1;
    }

    //����ͷ�����һ��ָ���������
    return q->front->next->data;
}


//������
void PopQueue(LinkQueue* q)
{
    if (q->front->next == NULL)
    {
        printf("����Ϊ�գ���Ԫ�ؿ��Գ����У�");
        return;
    }
    //ָ���һ���ڵ�
    struct QNode* next = q->front->next;
    q->front->next = next->next;
    free(next);
    //printf("�����гɹ�!\n");
}

//�ж϶����Ƿ�Ϊ��
int EmptyQueue(LinkQueue* q)
{
    return q->front->next == NULL;
}


//���еı���
void PrintQueue(LinkQueue*q)
{

    if (EmptyQueue(q))
    {
        printf("����Ϊ�գ��޷�����!");
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

//���е�����
void Destory(LinkQueue* q)
{
    free(q->front);
    free(q->rear);
    q->front = NULL;
    q->rear = NULL;
}

//���˵�����
void menu()
{
    printf("\t\t1.�����     \n");
    printf("\t\t2.������     \n");
    printf("\t\t3.��ͷԪ��   \n");
    printf("\t\t4.��������   \n");
    printf("\t\t0.�˳�����   \n");
}

int main()
{
    LinkQueue q;//��������
    InitQueue(&q);//��ʼ������
    QElemType val = 0;//���ȡ���Ķ�ͷԪ��
    int option = 0;//��Ӧ��ѡ��
    while (1)
    {
        menu();
        printf("�������Ӧѡ��:\n");
        scanf("%d", &option);
        switch (option)
        {
        case 1:
            PushQueue(&q);//�����
            break;
        case 2:
            PopQueue(&q);//������
            break;
        case 3:
            val = FrontQueue(&q);//ȡ����ͷԪ��
            if (val != -1)
            {
                printf("��ͷԪ��Ϊ:%c\n", val);
            }
            break;
        case 4:
            PrintQueue(&q);
            break;
        case 0:
            exit(-1);//�˳�
            break;
        default:
            printf("�����������������!\n");
            break;
        }
    }
    Destory(&q);
}
