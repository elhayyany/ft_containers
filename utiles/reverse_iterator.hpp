/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_iterator.hpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-hayy <ael-hayy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 09:32:06 by ael-hayy          #+#    #+#             */
/*   Updated: 2023/03/06 11:36:57 by ael-hayy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef REVERSE_ITERATOR_HPP
#define REVERSE_ITERATOR_HPP
#include "../utiles/iterator_traits.hpp"
namespace ft
{
template <class it>
class reverse_iterator
{
public:
	typedef				it										iterator_type;
	typedef	typename	it::value_type							value_type;
	typedef typename	it::pointer								pointer;
	typedef	typename	it::reference							reference;
	typedef				std::ptrdiff_t							difference_type;
	typedef	typename	it::iterator_category					iterator_category;



	iterator_type base() const  {return It;}
	reverse_iterator() {}
	template <class A> reverse_iterator(const reverse_iterator<A>& other): It(other.base()){}
	reverse_iterator(it me): It(me){}
	~reverse_iterator() {}
	reverse_iterator& operator = (const reverse_iterator& other)
	{
		It = other.It;
		return (*this);
	}
	reverse_iterator operator ++ (int)
	{
		reverse_iterator tem;

		tem = *this;
		++(*this);
		return tem;
	}
	reverse_iterator& operator ++ ()
	{
		It--;
		return (*this);
	}
	reverse_iterator operator -- (int)
	{
		reverse_iterator tem;

		tem = *this;
		--(*this);
		return tem;
	}
	reverse_iterator& operator -- ( )
	{
		It++;
		return (*this);
	}
	reverse_iterator operator - (difference_type a)
	{
		// it	tem(It);
		// tem += a;
		// return (tem);
		reverse_iterator t(It + a);
		return (t);
	}
	reverse_iterator operator - (reverse_iterator& other)
	{
		
		reverse_iterator t(It + other.It);
		return (t);
	}
	reverse_iterator operator + (difference_type a)
	{
		reverse_iterator t(It - a);
		return (t);
	}

	template <class ittt> bool operator== (const reverse_iterator<ittt>& rhs)
	{
		return (It == rhs.base());
	}
	template<class itt> bool operator != (const reverse_iterator<itt>& other)
	{
		return (It != other.base());
	}
	// difference_type operator+ (const reverse_iterator& other) const {
    //     return (static_cast<difference_type>(base() + other.base()));
    // }
    difference_type operator- (const reverse_iterator& other) const {
        return (static_cast<difference_type>(other.base() - base()));
    }
	reference	operator * ()
	{
		it	tem(It);
		return (*--tem);
		// return (*It);
	}
	pointer	operator -> ()
	{
		return (It.operator->());
	}
	template<class itt> bool operator > (const reverse_iterator<itt>& other)
	{
		return (It < other.base());
	}
	template<class itt> bool operator >= (const reverse_iterator<itt>& other)
	{
		return (It <= other.base());
	}
	template<class itt> bool operator < (const reverse_iterator<itt>& other)
	{
		return (It > other.base());
	}
	template<class itt> bool operator <= (const reverse_iterator<itt>& other)
	{
		return (It >= other.base());
	}
	reverse_iterator& operator += (const difference_type a)
	{
		It -= a;
		return (*this);
	}
	reverse_iterator& operator -= (const difference_type a)
	{
		It += a;
		return (*this);
	}
	reference operator [] (difference_type a)
	{
		return (*(It - a));
	}
private:
	it		It;
};
	template<typename T>
	reverse_iterator<T> operator + (typename reverse_iterator<T>::difference_type a, reverse_iterator<T>& t )
	{
		reverse_iterator<T> k(t);
		k += a;
		return (k);
	}
}





#endif