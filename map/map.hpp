/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-hayy <ael-hayy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 11:02:49 by ael-hayy          #+#    #+#             */
/*   Updated: 2022/12/19 17:25:09 by ael-hayy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_HPP
#define MAP_HPP

#include "../utiles/pair.hpp"
#include <memory>
#include <exception>
#include "map_iterator.hpp"

#define  _INSERTION	1
#define  _DELETION	0

namespace	ft
{
template < class Key,
	class T,
	class Compare = std::less<Key>,
	class Alloc = std::allocator<ft::pair<const Key, T> >
	> class map
{


class t_node
{
public:
	friend class map;
	t_node(const ft::pair<const	Key, T>& v, t_node *par):val(v), left(nullptr), right(nullptr), parent(par), color(_RED) {}
	ft::pair<const	Key, T>	val;
	t_node   	*left;
	t_node		*right;
	t_node		*parent;
	bool    	color; 
};

typedef struct replacment_s_child
{
public:
	replacment_s_child(): self(nullptr), parent(nullptr) {}
	replacment_s_child(const replacment_s_child& tem): self(tem.self), parent(tem.parent), _side(tem._side) {}
	replacment_s_child(t_node *child, t_node *par): self(child), parent(par) {}
	replacment_s_child& operator=(const replacment_s_child& tem)
	{
		self = tem.self;
		parent = tem.parent;
		_side = tem._side;
		return(*this);
	} 
	t_node	*self;
	t_node	*parent;
	bool	_side;

} t_rep_info;


public:
	typedef     				Key											key_type;
	typedef     				T											mapped_type;
	typedef						ft::pair<const	Key, T>						value_type;
	typedef						size_t										size_type;
	typedef	typename			std::ptrdiff_t								difference_type;
	typedef						Compare										key_compare;
	typedef						Alloc										allocator_type;
	typedef	typename			Alloc::reference							reference;
	typedef	typename			Alloc::const_reference						const_reference;
	typedef typename			Alloc::pointer								pointer;
	typedef	typename			Alloc::const_pointer						const_pointer;
	typedef						map_iterator<Key, T, t_node *>				iterator;
	// typedef						map_iterator<Key, T, rbtree*>				const_iterator;
	// typedef			reverse_iterator;
	// typedef			const_reverse_iterator;

//! //////////////////////////////////////
	
	void	clear()	{clear_it(_root);}
//! //////////////////// 
//* CONSTRUCTERS:
	map(): _root(nullptr) {};
	explicit map( const Compare& comp, const Alloc& alloc = Alloc()): Alloc(alloc), _com(comp){}
	// template< class InputIt >
	// map( InputIt first, InputIt last, const Compare& comp = Compare(), const Alloc& alloc = Alloc() ): _allocator(alloc), _com(comp){}
	map( const map& other );
	~map() { clear(); };
	map& operator=( const map& other );
	allocator_type get_allocator() const {return(_allocat);}
//! ////////////////////



//! Iterators
	
	iterator					begin() {return (iterator(_root));}
	// const_iterator				begin() const {return (iterator(_root));}
	iterator					end() {return (iterator(_root));}
	// const_iterator				end() const {return (iterator(_root));}
	// reverse_iterator			rbegin() {register_t}
	// const_reverse_iterator		rbegin() const {register_t}
	// reverse_iterator			rend() {register_t}
	// const_reverse_iterator		rend() const {register_t}
	iterator find (const key_type& k);
	// const_iterator find (const key_type& k) const;

//! ////////////////////

//? DELETE 
	iterator erase( iterator pos )
	{
		return iterator(__erase_node(pos.base()));
	}






//? INSERT 

	ft::pair<iterator, bool>	insert(const value_type& val)
	{
		// std::cout<<"i: "<<val.first<<"\n";
		ft::pair<t_node *, bool> to_return = __add_node_to_BST_returnIT(val);
		std::cout<<"root is "<<_root->val.first<<std::endl;
		if (!to_return.second){
			return (ft::pair<iterator, bool>(iterator(to_return.first), 0));}
		_size++;
		t_node	*node = to_return.first;
		// 	std::cout<<"........\n"<<node->color  << " ... " << node->parent->color<<"    "<<node->parent->val.first <<std::endl;
		while(node->color == _RED && node->parent->color == _RED)
		{
			if (__brother_color(node->parent) == _RED)
			{
					std::cout<<"hrer 0     "<<node->parent->val.first<<"\n";
				t_node *tem = node->parent;
				tem->parent->color = _RED;
				tem->color = _BLACK;
				__get_brother(tem)->color = _BLACK;
				// std::cout<<"hrer 0     "<<__get_brother(tem)->val.first<<"\n";
				node = tem->parent;
				if (!node->parent)
					node->color = _BLACK;
			}
			else
			{
				bool	node_side = __get_node_side(node);
				if (node_side == __get_node_side(node->parent) && node_side == _LEFT)
				{
					std::cout<<"hrer 1\n";
					node = __right_rotation(node->parent);
				}
				else if (node_side == __get_node_side(node->parent) && node_side == _RIGHT)
				{
					std::cout<<"hrer 2\n";
					node = __left_rotation(node->parent);
				}
				else if (node_side == _RIGHT)
				{
					std::cout<<"hrer 3\n";
					node = __angle_to_line_left_rotation(node->parent, node);
				}
				else
				{
					std::cout<<"hrer 4\n";
					node = __angle_to_line_right_rotation(node->parent, node);
				}
			}
		}
		std::cout<<"-----------------enserd "<<to_return.first->val.first<<std::endl;
		return (ft::pair<iterator, bool>(iterator(to_return.first), 1));
	}

	void	p(t_node *node)
	{

		if ((!node->left && !node->right))
		{
		std::cout<<": "<<node->val.first<<" "<<std::endl;
		return;
		}
		if (node->left)
		p(node->left);
		if (node->right)
		p(node->right);
	}

	void	print()
	{
		p(_root);
		
	}

//! ///////////////////////////////////////////////////////////

//! Observers
	// key_compare key_comp() const;
	//! std::map::value_compare value_comp() const; 



//! CAPACITY
	bool		empty() {return !_size;}
	size_type	size() {return _size;}
	size_type	max_size() {return Alloc::MAX_SIZE;}


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


//! NON member functions
// friend bool operator== ( const std::map<Key,T,Compare,Alloc>& lhs, const std::map<Key,T,Compare,Alloc>& rhs );
// friend bool operator!= ( const std::map<Key,T,Compare,Alloc>& lhs, const std::map<Key,T,Compare,Alloc>& rhs );
// friend bool operator<  ( const std::map<Key,T,Compare,Alloc>& lhs, const std::map<Key,T,Compare,Alloc>& rhs );
// friend bool operator<= ( const std::map<Key,T,Compare,Alloc>& lhs, const std::map<Key,T,Compare,Alloc>& rhs );
// friend bool operator>  ( const std::map<Key,T,Compare,Alloc>& lhs, const std::map<Key,T,Compare,Alloc>& rhs );
// friend bool operator>= ( const std::map<Key,T,Compare,Alloc>& lhs, const std::map<Key,T,Compare,Alloc>& rhs );


//! ///////////////////////////////////////////////////////////
private:


	typedef typename Alloc::template rebind<t_node>::other _node_allocator;
	// typedef typename _allocator::template rebind<Node>::other _node_allocator_type;
	t_node			*_root;
	size_t			_size;
	Compare			_com;
	_node_allocator	_allocat;

	t_node	*__allocate_costruct_node(const value_type& v, t_node *par)
	{
		t_node	*saver = _allocat.allocate(sizeof(t_node));
		_allocat.construct(saver, t_node(v,par));
		return	(saver);
	}

	void	__destroy_deallocate_node(t_node *node)
	{
		_allocat.destroy(node);
		_allocat.deallocate(node, sizeof(t_node));
	}

	ft::pair<t_node *, bool>	__add_node_to_BST_returnIT(const value_type &val)
	{
		if (!_root)
		{
			_root = __allocate_costruct_node(val, 0);
			_root->color = _BLACK;
			return ft::pair<t_node *, bool>(_root, 1);
		}
		t_node	*tem  = _root;
		while (tem)
		{
			if (tem->val.first == val.first)
				return ft::pair<t_node *, bool>(tem, 0);
			if (!_com(tem->val.first, val.first))
			{
				// std::cout<<"less than "<<tem->val.first<<"    "<< val.first<<std::endl;
				if (!tem->left)
				{
					tem->left = __allocate_costruct_node(val, tem);
					return ft::pair<t_node *, bool>(tem->left, 1);
				}
				tem = tem->left;
			}
			else
			{
				// std::cout<<"grater than "<<tem->val.first<<"    "<< val.first<<std::endl;
				if (!tem->right)
				{
					tem->right = __allocate_costruct_node(val, tem);
					return ft::pair<t_node *, bool>(tem->right, 1);
				}
				tem = tem->right;
			}
		}
		std::cout<<"error on BST add node"<<std::endl;
		exit(1);
		return ft::pair<t_node *, bool>(0, 0);
	}

	bool	__is_it_balanced(t_node	*node)
	{
		if (!(node->parent) || node->color == _BLACK)
			return (true);
		if ((node->parent->color == _RED) && ((node->parent && node->parent->color == _RED) || \
			(node->left && node->left->color == _RED) || (node->right && node->right->color == _RED)))
			return (false);
		return (true);
	}

	bool	__get_node_side(t_node	*node)
	{
		if (node && node->parent && node->parent->left == node)
			return (_LEFT);
		return (_RIGHT);
	}

	t_node	*__angle_to_line_left_rotation(t_node *node, t_node *new_node) // anti-clockwise rotation and it will work when we have an angle and we want it to became a line so we can do left rotation
	{
		// std::cout<<"node: "<<node->val.first<<"  new_node: "<<new_node->val.first<<std::endl;
		node->right = new_node->left;
		if (node->right)
			node->right->parent = node;
		new_node->left = node;
		new_node->parent = node->parent;
		node->parent = new_node;
		if (new_node->parent)
			new_node->parent->left = new_node;
		return(__right_rotation(new_node));
	}

	t_node	*__angle_to_line_right_rotation(t_node *node, t_node *new_node) // mirror of __angle_to_line_left_rotation()
	{
		node->left = new_node->right;
		if (node->left)
			node->left->parent = node;
		new_node->right = node;
		new_node->parent = node->parent;
		node->parent = new_node;
		if (new_node->parent)
			new_node->parent->right = new_node;
		return(__left_rotation(new_node));
	}

	t_node	*__right_rotation(t_node *node) // right/clockwise rotaion
	{
		t_node	*gran_node =  node->parent;
		gran_node->left = node->right;
		if(node->right)
			node->right->parent = gran_node;
		node->parent = gran_node->parent;
		if (node->parent)
		{
			if(__get_node_side(gran_node) == _LEFT)
				node->parent->left = node;
			else
				node->parent->right = node;
		}
		node->right = gran_node;
		gran_node->parent = node;
		node->color = _BLACK;
		gran_node->color = _RED;
		if (_root == gran_node)
		{
			_root = node;
			node->parent = nullptr;
		}
		return (node);
	}

	t_node	*__left_rotation(t_node *node) // left/anti-clockwise rotaion    mirror of __right_rotation()
	{
		t_node	*gran_node =  node->parent;
		gran_node->right = node->left;
		if(node->left)
			node->left->parent = gran_node;
		// exit(0);
		node->parent = gran_node->parent;
		if (node->parent)
		{
			if(__get_node_side(gran_node) == _RIGHT)
				node->parent->right = node;
			else
				node->parent->left = node;
		}
		node->left = gran_node;
		gran_node->parent = node;
		node->color = _BLACK;
		gran_node->color = _RED;
		if (_root == gran_node)
		{
			_root = node;
			node->parent = nullptr;
		}
		return (node);
	}

	bool 	__brother_color(t_node* node)
	{
		if (__get_node_side(node) == _LEFT)
		{
			if (node->parent && node->parent->right && node->parent->right->color == _RED)
				return (_RED);
		}
		else
		{
			if (node->parent && node->parent->left && node->parent->left->color == _RED)
				return (_RED);
		}
		return (_BLACK);
	}

	t_node	*__get_brother(t_node *node)
	{
		if (__get_node_side(node) == _LEFT)
			return (node->parent->right);
		return (node->parent->left);
	}

	t_node	*__erase_node(t_node *node)
	{
		t_rep_info	rep;
		t_rep_info	rep_x;
		if (node->left && node->right)
		{
			std::cout<<"node with two children"<<std::endl;
			t_node	*secsessor = __get_secsessor(node);
			rep.parent = secsessor->parent;
			rep.self = secsessor;
			rep_x.parent = secsessor;
			rep_x.self = secsessor->right;
			rep_x._side = _RIGHT;
			rep_x = __delete_node_with_two_children(node, rep, rep_x);
			__next_deletion_step(node, rep, rep_x);
		}
		else if (node->left)
		{
			std::cout<<"node with LEFT child and its color is: "<<node->color<<"and its value is: "<<node->val.first<<std::endl;
			rep.parent = node;
			rep.self = node->left;
			rep._side = __get_node_side(node);
			rep_x = rep;
			rep_x._side = _LEFT;
			rep_x = __delete_node_with_one_child(node, rep);
			__next_deletion_step(node, rep, rep_x);
		}
		else if (node->right)
		{
			std::cout<<"node with RIGHT child and its color is: "<<node->color<<"and its value is: "<<node->val.first<<std::endl;
			std::cout<<__get_node_side(node)<<std::endl;
			rep.parent = node;
			rep.self = node->right;
			rep._side = __get_node_side(node);
			rep_x = rep;
			rep_x._side = _RIGHT;
			rep_x = __delete_node_with_one_child(node, rep);
			__next_deletion_step(node, rep, rep_x);
		}
		else
		{
			std::cout<<"node with NO children and its color is: "<<node->color<<"and its value is: "<<node->val.first<<std::endl;
			rep.parent = node->parent;
			rep.self = nullptr;
			rep_x = __delete_node_with_no_children(node, rep_x);
			if (rep_x.parent)
				__next_deletion_step(node, rep, rep_x);
		}
		__destroy_deallocate_node(node);
		return (rep.self);
	}

	t_node	*__get_secsessor(t_node *node)
	{
		node = node->right;
		while (node->left)
			node = node->left;
		return 	(node);
	}

	t_rep_info	__delete_node_with_two_children(t_node *node, t_rep_info remp, t_rep_info rep_x)
	{
		// exit(0);
		std::cout<<"node: "<<node->val.first  <<"  "<<node->parent<<"\n";
		std::cout<<"parent:  "<<remp.self->val.first<<std::endl;
		// exit(0);
		if (node->parent)
		{
			if (__get_node_side(node) == _LEFT)
				node->parent->left = remp.self;
			else
				node->parent->right = remp.self;
		}
		if (__get_node_side(remp.self) == _LEFT)
		{
			std::cout<<"Lefttt\n";
			remp.self->parent->left = rep_x.self;
			rep_x._side = _LEFT;
		}
		else if (remp.self->parent != node )
		{
			
			remp.self->parent->right = rep_x.self;
			rep_x._side = _RIGHT;
			rep_x.parent = remp.self->parent;
			if (rep_x.self)
				rep_x.self->parent = remp.self->parent;
		}
		remp.self->parent = node->parent;
		remp.parent = node->parent;
		remp.self->left = node->left;
		if (node->left)
			node->left->parent = remp.self;
		if (remp.self != node->right && remp.self != node->right)
			remp.self->right = node->right;
		if (node->right && remp.self != node->right)
			node->right->parent = remp.self;
		// std::cout<<"node: "<<remp.self->val.first<<"\t"<<"parent:  "<<remp.self->parent->val.first<<std::endl;
		// std::cout<<"node: "<<remp.self->val.first<<"\t"<<"parent:  "<<remp.self->parent->val.first<<std::endl;
		if (node == _root)
			_root = remp.self;
		return (rep_x);
	}

	t_rep_info	__delete_node_with_one_child(t_node *node, t_rep_info remp)
	{
		if (node->parent)
		{
			if (__get_node_side(node) == _LEFT)
			{
				node->parent->left = remp.self;
				remp._side = _LEFT;
			}	
			else
			{
				remp._side = _RIGHT;
				node->parent->right = remp.self;
			}
		}
		remp.self->parent = node->parent;
		remp.parent = node->parent;
		if (node == _root)
			_root = remp.self;
		return (remp);
	}


	t_rep_info	__delete_node_with_no_children(t_node *node, t_rep_info rep_x)
	{
		if (node->parent)
		{
			if (__get_node_side(node) == _LEFT)
			{
				node->parent->left = nullptr;
				rep_x._side = _LEFT;
			}
			else
			{
				node->parent->right = nullptr;
				rep_x._side = _RIGHT;
			}
		}
		rep_x.parent = node->parent;
		rep_x.self = nullptr;
		if (node == _root)
			_root = nullptr;
		return (rep_x);
	}

	void	__next_deletion_step(t_node *node, t_rep_info rep, t_rep_info rep_x)
	{
		// if (node->parent == rep_x.parent)
		// 	exit(0);
		if (node->color == _RED && rep.self && rep.self->color == _BLACK)
		{
			std::cout<<"step 1\n\n";
			rep.self->color = _RED;
			__fixUP_step(rep_x);
		}
		else if (node->color == _BLACK)
		{
			if (rep.self && rep.self->color == _RED)
			{std::cout<<"step 2\n\n";
				rep.self->color = _BLACK;
			}else if (rep_x.self != _root)
			{	std::cout<<"step 3\n\n";__fixUP_step(rep_x);}
		}
		// if (rep.self)
		// std::cout<<rep.self->parent->left->val.first<<"out\n\n";
		std::cout<<"out\n\n";
	}
	// bool pk(){std::cout<<"here\n"; return (1);}
	void	__fixUP_step(t_rep_info x)
	{
		t_rep_info w = __get_rep_sibling(x);
		std::cout<<"w v: "<<w.self->val.first<<std::endl;
		std::cout<<"w c: "<<w.self->color<<std::endl;
		while (x.self != _root || (x.self && x.self->color == _RED))
		{
					// std::cout<<"llllll:::   "<<w.self->right->color<<std::endl;;
			if (x.self && x.self->color == _RED) // Node x is red
			{
				std::cout<<"case 0\n";
				x.self->color = _BLACK;
				return;
			}
			else if (w.self && w.self->color == _RED) // Node x is black and its sibling w is red
			{
				std::cout<<"case 1\n";
				w.self->color = _BLACK;
				// if (!x.self)
				// 	exit(0);
				x.parent->color = _RED;
				if (x._side == _LEFT)
				{
					std::cout<<"case 1 left\n";
					__deletion_left_rotation(x.parent);
				}
				else
				{
					std::cout<<"case 1 right\n";
					__deletion_right_rotation(x.parent);
				}
				if (x._side == _LEFT)
				{
					w.self = x.parent->right;
					w.parent = x.parent;
					w._side = _RIGHT;
				}
				else
				{
					w.self = x.parent->left;
					w.parent = x.parent;
					w._side = _LEFT;
				}
				
			}
			// else if (!w.self)
			// {
			// 	exit(1);
			// }
			else if ((!w.self->left || w.self->left->color == _BLACK) && (!w.self->right || w.self->right->color == _BLACK)) //Node x is black, its sibling w is black, and both of w's children are black
			{
				std::cout<<"case 2\n";
				w.self->color = _RED;
				x.self = x.parent;
				x._side = __get_node_side(x.parent);
				x.parent = x.parent->parent;
				if (!x.parent)
					return;
				// std::cout<<"w v: "<<w.self->val.first<<std::endl;
				// std::cout<<"w c: "<<w.self->color<<std::endl;
				// std::cout<<"x v: "<<x.self->val.first<<std::endl;
				// std::cout<<"x c: "<<x.self->color<<std::endl;
			}
			// Node x is black, its sibling w is black, and
			else if (x._side == _LEFT && w.self && w.self->left && w.self->left->color == _RED\
				&& ( !w.self->right || w.self->right->color == _BLACK)) //If x is the left child, w's left child is red and w's right child is black
			{
				std::cout<<"case 3.0\n";
				w.self->left->color = _BLACK;
				w.self->color = _RED;
				__deletion_right_rotation(w.self);
				w.self = x.parent->right;
				w.parent = x.parent;
				w._side = _RIGHT;
			}
			else if (x._side == _RIGHT && w.self && w.self->right && w.self->right->color == _RED\
				&& ( !w.self->left || w.self->left->color == _BLACK)) // If x is the right child, w's right child is red and w's left child is black
			{
				std::cout<<"case 3.1\n";
				w.self->right->color = _BLACK;
				w.self->color = _RED;
				__deletion_left_rotation(w.self);
				w.self = x.parent->left;
				w.parent = x.parent;
				w._side = _LEFT;
			}
			//  Node x is black, its sibling w is black, and
			else if (x._side == _LEFT && w.self && w.self->right && w.self->right->color == _RED) // • If x is the left child, w's right child is red
			{
				std::cout<<"case 4.0\n";
				w.self->color = x.parent->color;
				x.parent->color = _BLACK;
				w.self->right->color = _BLACK;
				__deletion_left_rotation(x.parent);
				// w.parent = w.self->parent;
				// x.parent = x.self->parent;
				// w._side = __get_node_side(w.self);
				// x._side = x._side;
				return ;
			}
			else if (x._side == _RIGHT && w.self && w.self->left && w.self->left->color == _RED) //• If x is the right child, w's left child is red
			{
				std::cout<<"case 4.1\n";
				w.self->color = x.parent->color;
				x.parent->color = _BLACK;
				w.self->left->color = _BLACK;
				__deletion_right_rotation(x.parent);
				// w.parent = w.self->parent;
				// x.parent = x.self->parent;
				// w._side = __get_node_side(w.self);
				// x._side = x._side;
				return ;
			}
			else
			{
				std::cout<<"qqqqqqq\n";
			}
		}
	}
	bool oo(const std::string &h){std::cout<<h<<std::endl;return (1);}
	t_rep_info	__get_rep_sibling(t_rep_info remp_x)
	{
		t_rep_info tem;
		if (remp_x._side == _LEFT)
		{
			tem.self = remp_x.parent->right;
			tem.parent = remp_x.parent;
			tem._side = _RIGHT;
			return (tem);
		}
		tem.self = remp_x.parent->left;
		tem.parent = remp_x.parent;
		tem._side = _LEFT;
		return (tem);
	}
	void	clear_it(t_node *node)
	{
		static int i    = 0;
		if (!node)
			return ;
		if (node->left)
			clear_it(node->left);
		std::cout<<i++<<std::endl;
		if (node->right)
			clear_it(node->right);
		if (__get_node_side(node) == _LEFT)
			node->parent->left = nullptr;
		else if (node->parent)
			node->parent->right = nullptr;
		__destroy_deallocate_node(node);
	}
	void	__deletion_left_rotation(t_node	*node)
	{
		t_node	*rh_child = node->right;
		if (__get_node_side(node) == _LEFT)
			node->parent->left = rh_child;
		else if (node->parent)
			node->parent->right = rh_child;
		rh_child->parent = node->parent;
		node->right = rh_child->left;
		if (node->right)
			node->right->parent = node;
		rh_child->left = node;
		node->parent = rh_child;
		if (_root == node)
			_root = rh_child;	
		std::cout<<"out of deletion LEFT rotate\n";
	}
	void	__deletion_right_rotation(t_node	*node)
	{
		t_node	*lf_child = node->left;
		if (__get_node_side(node) == _LEFT)
			node->parent->right = lf_child;
		else if (node->parent)
			node->parent->right = lf_child;
		lf_child->parent = node->parent;
		node->left = lf_child->right;
		if (node->left)
			node->left->parent = node;
		lf_child->right = node;
		node->parent = lf_child;
		if (_root == node)
			_root = lf_child;
	}

};
}
#endif