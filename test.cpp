/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-hayy <ael-hayy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 11:02:24 by ael-hayy          #+#    #+#             */
/*   Updated: 2022/11/07 10:55:29 by ael-hayy         ###   ########.fr       */
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
#include <cmath>
// #include "set.hpp"
// #include "map.hpp"
// #include "stack.hpp"
// #include <iostream>


int main()
{
{
    std::cout<<std::endl<<"---------------FT---------------"<<std::endl;
	ft::vector<int> s(10, 10);
    for (int i = 0; i < 10; i++)
    {
        s[i] = i;
    }
    s.insert(++(++s.begin()), 5, 9);
    for (ft::vector<int>::iterator u = s.begin(); u != s.end(); u++)
    {
        std::cout<<*u<<" ";
    }
    s.insert(++(++(++(++s.begin()))), 78);
    std::cout<<std::endl;
    for (ft::vector<int>::iterator u = s.begin(); u != s.end(); u++)
    {
        std::cout<<*u<<" ";
    }
}
    std::cout<<std::endl<<"---------------STD---------------"<<std::endl;
{
	std::vector<int> s(10, 10);
    for (int i = 0; i < 10; i++)
    {
        s[i] = i;
    }
    s.insert(++(++s.begin()), 5, 9);
    for (std::vector<int>::iterator u = s.begin(); u != s.end(); u++)
    {
        std::cout<<*u<<" ";
    }
    std::cout<<std::endl;
    s.insert(++(++(++(++s.begin()))), 78);
    for (std::vector<int>::iterator u = s.begin(); u != s.end(); u++)
    {
        std::cout<<*u<<" ";
    }
}	

}

