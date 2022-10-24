/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-hayy <ael-hayy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 11:02:24 by ael-hayy          #+#    #+#             */
/*   Updated: 2022/10/24 09:47:13 by ael-hayy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


// #include <vector>
// #include <map>
// #include <stack>
// #include <set>
// #include <iostream>
// #include <iostream>
// #include <string>
#include <vector>
// #include <algorithm>
// #include "vector.hpp"
// #include "set.hpp"
// #include "map.hpp"
// #include "stack.hpp"
#include <iostream>
int main()
{
   std::vector<int> a;
   a.pop_back();
   a.pop_back();
   a.pop_back();
   std::cout<<a.size()<<"  "<<a.capacity()<< "  "<<"  "<<a.empty()<<"   "<<std::endl;
//    a.push_back(2);
   std::cout<<a.size()<<"  "<<a.capacity()<< "  "<<"  "<<a.empty()<<"   "<<std::endl;
}
