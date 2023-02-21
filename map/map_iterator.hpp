/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_iterator.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-hayy <ael-hayy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 11:15:52 by ael-hayy          #+#    #+#             */
/*   Updated: 2022/12/21 10:22:01 by ael-hayy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_ITERATOR_HPP
#define MAP_ITERATOR_HPP

#include <memory>
#include <exception>
#include "map.hpp"
namespace ft
{




//! /////////////////////////////////???////////////?????????????








template <class key, class T, class _NodePtr, class Compare>
class	map_iterator
{


public:
	typedef		typename iterator_traits<_NodePtr>::pointer				pointer;
	typedef		typename iterator_traits<_NodePtr>::value_type			value_type;
	typedef		typename iterator_traits<_NodePtr>::difference_type		difference_type;
	typedef		typename iterator_traits<_NodePtr>::reference			reference;
	typedef 	std::bidirectional_iterator_tag							iterator_category;


	map_iterator(): _root(nullptr), _root_tem(nullptr), _base(nullptr) {}
	map_iterator(_NodePtr node): _root(node), _root_tem(node), _base(node) {_root = _get_left(_root);}
	map_iterator(_NodePtr node, bool i): _root(node), _root_tem(node), _base(node) {i = false;}
	map_iterator(const map_iterator& it) : _root(it._root), _root_tem(it._root), _base(it._base) {}
	map_iterator&	operator=(const map_iterator& it) 
	{
		_base = it._base;
		_root = it._root;
		_root_tem = _root;
		return *(this);	
	}


	map_iterator& operator++()
	{

		// if (comp(_root->val.first, _root->parent->val.first))
		// {
			// std::cout<<"not statment. the first one is _root:"<<_root->val.first<<"  the second one is parent:"<<_root->parent->val.first<<std::endl;
		// }
		// else
		// {
			// std::cout<<"yes statment. the first one is _root:"<<_root->val.first<<"  the second one is parent:"<<_root->parent->val.first<<std::endl;
		// }
		// exit(0);
		// if (_root)
		// std::cout<<"++ operator: "<<_root->val.first<<std::endl;
		_root_tem = _root;
		if (_root && _root->right)
			_root = _get_left(_root->right);
		else if (_root)
		{
			// std::cout<<"here   "<<_root->val.first<<std::endl;;
			_NodePtr	tem = _root;
			_root = _root->parent;
			while (_root && comp(_root->val.first, tem->val.first))
			{
				// std::cout<<"wile: "<<_root->val.first<<std::endl;
				_root = _root->parent;
				
			}
			// std::cout<<";;;   "<<_root->val.first<<std::endl;}
		}
		// if (_root)
		// std::cout<<"++ enf `operator: "<<_root->val.first<<std::endl;
		return (*this);
	}

	map_iterator operator++(int)
	{
		map_iterator	tem = *this;
		++(*this);
		return (tem);
	}

	map_iterator& operator--()
	{
		if (_root && _root->left)
			_root = _get_right(_root->left);
		else if (_root)
		{
			_NodePtr	tem = _root;
			_root = _root->parent;
			while (_root && !comp(_root->val.first, tem->val.first))
			{
				_root = _root->parent;
			}
		}
		else
			_root = _root_tem->parent;;
		_root_tem = _root;
		return (*this);
	}
	map_iterator operator--(int)
	{
		map_iterator	tem = *this;
		--(*this);
		return (tem);
	}

	_NodePtr base(){return (_root);}

	bool	operator==(const map_iterator& it) {return (_root == it._root);}
	bool	operator!=(const map_iterator& it) {return (_root != it._root);}

	ft::pair<const key, T>	operator*()  { return (_root->val); }
	ft::pair<const key, T>*	operator->() { return (&(_root->val)); }

private:
	_NodePtr	_root;
	_NodePtr	_root_tem;
	_NodePtr	_base;
	Compare		comp;
	pointer	_get_left(const pointer& it) const
	{
		pointer	tem = it;
		while(tem && tem->left)
			tem = tem->left;
		return (tem);
	}
	pointer	_get_right(const pointer& it) const
	{
		pointer	tem = it;
		while(tem && tem->right)
			tem = tem->right;
		return (tem);
	}
	bool	__get_node_side(_NodePtr	node)
	{
		if (node && node->parent && node->parent->left == node)
			return (_LEFT);
		return (_RIGHT);
	}
};
}
#endif