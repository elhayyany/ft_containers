/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-hayy <ael-hayy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 12:00:07 by ael-hayy          #+#    #+#             */
/*   Updated: 2022/10/11 12:03:12 by ael-hayy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef VECTOR_HPP
#define VECTOR_HPP

#include <memory>




template< class T, class Allocator = std::allocator<T> > 
class vector
{
public:
	typedef				T									value_type;
	typedef				Allocator							allocator_type;
	typedef	typename	allocator_type::reference			reference;
	typedef typename	allocator_type::const_reference		const_reference;
	typedef typename	allocator_type::pointer         	pointer;
    typedef typename	allocator_type::const_pointer   	const_pointer;
	typedef typename	allocator_type::size_type       	size_type;
	typedef typename	allocator_type::difference_type		difference_type;
	vector();
	~vector();
	vector operator=(vector& other)
	{
		this = &other;
		return (*this);
	}
};

#endif