/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pair.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-hayy <ael-hayy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 09:56:09 by ael-hayy          #+#    #+#             */
/*   Updated: 2022/12/07 14:55:23 by ael-hayy         ###   ########.fr       */
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
	template<class U, class V> pair (const pair<U,V>& pr);
	pair (const first_type& a, const second_type& b);
	pair& operator=( const pair& other );

	//!  non mumber functions
	friend ft::pair<T1, T2> make_pair( T1 t, T2 u )
	{
		return ( pair<T1,T2>(t, u) );
	}
	friend bool operator==( const ft::pair<T1,T2>& lhs, const ft::pair<T1,T2>& rhs );
	friend bool operator!=( const ft::pair<T1,T2>& lhs, const ft::pair<T1,T2>& rhs );
	friend bool operator<( const ft::pair<T1,T2>& lhs, const ft::pair<T1,T2>& rhs );
	friend bool operator<=( const ft::pair<T1,T2>& lhs, const ft::pair<T1,T2>& rhs );
	friend bool operator>( const ft::pair<T1,T2>& lhs, const ft::pair<T1,T2>& rhs );
	friend bool operator>=( const ft::pair<T1,T2>& lhs, const ft::pair<T1,T2>& rhs );
};

}