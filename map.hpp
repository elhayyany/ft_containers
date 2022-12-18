/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-hayy <ael-hayy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 11:02:49 by ael-hayy          #+#    #+#             */
/*   Updated: 2022/12/18 10:44:11 by ael-hayy         ###   ########.fr       */
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

int gl = 0;
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
	rbtree(ft::pair<const	Key, T>	 v, rbtree *_parent = nullptr, bool _sidebool = 0, bool co = _RED):val(v), color(co), side(_sidebool), left(nullptr), right(nullptr), parent(_parent) {}
	ft::pair<const	Key, T>	val;
	bool		color;
	bool		side;
	rbtree		*left;
	rbtree		*right;
	rbtree		*parent;
};

public:
	typedef     				Key											key_type;
	typedef     				T											mapped_type;
	typedef						ft::pair<const	Key, T>							value_type;
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
	void	print(rbtree *node)
	{
		if (!node && !gl)
			std::cout<<"sss\n";
		gl++;
		if (!node)
			return ;
		print(node->left);
		std::cout<<node->val.first <<"\t";
		print(node->right);
	}
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
	rbtree *troot(){return _root;}
	bool insert( const value_type& value )
	{
		if (!_root)
			_root = _allocate_and_construct(value, _BLACK, _LEFT, 0);
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
						node->left = _allocate_and_construct(value,_RED, _LEFT, node);
						new_node = node->left;
						std::cout<<"new node "<<node->left->val.first<<"\n";
						break;
					}
				}
				else if (node->val.first < value.first)
				{
					if (node->right)
						node = node->right;
					else
					{
						node->right = _allocate_and_construct(value,_RED, _RIGHT, node);
						new_node = node->right;
						std::cout<<"new node "<<node->right->val.first<<"\n";
						break;
					}
				}
				else
				{
					std::cout<<"the same: "<<node->val.first<<" and "<<value.first<<std::endl;
					return (0);
				}
			}
			if (node->color != _BLACK)
			{
				while (_not_balanced(node))
				{
					std::cout<<"not balaced"<<std::endl;
					if (_sib_color(node) == _BLACK)
					{
						if (node->side == new_node->side && new_node->side == _LEFT)
						{
							std::cout<<std::endl<<"L_L"<<std::endl;
							node = __L_L__rotation(node, node->parent);
						}
						else if (node->side == new_node->side && new_node->side == _RIGHT)
						{
							std::cout<<std::endl<<"R_R"<<std::endl;
							node = __R_R__rotation(node, node->parent);
						}
						else if (node->side != new_node->side && new_node->side == _RIGHT)
						{
							std::cout<<std::endl<<"L_R"<<std::endl;
							node = __L_R__rotation(node, node->parent);
						}
						else if (node->side != new_node->side && new_node->side == _LEFT)
						{
							std::cout<<std::endl<<"R_L"<<std::endl;
							node = __R_L__rotation(node, node->parent);
						}
						else
							std::cout<<"3wrtihaaaa"<<std::endl;
					}
					else
					{
						std::cout<<"recoloring \n";
						if (node->parent->parent)
							node->parent->color = _RED;
						node->color = _BLACK;
						// new_node->color = _BLACK;÷
						if (_get_sib(node))
							_get_sib(node)->color = _BLACK;
					}
				}
			}
			_root = _get__root(node);
		}
		gl = 0;
		print(_root);
		return (1);
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
		_rballocatr.construct(node, rbtree(val, parent, side, color));
		return (node);
	}

	bool	_sib_color(rbtree *node)
	{
		if (node->side == _LEFT)
		{
			if (node->parent->right)
				return (node->parent->right->color);
		}
		else if (node->parent->left)
			return (node->parent->left->color);
		return (_BLACK);
	}
	rbtree	*_get_sib(rbtree *node)
	{
		if (node->parent)
		{
			return (node->side ? node->parent->left : node->parent->right);
		}
		return (nullptr);
	}
	rbtree	*__L_L__rotation(rbtree	*node, rbtree *nod_parent)
	{
		nod_parent->left = node->right;
		if (node->right)
			node->right->side = _LEFT;
		node->right = nod_parent;
		node->parent = nod_parent->parent;
		nod_parent->parent = node;
		if (node->parent)
		{
			if (nod_parent->side == _LEFT)
				node->parent->left = node;
			else
				node->parent->right = node;
		}
		nod_parent->side = _RIGHT;
		node->color = _BLACK;
		nod_parent->color = _RED;
		return (node);
	}
	rbtree *__R_R__rotation(rbtree *node, rbtree *nod_parent)
	{
		nod_parent->right = node->left;
		node->left = nod_parent;
		node->parent = nod_parent->parent;
		nod_parent->parent = node;
		if (node->parent)
		{
			if (nod_parent->side == _LEFT)
				node->parent->left = node;
			else
				node->parent->right = node;
		}
		nod_parent->side = _LEFT;
		node->color = _BLACK;
		nod_parent->color = _RED;
		return (node);
	}
	rbtree *__R_L__rotation(rbtree *node, rbtree *nod_parent)
	{
		rbtree	*new_node = node->left;
		new_node->right = node;
		node->side = _RIGHT;
		node->left = nullptr;
		new_node->parent = nod_parent;
		node->parent = new_node;
		nod_parent->right = new_node;
		new_node->side = _RIGHT;
		return (__R_R__rotation(new_node, new_node->parent));
	}
	rbtree *__L_R__rotation(rbtree *node, rbtree *nod_parent)
	{
		rbtree	*new_node = node->right;
		new_node->left = node;
		node->side = _LEFT;
		node->right = nullptr;
		new_node->parent = nod_parent;
		node->parent = new_node;
		nod_parent->left = new_node;
		new_node->side = _LEFT;
		return (__L_L__rotation(new_node, new_node->parent));
	}
	bool	_not_balanced(rbtree *node)
	{
		if (node->color == _RED && node->left && node->left->color == _RED)
			return (1);
		if (node->color == _RED && node->right && node->right->color == _RED)
			return (1);
		if (node->color == _RED && node->parent && node->parent->color == _RED)
			return (1);
		return (0);
	}
	rbtree *_get__root(rbtree *node)
	{
		while(node->parent)
			node = node->parent;
		return (node);
	}
};
}
#endif
