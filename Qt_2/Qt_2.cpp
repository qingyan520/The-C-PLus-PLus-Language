#include "Qt_2.h"
//���󣺴��������� Teacher��    student��
//�¿κ�  teacher��  zt  ����һ���ź�  ����
//ѧ����Ӧ�źţ������źŵĲۺ���   ��ͳԷ�

Qt_2::Qt_2(QWidget *parent)
    : QMainWindow(parent)
{
    zt = new Teacher;
    st = new student(this);
    //������ʦ��ѧ��
    connect(zt, &Teacher::hungary, st, &student::treat);
    ui.setupUi(this);
}
void Qt_2::classisover()
{
    //������ʦ���˵��ź������Զ����źţ��ؼ���Ϊemit
    emit zt->hungary();
}
