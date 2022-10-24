/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-hayy <ael-hayy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 12:00:07 by ael-hayy          #+#    #+#             */
/*   Updated: 2022/10/24 17:46:50 by ael-hayy         ###   ########.fr       */
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
	typedef				vector_iterator<value_type>			iterator;	

private:
size_type		_size;
size_type		_capacity;
pointer			_arr;
allocator_type	_allocator;


public:
	vector():_size(0), _capacity(0), _arr(0), _allocator(allocator_type()) {};
	// explicit vector( const Allocator& alloc ):_size(0), _capacity(0), _arr(0), _allocator(alloc){}  //! 3 
	explicit vector( size_type count, const T& value = T(), const Allocator& alloc = Allocator()): _allocator(alloc)
	{
		if (count < 0)
			throw std::__throw_length_error;
		_arr = _allocator.allocate(count);
		for (size_type i = 0; i < count; i++)
			_allocator.construct(_arr + i, value);
	}
	reference	front() {return (*_arr);}
	const_reference front() const {return (*_arr);}
	size_type size() const {return _size; };
	// vector( const vector& other )
	// {
	// 	if (_capacity >= other._size)
	// 	{
			
	// 	}
	// 	else
	// 	{
			
	// 	}
	// }
	// template< class InputIt > vector( InputIt first, InputIt last, const Allocator& alloc = Allocator() )
	// {

	// }
	// ~vector()
	// {
	// 	if (_arr)
	// 		_allocator.deallocate(_arr, _capacity);
	// }
	vector& operator=( const vector& other )
	{
		if (!_arr)
		{
			_arr = _allocator.allocatte(other._size);
		}
	}

	// allocator_type get_allocator() const;
	// reference at( size_type pos );
	// reference operator[]( size_type pos );
	// vector operator=(vector& other) {}

};
}
#endif
