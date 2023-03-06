/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_iterator.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-hayy <ael-hayy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 11:15:52 by ael-hayy          #+#    #+#             */
/*   Updated: 2023/03/06 16:47:23 by ael-hayy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SET_ITERATOR_HPP
#define SET_ITERATOR_HPP

#include "../utiles/reverse_iterator.hpp"
#include "../utiles/pair.hpp"

namespace ft
{




//! /////////////////////////////////???////////////?????????????




template <class key, class _NodePtr, class Compare>
class	set_iterator
{


public:
	typedef		typename ft::iterator_traits<key*>::pointer				pointer;
	typedef		typename ft::iterator_traits<key*>::value_type				value_type;
	typedef		typename ft::iterator_traits<key*>::difference_type		difference_type;
	typedef		typename ft::iterator_traits<key*>::reference			reference;
	typedef 	std::bidirectional_iterator_tag								iterator_category;


	set_iterator(): _root(NULL), _root_tem(NULL) {}
	set_iterator(const _NodePtr node) {_root = _get_left(node); _root_tem = _root;}
	set_iterator(_NodePtr node, bool i): _root(node), _root_tem(node) {i = false;}
	template<class A, class C, class D> set_iterator(const set_iterator<A, C, D>& it) : _root(it.base()), _root_tem(it.base_tem()) {}
	template<class A, class C, class D> set_iterator<key, _NodePtr, Compare>&	operator=(const set_iterator<A, C, D>& it)
	{
		_root = it.base();
		_root_tem = it.base_tem();
		return (*this);	
	}


	set_iterator& operator++()
	{
		_root_tem = _root;
		if (_root && _root->right)
			_root = _get_left(_root->right);
		else if (_root)
		{
			_NodePtr	tem = _root;
			_root = _root->parent;
			while (_root && comp(*_root->val, *tem->val))
				_root = _root->parent;
		}
		return (*this);
	}

	set_iterator operator++(int)
	{
		set_iterator	tem = *this;
		++(*this);
		return (tem);
	}

	set_iterator& operator--()
	{
		if (_root && _root->left)
			_root = _get_right(_root->left);
		else if (_root)
		{
			_NodePtr	tem = _root;
			_root = _root->parent;
			while (_root && !comp(*_root->val, *tem->val))
				_root = _root->parent;
		}
		else
			_root = _root_tem;
		_root_tem = _root;
		return (*this);
	}
	set_iterator operator--(int)
	{
		set_iterator	tem = *this;
		--(*this);
		return (tem);
	}

	const _NodePtr base() const {return (_root);}
	const _NodePtr base_tem() const {return (_root_tem);}

	reference	operator*()  { return ((*_root->val)); }
	pointer		operator->() { return (_root->val); }

	template <class iter> bool operator == (const iter& ti)  const {return (this->_root == ti.base());}
	template <class iter> bool operator != (const iter& ti)  const {return (this->_root != ti.base());}


protected:
	_NodePtr	_root;
	_NodePtr	_root_tem;
	Compare		comp;
	_NodePtr	_get_left(const _NodePtr& it) const
	{
		_NodePtr	tem = it;
		while(tem && tem->left)
			tem = tem->left;
		return (tem);
	}
	_NodePtr	_get_right(const _NodePtr& it) const
	{
		_NodePtr	tem = it;
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







