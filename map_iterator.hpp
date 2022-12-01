/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_iterator.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-hayy <ael-hayy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 11:15:52 by ael-hayy          #+#    #+#             */
/*   Updated: 2022/11/30 13:18:17 by ael-hayy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_ITERATOR_HPP
#define MAP_ITERATOR_HPP

#include <memory>
#include <exception>
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






template <class value_type>
struct rbtree
{
	rbtree(value_type v, bool co):val(v), color(co), left(nullptr), wright(nullptr) {}
	value_type	val;
	bool		color;
	rbtree		*left;
	rbtree		*wright;
	rbtree		*parent;
};

template <class _Tp, class _NodePtr, class _DiffType>
class	map_iterator
{

typedef		iterator_traits<it>::pointer			pointer;
typedef		iterator_traits<it>::value_type			value_type;
typedef		iterato_traits<it>::difference_type		difference_type;
typedef		iterator_traits<it>::reference			reference;
typedef		iterator_traits<it>::iterator_category	iterator_category;



private:	
	pointer	root;;
};
}
#endif