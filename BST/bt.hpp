#include <iostream>
#include <memory>


template <class T>
struct BT
{
	BT<T>  *left;
	BT<T>  *right;
	BT<T>  *parent;
	T   val;
	BT(T v): left(nullptr), right(nullptr), parent(nullptr), val(v){}
};



template <class T, class alloc = std::allocator<T> >
class BTs
{
public:
	BTs():_root(nullptr), _size(0) {}
	BT<T>	*insert(int data)
	{
		BT<T>	*node = _root;
		if (!_root)
		{
			_root = new BT<T>(data);
			return (_root);
		}
		while (true)
		{
			if (data < node->val)
			{
				if (!node->right)
				{
					node->right = new BT<T>(data);
					node->right->parent = node;
					break;
				}
				node = node->right;
			}
			else
			{
				if (!node->left)
				{
					node->left = new BT<T>(data);
					node->left->parent = node;
					break;
				}
				node = node->left;
			}
		}
		return _root;
	}

	BT<T> * search(T g)
	{
		BT<T> *a = _root;
		while(a)
		{
			if (a->val == g)
				return (a);
			if (a->val > g)
				a = a->right;
			else
				a = a->left;
		}
		return (NULL);
	}

	void	deletez(T data)
	{
		BT<int> *a = search(data);
		if (!a)
			return ;
		if (!a->left && !a->right)
		{
			if (a->parent)
			{
				if (a->parent->left == a) a->parent->left = nullptr;
				else a->parent->right = nullptr;
			}
			delete a;
		}
		else if (!a->left)
		{
			if (a->parent)
			{
				if (a->parent->left == a) a->parent->left = a->right;
				else a->parent->right = a->right;
			}
			delete a;
		}
		else if (!a->right)
		{
			if (a->parent)
			{	
				if (a->parent->left == a) a->parent->left = a->left;
				else a->parent->right = a->left;
			}
			delete a;
		}
		else
		{
			std::cout<<"first\n";
			BT<T> *node = get_last(a);
			node->left = a->left;
			node->right = a->right;
				std::cout<<"first "<<node->val<<std::endl;
			if (a->parent)
			{
				node->parent = a->parent;
				if
					(a->parent->left == a) a->parent->left = node;
				else
					a->parent->right = node;
			}
			else
				_root = node;
			delete a;
					
		}
	}

	BT<T>  *_root;
private:
	BT<T> *get_last(BT<T> *node)
	{
		while (node->left || node->right)
		{
			while(node->left)
				node = node->left;
			while(node->right)
				node = node->right;
		}
			
		if (node->parent && node->parent->left == node)
			node->parent->left = nullptr;
		else if (node->parent)
			node->parent->right = nullptr;
		return node;
	}
	int _size;
};