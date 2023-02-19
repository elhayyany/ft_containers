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








template <class key, class T, class _NodePtr>
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
		if (__get_node_side(_root) == _LEFT || !_root->parent)
		{
			_root_tem = _root;
			if (_root->right)
				_root = _get_left(_root->right);
			if (_root == _root_tem)
				_root = _root->parent;
			_root_tem = _root;
			return (*this);
		}
		else if (_root->parent)
		{
			_root_tem = _root;
			while (__get_node_side(_root) == _RIGHT && _root->parent)
				_root = _root->parent;
			if (!_root->parent)
			{
				// _root_tem = _get_right(_root);
				_root = nullptr;
			std::cout<<"++ "<<_root_tem->val.first<<std::endl;
				return (*this);
			}
			_root = _root->parent;
			_root_tem = _root;
			return (*this);
		}

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
		// std::cout<<_root_tem<<std::endl;exit(0);
		if (!_root)
		{
			_root = _root_tem;
			return (*this);
		}
		_root_tem = _root; 
		// std::cout<<_root->val.first<<std::endl;
		// std::cout<<_root->left->val.first<<std::endl;
		// std::cout<<_root->right<<std::endl;
		// exit(0);
		if (__get_node_side(_root) == _RIGHT || !_root->parent)
		{
			if (_root->left)
			{
				_root = _get_right(_root->left);
				return (*this);
			}
			if (_root == _root_tem)
					_root = _root->parent;
			
			return (*this);
		}
		else if (__get_node_side(_root) == _LEFT && !_root->left)
		{
			// exit(0);
			while (__get_node_side(_root) == _LEFT)
				_root = _root->parent;
			// if (_root)
			// 	_root = _root->parent;
			return (*this);
		}

		_root = _root->left;
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

	const ft::pair<key, T>	operator*()  { return (_root->val); }
	const ft::pair<key, T>	operator->() { return ((_root->val)); }

private:
	_NodePtr	_root;
	_NodePtr	_root_tem;
	_NodePtr	_base;
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