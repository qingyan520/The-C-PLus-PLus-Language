#include "Qt_1.h"
#include<qpushbutton.h>

Qt_1::Qt_1(QWidget *parent)
    : QMainWindow(parent)
{
    QPushButton* btn = new QPushButton;
    //���ø���
   btn->setParent(this);
    //���ð�ť��С
    btn->resize(100, 40);
    //��������
    btn->setText("Button");
    //���ô��ڴ�С
    this->resize(1000, 800);
    //���ð�ťλ��
    btn->move(0, 0);

    //�����ź���ۣ�Ϊ��ť���蹦��
    //connect(�źŵķ����ߣ��źŵĽ����ߣ�)
    connect(btn, &QPushButton::clicked, this, &QWidget::close);

    ui.setupUi(this);
}
