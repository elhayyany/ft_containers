/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pair.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-hayy <ael-hayy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 09:56:09 by ael-hayy          #+#    #+#             */
/*   Updated: 2022/12/18 11:50:06 by ael-hayy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

namespace ft
{
template<
	class T1,
	class T2>
struct pair
{
	typedef	T1  first_type;
	typedef	T2  second_type;
	T1		first;
	T2		second;
	pair();
	template<class U, class V> pair (const pair<U,V>& pr): first(pr.first), second(pr.second) {}
	pair (const first_type& a, const second_type& b):first(a), second(b)  {}
	pair& operator=( const pair& other )
	{
		first = other.first;
		second = other.second;
	}

	//!  non mumber functions
	// friend ft::pair<T1, T2> make_pair( const T1 t, const T2 u )÷;
	friend bool operator==( const ft::pair<T1,T2>& lhs, const ft::pair<T1,T2>& rhs );
	friend bool operator!=( const ft::pair<T1,T2>& lhs, const ft::pair<T1,T2>& rhs );
	friend bool operator<( const ft::pair<T1,T2>& lhs, const ft::pair<T1,T2>& rhs );
	friend bool operator<=( const ft::pair<T1,T2>& lhs, const ft::pair<T1,T2>& rhs );
	friend bool operator>( const ft::pair<T1,T2>& lhs, const ft::pair<T1,T2>& rhs );
	friend bool operator>=( const ft::pair<T1,T2>& lhs, const ft::pair<T1,T2>& rhs );
};
template<class T1, class T2>
ft::pair<T1, T2> make_pair( const T1& t, const T2& u )
{
	return ( ft::pair<T1,T2>(t, u) );
}

}