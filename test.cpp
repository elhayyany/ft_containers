/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-hayy <ael-hayy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 11:02:24 by ael-hayy          #+#    #+#             */
/*   Updated: 2022/10/25 15:51:51 by ael-hayy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


// #include <vector>
// #include <map>
// #include <stack>
// #include <set>
// #include <iostream>
// #include <iostream>
#include <string>
#include <vector>
// #include <algorithm>
#include "vector.hpp"
// #include "set.hpp"
// #include "map.hpp"
// #include "stack.hpp"
#include <iostream>
struct m
{
   int *i;
   m(){i = new int(3);}
};

int main()
{
  
   std::vector<m> a;
   for (size_t i = 0; i < 5; i++)
      a.push_back(m());
   a.assign(3, m());
   for (auto s : a)
   {
      std::cout<<"a\n";
   }
   
}
