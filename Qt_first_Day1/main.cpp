#include "Qt_first_Day1.h"
#include <QtWidgets/QApplication>  //Ӧ�ó���

//������� argc�����еı���������argv�����б�������
int main(int argc, char *argv[])
{
    //Ӧ�ó������a������ֻ��һ��Ӧ�ó������
    QApplication a(argc, argv);
    //����һ������w
    Qt_first_Day1 w;
    //����Ĭ�ϲ��ᵯ����Ҫ��������show()
    w.show();
    //a.exec()������Ϣѭ������,��������
    return a.exec();
}
