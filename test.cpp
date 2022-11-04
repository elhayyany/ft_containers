/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-hayy <ael-hayy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 11:02:24 by ael-hayy          #+#    #+#             */
/*   Updated: 2022/11/04 08:43:41 by ael-hayy         ###   ########.fr       */
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
// #include <iostream>


int main()
{

	ft::vector<int> a(10, 10);


 	ft::vector<int>::const_iterator u = a.begin();
 	ft::vector<int>::iterator u1;
	u1  = a.begin();
	u1 = u;
	// ft::cout<<a.capacity()<<ft::endl;
	// for (size_t i = 0; i < 7; i++)
	// 	a.push_back(i);
	// ft::vector<int>::iterator it = a.begin();
	// ft::vector<int>::iterator itg = a.begin();
	// it++;
	// it++;
	// it++;
	// it++;
	// a.insert(a.begin(), 99);
	// for (size_t i = 0; i < 5; i++)
	// // {
	// 	std::cout<<a[0]<<" ";
	// 	std::cout<<*it<<" ";
	// 	a[1] =0;
	// 	std::cout<<*(it+1)<<" ";

	// }
	// std::cout<< ft::is_integral<float>::value<<std::endl;
	// a.insert(a.end(), 8);
	// a.insert(a.begin(), 7);
	// a.insert(a.begin(), 7);
	// a.insert(a.begin(), 7);
	// a.insert(a.begin(), 7);
	// std::vector<int>::reverse_iterator    ap  = a.rbegin();
	// for (std::vector<int>::reverse_iterator it = a.rbegin(); it != a.rend(); it++)
	// {
	// 	std::cout<<*it<<" ";
	// }
	// ap[0] = 8;
	// std::cout<<a[0]<<std::endl;

}

