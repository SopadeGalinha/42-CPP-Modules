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

// Colors
#define RED "\033[1;31m"
#define BLUE "\033[1;34m"
#define GREEN "\033[1;32m"
#define YELLOW "\033[1;33m"
#define RESET "\033[0m"

// Class
/**
 * @brief
 * The ScalarConverter class provides static methods to convert a string
 * representation of a C++ literal to different data types.
 */

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
};

#endif