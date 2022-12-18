/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-hayy <ael-hayy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 11:03:55 by ael-hayy          #+#    #+#             */
/*   Updated: 2022/12/06 09:56:18 by ael-hayy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vector>
#include <algorithm>
#include <iostream>
#include <map>
class p{
    public:
    typedef int INTEGER;
};

template<typename T>class p2{
    public:
    p2(){}
    typedef typename T::INTEGER *ptr;
};

int main()
{
    int a = 10;
    p2<p>::ptr l = &a;
    std::cout<<*l<<"\n";
    // net *h = & networking;
    // // std :: cout << networking.a;
    // networking.setter(68767687);
    // networking.printA();
    // int h = networking.getter();
    // std :: cout << h << std :: endl;

    // std :: vector <int> arr;

    // for (int i = 0; i < 5; i++)
    // {
    //     arr.push_back(i);
    // }
}
