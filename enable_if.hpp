/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enable_if.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-hayy <ael-hayy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 16:23:10 by ael-hayy          #+#    #+#             */
/*   Updated: 2022/11/01 16:24:24 by ael-hayy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

template< bool B, class T = void >
struct enable_if{};

// struct enable_if{};