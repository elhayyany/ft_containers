/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_reverse_iterator.hpp                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-hayy <ael-hayy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 11:16:10 by ael-hayy          #+#    #+#             */
/*   Updated: 2022/11/20 11:16:12 by ael-hayy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_REVERSE_ITERATOR_HPP
#define MAP_REVERSE_ITERATOR_HPP

#include <memory>
#include <exception>
#include "map.hpp"
namespace ft
{

template<class It, class _NodePtr, class key, class T>
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
		~map_reverse_iterator() {}
	

	map_reverse_iterator(_NodePtr node): it(node) {}
	map_reverse_iterator(const map_reverse_iterator& itt):it(itt.it) {}
	map_reverse_iterator&	operator=(const map_reverse_iterator& iit) 
	{
		it = iit.it;
	}



	map_reverse_iterator& operator++()
	{
		--it;
		return (*this);
	}
	map_reverse_iterator operator++(int)
	{
		map_reverse_iterator	tem = *this;
		--(*this);
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
		++(*this);
		return (tem);
	}

	_NodePtr base(){return (it.base());}

	bool	operator==(map_reverse_iterator& itt) {return (it == itt.it);}
	bool	operator!=(map_reverse_iterator& itt) {return (it != itt.it);}

	const ft::pair<key, T>	operator*()  { return (*it); }
	const ft::pair<key, T>	operator->() { return ((*it)); }

};
}


#endif