/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-hayy <ael-hayy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 12:00:07 by ael-hayy          #+#    #+#             */
/*   Updated: 2022/10/28 10:56:31 by ael-hayy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef VECTOR_HPP
#define VECTOR_HPP

#include <memory>
#include <exception>
#include "vector_iterator.hpp"
namespace ft
{
template< class T, class Allocator = std::allocator<T> > 
class vector
{
private:

public:
	typedef				T									value_type;
	typedef				Allocator							allocator_type;
	typedef	typename	allocator_type::reference			reference;
	typedef typename	allocator_type::const_reference		const_reference;
	typedef typename	allocator_type::pointer				pointer;
    typedef typename	allocator_type::const_pointer		const_pointer;
	typedef typename	allocator_type::size_type			size_type;
	typedef typename	allocator_type::difference_type		difference_type;
	typedef				vector_iterator<pointer>			iterator;	

private:
size_type		_size;
size_type		_capacity;
pointer			_arr;
allocator_type	_allocator;

void	destroy(pointer _to_destroy, size_type count)
{
	for(size_t i = 0; i < count; i++)
		_allocator.destroy(_to_destroy + i);
}
void	construct(pointer _to_construct, size_type count, const_reference value)
{
	for(size_t i = 0; i < count; i++)
		_allocator.construct(_to_construct + i, value);
}
void	construct(pointer _to_construct, size_type count, pointer value)
{
	for(size_t i = 0; i < count; i++)
		_allocator.construct(_to_construct + i, *(value + i));
}
public:

	// Iterator


	iterator begin()
	{
		iterator oo(_arr);
		return oo;
	}
	// const_iterator begin() const
	// {
	// 	return (iterator(pointer));
	// }


	// Member functions !!!


	explicit vector():_size(0), _capacity(0), _arr(0), _allocator(allocator_type()) {};
	explicit vector( size_type count, const T& value = T(), const Allocator& alloc = Allocator()): _allocator(alloc)
	{
		if (count > _allocator.max_size())
			throw std::length_error("vector");
		_arr = _allocator.allocate(count);
		construct(_arr, count, value);
		_size = count;
		_capacity = count;
	}

	vector( const vector& other )
	{
		_arr = _allocator.allocate(other._size);
		construct(_arr, other._size, other._arr);
		_size = other._size;
		_capacity = other._size;
	}
	// template< class InputIt > vector( InputIt first, InputIt last, const Allocator& alloc = Allocator() ): _allocator(alloc)
	// {

	// }
	~vector()
	{
		if (_arr)
		{
			destroy(_arr, _size);
			_allocator.deallocate(_arr, _capacity);
		}
	}
	vector& operator=( const vector& other )
	{
		destroy(_arr, _size);
		if (_arr && _capacity < other._size)
		{
			_allocator.diallocate(_arr, _size);
			_capacity = other._size;
			_arr = 0;
		}
		if (!_arr)
			_arr = _allocator.allocatte(other._size);
		construct(_arr, other._size, other._arr);
		_size = other._size;
		return (*this);
	}
	void assign( size_type count, const T& value )
	{
		if (count > _allocator.max_size())
			throw std::length_error("vector");
		destroy(_arr, _size);
		if (_capacity < count)
		{
			_arr = _allocator.allocate(count);
			_capacity = count;
		}
		construct(_arr, count, value);
		_size = count;
	}
	allocator_type get_allocator() const {return (_allocator);};


	// Element access


	reference at( size_type pos )
	{
		if (pos >= _size )
			throw std::out_of_range("vector");
		return (*(_arr + pos));
	}
	const_reference at( size_type pos ) const
	{
		if (pos >= _size)
			throw std::out_of_range("vector");
		return (*(_arr + pos));
	}
	reference operator[]( size_type pos )
	{
		return (*(_arr + pos));
	}
	const_reference operator[]( size_type pos ) const
	{
		return (*(_arr + pos));
	}
	reference back() {return (*(_arr + _size - 1));}
	const_reference back() const {return (*(_arr + _size - 1));}
	reference	front() {return (*_arr);}
	const_reference front() const {return (*_arr);}



	//! Capacity


	bool empty() const {return (!_size);}
	size_type size() const {return (_size);}
	size_type max_size() const {return (_allocator.max_size());}
	size_type capacity() const {return (_capacity);}
	void resize(size_type sz, T c = T());
	void reserve(size_type n);

	//Modifiersgit 


	void clear()
	{
		destroy(_arr, _size);
		_size = 0;
	}
	void push_back(const T& x);
	void pop_back();
	iterator insert(iterator position, const T& x);
	void insert(iterator position, size_type n, const T& x);
	template <class InputIterator> void insert(iterator position, InputIterator first, InputIterator last);
	iterator erase(iterator position);
	iterator erase(iterator first, iterator last);
	void swap(vector<T,Allocator>&);

};
	
	template <class T, class Allocator> bool operator==(const vector<T,Allocator>& x,
	const vector<T,Allocator>& y);
	template <class T, class Allocator> bool operator< (const vector<T,Allocator>& x, const vector<T,Allocator>& y);
	template <class T, class Allocator> bool operator!=(const vector<T,Allocator>& x, const vector<T,Allocator>& y);
	template <class T, class Allocator> bool operator> (const vector<T,Allocator>& x, const vector<T,Allocator>& y);
	template <class T, class Allocator> bool operator>=(const vector<T,Allocator>& x, const vector<T,Allocator>& y);
	template <class T, class Allocator> bool operator<=(const vector<T,Allocator>& x, const vector<T,Allocator>& y);
	// specialized algorithms:
	template <class T, class Allocator> void swap(vector<T,Allocator>& x, vector<T,Allocator>& y);
}

#endif


