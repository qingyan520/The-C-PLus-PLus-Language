#pragma once
#include <qobject.h>
class student :
    public QObject
{
    Q_OBJECT;
public:
    explicit student(QObject* parent = 0);
signals:

public slots:
    //�Զ���ۺ���
    //�߰汾�¿���д��public����ȫ�ֺ�����ȥ
    //�ۺ�����Ҫ������Ҳ��Ҫʵ��
    //�ۺ�������ֵ void
    //�ۺ����в�����Ҳ���Է�������
    void treat();
};

