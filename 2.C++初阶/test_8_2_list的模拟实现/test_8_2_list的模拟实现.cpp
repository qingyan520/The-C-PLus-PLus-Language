#include<iostream>
using namespace std;
namespace hello
{
	template<class T>
	struct _list_node
	{
		T _val;
		_list_node<T>* _next;
		_list_node<T>* prev;


		_list_node(const T& val = T())
			:val(val),
			prev(nullptr),
			_next(nullptr)
		{

		}
	};

	template<class T,class Ref,class Ptr>
	struct _list_iterator
	{
		typedef _list_node<T> node;
		typedef _list_node<T, Ref, Ptr> self;
		node* _pnode;
		_list_iterator(node* pnode):
			_pnode(pnode)
		{

		}

		Ref operator*()
		{
			return _pnode->_val;
		}

		bool operator==(const self& s) const
		{
			return _pnode == s._pnode;
		}

		self& operator++()
		{
			_pnode = _pnode->_next;

			return *this;
		}

		self &operator--()
		{
			_pnode = _pnode->prev;
			return *this;
		}

		self operator--(int)
		{
			self tmp(*this);
			_pnode = _pnode->prev;
			return tmp;
		}

	};


	template<class T>
	class list
	{
		typedef _list_node<T> node;

	public:

		typedef _list_iterator<T, T&, T*> iterator;
		typedef _list_iterator<T, const T&, const T*> const_iterator;



		list()
		{
			_head = new node;
			_head->_next = _head;
			_head->prev = _head;
		}

		iterator begin()
		{
			return iterator(_head->_next);
		}

		const_iterator begin() const
		{
			return const_iterator(_head->_next);
		}

		iterator end()
		{
			return iterator(_head->prev);
		}

		const_iterator end()const
		{
			return const_iterator(_head->prev);
		}

		void push_back(const T& x)
		{
			node* newnode = new node(x);
			node* tail = _head->prev;
			tail->_next =newnode;
			newnode->prev = tail;
			newnode->_next = _head;
			_head->prev = tail;
			
		}
	private:
		node* _head;
	};


	
}
int main()
{

	return 0;
}
