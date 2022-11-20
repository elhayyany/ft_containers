/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-hayy <ael-hayy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 11:02:24 by ael-hayy          #+#    #+#             */
/*   Updated: 2022/11/17 17:07:27 by ael-hayy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


// #include <vector>
// #include <map>
#include <stack>
// #include <set>
// #include <iostream>
#include <iostream>
#include <string>
#include <vector>
// #include <algorithm>
#include "vector.hpp"
#include <cmath>
// #include "set.hpp"
// #include "map.hpp"
#include "stack.hpp"
// #include <iostream>
#include <algorithm>


int main()
{
   ft::vector<int> j;
   for (size_t i = 250; i > 0; i--)
   {
    j.push_back(i);
   }
    std::sort(j.begin(), j.end());
    ft::vector<int>::iterator it = j.begin();
    ft::vector<int>::reverse_iterator   y(it);
    
   
}