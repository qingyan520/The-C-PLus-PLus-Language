#include"Set.h"
#include"Map.h"
int main()
{
	hello::set<int>s;
	int arr[]{4,2,6,1,3,5,15,7,16,14};
	for (auto e : arr)
	{
		s.insert(e);
	}
	cout<<s.Is_Set()<<endl;
	cout << endl;
	//s.inorder();
	hello::set<int>::iterator it = s.begin();
	while (it != s.end())
	{
		cout << *it << endl;
		++it;
	}






	//world::map<int, int>m;
	//int arr[]{4,2,6,1,3,5,15,7,16,14};
	//for (auto e : arr)
	//{
	//	m.insert(make_pair(e, e));
	//}
	//cout<<m.Is_Map()<<endl;
	//cout << endl;
	//m.inorder();
	
}