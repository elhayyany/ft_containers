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
   
int g[100] = {0};
// // while(1){
//       srand(time(0));
//    // {
   ft::map<int, int> mp;
//    // std::cout<<"=========================================================\n=========================================================\n";
   for (size_t i = 0; i < 100; i++)
   {
      int k = rand()%500000;
      // g[i] = k;
      // std::cout<<"K: "<<k<<std::endl;
      mp.insert(ft::pair<int, int>(i,i));
   }
   ft::map<int, int>::iterator a = mp.begin();

   std::cout<<"s'\n"<<(*a).first<<"s'\n"<<std::endl;
   // ++a;
   // std::cout<<(*a).first<<std::endl;
   // ++a;
   // std::cout<<(*a).first<<std::endl;
   // ++a;
   // std::cout<<(*a).first<<std::endl;
   // std::cout<<(*a).first<<std::endl;
   // std::cout<<(*(mp.erase(a))).first<<std::endl;
   // mp.print();
   mp.erase(a);
   // exit(0);
   // a = mp.begin();
   // std::cout<<(*a).first<<std::endl;
   //}}
   // mp.erase(6)
   // for (auto &i : mp)
   // {
   //    std::cout<<i.first<<"   ";
   // }
   // ft::map<int, int> a;
   // a.insert(ft::pair<int, int>(1,2));

}
 
