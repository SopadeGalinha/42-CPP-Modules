/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhogonca <jhogonca@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/12 11:52:51 by jhogonca          #+#    #+#             */
/*   Updated: 2024/05/12 11:52:51 by jhogonca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

// Libraries
#include <iostream>
#include <iomanip>
#include <limits.h>
#include <cmath>
#include <sstream>
#include <string.h>
#include <cstdlib>
#include <cfloat>
#include "Macros.hpp"

// Class
class ScalarConverter
{	
	// Constructors and Destructor
	ScalarConverter();
	ScalarConverter(const ScalarConverter &src);
	~ScalarConverter();

	// Assignment Operator
	ScalarConverter &operator=(const ScalarConverter &src);

public:
	
	// Methods
	static void convert(const std::string &literal);
};
	// Exceptions
	class invalidLiteralException : public std::exception
	{
		virtual const char *what() const throw()
		{
			return (RED "Invalid scalar literal." RESET);
		}
	};

	class impossibleConversionException : public std::exception
	{
		virtual const char *what() const throw()
		{
			return (RED "Impossible conversion." RESET);
		}
	};

#endif
