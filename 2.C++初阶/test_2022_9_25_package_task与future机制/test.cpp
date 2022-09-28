#include<iostream>
#include<thread>
#include<future>
using namespace std;
int sum_1(int a, int b)
{
	return a + b;
}
double sum_2(double a, double b)
{
	return a + b;
}
template<class Func, typename...Args>
auto sum(Func&& func, Args&&... args) ->  std::future<decltype(func(args...))>
{
	using RTtype = decltype(func(args...));
	auto ptr = std::make_shared<std::packaged_task<RTtype()>>(
		std::bind(std::forward<Func>(func), std::forward<Args>(args)...));
	future<RTtype>f = ptr->get_future();
	thread t([&] {
		(*ptr)();
		});
	t.join();
	return f;
}


int main()
{
	//packaged_task<int(int,int)>pack(sum);  //��������൱�����ǵ�ִ������
	//future<int>f=pack.get_future();       //future���ͺ������Լ�д��Result���ͷǳ�����
	//thread t(std::move(pack), 110, 10);     
	//t.join();
	//cout << f.get() << endl;
	future<int>f=sum(sum_1, 1, 2);
	cout << f.get() << endl;
	int c = getchar();
	
	
}