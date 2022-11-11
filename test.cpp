/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-hayy <ael-hayy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 11:02:24 by ael-hayy          #+#    #+#             */
/*   Updated: 2022/11/11 09:42:13 by ael-hayy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


// #include <vector>
// #include <map>
// #include <stack>
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
// #include "stack.hpp"
// #include <iostream>



int main()
{
	ft::vector<int> s(15, -1);
	ft::vector<int> a;
	for (size_t i = 0; i < 16; i++)
	{
		// if (i == 14)
		// a.push_back(1);
		// else
		a.push_back(-1);
	}
	std::cout<<a.capacity()<<"  "<<a.size()<<"       "<<s.capacity()<<"  "<<s.size()<<std::endl;
	
	std::cout<< (s != a) <<std::endl;
}
