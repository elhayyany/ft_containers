/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-hayy <ael-hayy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 11:02:24 by ael-hayy          #+#    #+#             */
/*   Updated: 2022/10/26 14:36:41 by ael-hayy         ###   ########.fr       */
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


int main()
{
  
   std::vector<int> a(9, 9);
   // a.push_back(0);
   a.clear();
   std::cout<<a.capacity()<<std::endl;
   try
   {
   std::cout<<a.at(0);
      /* code */
   }
   catch(const std::exception& e)
   {
      std::cerr << e.what() << '\n';
   }
}
