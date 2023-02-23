/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pair.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-hayy <ael-hayy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 09:56:09 by ael-hayy          #+#    #+#             */
/*   Updated: 2022/12/19 17:19:33 by ael-hayy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef PAIR_HPP
#define PAIR_HPP

#include "enable_if.hpp"

#define	_BLACK	0
#define	_RED	1
#define	_LEFT	0
#define	_RIGHT	1
namespace ft
{
template<
	class T1,
	class T2>
struct pair
{
	typedef	T1  first_type;
	typedef	T2  second_type;
	const T1		first;
	T2		second;
	pair():first(T1()){}
	template<class U, class V> pair (const pair<U,V>& pr): first(pr.first), second(pr.second) {}
	pair (const T1& a, const T2& b): first(a), second(b) {}
	pair& operator=( const pair& other )
	{
		// first = other.first;
		second = other.second;
		return (*this);
	}

	//!  non mumber functions
	// friend ft::pair<T1, T2> make_pair( const T1 t, const T2 u )÷;
};
template<class T1, class T2>
ft::pair<T1, T2> make_pair( const T1& t, const T2& u )
{
	return ( ft::pair<T1,T2>(t, u) );
}
template<class T1, class T2>
bool operator==(const pair<T1, T2> &lhs, const pair<T1, T2> &rhs) { return lhs.first == rhs.first && lhs.second == rhs.second; }
template<class T1, class T2>
bool operator!=(const pair<T1, T2> &lhs, const pair<T1, T2> &rhs) { return !(lhs == rhs); }
template<class T1, class T2>
bool operator<(const pair<T1, T2> &lhs, const pair<T1, T2> &rhs) { return lhs.first < rhs.first || (!(rhs.first < lhs.first) && lhs.second < rhs.second); }
template<class T1, class T2>
bool operator<=(const pair<T1, T2> &lhs, const pair<T1, T2> &rhs) { return !(rhs < lhs); }
template<class T1, class T2>
bool operator>(const pair<T1, T2> &lhs, const pair<T1, T2> &rhs) { return rhs < lhs; }
template<class T1, class T2>
bool operator>=(const pair<T1, T2> &lhs, const pair<T1, T2> &rhs) { return !(lhs < rhs); }
}


#endif