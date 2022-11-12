/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-hayy <ael-hayy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 11:02:24 by ael-hayy          #+#    #+#             */
/*   Updated: 2022/11/12 15:56:55 by ael-hayy         ###   ########.fr       */
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



int main()
{
    ft::stack<int> a;
    for (int i = 0; i < 10; i++)
    {
        a.push(i);
    }
    ft::stack<int> v;
    for (int i = 0; i < 10; i++)
    {
        v.push(i);
    }
    std::cout<< (v==a) <<std::endl;
}