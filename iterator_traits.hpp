	/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_iterator_traits.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-hayy <ael-hayy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 11:36:45 by ael-hayy          #+#    #+#             */
/*   Updated: 2022/10/24 09:16:37 by ael-hayy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#ifndef TERATOR_TRAITS_HPP
#define TERATOR_TRAITS_HPP
#include "enable_if.hpp"
namespace ft
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
	typedef std::random_access_iterator_tag 			iterator_category;
	typedef T                          					value_type;
	typedef std::ptrdiff_t                  			difference_type;
	typedef T*                         					pointer;
	typedef T&                         					reference;
};
template< class T >
struct iterator_traits<const T*>
{
	typedef std::random_access_iterator_tag 			iterator_category;
	typedef T                          					value_type;
	typedef std::ptrdiff_t                  			difference_type;
	typedef const	T*                         			pointer;
	typedef const	T&                         			reference;

};

}
#endif