#pragma once
#include <qobject.h>
#include<qobject.h>
class Teacher :
    public QObject
{
    Q_OBJECT;
public:
  //  explicit Teacher(QObject* parent=0);
signals:
        //�Զ����źţ���Ҫд���ۺ���signals�¡�
    //�������ͱ�����void
    //ֻ��Ҫ����������Ҫʵ��
    //�źſ����в���
    //���Է�������
    void hungary();
public slots:
};

