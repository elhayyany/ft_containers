/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_integral.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-hayy <ael-hayy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 17:00:59 by ael-hayy          #+#    #+#             */
/*   Updated: 2022/11/02 16:54:32 by ael-hayy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <type_traits>

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
  
}