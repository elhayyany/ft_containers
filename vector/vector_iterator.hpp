/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_iterator.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-hayy <ael-hayy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/15 18:26:39 by ael-hayy          #+#    #+#             */
/*   Updated: 2023/03/06 13:32:03 by ael-hayy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef VECTOR_ITERATOR_HPP
#define VECTOR_ITERATOR_HPP
#include <iostream>

#include "../utiles/iterator_traits.hpp"
namespace ft
{
template <class it>
class vector_iterator
{
public:
	
	typedef	typename	ft::iterator_traits<it*>::value_type						value_type;
	typedef typename	ft::iterator_traits<it*>::pointer							pointer;
	typedef	typename	ft::iterator_traits<it*>::reference							reference;
	typedef				std::ptrdiff_t												difference_type;
	typedef	typename	std::random_access_iterator_tag								iterator_category;




	vector_iterator()
	{
		_ptr = NULL;
	}
	pointer base() const  {return _ptr;}
	template<class A> vector_iterator(const vector_iterator<A>& other)
	{
		_ptr = other.base();	
	}
	vector_iterator(pointer me)
	{
		_ptr = me;
	}
	~vector_iterator()
	{
	}
	vector_iterator& operator=(const vector_iterator& other)
	{
		_ptr = other._ptr;
		return (*this);
	}
	vector_iterator operator ++ (int)
	{
		vector_iterator tem;

		tem = *this;
		_ptr++;
		return tem;
	}
	vector_iterator& operator ++ ()
	{
		_ptr++;
		return (*this);
	}
	vector_iterator operator -- (int)
	{
		vector_iterator tem;

		tem = *this;
		_ptr--;
		return tem;
	}
	vector_iterator& operator -- ( )
	{
		_ptr--;
		return (*this);
	}
	vector_iterator operator - (difference_type a)
	{
		vector_iterator t(_ptr - a);
		return (t);
	}
	vector_iterator operator + (difference_type a)
	{
		vector_iterator t(_ptr + a);
		return (t);
	}

	template <class ii, class ittt> friend bool operator== (const vector_iterator<ii>& lhs, const vector_iterator<ittt>& rhs)
	{
		return (lhs.base() == rhs.base());
	}
	template <class itt> bool operator != (const vector_iterator<itt>& other)
	{
		return (_ptr != other.base());
	}
	difference_type operator - (const vector_iterator& other)
	{
		return (_ptr - other._ptr);
	}
	reference	operator * ()
	{
		return (*_ptr);
	}
	pointer	operator -> ()
	{
		return (_ptr);
	}
	template <class itt> bool operator < (const vector_iterator<itt>& other)
	{
		return (_ptr < other.base());
	}
	template <class itt> bool operator <= (const vector_iterator<itt>& other)
	{
		return (_ptr <= other.base());
	}
	template <class itt> bool operator > (const vector_iterator<itt>& other)
	{
		return (_ptr > other.base());
	}
	template <class itt> bool operator >= (const vector_iterator<itt>& other)
	{
		return (_ptr >= other.base());
	}
	void operator += (const difference_type a)
	{
		_ptr += a;
	}
	void operator -= (const difference_type a)
	{
		_ptr -= a;
	}
	reference operator [] (difference_type a)
	{
		return (*(_ptr + a));
	}
private:
	pointer		_ptr;
};
	template<typename T>
	vector_iterator<T> operator + (typename vector_iterator<T>::difference_type a, vector_iterator<T>& t )
	{
		vector_iterator<T> k(t + a);
		return (k);
	}
}


#endif