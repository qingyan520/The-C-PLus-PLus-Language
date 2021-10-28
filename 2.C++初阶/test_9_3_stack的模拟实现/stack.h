#pragma once
#include<iostream>
#include<deque>
#include<vector>
#include<stack>
using namespace std;
namespace hello
{
    //该种写法为容器适配器的写法;
        template<class T, class Container = deque<T>>
        class stack

        {

        public:

            stack()
            {

            }

            void push(const T& x)
            {
                _c.push_back(x);
            }

            void pop()
            {
                _c.pop_back();
            }

            T& top()
            {
                return _c.back();
            }

            const T& top()const
            {
                return _c.back();
            }

            size_t size()const
            {
                return _c.size();
            }

            bool empty()const
            {
                return _c.empty();
            }

        private:

            Container _c;

        };


}
