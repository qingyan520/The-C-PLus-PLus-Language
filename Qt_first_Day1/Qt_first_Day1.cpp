#include "Qt_first_Day1.h"
#include<qpushbutton.h>
//Qt�����淶����������ĸ��д  �����뵥��֮������ĸ��д
//����  ����  ����ĸСд   �����뵥��֮������ĸ��д
//����  ctrl+R
//����  ctrl+B
//����  ctrl+F
//�����ĵ� F1
//��������  ctrl+���
//�Զ�����  ctrl+i
//�����ƶ�  ctrl+shift+��/��
//ͬ��֮���.h,.cpp�л� F4


Qt_first_Day1::Qt_first_Day1(QWidget *parent)
    : QMainWindow(parent) //��ʼ���б�
{
    //��ť
    QPushButton* brn = new QPushButton;
   // brn->show(); //show�ö��㷽ʽ�������������Qt_first_Day1���ڵ���������Ҫ��1����Qt_first_Day1����
    //���ø���
    brn->setParent(this);
    //��������
    brn->setText("hello world");  //��char*��ʽ����ת��ΪQString
    

    //������ť�ڶ��ַ�ʽ
    QPushButton* btn2 = new QPushButton("ceww   ", this);
    //���ô��ڴ�С
    this->resize(1600, 400);
    //�ƶ��ڶ�����ť
    btn2->move(100, 100);
    brn->move(0, 0);

    //��ť��С����
    brn->resize(100, 100);

    //���ô��ڱ���
    brn->setWindowTitle("Qt��һ������");

    //���ù̶�����
    setFixedSize(1600, 400);

    //7.Qt�еĶ�����
    //һ���̶��ϼ����ڴ���ջ���
    //�������������ر�ʱ���Զ����丸�����б���ɾ��


    //8.Qt�е����꣺xΪ�Ҳ�����yΪ����Ϊ������



    //9.Qt�е��źźͲ�
    //�����ť->���ڹر�
    //���������������connect(�źŵķ����ߣ����͵��źţ��źŵĽ����ߣ�����ĺ���(�ۺ���));\
    //����1���źŵķ����� brn
    //����2�����͵��ź� &
    //����3
    connect(brn, &QPushButton::clicked,this,&QWidget::close);


    ui.setupUi(this);
}
