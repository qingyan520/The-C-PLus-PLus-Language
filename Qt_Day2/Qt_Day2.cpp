#include "Qt_Day2.h"
#include<qpushbutton.h>
Qt_Day2::Qt_Day2(QWidget *parent)
    : QDialog(parent)
{
    //�����´���
    QPushButton* but = new QPushButton;
    //���ø���
    but->setParent(this);
    //���ô�������
    but->setText("QtButton");
    //���ô��ڴ�С
    this->resize(1000, 500);
    //���ð�ť��С
    but->resize(100, 50);
    //�ƶ���ť
    but->move(0, 0);
    //�̶����ڴ�С
    this->setFixedSize(1000, 500);
    //���ô��ڱ���
    this->setWindowTitle("QtWindows");
    ui.setupUi(this);
}
