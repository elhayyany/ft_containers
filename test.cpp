/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-hayy <ael-hayy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 11:02:24 by ael-hayy          #+#    #+#             */
/*   Updated: 2023/03/06 17:45:18 by ael-hayy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cstdlib>
#include <iostream>
#include <time.h>
#include <ctime>
#include <map>
#include <stack>
#include <iostream>
#include <string>
#include <vector>
#include "vector/vector.hpp"
#include <cmath>
#include <map>
#include "map/map.hpp"
#include "set/set.hpp"
#include "stack/stack.hpp"
#include <iostream>
#include <algorithm>
#include <deque>

// #include "map/red_black_tree.hpp"
#define AA 1

void  print(ft::map<int, int>::iterator a, ft::map<int, int>::iterator b)
{
   while (a != b){
      std::cout<<a->first<<std::endl; a++;}
   std::cout<<"jjj\n";
   exit(0);
}

int maizn()
{
   // rbtree<ft::pair<int, int>, int> a;
   // for (size_t i = 0; i < 50; i++)
   // {
   //    a.insert(ft::pair<int, int>(i,i));
   //    /* code */
   // }
   // std::cout<<a.serch(ft::pair<int, int>(7, 33))->val->first<<std::endl;
   
// int g[100] = {0};
// // while(1){
//       srand(time(0));
//    // {

   


   std::map<int, int> mp;
   std::map<int, int> mq;

   mp = mq;
   std::cout<<((mp.begin()) == (mp.end())) <<std::endl;
   #ifndef AA
   #define
   print(mp.begin(), mp.end());
//    // std::cout<<"=========================================================\n=========================================================\n";
   for (size_t i = 0; i < 10 ; i++)
   {
      int k = rand()%30;
      // g[i] = k;
      std::cout<<"K: "<<k<<std::endl;
      mp.insert(ft::pair<int, int>(k,i));
   }
   // std::map<int, int>::iterator a = mp.begin();
   // (*a).first = 2;
   // std::cout<<".. "<<(*a).first<<" ..'\n"<<std::endl;
   // ++a;
   for (ft::map<int, int>::iterator i = mp.end(); i != mp.begin();)
   {
      --i;
      // i->second = 7;
      std::cout<<"--- [[[[]]]]"<<(*i).second<<" ..'\n"<<std::endl;
   }
   // exit(0);
   // mpp = mp;÷
   ft::map<int, int> mpp;
   // // mpp.clra
   mpp.insert(mp.begin(), mp.end());
   for (ft::map<int, int>::iterator i = mp.begin(); i != mp.end(); i++)
   {
      // std::cout<<"inside loop\n";
      // if (i.base())
      std::cout<<".. "<<mp.at((*i).first)<<" ..'\n"<<std::endl;
      /* code */
   }
   std::cout<<"............."<<std::endl;
   // mpp.insert(std::make_pair(203, 23));
   for (ft::map<int, int>::iterator i = mpp.begin(); i != mpp.end(); i++)
   {
      std::cout<<".. "<<(*i).first<<" ..'\n"<<std::endl;
      /* code */
   }
   mpp.erase(23);
   mpp[23] = 23;
   // mp.get_allocator();
   if (mpp == mp)
      std::cout<<"yes they are equal     mp.size = "<<mp.size()<<" and mpp.size = "<<mpp.size()<<"\n";
   if (mpp != mp)
      std::cout<<"yes they are NOT equal     mp.size = "<<mp.size()<<" and mpp.size = "<<mpp.size()<<"\n";
   if (mp > mpp)
      std::cout<<"mp greater thtn mpp\n";
   if (mp < mpp)
      std::cout<<"mp is smaler than mpp\n";
   //mp.erase(mp.begin(), mp.end());
   mp.swap(mpp);
   for (ft::map<int, int>::iterator i = mpp.begin(); i != mpp.end(); i++)
   {
      std::cout<<"LL "<<(i)->first<<" ..'\n"<<std::endl;
      /* code */
   }
   for (ft::map<int, int>::reverse_iterator i = mpp.rbegin(); i != mpp.rend(); i++)
   {
      /* code */
      std::cout<<"RE "<<(i)->first<<" ..'\n"<<std::endl;
   }
   
   // std::cout<<mp.at(23)<<"sshjsjsjhshjshushus\n";
   // std::cout<<"............."<<std::endl;
   // for (ft::map<int, int>::iterator i = mpp.begin(); i != mpp.end(); i++)
   // {
   //    std::cout<<".. "<<(*i).first<<" ..'\n"<<std::endl;
   //    /* code */
   // }
   
   // ++a;
   // ++a;
   // mp.erase(a);
   // a = mp.begin();
   // std::cout<<".. "<<(*a).first<<" ..'\n"<<std::endl;
   // ++a;
   // std::cout<<".. "<<(*a).first<<" ..'\n"<<std::endl;
   // ++a;
   // std::cout<<".. "<<(*a).first<<" ..'\n"<<std::endl;
   // ++a;
   // std::cout<<"-- "<<(*a).first<<" ..'\n"<<std::endl;
   // a++;
   // // std::cout<<".. "<<a.base()<<" ..'\n"<<std::endl;
   // // exit(00);
   // a--;

   // std::cout<<".. "<<(*a--).first<<" ..'\n"<<std::endl;
   // std::cout<<".. "<<(*a--).first<<" ..'\n"<<std::endl;
   // // a--;
   // std::cout<<".. "<<(*a).first<<" ..'\n"<<std::endl;
   // a--;
   // std::cout<<".. "<<(*a).first<<" ..'\n"<<std::endl;
   // ++a;
   // std::cout<<".. "<<(*a).first<<" ..'\n"<<std::endl;
   // ++a;
   // std::cout<<"-- "<<(*a).first<<" ..'\n"<<std::endl;
   // a--;
   // std::cout<<".. "<<(*a).first<<" ..'\n"<<std::endl;
   // std:÷:cout<<".. "<<a.base()<<" ..'\n"<<std::endl;
   // a++;
   // a++;
   // a++;
   // a++;
   // a++;
   // a--;
   // a--;
   // a--;
   // a--;
   // a--;
   // a--;
   // a--;
   // std::cout<<"s"<<(*a).first<<"s'\n"<<std::endl;
   // exit(0);
   // ++a;
   // std::cout<<(*a).first<<std::endl;
   // ++a;
   // std::cout<<(*a).first<<std::endl;
   // ++a;
   // std::cout<<(*a).first<<std::endl;
   // std::cout<<(*a).first<<std::endl;
   // std::cout<<(*(mp.erase(a))).first<<std::endl;
   // mp.print();
   // mp.dele();
   // mp.erase(a);
   // mp.erase(a);
   //    mp.insert(std::pair<int, int>(99,4));
   //    mp.insert(ft::pair<int, int>(-9,4));
   //    mp.insert(ft::pair<int, int>(-11,4));
   // mp.erase(a);
   //    mp.insert(ft::pair<int, int>(100,4));
   // mp.erase(a);
   // a = mp.begin();
   // mp.erase(a);
   // a = mp.begin();
   // mp.erase(a);
   // a = mp.begin();
   // mp.erase(a);
   // a = mp.begin();
   // mp.erase(a);
   // a = mp.begin();
   // mp.erase(a);
   // a = mp.begin();
   // mp.erase(a);
   // // exit(0);
   // a = mp.begin();
   // mp.erase(a);
   // a = mp.begin();
   // mp.erase(a);
   // a = mp.begin();
   // mp.erase(a);
   // exit(0);
   // a = mp.begin();
   // std::cout<<"scgxcv\n"<<std::endl;
   //}}
   // mp.erase(6)
   // for (auto &i : mp)
   // {
   //    std::cout<<i.first<<"   ";
   // }
   // ft::map<int, int> a;
   // a.insert(ft::pair<int, int>(1,2));
   // exit(0);
   #endif
   return (0);
}
#define  typedef ft::map<int, char>             map_i_c
// #define  map_i_c::iterator   map_it


// void  rest()
// {
//    ft::map<int, char> a;
//    for (size_t i = 0; i < 50; i++)
//       a.insert(ft::make_pair(i, i+50));
//    map_i_c::iterator k = a.begin();
// }



//284 76 122 463 429 212 154 140 293 419 430 245 43 269 334 381 231 298 176 46 335 78 223 127
void maina()
{
   ft::pair<int, int> s[100];
   srand(time(0));
   for (size_t i = 0; i < 100; i++)
      s[i].first = rand() % 500  , s[i].second = i, std::cout<<s[i].first<<" ";
   std::cout<<std::endl;
   ft::map<int, int> m(s, s + 100);
   // m.print();
   ft::map<int, int>::iterator it = m.begin() ;


      m.erase(it);

      it = m.begin();

      std::advance(it, 21);

      m.erase(it);

      it = m.end();

      std::advance(it, -10);

      m.erase(it);

      it = m.end();

      std::advance(it, -3);

      m.erase(it);
// exit(0);

      it = m.end();

      std::advance(it, -1);
      m.erase(it);

      it = m.begin();

      std::advance(it, 1);

      m.erase(it);
      for (it = m.begin(); it != m.end(); it = m.begin())
      {
         m.erase(it);
         // PRINT_ALL(m);
      }
      std::cout<<m.size()<<std::endl;
   // ft::map<int, int> a;
   // for (size_t i = 0; i < 4; i++)
   // {
   //    a.insert(ft::make_pair(i,i));
   // }
   // ft::map<int, int>::iterator b = a.begin(), c;
   // // for (size_t i = 0; i < 4; i++)
   // // {
   //    c = a.erase(b);
   // // }
   // std::cout<<c->first<<std::endl;
   // c = a.end();
   // std::advance(c, -1);
   // // c--;
   // a.erase(c);
   // // std::cout<<c->first<<std::endl;
   
}
int main()
{
   ft::map<int, int> a;
   ft::map<int, int>::iterator b;
   ft::map<int, int>::const_iterator c(a.begin());
   ft::map<int, int>::iterator d(c);
   
   // maina();
}