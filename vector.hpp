/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-hayy <ael-hayy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 12:00:07 by ael-hayy          #+#    #+#             */
/*   Updated: 2022/11/12 14:30:32 by ael-hayy         ###   ########.fr       */
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
template <class InputIterator> difference_type	size_it(InputIterator first, InputIterator last)
{
	difference_type	index = 0;

	for (; first != last; first++)
		index++;
	return(index);
}
void	destroy(pointer _to_destroy, size_type count)
{
	for(size_t i = 0; i < count; i++)
		_allocator.destroy(_to_destroy + i);
}
void	construct(pointer _to_construct, size_type count, value_type value)
{
	// std::cout<<"asdfghjkl\n"<<std::endl;
	for(size_t i = 0; i < count; i++)
		_allocator.construct(_to_construct + i, value);
}
void	construct(pointer _to_construct, size_type count, pointer value)
{
	// std::cout<<"--------------------\n"<<std::endl;
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


	explicit vector():_size(0), _capacity(0), _allocator(allocator_type()) {_arr = nullptr;};
	explicit vector( size_type count, const value_type& val = value_type(), const Allocator& alloc = Allocator()): _allocator(alloc)
	{
		if (count > _allocator.max_size())
			throw std::length_error("vector");
		if(count)
			_arr = _allocator.allocate(count);
		else
			_arr = nullptr;
		for (size_t i = 0; i < count; i++)
			_allocator.construct(_arr + i, val);
		_size = count;
		_capacity = count;
	}

	vector( const vector& other )
	{
		if (other._arr)
			_arr = _allocator.allocate(other._size);
		else
			_arr = nullptr;
		construct(_arr, other._size, other._arr);
		_size = other._size;
		_capacity = other._size;
	}
	template< class InputIt >
		vector(InputIt  first, InputIt last,
		const Allocator& alloc = Allocator(), typename ft::enable_if<!ft::is_integral< InputIt >::value, InputIt>::type* = 0)
		: _allocator(alloc)
	{
		difference_type	a = size_it(first, last);
		_arr = _allocator.allocate(a);
		for(difference_type o = 0; o != a; o++)
			_allocator.construct(_arr + o, *(first + o));
		_size = a;
		_capacity = a;
	}
	~vector()
	{
		if (_capacity)
		{
			destroy(_arr, _size);
			_allocator.deallocate(_arr, _capacity);
		}
	}
	vector& operator=( const vector& other )
	{
		clear();
		if (_capacity < other._size)
		{
			if (_capacity)
				_allocator.deallocate(_arr, _capacity);
			_arr = _allocator.allocate(other._size);
			_capacity = other._size;
		}	
		construct(_arr, other._size, other._arr);
		_size = other._size;
		return (*this);
	}
	void assign( size_type count, const value_type& value )
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
	template <class InputIterator>
	void assign (InputIterator first, InputIterator last, typename ft::enable_if<!ft::is_integral< InputIterator >::value, InputIterator>::type* = 0)
	{
		difference_type	a = size_it(first, last);
		clear();
		if (a > (difference_type)_capacity)
			reserve(a);
		for (size_type	i = 0; first != last && ++i; first++)
			_allocator.construct(_arr + i - 1 , *first);
		_size = a;
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
		if (pos >= _size)
			throw std::out_of_range("vector");
		return (*(_arr + pos));
	}
	const_reference operator[]( size_type pos ) const
	{
		if (pos >= _size)
			throw std::out_of_range("vector");
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
			_allocator.deallocate(ptr, _capacity);
			_capacity = n;
		}
	}

	//Modifiersgit 


	void clear()
	{
		destroy(_arr, _size);
		_size = 0;
	}
	template<typename ST>
    void insert (iterator position, ST n, const value_type& val, typename ft::enable_if<ft::is_integral< ST >::value, ST>::type* = 0)
	{
		size_type	index = position - begin();
		if (_size + n > _capacity * 2)
			reserve(_capacity + n);
		else if(_size + n > _capacity)
			reserve(_capacity * 2);
		for (size_t i = _size; i > index; i--)
		{
			_allocator.construct(_arr + i + n - 1 , _arr[i - 1]);
			_allocator.destroy(_arr + i - 1);
		}
		for (size_t i = index; i < index + n; i++)
			_allocator.construct(_arr + i, val);
		_size += n;
	}
	iterator insert (iterator position, const value_type& val)
	{
		size_type	index = position - begin();
		if (_size == _capacity && _capacity == 0)
			reserve(1);
		else if (_size == _capacity)
			reserve(_capacity * 2);
		for (size_t i = _size; i > index; i--)
		{
			_allocator.construct(_arr + i, *(_arr + i -1));
			_allocator.destroy(_arr + i - 1);
		}
		_allocator.construct(_arr + index, val);
		_size++;
		return (iterator (_arr + index));
	}
	template <class InputIterator>
	void insert (iterator position, InputIterator first, InputIterator last, typename ft::enable_if<!ft::is_integral< InputIterator >::value, InputIterator>::type* = 0)
	{
		size_type	index = position - begin(); //! dhddjiu
		size_type	n = size_it(first, last);
		if (_capacity == 0)
			reserve(n);
		else if (_size + n > _capacity * 2)
			reserve(_capacity + n);
		else if (_size + n > _capacity)
			reserve(_capacity * 2);
		// std::cout<<_size<<" "<<index<<" "<<n<<" "<<_capacity<<" we\n";
		if (_size)
			for (size_t i = _size; i > index; i--)
			{
				_allocator.construct(_arr + i + n - 1, _arr[i - 1]);
				_allocator.destroy(_arr + i -1);
			}
		for (;  first != last; first++, index++)
			_allocator.construct(_arr + index, *first);
		_size += n;
	}
	void resize(size_type n, T c = T())
	{
		if (n > _capacity * 2)
			reserve(n);
		else if (n > _capacity)
			reserve(_capacity * 2);
		if (n > _size)
			for (size_t i = _size; i < n; i++)
				_allocator.construct(_arr + i, c);
		else
			for (size_t i = _size; i > n; i--)//{
				_allocator.destroy(_arr + i - 1);
				// _allocator.destroy(_arr + i);}
		_size = n;
	}
	void push_back(const T& x)
	{
		if (!_capacity)
			reserve(1);
		else if (_capacity <= _size)
			reserve(_capacity * 2);
		_allocator.construct(_size + _arr, x);
		_size++;
	}
	void pop_back()
	{
		_allocator.destroy(_arr + _size);
		_size--;
	}
	// template <class InputIterator> void insert(iterator position, InputIterator first, InputIterator last);
	iterator erase(iterator position)
	{
		size_type	index = position - begin();
		for (size_type i = index; i < _size - 1; i++)
		{
			_allocator.destroy(_arr + i);
			_allocator.construct(_arr + i, *(_arr + i + 1));
		}
		_allocator.destroy(_arr + _size - 1);
		_size--;
		return iterator(_arr + index);
	}
	iterator erase(iterator first, iterator last)
	{
		difference_type	tem = last - first;
		size_type	index = first - begin();
		size_type	lst = last - begin();
		for (size_type i = index, j = 0; j < _size; j++, i++)
		{
			if (j + lst < _size){
				_allocator.destroy(_arr + i);
				_allocator.construct(_arr + i, *(last + j));
			}
			else
				_allocator.destroy(_arr + lst + j);
		}
		_size -= tem;
		return (iterator(_arr + index));
	}
	void swap(vector<T,Allocator>& other)
	{
		pointer tem = other._arr;
		other._arr = _arr;
		_arr = tem;
		_size = _size ^ other._size, other._size = _size ^ other._size, _size = _size ^ other._size;
		_capacity = _capacity ^ other._capacity, other._capacity = _capacity ^ other._capacity, _capacity = _capacity ^ other._capacity;
	}

};

	template <class T, class Allocator> bool operator==(const vector<T,Allocator>& x, const vector<T,Allocator>& y)
	{
		if (x.size() != y.size())
			return (0);
		for (size_t i = 0; i < x.size(); i++)
			if (x[i] != y[i])
				return (0);
		return (1);
	}
	template <class T, class Allocator> bool operator!=(const vector<T,Allocator>& x, const vector<T,Allocator>& y)
	{
		if (x.size() != y.size())
			return (1);
		for (size_t i = 0; i < x.size(); i++)
			if (x[i] == y[i])
				return (0);
		return (1);
	}
	template <class T, class Allocator> bool operator < (const vector<T,Allocator>& x, const vector<T,Allocator>& y)
	{
		return (ft::lexicographical_compare(x.begin(), x.end(), y.begin(), y.end()));
	}
	template <class T, class Allocator> bool operator > (const vector<T,Allocator>& x, const vector<T,Allocator>& y)
	{
		return (ft::lexicographical_compare(y.begin(), y.end(), x.begin(), x.end()));
	}
	template <class T, class Allocator> bool operator >= (const vector<T,Allocator>& x, const vector<T,Allocator>& y)
	{
		if (x > y || x == y)
			return (1);
		return (0);
	}
	template <class T, class Allocator> bool operator <= (const vector<T,Allocator>& x, const vector<T,Allocator>& y)
	{
		if (x < y || x == y)
			return (1);
		return (0);
	}
	// specialized algorithms:
}

#endif
