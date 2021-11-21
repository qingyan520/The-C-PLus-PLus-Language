//unordered_map������map����һ������ͬ���У�
//1.����ʵ�ֵķ�ʽ��ͬ��unordered_map�ײ�ΪhashMap,map�ײ�ʵ��ΪRbTree
//2.����ʱmap�ᰴ�ն��������������Զ����򣬶�unordered_map�����������
//3.���߲���Ч�ʲ�ͬ:unordered_map����Ч��ΪO(1),��map����Ч��ΪlogN

//unordered_set��set�Ĺ��ܻ���һ�£���ͬ������unordered_map��map����һ��

//unorder_map��unordered_mulitmap��map/multimap����һ��
//unorder_set��unorder_multiset��set/multiset����һ��

//#include<iostream>
//#include<unordered_map>
//#include<unordered_set>
//using namespace std;
//void test_um()
//{
//	unordered_map<int, int>um;
//	int arr[]{ 1,5,2,4,7,8,2,1,2 };
//	for (auto e : arr)
//	{
//		um.insert(make_pair(e, e));
//	}
//	unordered_map<int, int>::iterator it = um.begin();
//	while (it != um.end())
//	{
//		cout << it->first << ":" << it->second << endl;
//		++it;
//	}
//	
//}
//
//void test_us()
//{
//	unordered_set<int>us;
//	int arr[]{ 1,5,2,4,7,8,2,1,2 };
//	for (auto e : arr)
//	{
//		us.insert(e);
//	}
//	unordered_set<int>::iterator it = us.begin();
//	while (it != us.end())
//	{
//		cout << *it << endl;
//		it++;
//	}
//}
//
//int main()
//{
//	test_um();
//	test_us();
//	return 0;
//}

#include<iostream>
#include<unordered_set>
#include<unordered_map>
#include<time.h>
#include<set>
using namespace std;
namespace std
{
    void test_unordered_set()
    {
        unordered_set<int>us;
        us.insert(1);
        us.insert(5);
        us.insert(0);
        us.insert(2);
        us.insert(1);
        //����������
        //��������������
        unordered_set<int>::iterator it = us.begin();
        while (it != us.end())
        {
            cout << *it << " ";
            ++it;
        }
        for (auto e : us)
        {
            cout << e << " ";
        }
        cout << endl;
        auto pos = us.find(2);
        //auto pos find(us.begin(),us.end(),2)//ͨ���㷨���е���ÿ������������ʹ�ã����ͱ�̣��������ң�ʱ�临�Ӷ���O(N)
        //unordered_set�е�find��unordered_mapר�ò����㷨��ʹ���˹�ϣ���Խ��в��ң�Ч�ʸ�,����Ч����O(1)
        //���Ƶģ������set������Ч����O(logN)
        //�������ֲ��ҷ�ʽ��
        //��һ��
        if (pos != us.end())
        {
            cout << "�ҵ���" << endl;
        }
        else
        {
            cout << "δ�ҵ�" << endl;
        }

    }

    void test_unordered_map()
    {
        //�������key��������
        unordered_map<int, int>m;
        int arr[]{ 5,2,3,4,1,0 };
        for (auto e : arr)
        {
            m.insert(make_pair(e, e));
        }

        auto it = m.begin();
        while (it != m.end())
        {
            cout << it->first << ":" << it->second << endl;
        }

        for (auto e : m)
        {
            cout << e.first << ":" << e.second << endl;
        }
    }

    //��ɾ��ĵ�Ч��
    void test_op()
    {
        int N = 300000000;
        srand(time(0));
        vector<int>v;
        v.reserve(N);
        for (int i = 0; i < N; i++)
        {
            v.push_back(rand());
        }

        unordered_set<int>us;
        set<int>s;
        size_t begin1 = clock();
        for (auto e : v)
        {
            us.insert(e);
        }
        size_t end1 = clock();
        size_t begin2 = clock();
        for (auto e : v)
        {
            s.insert(e);
        }
        size_t end2 = clock();
        cout << "unordered_set_insert:" << end1 - begin1 << endl;
        cout << "set_insert:" << end2 - begin2 << endl << endl;;

        size_t begin3 = clock();
        for (auto e : v)
        {
            us.find(e);
        }
        size_t end3 = clock();

        size_t begin4 = clock();
        for (auto e : v)
        {
            s.find(e);
        }
        size_t end4 = clock();

        cout << "unordered_set_find:" << end3 - begin3 << endl;
        cout << "set_find:" << end4 - begin4 << endl << endl;;

        size_t begin5 = clock();
        for(auto e:v)
        {
            us.erase(e);
        }
        size_t end5 = clock();

        size_t begin6 = clock();
        for (auto e : v)
        {
            s.erase(e);
        }
        size_t end6 = clock();

        cout << "unordered_set_erase:" << end5 - begin5 << endl;
        cout << "set_erase:" << end6 - begin6 << endl;

    }

}
int main()
{
    std::test_op();

    return 0;
}