/**
 * ����һ����װ��(wrapper class)����װ����C++���е�СС���ô�(������û��)����Java�е��ô�����һЩ��
 */

#ifndef _INT_H_  //����define guard 
#define _INT_H_  //��C��C++�У�ͷ�ļ���Ӧ���������� 

class Int {

private://���Ƿ��ʿ��ơ���˽�е� 
    int value; //�������ݳ�Ա�����ǳ�Int�ǻ�������int�İ�װ�࣬������ΪInt����ֻ��һ��int���͵����ݳ�Ա 

public:	//���ǹ��е� 
    //�������¿հ���д���캯�����أ����ṩ3�����캯��
    /********** Begin **********/
    Int(int a = 0) :
        value(a)
    {

    }
    Int(const Int& I)
    {
        value = I.value;
    }


    /********** End **********/

    //�벻Ҫ�Ķ����³�Ա����
    int getValue()const { return value; }

};//��ס������һ���ֺ� 

#endif


