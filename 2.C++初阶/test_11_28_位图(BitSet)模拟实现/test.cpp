#include<iostream>
#include<vector>
using namespace std;
template<size_t N>
class BitSet
{
public:
	BitSet()
	{
		_bits.resize(N / 32 + 1, 0);
	}

	void Set(size_t x)
	{
		int i = x / 32;
		int j = x % 32;
		_bits[i] |= (1 << j);
	}

	void ReSet(size_t x)
	{
		int i = x / 32;
		int j = x % 32;
		_bits[i] &= (~(1 << j));
	}


	bool Test(size_t x)
	{
		int i = x / 32;
		int j = x % 32;
		return (_bits[i] >> j) & 1;
	}

private:
	vector<int>_bits;
};

void test_BitSet()
{
	BitSet<-1>bits;
	bits.Set(1);
	bits.Set(2);
	cout << bits.Test(1) << endl;;
	bits.ReSet(1);
	cout << bits.Test(1) << endl;
}
int main()
{
	test_BitSet();
	return 0;
}