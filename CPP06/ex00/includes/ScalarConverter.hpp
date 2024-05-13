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
#include "Macros.hpp"

// Class
	/*** @brief
	 * The ScalarConverter class provides static methods to convert a string
	 * representation of a C++ literal to different data types.*/
class ScalarConverter
{
private:
		/*** @brief
		 * Private constructor to prevent
		 * instantiation of the ScalarConverter class.*/
	ScalarConverter();

		/*** @brief
		 * Copy constructor of the ScalarConverter class.
		 * @param src The ScalarConverter object to be copied.*/
	ScalarConverter(const ScalarConverter &src);

		/*** @brief
		 * Destructor of the ScalarConverter class.*/
	~ScalarConverter();

		/*** @brief
		 * Assignment operator of the ScalarConverter class.
		 * @param src The ScalarConverter object to be assigned.
		 * @return A reference to the assigned ScalarConverter object.*/
	ScalarConverter &operator=(const ScalarConverter &src);

		/*** @brief
		 * Determines the type of the scalar literal.
		 * @param literal The string representation of the C++ literal.
		 * @return The type of the scalar literal.*/
	static int getScalarType(const std::string &literal);

		/*** @brief
		 * Converts a string to lowercase.
		 * @param str The string to be converted to lowercase.
		 * @return The lowercase version of the string.*/
	static std::string toLowerCase(std::string str);

		/*** @brief
		 * Checks if the string is a character.
		 * @param literal The string to be checked.
		 * @return True if the string is a character, false otherwise.*/
	static bool _isChar(const std::string &literal);
public:

		/*** @brief Converts a string representation of a
		 * C++ literal to different data types.
		 * @param literal The string representation of
		 * the C++ literal to be converted.*/
	static void convert(const std::string &literal);

		/*** @brief Converts a string representation of
		 * a C++ literal to an integer.
		 * @param literal The string representation of
		 * the C++ literal to be converted.*/
	static void toInt(const std::string &literal);

		/*** @brief Converts a string representation of 
		 * a C++ literal to a character.
		 * @param literal The string representation of 
		 * the C++ literal to be converted.*/
	static void toChar(const std::string &literal);

		/*** @brief Converts a string representation of a 
		 * C++ literal to a float.
		 * @param literal The string representation of 
		 * the C++ literal to be converted.*/
	static void toFloat(const std::string &literal);

		/*** @brief Converts a string representation of 
		 * a C++ literal to a double.
		 * @param literal The string representation of 
		 * the C++ literal to be converted.*/
	static void toDouble(const std::string &literal);

		/*** @brief Converts a string representation of 
		 * a C++ literal to a long double.
		 * @param literal The string representation of 
		 * the C++ literal to be converted.*/
	class invalidLiteralException : public std::exception
	{
		virtual const char *what() const throw()
		{
			return (RED "Invalid scalar literal." RESET);
		}
	};
};

#endif
