/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_integral.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-hayy <ael-hayy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 17:00:59 by ael-hayy          #+#    #+#             */
/*   Updated: 2023/03/06 15:15:09 by ael-hayy         ###   ########.fr       */
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
  template <> struct is_integral<const bool> : public true_type{};
  template <> struct is_integral<volatile bool> : public true_type{};
  template <> struct is_integral<const volatile bool> : public true_type{};
  template <> struct is_integral<char> : public true_type{};
  template <> struct is_integral<const char> : public true_type{};
  template <> struct is_integral<volatile char> : public true_type{};
  template <> struct is_integral<const volatile char> : public true_type{};
  template <> struct is_integral<signed char> : public true_type{};
  template <> struct is_integral<const signed char> : public true_type{};
  template <> struct is_integral<volatile signed char> : public true_type{};
  template <> struct is_integral<const volatile signed char> : public true_type{};
  template <> struct is_integral<unsigned char> : public true_type{};
  template <> struct is_integral<const unsigned char> : public true_type{};
  template <> struct is_integral<volatile unsigned char> : public true_type{};
  template <> struct is_integral<const volatile unsigned char> : public true_type{};
  template <> struct is_integral<wchar_t> : public true_type{};
  template <> struct is_integral<const wchar_t> : public true_type{};
  template <> struct is_integral<volatile wchar_t> : public true_type{};
  template <> struct is_integral<const volatile wchar_t> : public true_type{};
  template <> struct is_integral<short> : public true_type{};
  template <> struct is_integral<const short> : public true_type{};
  template <> struct is_integral<volatile short> : public true_type{};
  template <> struct is_integral<const volatile short> : public true_type{};
  template <> struct is_integral<int> : public true_type{};
  template <> struct is_integral<const int> : public true_type{};
  template <> struct is_integral<volatile int> : public true_type{};
  template <> struct is_integral<const volatile int> : public true_type{};
  template <> struct is_integral<long> : public true_type{};
  template <> struct is_integral<const long> : public true_type{};
  template <> struct is_integral<volatile long> : public true_type{};
  template <> struct is_integral<const volatile long> : public true_type{};
  template <> struct is_integral<long long> : public true_type{};
  template <> struct is_integral<const long long> : public true_type{};
  template <> struct is_integral<volatile long long> : public true_type{};
  template <> struct is_integral<const volatile long long> : public true_type{};
  template <> struct is_integral<unsigned short> : public true_type{};
  template <> struct is_integral<const unsigned short> : public true_type{};
  template <> struct is_integral<volatile unsigned short> : public true_type{};
  template <> struct is_integral<const volatile unsigned short> : public true_type{};
  template <> struct is_integral<unsigned int> : public true_type{};
  template <> struct is_integral<const unsigned int> : public true_type{};
  template <> struct is_integral<volatile unsigned int> : public true_type{};
  template <> struct is_integral<const volatile unsigned int> : public true_type{};
  template <> struct is_integral<unsigned long> : public true_type{};
  template <> struct is_integral<const unsigned long> : public true_type{};
  template <> struct is_integral<volatile unsigned long> : public true_type{};
  template <> struct is_integral<const volatile unsigned long> : public true_type{};
  template <> struct is_integral<unsigned long long> : public true_type{};
  template <> struct is_integral<const unsigned long long> : public true_type{};
  template <> struct is_integral<volatile unsigned long long> : public true_type{};
  template <> struct is_integral<const volatile unsigned long long> : public true_type{};
  
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