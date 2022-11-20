/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-hayy <ael-hayy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 11:02:49 by ael-hayy          #+#    #+#             */
/*   Updated: 2022/11/13 11:30:56 by ael-hayy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_HPP
#define MAP_HPP

// template < class Key,  [map::key_type  ]
//         class T,                                        [map::mapped_type]
//         class Compare = less<Key>,                      [map::key_compare]
//         class Alloc = allocator<pair<const Key, T> >     [map::allocator_type]
//         > class map



template < class Key,
        class T,
        class Compare = less<Key>,
        class Alloc = allocator<pair<const Key, T> >
        > class map
{
    
}

#endif