//unordered_map功能与map基本一样，不同点有：
//1.两者实现的方式不同，unordered_map底层为hashMap,map底层实现为RbTree
//2.插入时map会按照二叉搜索树进行自动排序，而unordered_map不会进行排序
//3.两者查找效率不同:unordered_map查找效率为O(1),而map查找效率为logN

//unordered_set与set的功能基本一致，不同区别与unordered_map和map区别一样

//unorder_map与unordered_mulitmap与map/multimap区别一致
//unorder_set与unorder_multiset与set/multiset区别一致

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
        //迭代器遍历
        //遍历结果是无序的
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
        //auto pos find(us.begin(),us.end(),2)//通用算法，有点事每个容器都可以使用，泛型编程，暴力查找，时间复杂度是O(N)
        //unordered_set中的find是unordered_map专用查找算法，使用了哈希特性进行查找，效率高,查找效率是O(1)
        //类似的，如果是set，查找效率是O(logN)
        //上面两种查找方式：
        //第一种
        if (pos != us.end())
        {
            cout << "找到了" << endl;
        }
        else
        {
            cout << "未找到" << endl;
        }

    }

    void test_unordered_map()
    {
        //不会根据key进行排序
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

    //增删查改的效率
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