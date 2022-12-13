/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-hayy <ael-hayy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 11:02:49 by ael-hayy          #+#    #+#             */
/*   Updated: 2022/12/13 10:33:40 by ael-hayy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_HPP
#define MAP_HPP

#include "pair.hpp"
#include <memory>
#include <exception>
#include "map_iterator.hpp"

#define	_BLACK	0
#define	_RED	1
#define	_LEFT	0
#define	_RIGHT	1

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
	rbtree(pair<const	Key, T>	 v, rbtree *_parent = nullptr, bool _sidebool, co = _RED):val(v), color(co), side(_side), left(nullptr), right(nullptr), parent(_parent) {}
	pair<const	Key, T>	val;
	bool		color;
	bool		side;
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

	map(): _root(nullptr) {};
	explicit map( const Compare& comp, const Alloc& alloc = Alloc()): _allocator(alloc), _com(comp){}
	template< class InputIt >
	// map( InputIt first, InputIt last, const Compare& comp = Compare(), const Alloc& alloc = Alloc() ): _allocator(alloc), _com(comp){}
	map( const map& other );
	~map(){};
	map& operator=( const map& other );
	allocator_type get_allocator() const {return(_allocator);};

//! element access

	T& operator[]( const Key& key );


//! Iterators
	



//! Modifiers
	void clear();
	std::pair<iterator, bool> insert( const value_type& value )
	{
		if (!_root)
			_root = _allocate_and_construct(value, _BLACK, 0);
		else
		{
			rbtree *node = _root;
			rbtree *new_node = nullptr;
			while (1)
			{
				if (node->val.first > value.first)
				{
					if (node->left)
						node = node->left;
					else
					{
						node->left = _allocate_and_construct(value, _LEFT, node);
						new_node = node->left;
						break;
					}
				}
				else if (node->val.first < value.first())
				{
					if (node->right)
						node = node->right;
					else
					{
						node->right = _allocate_and_construct(value, _RIGHT, node);
						new_node = node->right;
						break;
					}
				}
				else
					return (iterator(node), 0);
			}
			if (node->color == _BLACK)
				return (iterator(node), 1);
			else
			{
				if (_sib_color(node) == _BLACK)
				{
					if (new_node->side == node->side)
					{
						right_rotation(node);
					}
					else
					{
						left_rotatio(node);
						right_rotation(node);
					}
				}
				else
				{
					if (node->parent.parent)
						node->parent->color = _RED;
					node->color = _BLACK;
					new_node->color = _BLACK;
					if (_get_sib(node))
						_get_sib(node)->color = _BLACK;
				}
			}
		}
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
	rbtree					*_root;
	size_type				_size;
	Alloc					_allocator;
	std::allocator<rbtree>	_rballocatr;
	key_compare				_com;
	rbtree	*_allocate_and_construct(const value_type& val, bool color, bool side, rbtree *parent)
	{
		rbtree	*node = _rballocatr.allocate(1);
		_rballocatr.construct(node, rbtree(val, parent, color, side));
		return (node);
	}

	bool	_sib_color(rbtree *node)
	{
		if (node->side == _LEFT)
		{
			if (node->parent->right)
				return (node->parent->right.color);
		}
		else (node->parent->left)
			return (node->parent->left.color);
		return (_BLACK);
	}
	rbtree	*_get_sib(rbtree *node)
	{
		return (node->side ? node->left : node->right);
	}
	rbtree	*__L_L__rotation(rbtree	*node)
	{
		
	}
	rbtree *__R_R__rotation(rbtree *node)
	{
		
	}
	rbtree *__R_L__rotation(rbtree *node)
	{
		
	}
	rbtree *__L_R__rotation(rbtree *node)
	{

	}
};
}
#endif
