/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-hayy <ael-hayy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 12:00:01 by ael-hayy          #+#    #+#             */
/*   Updated: 2022/11/12 16:50:12 by ael-hayy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef STACK_HPP
#define STACK_HPP
#include <deque>
#include "vector.hpp"
namespace ft
{



template <class T, class Container = ft::vector<T> > 
class stack
{
public:
	typedef                 T                               value_type;
	typedef                 Container                       container_type;
	typedef typename        container_type::size_type       size_type;

private:

protected:
	container_type c;

public:
	explicit stack (const container_type& ctnr = container_type()): c(ctnr){}
	bool empty() const
	{
		return (c.empty());
	}
	size_type size() const
	{
		return (c.size());
	}
	void pop()
	{
		c.pop_back();
	}
	void push (const value_type& val)
	{
		c.push_back(val);
	}
	value_type& top()
	{
		return (c.back());
	}
	const value_type& top() const
	{
		return (c.back());
	}

friend bool operator != (const stack<T,Container>& lhs, const stack<T,Container>& rhs){ return (lhs.c != rhs.c); }
friend bool operator == (const stack<T,Container>& lhs, const stack<T,Container>& rhs){ return (lhs.c == rhs.c); }
friend bool operator <  (const stack<T,Container>& lhs, const stack<T,Container>& rhs){ return (lhs.c < rhs.c); }
friend bool operator <= (const stack<T,Container>& lhs, const stack<T,Container>& rhs){ return (lhs.c <= rhs.c); }
friend bool operator >  (const stack<T,Container>& lhs, const stack<T,Container>& rhs){ return (lhs.c > rhs.c); }
friend bool operator >= (const stack<T,Container>& lhs, const stack<T,Container>& rhs){ return (lhs.c >= rhs.c); }
};


}
#endif