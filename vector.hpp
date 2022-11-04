/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-hayy <ael-hayy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 12:00:07 by ael-hayy          #+#    #+#             */
/*   Updated: 2022/11/03 15:06:19 by ael-hayy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef VECTOR_HPP
#define VECTOR_HPP

#include <memory>
#include <exception>
#include "vector_iterator.hpp"
#include "vector_reverse_iterator.hpp"
#include "is_integral.hpp"
namespace ft
{
template< class T, class Allocator = std::allocator<T> > 
class vector
{

public:
	typedef				T											value_type;
	typedef				Allocator									allocator_type;
	typedef	typename	allocator_type::reference					reference;
	typedef typename	allocator_type::const_reference				const_reference;
	typedef typename	allocator_type::pointer						pointer;
    typedef typename	allocator_type::const_pointer				const_pointer;
	typedef typename	allocator_type::size_type					size_type;
	typedef typename	allocator_type::difference_type				difference_type;
	typedef				vector_iterator<pointer>					iterator;	
	typedef				vector_iterator<const_pointer>				const_iterator;	
	typedef				vector_reverse_iterator<pointer>			reverse_iterator;	
	typedef				vector_reverse_iterator<const_pointer>		const_reverse_iterator;	

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


	const_iterator begin() const { return (const_iterator(_arr)); } 								//! const begin iterator
	iterator begin() { return (iterator(_arr)); }													//!	begin iterator
	iterator end() { return (iterator(_arr + _size)); }												//! end iterator 
	const_iterator end() const { return (const_iterator(_arr + _size)); }							//! const end iterator
	reverse_iterator rbegin() { return(reverse_iterator(_arr + _size - 1)); }						//! reverse begin iterator
	const_reverse_iterator rbegin() const { return(const_reverse_iterator(_arr + _size - 1)); }		//! const reverse begin iterator
	reverse_iterator rend() { return(reverse_iterator(_arr - 1)); }									//! reverse end iterator
	const_reverse_iterator rend() const { return(const_reverse_iterator(_arr - 1)); }				//! const reverse end iterator
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
	// template< class InputIt > vector( InputIt first, InputIt last, const Allocator& alloc = Allocator() )
	// 	: _allocator(alloc)
	// {
	// 	difference_type	a = last - first;
	// 	std::cout<<a<<std::endl;
	// 	_arr = _allocator.allocate(a);
	// 	for(difference_type o = 0; o != a; o++)
	// 		_allocator.construct(_arr + o, *(first + o));
	// 	_size = a;
	// 	_capacity = a;
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
			_allocator.deallocate(_arr, _size);
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
	void reserve(size_type n)
	{
		if (n > _allocator.max_size())
			throw std::length_error("vector");
		if (n > _capacity)
		{
			pointer	ptr = _arr;
			_arr = _allocator.allocate(n);
			construct(_arr, _size, ptr);
			destroy(ptr, _size);
			_allocator.deallocate(ptr, _size);
			_capacity = n;
		}
	}

	//Modifiersgit 


	void clear()
	{
		destroy(_arr, _size);
		_size = 0;
	}

    void insert (iterator position, size_type n, const value_type& val)
	{
		size_type	index = begin() - position;
		if (_size + n > _capacity)
			reserve(_capacity + n);
		for (size_t i = _size - 1; i != index; i--)
			_arr[i + n] = _arr[i];
		for (size_t i = index; i < index + n; i++)
			_arr[i] = val;
		_size = _capacity;
	}
	iterator insert (iterator position, const value_type& val)
	{
		size_type	index = begin() - position;
		std::cout<<index<<std::endl;
		if (_size == _capacity && _capacity == 0)
			reserve(1);
		else if (_size == _capacity)
			reserve(_capacity * 2);
		for (size_t i = _size - 1; i != index; i--)
			_allocator.construct(_arr + i + 1, *(_arr + i));
			// _arr[i + 1] = _arr[i];
		_arr[index] = val;
		_size++;
		return (iterator(_arr + index));
	}
	// template <class InputIterator>    void insert (iterator position, InputIterator first, InputIterator last);
	void resize(size_type sz, T c = T());
	void push_back(const T& x);
	void pop_back();
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
