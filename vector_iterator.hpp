/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_iterator.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-hayy <ael-hayy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/15 18:26:39 by ael-hayy          #+#    #+#             */
/*   Updated: 2022/10/24 12:34:52 by ael-hayy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector_iterator_traits.hpp"
namespace ft
{
template <class it>
class vector_iterator
{
public:
	typedef	typename	ft::iterator_traits<it>::value_type							value_type;
	typedef typename	ft::iterator_traits<it>::pointer							pointer;
	typedef	typename	ft::iterator_traits<it>::reference							reference;
	typedef	typename	ft::iterator_traits<it>::ptrdiff_t							difference_type;
	typedef	typename	ft::iterator_traits<it>::random_access_iterator_tag			iterator_category;




	vector_iterator()
	{
	}
	vector_iterator(pointer me)
	{
		ptr = me;
	}
	~vector_iterator()
	{
	}
	vector_iterator operator++(int)
	{
	}
	vector_iterator operator++()
	{
	}
	vector_iterator operator--(int)
	{
	}
	vector_iterator operator--()
	{
	}
private:
	pointer		ptr;
};
}
