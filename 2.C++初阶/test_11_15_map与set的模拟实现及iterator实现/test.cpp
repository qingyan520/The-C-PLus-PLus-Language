#include"Set.h"
#include"Map.h"
#include<string.h>
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
		cout << *it << " ";
		++it;
	}
	cout << endl;

	hello::set<int>::reverse_iterator rit = s.rbegin();
	while (rit != s.rend())
	{
		cout << (*rit) << " ";
		++rit;
	}
	cout << endl;





	//world::map<int, int>m;
	//int arr[]{4,2,6,1,3,5,15,7,16,14};
	//for (auto e : arr)
	//{
	//	m.insert(make_pair(e, e));
	//}
	//cout<<m.Is_Map()<<endl;

	//world::map<int, int>::iterator it = m.begin();
	//while (it != m.end())
	//{
	//	cout << (*it).first << ":" << (*it).second << endl;
	//	++it;
	//}
	//world::map<int, int>::reverse_iterator rit = m.rbegin();
	//while (rit != m.rend())
	//{
	//	cout << (*rit).first << ":" << (*rit).second<< endl;
	//	++rit;
	//}


	////operator[]µÄ²âÊÔ
	//world::map<string, string>m;
	//m["left"] = "×ó±ß";
	//m["left"] += ",Ê£Óà";
	//m["right"] = "ÓÒ±ß";
	//auto it = m.begin();
	//while (it != m.end())
	//{
	//	cout << it->first << ":" << it->second << endl;
	//	++it;
	//}
}