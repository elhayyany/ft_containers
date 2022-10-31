/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_reverse_iterator.hpp                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-hayy <ael-hayy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 09:32:06 by ael-hayy          #+#    #+#             */
/*   Updated: 2022/10/31 10:23:30 by ael-hayy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef VECTOR_REVERSE_ITERATOR_HPP
#define VECTOR_REVERSE_ITERATOR_HPP
#include "vector_iterator_traits.hpp"
namespace ft
{
template <class it>
class vector_reverse_iterator
{
public:
	typedef	typename	ft::iterator_traits<it>::value_type							value_type;
	typedef typename	ft::iterator_traits<it>::pointer							pointer;
	typedef	typename	ft::iterator_traits<it>::reference							reference;
	typedef				std::ptrdiff_t												difference_type;
	typedef	typename	std::random_access_iterator_tag								iterator_category;




	vector_reverse_iterator()
	{
		_ptr = nullptr;
	}
	vector_reverse_iterator(const vector_reverse_iterator& other)
	{
		_ptr = other._ptr;	
	}
	vector_reverse_iterator(pointer me)
	{
		_ptr = me;
	}
	~vector_reverse_iterator()
	{
	}
	vector_reverse_iterator& operator = (const vector_reverse_iterator& other)
	{
		_ptr = other._ptr;
		return (*this);
	}
	vector_reverse_iterator operator ++ (int)
	{
		vector_reverse_iterator tem;

		tem = *this;
		_ptr--;
		return tem;
	}
	vector_reverse_iterator& operator ++ ()
	{
		_ptr--;
		return (*this);
	}
	vector_reverse_iterator operator -- (int)
	{
		vector_reverse_iterator tem;

		tem = *this;
		_ptr++;
		return tem;
	}
	vector_reverse_iterator& operator -- ( )
	{
		_ptr++;
		return (*this);
	}
	vector_reverse_iterator operator - (difference_type a)
	{
		vector_reverse_iterator t(_ptr - a);
		return (t);
	}
	vector_reverse_iterator operator - (vector_reverse_iterator& other)
	{
		
		vector_reverse_iterator t(_ptr - other._ptr);
		return (t);
	}
	vector_reverse_iterator operator + (difference_type a)
	{
		vector_reverse_iterator t(_ptr + a);
		return (t);
	}

	bool operator == (const vector_reverse_iterator& other)
	{
		return (_ptr == other._ptr);
	}
	vector_reverse_iterator& operator - (const vector_reverse_iterator& other)
	{
		return (_ptr - other._ptr);
	}
	reference	operator * ()
	{
		return (*_ptr);
	}
	bool operator < (const vector_reverse_iterator& other)
	{
		return (_ptr < other._ptr);
	}
	bool operator <= (const vector_reverse_iterator& other)
	{
		return (_ptr <= other._ptr);
	}
	bool operator > (const vector_reverse_iterator& other)
	{
		return (_ptr > other._ptr);
	}
	bool operator >= (const vector_reverse_iterator& other)
	{
		return (_ptr >= other._ptr);
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
	vector_reverse_iterator<T> operator + (typename vector_reverse_iterator<T>::difference_type a, vector_reverse_iterator<T>& t )
	{
		vector_reverse_iterator<T> k(t + a);
		return (t);
	}
}





#endif