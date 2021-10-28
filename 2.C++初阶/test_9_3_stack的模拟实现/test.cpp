#include"stack.h"
int main()
{
	std::stack<int,vector<int>>st;
	st.push(1);
	st.push(2);
	st.push(3);
	st.push(4);
	st.push(5);
	cout <<"st.size()="<< st.size() << endl;
	while (!st.empty())
	{
		cout << st.top() << endl;
		st.pop();
	}
	return 0;
}