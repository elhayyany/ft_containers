/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-hayy <ael-hayy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 11:02:24 by ael-hayy          #+#    #+#             */
/*   Updated: 2022/12/21 10:19:37 by ael-hayy         ###   ########.fr       */
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
#include "vector/vector.hpp"
#include <cmath>
#include <map>
#include "map/map.hpp"
#include "stack/stack.hpp"
#include <iostream>
#include <algorithm>
#include <deque>
#include "map/red_black_tree.hpp"


int main()
{
   // rbtree<ft::pair<int, int>, int> a;
   // for (size_t i = 0; i < 50; i++)
   // {
   //    a.insert(ft::pair<int, int>(i,i));
   //    /* code */
   // }
   // std::cout<<a.serch(ft::pair<int, int>(7, 33))->val->first<<std::endl;
   
   ft::map<int, int> mp;
      srand(time(0));
int g[] = {176, 14, 279, 8, 46, 33, 187, 150, 165};
   for (size_t i = 0; i < 9; i++)
   {
      int k = rand()%300;
      std::cout<<"K: "<<g[i]<<std::endl;
      mp.insert(ft::pair<int, int>(g[i],i));
   }
   mp.print();
   // mp.erase(6);
   // for (auto &i : mp)
   // {
   //    std::cout<<i.first<<"   ";
   // }
   // ft::map<int, int> a;
   // a.insert(ft::pair<int, int>(1,2));

}
 
