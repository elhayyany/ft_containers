/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-hayy <ael-hayy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 11:02:24 by ael-hayy          #+#    #+#             */
/*   Updated: 2022/10/28 15:06:42 by ael-hayy         ###   ########.fr       */
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
#include <iostream>


int main()
{
	
	ft::vector<int> a(10, 10);
	ft::vector<int>::iterator    ap  = a.begin();
	ap = a.begin();
	std::cout<<*++ap<<std::endl;
	
	
}
