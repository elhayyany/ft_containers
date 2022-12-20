/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   red_black_tree.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-hayy <ael-hayy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 11:35:03 by ael-hayy          #+#    #+#             */
/*   Updated: 2022/12/20 14:17:34 by ael-hayy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RED_BLACK_TREE_H
#define RED_BLACK_TREE_H
#include <memory>
#include "pair.hpp"




template <class T, class Key, class Alloc = std::allocator<T>, class Compare = std::less<Key> >
class rbtree
{
private:
	class t_node
	{
	private:
		Alloc _alloc;
	public:
		friend class rbtree;
	    t_node(const T& v,t_node *par, bool col = _RED): left(nullptr), right(nullptr), parent(par), color(col)
	    {
	        val = _alloc.allocate(1);
			_alloc.construct(val, v);
	    }
	    ~t_node()
	    {
	        _alloc.destroy(val);
			_alloc.deallocate(val, 1);
	    }
	    T       *val;
	    t_node   *left;
	    t_node   *right;
	    t_node   *parent;
	    bool    color;
	};

	t_node      *_root;
	size_t      _size;
	Compare		_com;

public:
	typedef    T   value_type;
	//* ...................... PRIINT .................

	    rbtree():_root(nullptr), _size(0) {};
	    ~rbtree() {}


	//* ...................... INSERT .................

	ft::pair<t_node*, bool> insert( const value_type& value )
	{
	    t_node *node = _root;
	    t_node *new_node = nullptr;
		if (!_root && ++_size)
			_root = _make_node(value,nullptr, _BLACK);
		else
		{
			while (1)
			{
				if (node->val->first == value.first)
				{
					std::cout<<"the same: "<<node->val->first<<" and "<<value.first<<std::endl;
					return (ft::pair<t_node*, bool>(node, 0));
				}
				else if (_com(value.first, node->val->first))
				{
					if (node->left)
						node = node->left;
					else
					{
						node->left = _make_node(value,node, _RED);
						new_node = node->left;
						_size++;
						std::cout<<"new node "<<node->left->val->first<<"\n";
						break;
					}
				}
				else
				{
					if (node->right)
						node = node->right;
					else
					{
						node->right = _make_node(value,node, _RED);
						new_node = node->right;
						std::cout<<"new node "<<node->right->val->first<<"\n";
						_size++;
						break;
					}
				}

			}
			if (node->color != _BLACK)
			{
				while (_not_balanced(node))
				{
					std::cout<<"not balaced"<<std::endl;
					if (_sib_color(node) == _BLACK)
					{
						if (_get_side(node) == _get_side(new_node) && _get_side(new_node) == _LEFT)
						{
							std::cout<<std::endl<<"L_L"<<std::endl;
							node = __L_L__rotation(node, node->parent);
						}
						else if (_get_side(node) == _get_side(new_node) && _get_side(new_node) == _RIGHT)
						{
							std::cout<<std::endl<<"R_R"<<std::endl;
							node = __R_R__rotation(node, node->parent);
						}
						else if (_get_side(node) != _get_side(new_node) && _get_side(new_node) == _RIGHT)
						{
							std::cout<<std::endl<<"L_R"<<std::endl;
							node = __L_R__rotation(node, node->parent);
						}
						else if (_get_side(node) != _get_side(new_node) && _get_side(new_node) == _LEFT)
						{
							std::cout<<std::endl<<"R_L"<<std::endl;
							node = __R_L__rotation(node, node->parent);
						}
						else
							std::cout<<"3wrtihaaaa"<<std::endl;
					}
					else
					{
						std::cout<<"recoloring \n";
						if (node->parent->parent)
							node->parent->color = _RED;
						node->color = _BLACK;
						// new_node->color = _BLACK;÷
						if (_get_sib(node))
							_get_sib(node)->color = _BLACK;
					}
				}
			}
			_root = _get__root(node);
		}
		print(_root);
		return (ft::pair<t_node*, bool>(new_node, 1));
	}

	//* ...................... SERCG .................

	t_node  *serch(const value_type& val)
	{
	    t_node *tem = _root;
	    while (tem)
	    {
	        if (tem->val->first == val.first)
	            return (tem);
	        else if (_com(val.first, tem->val->first))
	            tem = tem->left;
	        else
	            tem = tem->right;
	    }
	    return tem;   
	}

	//* ...................... DELETE .................

	void	delete_node(t_node	*node)
	{
		if (!node->left && !node->right)
		{
			if (node->parent)
			{	
				if (_get_side(node) == _LEFT)
					node->parent->left = nullptr;
				else
					node->parent->right = nullptr;
			}
			delete node;
		}
		else if (!node->right || !node->left)
		{
			t_node	*tem = node->left ? node->left : node->right;
			if (node->parent)
			{
				if (_get_side(node) == _LEFT)
					node->parent->left = tem;
				else
					node->parent->right = tem;
			}
			else
				_root = tem;
			tem->parent = node->parent;
			delete node;
		}
		else
		{
			t_node	*tem = get_left(node);
			node->val = node
		}
	}

	//!.................................................................
private: 
	bool	_sib_color(t_node *node)
	{
		if (_get_side(node) == _LEFT)
		{
			if (node->parent->right)
				return (node->parent->right->color);
		}
		else if (node->parent->left)
			return (node->parent->left->color);
		return (_BLACK);
	}
	t_node	*_get_sib(t_node *node)
	{
		if (node->parent)
		{
			return (_get_side(node)? node->parent->left : node->parent->right);
		}
		return (nullptr);
	}
	t_node	*__L_L__rotation(t_node	*node, t_node *nod_parent)
	{
	    bool siide = _get_side(nod_parent);
		nod_parent->left = node->right;
		node->right = nod_parent;
		node->parent = nod_parent->parent;
		nod_parent->parent = node;
		if (node->parent)
		{
			if (siide == _LEFT)
				node->parent->left = node;
			else
				node->parent->right = node;
		}
		node->color = _BLACK;
		nod_parent->color = _RED;
		return (node);
	}
	t_node *__R_R__rotation(t_node *node, t_node *nod_parent)
	{
	    bool siide = _get_side(nod_parent);
		nod_parent->right = node->left;
		node->left = nod_parent;
		node->parent = nod_parent->parent;
		nod_parent->parent = node;
		if (node->parent)
		{
			if (siide == _LEFT)
	        {
	            std::cout<<"scgcisch\n";
				node->parent->left = node;
	        }
			else
	        {
				std::cout<<"-------\n";
				node->parent->right = node;
	        }
		}
		node->color = _BLACK;
		nod_parent->color = _RED;
		return (node);
	}
	t_node *__R_L__rotation(t_node *node, t_node *nod_parent)
	{
		t_node	*new_node = node->left;
		new_node->right = node;
		node->left = nullptr;
		new_node->parent = nod_parent;
		node->parent = new_node;
		nod_parent->right = new_node;
		return (__R_R__rotation(new_node, new_node->parent));
	}
	t_node *__L_R__rotation(t_node *node, t_node *nod_parent)
	{
		t_node	*new_node = node->right;
		new_node->left = node;
		node->right = nullptr;
		new_node->parent = nod_parent;
		node->parent = new_node;
		nod_parent->left = new_node;
		return (__L_L__rotation(new_node, new_node->parent));
	}
	bool	_not_balanced(t_node *node)
	{
		if (node->color == _RED && node->left && node->left->color == _RED)
			return (1);
		if (node->color == _RED && node->right && node->right->color == _RED)
			return (1);
		if (node->color == _RED && node->parent && node->parent->color == _RED)
			return (1);
		return (0);
	}
	t_node *_get__root(t_node *node)
	{
		while(node->parent)
			node = node->parent;
		return (node);
	}
	void clear_node(t_node* node)
	{
		if (!node)
			return ;
		clear_node(node->left);
		clear_node(node->right);
		delete node;
	}
	bool _get_side(t_node *node)
	{
		if (node->parent && node->parent->left == node)
	        return (_RIGHT);
	    return (_LEFT);
	}
	t_node	*get_left(t_node *node)
	{
		while(node->left)
			node = node->left;
		return (node);
	}
	void	print(t_node *node)
	{
		if (!node)
				return ;
		print(node->left);
		std::cout<<node->val->first <<"\t";
		print(node->right);
	}
	t_node    *_make_node(const T& val,t_node *parent = nullptr, bool color = _RED)
	{
	    return (new t_node(val,  parent, color));
	}

};


#endif

 