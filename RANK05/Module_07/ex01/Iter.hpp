/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhogonca <jhogonca@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/18 00:25:02 by jhogonca          #+#    #+#             */
/*   Updated: 2024/05/18 00:25:02 by jhogonca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
# define ITER_HPP

// Libraries
# include <iostream>

// Template to iterate over an array
template <typename T>
void	iter(T *array, int length, void (*func)(T const &))
{
	for (int i = 0; i < length; i++)
		func(array[i]);
}

template <typename T>
void	printElement(T const &element)
{
	std::cout << element << std::endl;
}

#endif
