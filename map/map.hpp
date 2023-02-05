/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-hayy <ael-hayy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 11:02:49 by ael-hayy          #+#    #+#             */
/*   Updated: 2022/12/19 17:25:09 by ael-hayy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP1_HPP
#define MAP1_HPP

#include "../utiles/pair.hpp"
#include <memory>
#include <exception>
#include "map_iterator.hpp"



namespace	ft
{
template < class Key,
	class T,
	class Compare = std::less<Key>,
	class Alloc = std::allocator<ft::pair<const Key, T> >
	> class map
{


class t_node
{
public:
	friend class map;
	t_node(const ft::pair<const	Key, T>& v, t_node *par):val(v), left(nullptr), right(nullptr), parent(par), color(_RED) {}
	ft::pair<const	Key, T>	val;
	t_node   	*left;
	t_node		*right;
	t_node		*parent;
	bool    	color; 
};


public:
	typedef     				Key											key_type;
	typedef     				T											mapped_type;
	typedef						ft::pair<const	Key, T>						value_type;
	typedef						size_t										size_type;
	typedef	typename			std::ptrdiff_t								difference_type;
	typedef						Compare										key_compare;
	typedef						Alloc										allocator_type;
	typedef	typename			Alloc::reference							reference;
	typedef	typename			Alloc::const_reference						const_reference;
	typedef typename			Alloc::pointer								pointer;
	typedef	typename			Alloc::const_pointer						const_pointer;
	typedef						map_iterator<Key, T, t_node *>				iterator;
	// typedef						map_iterator<Key, T, rbtree*>				const_iterator;
	// typedef			reverse_iterator;
	// typedef			const_reverse_iterator;



	ft::pair<iterator, bool>	insert(const value_type& val)
	{
		// std::cout<<"i: "<<val.first<<"\n";
		ft::pair<t_node *, bool> to_return = __add_node_to_BST_returnIT(val);
		// if (!to_return.second){
		// 	std::cout<<"ss\n"; return (ft::pair<iterator, bool>(iterator(to_return.first), 0));}
		_size++;
		t_node	*node = to_return.first;
		// if (node->parent)
		// 	std::cout<<"........\n"<<node->color  << " ... " << node->parent->color<<"    "<<node->parent->val.first <<std::endl;
		while(node->color == _RED && node->parent->color == _RED)
		{
			if (__brother_color(node->parent) == _RED)
			{
					// std::cout<<"hrer 0     "<<node->parent->val.first<<"\n";
				t_node *tem = node->parent;
				tem->parent->color = _RED;
				tem->color = _BLACK;
				__get_brother(tem)->color = _BLACK;
				// std::cout<<"hrer 0     "<<__get_brother(tem)->val.first<<"\n";
				node = tem->parent;
				if (!node->parent)
					node->color = _BLACK;
			}
			else
			{
				bool	node_side = __get_node_side(node);
				if (node_side == __get_node_side(node->parent) && node_side == _LEFT)
				{
					// std::cout<<"hrer 1\n";
					node = __right_rotation(node->parent);
				}
				else if (node_side == __get_node_side(node->parent) && node_side == _RIGHT)
				{
					// std::cout<<"hrer 2\n";
					node = __left_rotation(node->parent);
				}
				else if (node_side == _RIGHT)
				{
					// std::cout<<"hrer 3\n";
					node = __angle_to_line_left_rotation(node->parent, node);
				}
				else
				{
					// std::cout<<"hrer 4\n";
					node = __angle_to_line_right_rotation(node->parent, node);
				}
			}
		}
		return (ft::pair<iterator, bool>(iterator(to_return.first), 1));
	}
	map(){_root = nullptr;}
	~map()
	{
		delete_map(_root);
	}
	void	p(t_node *node)
	{

		if ((!node->left && !node->right))
		{
		// std::cout<<": "<<node->val.first<<" "<<std::endl;
		return;
		}
		if (node->left)
		p(node->left);
		if (node->right)
		p(node->right);
	}
	void	print()
	{
		p(_root);
		
	}


private:


	typedef typename Alloc::template rebind<t_node>::other _node_allocator;
	// typedef typename _allocator::template rebind<Node>::other _node_allocator_type;
	t_node			*_root = nullptr;
	size_t			_size;
	Compare			_com;
	_node_allocator	_allocat;

	t_node	*__allocate_costruct_node(const value_type& v, t_node *par)
	{
		t_node	*saver = _allocat.allocate(sizeof(t_node));
		_allocat.construct(saver, t_node(v,par));
		return	(saver);
	}
	void	__destroy_deallocate_node(t_node *node)
	{
		_allocat.destroy(node);
		_allocat.deallocate(node, sizeof(t_node));
	}
	ft::pair<t_node *, bool>	__add_node_to_BST_returnIT(const value_type &val)
	{
		if (!_root)
		{
			_root = __allocate_costruct_node(val, 0);
			_root->color = _BLACK;
			return ft::pair<t_node *, bool>(_root, 1);
		}
		t_node	*tem  = _root;
		while (tem)
		{
			if (tem->val.first == val.first)
				return ft::pair<t_node *, bool>(tem, 0);
			if (!_com(tem->val.first, val.first))
			{
				// std::cout<<"less than "<<tem->val.first<<"    "<< val.first<<std::endl;
				if (!tem->left)
				{
					tem->left = __allocate_costruct_node(val, tem);
					return ft::pair<t_node *, bool>(tem->left, 1);
				}
				tem = tem->left;
			}
			else
			{
				// std::cout<<"grater than "<<tem->val.first<<"    "<< val.first<<std::endl;
				if (!tem->right)
				{
					tem->right = __allocate_costruct_node(val, tem);
					return ft::pair<t_node *, bool>(tem->right, 1);
				}
				tem = tem->right;
			}
		}
		std::cout<<"error on BST add node"<<std::endl;
		exit(1);
		return ft::pair<t_node *, bool>(0, 0);
	}

	bool	__is_it_balanced(t_node	*node)
	{
		if (!(node->parent) || node->color == _BLACK)
			return (true);
		if ((node->parent->color == _RED) && ((node->parent && node->parent->color == _RED) || \
			(node->left && node->left->color == _RED) || (node->right && node->right->color == _RED)))
			return (false);
		return (true);
	}

	bool	__get_node_side(t_node	*node)
	{
		if (node->parent && node->parent->left == node)
			return (_LEFT);
		return (_RIGHT);
	}

	t_node	*__angle_to_line_left_rotation(t_node *node, t_node *new_node) // anti-clockwise rotation and it will work when we have an angle and we want it to became a line so we can do left rotation
	{
		// std::cout<<"node: "<<node->val.first<<"  new_node: "<<new_node->val.first<<std::endl;
		node->right = new_node->left;
		if (node->right)
			node->right->parent = node;
		new_node->left = node;
		new_node->parent = node->parent;
		node->parent = new_node;
		if (new_node->parent)
			new_node->parent->left = new_node;
		return(__right_rotation(new_node));
	}
	t_node	*__angle_to_line_right_rotation(t_node *node, t_node *new_node) // mirror of __angle_to_line_left_rotation()
	{
		node->left = new_node->right;
		if (node->left)
			node->left->parent = node;
		new_node->right = node;
		new_node->parent = node->parent;
		node->parent = new_node;
		if (new_node->parent)
			new_node->parent->right = new_node;
		return(__left_rotation(new_node));
	}

	t_node	*__right_rotation(t_node *node) // right/clockwise rotaion
	{
		t_node	*gran_node =  node->parent;
		gran_node->left = node->right;
		if(node->right)
			node->right->parent = gran_node;
		node->parent = gran_node->parent;
		if (node->parent)
		{
			if(__get_node_side(gran_node) == _LEFT)
				node->parent->left = node;
			else
				node->parent->right = node;
		}
		node->right = gran_node;
		gran_node->parent = node;
		node->color = _BLACK;
		gran_node->color = _RED;
		if (_root == gran_node)
			_root = node;
		return (node);
	}
	t_node	*__left_rotation(t_node *node) // left/anti-clockwise rotaion    mirror of __right_rotation()
	{
		t_node	*gran_node =  node->parent;
		gran_node->right = node->left;
		if(node->left)
			node->left->parent = gran_node;
		// exit(0);
		node->parent = gran_node->parent;
		if (node->parent)
		{
			if(__get_node_side(gran_node) == _RIGHT)
				node->parent->right = node;
			else
				node->parent->left = node;
		}
		node->left = gran_node;
		gran_node->parent = node;
		node->color = _BLACK;
		gran_node->color = _RED;
		if (_root == gran_node)
			_root = node;
		return (node);
	}

	bool 	__brother_color(t_node* node)
	{
		if (__get_node_side(node) == _LEFT)
		{
			if (node->parent && node->parent->right && node->parent->right->color == _RED)
				return (_RED);
		}
		else
		{
			if (node->parent && node->parent->left && node->parent->left->color == _RED)
				return (_RED);
		}
		return (_BLACK);
	}

	t_node	*__get_brother(t_node *node)
	{
		if (__get_node_side(node) == _LEFT)
			return (node->parent->right);
		return (node->parent->left);
	}

void	delete_map(t_node *node)
{
	if (node->left)
		delete_map(node->left);
	if (node->right)
		delete_map(node->right);
	__destroy_deallocate_node(node);
}

};                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                        
}
#endif