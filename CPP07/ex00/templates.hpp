/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   templates.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhogonca <jhogonca@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/18 00:07:02 by jhogonca          #+#    #+#             */
/*   Updated: 2024/05/18 00:07:02 by jhogonca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TEMPLATES_HPP
#define TEMPLATES_HPP

// Libraries
#include <iostream>

// Colors
#define RED "\033[0;31m"
#define GREEN "\033[0;32m"
#define YELLOW "\033[0;33m"
#define BLUE "\033[0;34m"
#define RESET "\033[0m"

// Template function to swap two values
template <typename T>
void swap(T &a, T &b)
{
	T swap = a;
	a = b;
	b = swap;
}

// Template function to get the min value between two values
template <typename T>
T min(const T &a, const T &b)
{
	return (a < b) ? a : b;
}

// Template function to get the max value between two values
template <typename T>
T max(const T &a, const T &b)
{
	return (a > b) ? a : b;
}

#endif
