/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-hayy <ael-hayy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 11:02:49 by ael-hayy          #+#    #+#             */
/*   Updated: 2022/12/07 15:56:25 by ael-hayy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_HPP
#define MAP_HPP

#include "pair.hpp"
#include <memory>
#include <exception>
#include "map_iterator.hpp"

#define	_black	0
#define	_red	1

namespace	ft
{
template < class Key,
	class T,
	class Compare = std::less<Key>,
	class Alloc = std::allocator<std::pair<const Key, T> >
	> class map
{


private:
struct rbtree
{
	rbtree(pair<const	Key, T>	 v, bool co = 0):val(v), color(co), left(nullptr), right(nullptr) {}
	pair<const	Key, T>	val;
	bool		color;
	rbtree		*left;
	rbtree		*right;
	rbtree		*parent;
};

public:
	typedef     				Key											key_type;
	typedef     				T											mapped_type;
	typedef						std::pair<const	Key, T>							value_type;
	typedef						size_t										size_type;
	typedef	typename			std::ptrdiff_t							difference_type;
	typedef						Compare										key_compare;
	typedef						Alloc										allocator_type;
	typedef	typename			Alloc::reference							reference;
	typedef	typename			Alloc::const_reference						const_reference;
	typedef typename			Alloc::pointer								pointer;
	typedef	typename			Alloc::const_pointer						const_pointer;
	typedef						map_iterator<Key, rbtree*, Compare>			iterator;
	typedef						map_iterator<Key, rbtree*, Compare>			const_iterator;
	// typedef			reverse_iterator;
	// typedef			const_reverse_iterator;

//! CONSTRUCTERS:

	map(): root(nullptr) {};
	explicit map( const Compare& comp, const Alloc& alloc = Alloc()): _allocator(alloc), _com(comp){}
	template< class InputIt >
	// map( InputIt first, InputIt last, const Compare& comp = Compare(), const Alloc& alloc = Alloc() ): _allocator(alloc), _com(comp){}
	map( const map& other );
	~map(){};
	map& operator=( const map& other );
	allocator_type get_allocator() const {return(_allocator);};

//! element access

	T& at( const Key& key );
	const T& at( const Key& key ) const;
	T& operator[]( const Key& key );


//! Iterators
	



//! Modifiers
	void clear();
	std::pair<iterator, bool> insert( const value_type& value )
	{
		std::cout<<"jj j .  "<<value.first();
		return (value);
	}
	void swap( map& other );
	
//! Lookup
	// size_type count( const Key& key ) const;
	// iterator find( const Key& key );
	// const_iterator find( const Key& key ) const;
	// std::pair<iterator,iterator> equal_range( const Key& key );
	// std::pair<const_iterator,const_iterator> equal_range( const Key& key ) const;
	// iterator lower_bound( const Key& key );
	// const_iterator lower_bound( const Key& key ) const;
	// iterator upper_bound( const Key& key );
	// const_iterator upper_bound( const Key& key ) const;


//! Observers
	// key_compare key_comp() const;
	//! std::map::value_compare value_comp() const; 



//! CAPACITY
	bool		empty() {return _size;}
	size_type	size() {return _size;}
	size_type	max_size() {return Alloc::MAX_SIZE;}

//! NON member functions
friend bool operator== ( const std::map<Key,T,Compare,Alloc>& lhs, const std::map<Key,T,Compare,Alloc>& rhs );
friend bool operator!= ( const std::map<Key,T,Compare,Alloc>& lhs, const std::map<Key,T,Compare,Alloc>& rhs );
friend bool operator<  ( const std::map<Key,T,Compare,Alloc>& lhs, const std::map<Key,T,Compare,Alloc>& rhs );
friend bool operator<= ( const std::map<Key,T,Compare,Alloc>& lhs, const std::map<Key,T,Compare,Alloc>& rhs );
friend bool operator>  ( const std::map<Key,T,Compare,Alloc>& lhs, const std::map<Key,T,Compare,Alloc>& rhs );
friend bool operator>= ( const std::map<Key,T,Compare,Alloc>& lhs, const std::map<Key,T,Compare,Alloc>& rhs );


// template< class Key, class T, class Compare, class Alloc >
// void swap( std::map<Key,T,Compare,Alloc>& lhs, std::map<Key,T,Compare,Alloc>& rhs );

private:
	rbtree			*root;
	size_type		_size;
	Alloc			_allocator;
	key_compare		_com;
};
}
#endif
