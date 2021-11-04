#include<iostream>
#include"Int.h"
using namespace std;
void add(Int const& lhs, Int const& rhs, Int& ret)
{
	ret.setValue(lhs.getValue() + rhs.getValue());
}
void mul(Int const& lhs, Int const& rhs, Int& ret)
{
	ret.setValue(lhs.getValue() * rhs.getValue());
}