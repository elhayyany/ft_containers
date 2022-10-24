/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-hayy <ael-hayy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 11:02:24 by ael-hayy          #+#    #+#             */
/*   Updated: 2022/10/24 17:45:27 by ael-hayy         ###   ########.fr       */
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
// #include "vector.hpp"
// #include "set.hpp"
// #include "map.hpp"
// #include "stack.hpp"
#include <iostream>
int main()
{
   // std::vector<int> l(14, 5);
   std::vector<int> o(5, 8);
   o.push_back(9);
   std::vector<int> l(o);
   // o = l;
   std::cout<<l.capacity()<< "  "<<l.size()<<std::endl;
   for (std::vector<int>::iterator it = l.begin(); it != l.end(); it++)
   {
      std::cout<<*it;
   }
      
}
