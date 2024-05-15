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
#include <string>
#include <iomanip>
#include <limits>
#include <cmath>
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
	static void fromInt(const std::string &literal);
	static void fromChar(const std::string &literal);
	static void fromFloat(const std::string &literal);
	static void fromDouble(const std::string &literal);

	static int getScalarType(const std::string &literal);
	
	static bool _isChar(const std::string &literal);
	static bool _isInt(const std::string &literal);
	static bool _isFloat(const std::string &literal);
	static bool _isDouble(const std::string &literal);

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

	class integerOverflowException : public std::exception
	{
		virtual const char *what() const throw()
		{
			return (RED "Integer overflow." RESET);
		}
	};
};
	std::string toLowerCase(std::string str);

#endif
