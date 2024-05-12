/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhogonca <jhogonca@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/12 12:24:50 by jhogonca          #+#    #+#             */
/*   Updated: 2024/05/12 12:24:50 by jhogonca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ScalarConverter.hpp"

// Constructor
ScalarConverter::ScalarConverter(void)
{
	delete this;
	return;
}

// Copy Constructor
ScalarConverter::ScalarConverter(ScalarConverter const &src)
{
	*this = src;
	return;
}

// Destructor
ScalarConverter::~ScalarConverter(void)
{
	return;
}

// Operator Overload
ScalarConverter &ScalarConverter::operator=(ScalarConverter const &src)
{
	if (this == &src)
		return (*this);
	*this = src;
	return (*this);
}

void ScalarConverter::convert(const std::string &literal)
{
	std::cout << BLUE << "[Convert] -> " << RESET << literal << std::endl;
}

void ScalarConverter::toInt(const std::string &literal)
{
	std::cout << BLUE << "[ToInt] -> " << RESET << literal << std::endl;
}

void ScalarConverter::toChar(const std::string &literal)
{
	std::cout << BLUE << "[ToChar] -> " << RESET << literal << std::endl;
}

void ScalarConverter::toFloat(const std::string &literal)
{
	std::cout << BLUE << "[ToFloat] -> " << RESET << literal << std::endl;
}

void ScalarConverter::toDouble(const std::string &literal)
{
	std::cout << BLUE << "[ToDouble] -> " << RESET << literal << std::endl;
}
