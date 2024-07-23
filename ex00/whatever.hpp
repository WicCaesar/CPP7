/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnascime <cnascime@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 06:12:12 by cnascime          #+#    #+#             */
/*   Updated: 2024/07/15 06:21:54 by cnascime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>

// This is a template declaration, meaning the following function is a template
// and can be used with any type. It must be declared before every template.
template <typename T>
void	swap(T &a, T &b)
{
	T	temp = a;
	a = b;
	b = temp;
};

template <typename T>
T	min(T const &a, T const &b)
{
	if (a < b)
		return (a);
	return (b);
};

template <typename T>
T	max(T const &a, T const &b)
{
	return (a > b ? a : b); // Another approach with ternary operator.
};