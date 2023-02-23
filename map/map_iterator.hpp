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

#include "map_reverse_iterator.hpp"
// #include "m÷ap.hpp"
#include "../utiles/pair.hpp"
#include "../utiles/iterator_traits.hpp"
namespace ft
{




//! /////////////////////////////////???////////////?????????????




// template< class T >
// struct iterator_traits
// {
// 	typedef typename T::iterator_category			 	iterator_category;
// 	typedef typename T::value_type						value_type;
// 	typedef typename T::difference_type			 		difference_type;
// 	typedef typename T::pointer							pointer;
// 	typedef typename T::reference						reference;
	
// };
// template< class T >
// struct iterator_traits<T*>
// {
// 	typedef std::bidirectional_iterator_tag 			iterator_category;
// 	typedef T                          					value_type;
// 	typedef std::ptrdiff_t                  			difference_type;
// 	typedef T*                         					pointer;
// 	typedef T&                         					reference;
// };
// template< class T >
// struct iterator_traits<const T*>
// {
// 	typedef std::bidirectional_iterator_tag 			iterator_category;
// 	typedef T                          					value_type;
// 	typedef std::ptrdiff_t                  			difference_type;
// 	typedef const	T*                         			pointer;
// 	typedef const	T&                         			reference;

// };




template <class key, class T, class _NodePtr, class Compare>
class	map_iterator
{


public:
	typedef		typename ft::iterator_traits<_NodePtr>::pointer				pointer;
	typedef		typename ft::iterator_traits<_NodePtr>::value_type			value_type;
	typedef		typename ft::iterator_traits<_NodePtr>::difference_type		difference_type;
	typedef		typename ft::iterator_traits<_NodePtr>::reference			reference;
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
		_root_tem = _root;
		if (_root && _root->right)
			_root = _get_left(_root->right);
		else if (_root)
		{
			_NodePtr	tem = _root;
			_root = _root->parent;
			while (_root && comp(_root->val.first, tem->val.first))
				_root = _root->parent;
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

	ft::pair<const key, T>&	operator*()  { return ((this->_root->val)); }
	ft::pair<const key, T>*	operator->() { return (&(this->_root->val)); }

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