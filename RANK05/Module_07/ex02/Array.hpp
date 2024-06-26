/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhogonca <jhogonca@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/18 00:35:52 by jhogonca          #+#    #+#             */
/*   Updated: 2024/05/18 00:35:52 by jhogonca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
# define ARRAY_HPP

// Libraries
#include <sstream>
#include <iostream>
#include <string>
#include <exception>

template <typename T>
class Array
{
	private:
		T				*_array;
		unsigned int	_size;
	public:
		// Constructors & Destructors
		Array();
		Array(unsigned int n);
		Array(Array const &other);
		~Array();

		// Assingment operator
		Array &operator=(Array const &other);
		
		// Member functions
		T &operator[](const int index);
		unsigned int size();
		
		// Exceptions
		class OutOfLimits : public std::exception
		{
			public:
				virtual const char *what() const throw();
		};
};

#endif
