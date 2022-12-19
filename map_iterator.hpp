/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_iterator.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-hayy <ael-hayy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 11:15:52 by ael-hayy          #+#    #+#             */
/*   Updated: 2022/12/19 10:49:50 by ael-hayy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_ITERATOR_HPP
#define MAP_ITERATOR_HPP

#include <memory>
#include <exception>
#include "map.hpp"
namespace
{

template< class T >
struct iterator_traits
{
	typedef typename T::iterator_category			 	iterator_category;
	typedef typename T::value_type						value_type;
	typedef typename T::difference_type			 		difference_type;
	typedef typename T::pointer							pointer;
	typedef typename T::reference						reference;
	
};
template< class T >
struct iterator_traits<T*>
{
	typedef std::bidirectional_iterator_tag 			iterator_category;
	typedef T                          					value_type;
	typedef std::ptrdiff_t                  			difference_type;
	typedef T*                         					pointer;
	typedef T&                         					reference;
};
template< class T >
struct iterator_traits<const T*>
{
	typedef std::bidirectional_iterator_tag 			iterator_category;
	typedef T                          					value_type;
	typedef std::ptrdiff_t                  			difference_type;
	typedef const	T*                         			pointer;
	typedef const	T&                         			reference;

};



//! /////////////////////////////////???////////////?????????????








template <class key, class T, class _NodePtr>
class	map_iterator
{

typedef		typename iterator_traits<_NodePtr>::pointer				pointer;
typedef		typename iterator_traits<_NodePtr>::value_type			value_type;
typedef		typename iterator_traits<_NodePtr>::difference_type		difference_type;
typedef		typename iterator_traits<_NodePtr>::reference			reference;
typedef		typename iterator_traits<_NodePtr>::iterator_category	iterator_category;


map_iterator(): _root(nullptr), _root_tem(nullptr) {}
map_iterator(map_iterator& it) : _root(it._root), _root_tem(it._root)
{
	_root = _get_left(_root);
}
map_iterator&	operator=(const map_iterator& it) {_root = it._root; _root_tem = _root;}



map_iterator& operator++()
{
	if (_root->parent && _root->parent->right)
	{
		_root = _get_left(_root->parent->right);
	}
	else if (_root->parent)
		_root = _root->parent;
	else 
	{
		_root_tem = _root;
		_root = nullptr;
	}
	return (*this);
}
map_iterator operator++(int);

map_iterator& operator--()
{
	if (_root->parent && _root->parent->left)
	{
		_root = _get_right(_root->parent->left);
	}
	else if (_root->parent)
		_root = _root->parent;
	else 
	{
		_root_tem = _root;
		_root = nullptr;
	}
	return (*this);
}
map_iterator operator--(int);



bool	operator==(map_iterator& it) {return (_root == it._root);}
bool	operator!=(map_iterator& it) {return (_root != it._root);}

value_type&	operator*()  { return (_root->val); }
value_type&	operator->() { return (_root->val); }


private:	
	pointer	_root;
	pointer	_root_tem;
	pointer	_get_left(pointer& it)
	{
		while(it && it->left)
			it = it.left;
		return (it);
	}
	pointer	_get_right(pointer& it)
	{
		while(it && it->right)
			it = it.right;
		return (it);
	}
};
}
#endif