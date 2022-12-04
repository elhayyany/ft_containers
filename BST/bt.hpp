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
					break;
				}
				node = node->right;
			}
			else
			{
				if (!node->left)
				{
					node->left = new BT<T>(data);
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
		if (!a->left && !a->right)
		{
			if (a->parent)
				if (a->parent->left == a) a->parent->left = nullptr;
				else a->parent->right = nullptr;
			delete a;
		}
		else if (!a->left)
		{
			if (a->parent->left == a) a->parent->left = a->right;
			else a->parent->right = a->right;
			delete a;
		}
		else if (!a->right)
		{
			if (a->parent->left == a) a->parent->left = a->left;
			else a->parent->right = a->left;
			delete a;
		}
		else
		{
			
		}
	}

	BT<T>  *_root;
private:
	int _size;
};