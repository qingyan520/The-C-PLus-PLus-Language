//4.3�ڽ���������
//1.�ڽ������Ķ���
//���
//STL������һЩ��������
//���ࣺ
//������º���
//��ϵ��º���
//�߼���º���
//�÷���
//��Щ�º����������Ķ����÷���һ�㺯����ȫ��ͬ
//ʹ���ڽ�����������Ҫ����ͷ�ļ�#include<functional>

//4.3.2�����º���
//��������
//ʵ����������
//����negate��һԪ���㣬�������Ƕ�Ԫ����
//�º���ԭ�ͣ�
//template<class T>T plus <T> //�ӷ��º���
//template<class T>T minus <T> //�����º���
//template<class T>T multilies <T> //�˷���º���
//template<class T>T divdes <T>   //������º���
//template<class T>T moduls<T>  //ȡģ�º���
//template<class T>T negate<T>  //ȡ���º���

//#include<iostream>
//#include<functional>
//using namespace std;
////negate:ȡ���º���
////plus:�ӷ��º���
//void test01()
//{
//	negate<int>n;
//	cout<<n(50);
//}
//void test02()
//{
//	plus<int >v;
//	cout << v(10, 20) << endl;
//}
//int main()
//{
//	test02();
//	system("pause");
//	return 0;
//}

//4.3.3��ϵ�º���
//����ԭ�ͣ�
//template<class T>bool equal_to<T>  //����
//template<class T>bool not_equal_to<T>  //������
//template<class T>bool greater <T>  //����
//template<class T>bool greater_equal<T>  //���ڵ���
//template<class T>bool less<T>  //С��
//template<class T>bool less_equal<T>//С�ڵ���
//#include<iostream>
//#include<functional>
//#include<vector>
//#include<algorithm>
//using namespace std;
//class compare
//{
//	bool operator()(int v1, int v2)
//	{
//		return v1 > v2;
//	}
//};
//void test01()
//{
//	equal_to<int>e;
//	cout << e(10, 10) << endl;
//	not_equal_to<int>n;
//	cout << n(10, 20) << endl;
//	greater<int>g;
//	cout << g(20, 21) << endl;
//	vector<int>v;
//	v.push_back(10);
//	v.push_back(30);
//	v.push_back(20);
//	v.push_back(40);
//	sort(v.begin(), v.end(),greater<int>());
//	for (vector<int>::iterator it = v.begin(); it != v.end(); it++)
//	{
//		cout << *it << " ";
//	}
//	cout << endl;
//}
//int main()
//{
//	test01();
//	system("pause");
//	return 0;
//}

//4.3.4�߼��º���
//ʵ���߼�����
//template<class T>bool logical_and<T> // �߼���
//template<class T>bool logical_or<T>   //�߼���
//template<class T>bool logical_not<T>   //�߼���
//#include<iostream>
//#include<functional>
//using namespace std;
//void test01()
//{
//	logical_and<int>l;
//	cout << l (1, 0) << endl;
//	logical_not<int>c;
//	cout << c(10) << endl;
//}
//int main()
//{
//	test01();
//	system("pause");
//	return 0;
//}


