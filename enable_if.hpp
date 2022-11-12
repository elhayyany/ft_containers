/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enable_if.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-hayy <ael-hayy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 16:23:10 by ael-hayy          #+#    #+#             */
/*   Updated: 2022/11/12 14:33:58 by ael-hayy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENABLE_IF_HPP
#define ENABLE_IF_HPP
namespace ft
{
template<bool B, typename T> struct enable_if {};

template<typename T> struct enable_if<true, T> { typedef T type; };






template< class InputIt1, class InputIt2, class BinaryPredicate >
bool equal( InputIt1 first1, InputIt1 last1, InputIt2 first2, BinaryPredicate pred )
{
	while (first1!=last1) {
		if (!pred(*first1,*first2))
			return false;
		++first1; ++first2;
	}
	return true;
}



// template< class InputIt1, class InputIt2 >
// bool lexicographical_compare( InputIt1 first1, InputIt1 last1, InputIt2 first2, InputIt2 last2 );
template <class InputIterator1, class InputIterator2>
bool lexicographical_compare (InputIterator1 first1, InputIterator1 last1, InputIterator2 first2, InputIterator2 last2)
{
	while (first1!=last1)
	{
		if (first2 == last2 || *first2 < *first1)
				return false;
		else if (*first1 < *first2)
				return true;
		++first1; ++first2;
	}
	return (first2!=last2);
}

// template< class InputIt1, class InputIt2, class Compare >
// bool lexicographical_compare( InputIt1 first1, InputIt1 last1, InputIt2 first2, InputIt2 last2, Compare comp );
template <class InputIterator1, class InputIterator2>
bool equal ( InputIterator1 first1, InputIterator1 last1, InputIterator2 first2 )
{
	while (first1!=last1) {
		if (!(*first1 == *first2))   // or: if (!pred(*first1,*first2)), for version 2
			return false;
		++first1; ++first2;
	}
	return true;
}

}
#endif