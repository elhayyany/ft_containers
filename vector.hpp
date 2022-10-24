/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-hayy <ael-hayy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 12:00:07 by ael-hayy          #+#    #+#             */
/*   Updated: 2022/10/24 09:52:29 by ael-hayy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef VECTOR_HPP
#define VECTOR_HPP

#include <memory>
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
	vector():_size(0), _capacity(0), arr(0){};
	~vector(){}
	vector operator=(vector& other) {}

};
}
#endif
