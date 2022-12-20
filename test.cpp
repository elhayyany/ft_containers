/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-hayy <ael-hayy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 11:02:24 by ael-hayy          #+#    #+#             */
/*   Updated: 2022/12/20 14:21:23 by ael-hayy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cstdlib>
#include <iostream>
#include <time.h>
#include <map>
#include <stack>
#include <iostream>
#include <string>
#include <vector>
#include "vector.hpp"
#include <cmath>
#include <map>
#include "map.hpp"
#include "stack.hpp"
#include <iostream>
#include <algorithm>
#include <deque>
#include "red_black_tree.hpp"


int main()
{
   // rbtree<ft::pair<int, int>, int> a;
   // for (size_t i = 0; i < 50; i++)
   // {
   //    a.insert(ft::pair<int, int>(i,i));
   //    /* code */
   // }
   // std::cout<<a.serch(ft::pair<int, int>(7, 33))->val->first<<std::endl;
   
   std::map<int, int> mp;
   for (size_t i = 0; i < 50; i++)
   {
      mp.insert(std::pair<int, int>(i,i));
   }
   

}
