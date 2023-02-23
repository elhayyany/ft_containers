/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_integral.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-hayy <ael-hayy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 17:00:59 by ael-hayy          #+#    #+#             */
/*   Updated: 2022/11/07 16:17:10 by ael-hayy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IS_INTEGRAL_HPP
#define IS_INTEGRAL_HPP
#include <iostream>
#include <type_traits>
// #include "../vector/vec÷tor.hpp"
namespace ft{

  template<class T, T v>
  struct integral_constant {
      static const T value = v;
      typedef T value_type;
      typedef integral_constant type;
    operator value_type() const { return value; }
  };

  typedef integral_constant<bool, true> true_type;
  typedef integral_constant<bool, false> false_type;
  template <class T> struct is_integral : public false_type{};
  template <> struct is_integral<bool> : public true_type{};
  template <> struct is_integral<char> : public true_type{};
  template <> struct is_integral<signed char> : public true_type{};
  template <> struct is_integral<unsigned char> : public true_type{};
  template <> struct is_integral<wchar_t> : public true_type{};
  template <> struct is_integral<short> : public true_type{};
  template <> struct is_integral<int> : public true_type{};
  template <> struct is_integral<long> : public true_type{};
  template <> struct is_integral<long long> : public true_type{};
  template <> struct is_integral<unsigned short> : public true_type{};
  template <> struct is_integral<unsigned int> : public true_type{};
  template <> struct is_integral<unsigned long> : public true_type{};
  template <> struct is_integral<unsigned long long> : public true_type{};
  
  // template<class T, T v>
  // struct  iterator_constant
  // {
  //   static const T value = v;
  //   operator T() const { return value; }
  // };
  // typedef iterator_constant<bool, true> true_Ittype;
  // typedef iterator_constant<bool, false> false_ITtype;
  // template <class T> struct is_iterator:false_ITtype{};
  // template  <class T> struct is_iterator<typename ft::vector<T>::iterator>:true_Ittype{};
  // template  <class T> struct is_iterator<typename ft::vector<T>::const_iterator>:true_Ittype{};
  // template  <class T> struct is_iterator<typename ft::vector<T>::reverse_iterator>:true_Ittype{};
  // template  <class T> struct is_iterator<typename ft::vector<T>::const_reverse_iterator>:true_Ittype{};

}
#endif