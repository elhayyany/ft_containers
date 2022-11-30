/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-hayy <ael-hayy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 11:02:49 by ael-hayy          #+#    #+#             */
/*   Updated: 2022/11/29 16:33:19 by ael-hayy         ###   ########.fr       */
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

// template < class Key,  [map::key_type  ]
//         class T,                                        [map::mapped_type]
//         class Compare = less<Key>,                      [map::key_compare]
//         class Alloc = allocator<pair<const Key, T> >     [map::allocator_type]
//         > class map



namespace	ft
{
template < class Key,
	class T,
	class Compare = std::less<Key>,
	class Alloc = std::allocator<std::pair<const Key, T> >
	> class map
{

public:
	typedef     				key_type									Key;
	typedef     				mapped_type									T;
	typedef						pair<const	Key, T>							value_type;
	typedef						size_t										size_type;
	typedef	typename			Allocator::ptrdiff_t						difference_type;
	typedef						Compare										key_compare;
	typedef						Alloc										allocator_type;
	typedef	typename			Allocater::reference						reference;
	typedef	typename			Allocater::const_reference					const_reference;
	typedef typename			Allocator::pointer							pointer;
	typedef	typename			Allocator::const_pointer					const_pointer;
	// typedef		iterator					
	// typedef		const_iterator
	// typedef		reverse_iterator
	// typedef		const_reverse_iterator

//! CONSTRUCTERS:

	map() root(nullptr) {};
	explicit map( const Compare& comp, const Allocator& alloc = Allocator() );
	template< class InputIt >
	map( InputIt first, InputIt last, const Compare& comp = Compare(), const Allocator& alloc = Allocator() );
	map( const map& other );
	~map();
	map& operator=( const map& other );
	allocator_type get_allocator() const;
	
//! element access

	T& at( const Key& key );
	const T& at( const Key& key ) const;
	T& operator[]( const Key& key );


//! Iterators
	



//! Modifiers
	void clear();
	std::pair<iterator, bool> insert( const value_type& value );
	template< class InputIt > void insert( InputIt first, InputIt last );
	iterator insert( iterator pos, const value_type& value );
	iterator erase( iterator pos );
	void swap( map& other );
	
//! Lookup
	size_type count( const Key& key ) const;
	iterator find( const Key& key );
	const_iterator find( const Key& key ) const;
	std::pair<iterator,iterator> equal_range( const Key& key );
	std::pair<const_iterator,const_iterator> equal_range( const Key& key ) const;
	iterator lower_bound( const Key& key );
	const_iterator lower_bound( const Key& key ) const;
	iterator upper_bound( const Key& key );
	const_iterator upper_bound( const Key& key ) const;


//! Observers
	key_compare key_comp() const;
	// std::map::value_compare value_comp() const;



//! CAPACITY
	bool		empty() {return _size;}
	size_type	size() {return _size;}
	size_type	max_size() {return alloca::MAX_SIZE;}

//! NON member functions
template< class Key, class T, class Compare, class Alloc >
bool operator== ( const std::map<Key,T,Compare,Alloc>& lhs, const std::map<Key,T,Compare,Alloc>& rhs );
template< class Key, class T, class Compare, class Alloc >
bool operator!= ( const std::map<Key,T,Compare,Alloc>& lhs, const std::map<Key,T,Compare,Alloc>& rhs );
template< class Key, class T, class Compare, class Alloc >
bool operator<  ( const std::map<Key,T,Compare,Alloc>& lhs, const std::map<Key,T,Compare,Alloc>& rhs );
template< class Key, class T, class Compare, class Alloc >
bool operator<= ( const std::map<Key,T,Compare,Alloc>& lhs, const std::map<Key,T,Compare,Alloc>& rhs );
template< class Key, class T, class Compare, class Alloc >
bool operator>  ( const std::map<Key,T,Compare,Alloc>& lhs, const std::map<Key,T,Compare,Alloc>& rhs );
template< class Key, class T, class Compare, class Alloc >
bool operator>= ( const std::map<Key,T,Compare,Alloc>& lhs, const std::map<Key,T,Compare,Alloc>& rhs );


template< class Key, class T, class Compare, class Alloc >
void swap( std::map<Key,T,Compare,Alloc>& lhs, std::map<Key,T,Compare,Alloc>& rhs );

private:
	rbtree<value_type>		*root;
	size_type	_size;
	
};
}
#endif
