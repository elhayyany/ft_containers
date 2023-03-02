/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_reverse_iterator.hpp                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-hayy <ael-hayy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 11:16:10 by ael-hayy          #+#    #+#             */
/*   Updated: 2023/03/01 11:14:49 by ael-hayy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_REVERSE_ITERATOR_HPP
#define MAP_REVERSE_ITERATOR_HPP

#include <memory>
#include <exception>
#include "../utiles/iterator_traits.hpp"
#include "map_iterator.hpp"
// #include "map.hpp"
namespace ft
{

template<class It>
class map_reverse_iterator
{
	private:
		It	it;
	public:

	typedef		typename	It::pointer							pointer;
	typedef		typename	It::value_type						value_type;
	typedef		typename	It::difference_type					difference_type;
	typedef		typename	It::reference						reference;
	typedef 	typename	It::iterator_category				iterator_category;



	map_reverse_iterator() {}
	map_reverse_iterator(const It& itte): it(itte) {}
	~map_reverse_iterator() {}
	map_reverse_iterator(pointer node): it(node) {}
	template <class itter>
	map_reverse_iterator(const map_reverse_iterator<itter>& itt):it(itt.base(), 1) {}
	template <class itter>
	map_reverse_iterator&	operator=(const map_reverse_iterator<itter>& iit) 
	{
		it = iit.base();
		return (*this);
	}



	map_reverse_iterator& operator++()
	{
		--it;
		return (*this);
	}
	map_reverse_iterator operator++(int)
	{
		map_reverse_iterator	tem = *this;
		++(*this);
		return (tem);
	}

	map_reverse_iterator& operator--()
	{
		++it;
		return (*this);
	}
	map_reverse_iterator operator--(int)
	{
		map_reverse_iterator	tem = *this;
		--(*this);
		return (tem);
	}

	pointer base() const {return (it.base());}

	template <class itter>
	bool	operator==(const map_reverse_iterator<itter>& itt) {return (it.base() == itt.base());}
	template <class itter>
	bool	operator!=(const map_reverse_iterator<itter>& itt) {return !(*this == itt);}

	value_type&	operator*()  { return (*it); }
	value_type*	operator->() { return ( it.operator->() ); }

};
}


#endif