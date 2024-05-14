/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhogonca <jhogonca@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 21:02:00 by jhogonca          #+#    #+#             */
/*   Updated: 2024/05/14 21:02:00 by jhogonca         ###   ########.fr       */
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

// Convert to Lower Case
std::string toLowerCase(std::string str)
{
	for (size_t i = 0; i < str.length(); i++)
		str[i] = std::tolower(str[i]);
	return (str);
}

// Check if Escape Sequence
static bool isEscSeq(const char *literal)
{
	return (strcmp(literal, "\\b") == 0) || \
		(strcmp(literal, "\\t") == 0) || \
		(strcmp(literal, "\\n") == 0) || \
		(strcmp(literal, "\\v") == 0) || \
		(strcmp(literal, "\\f") == 0) || \
		(strcmp(literal, "\\r") == 0) || \
		(strcmp(literal, "\\e") == 0) || \
		(strcmp(literal, "\\") == 0) || \
		(strcmp(literal, "\'") == 0);
}

// Check if Char
bool ScalarConverter::_isChar(const std::string &literal)
{		
	size_t length = literal.length();

	// Check if the string is a character
	if (length == 1 && isprint(literal[0]) && !isdigit(literal[0])) {
		return true;
	}
	// Check if the string is a character literal
	if (length == 3 && literal[0] == '\'' && literal[2] == '\'') {
		std::cout << "Entre" << std::endl;
		char ch = literal[1];
		if (isprint(ch) && ch >= 32 && ch <= 126) {
			return true;
		}
	}
	// Check if the string is escape sequence
	if (isEscSeq(literal.c_str())) {
		return true;
	}
	return false;
}

// Check if Int
bool ScalarConverter::_isInt(const std::string &literal)
{
	size_t length = literal.length();
	long i = 0;
	if (literal[0] == '-' || literal[0] == '+')
		i++;
	for (; i < (long)length; i++)
	{
		if (!isdigit(literal[i]))
			return false;
	}
	// check if the number is between the limits of int
	if (std::atoi(literal.c_str()) > std::numeric_limits<int>::max() || \
		std::atoi(literal.c_str()) < std::numeric_limits<int>::min())
		return false;
	return true;
}

// Check if Float
bool ScalarConverter::_isFloat(const std::string &literal)
{
	bool dot = false;
	long i = 0;
	if (IS_FLOAT_LITERAL(toLowerCase(literal)))
		return true;
	if (literal.find('.') == std::string::npos \
		|| literal.find('f') == std::string::npos)
		return false;
	if (literal[0] == '-' || literal[0] == '+')
		i++;
	for (; i < (long)literal.length(); i++)
	{
		if (literal[i] == '.')
		{
			if (!dot)
				dot = true;
			else
				return false;
		}
		// check if the character is a digit or a dot or a f
		if (!std::isdigit(literal[i]) && literal[i] != '.' && literal[i] != 'f')
			return false;
		// check if the f is at the end of the number
		if (literal[i] == 'f' && i != (long)literal.length() - 1)
			return false;
		// check if the f is after the dot
		if (literal[i] == 'f' && literal[i - 1] == '.')
			return false;
	}
	// check if the number is between the limits of float
	if (std::atof(literal.c_str()) > std::numeric_limits<float>::max() || \
		std::atof(literal.c_str()) < std::numeric_limits<float>::min())
		return false;
	return true;
}

// Check if Double
bool ScalarConverter::_isDouble(const std::string &literal)
{
	bool dot = false;
	long i = 0;
	if (IS_DOUBLE_LITERAL(toLowerCase(literal)))
		return true;
	if (literal.find('.') == std::string::npos)
		return false;
	if (literal[0] == '-' || literal[0] == '+')
		i++;
	for (; i < (long)literal.length(); i++)
	{
		if (literal[i] == '.')
		{
			if (!dot)
				dot = true;
			else
				return false;
		}
		// check if the character is a digit or a dot
		if (!std::isdigit(literal[i]) && literal[i] != '.')
			return false;
	}
	// check if the number is between the limits of double
	if (std::strtod(literal.c_str(), NULL) > std::numeric_limits<double>::max() || \
		std::strtod(literal.c_str(), NULL) < std::numeric_limits<double>::min())
		return false;
	return true;
}

// Get Scalar Type
int ScalarConverter::getScalarType(const std::string &literal)
{
	if (!literal.length() || literal.empty())
		throw invalidLiteralException();
	if (_isChar(literal))
		return CHAR;
	if (_isInt(literal))
		return INT;
	if(_isFloat(literal))
		return FLOAT;
	if (_isDouble(literal))
		return DOUBLE;
	throw invalidLiteralException();
}

// Convert
void ScalarConverter::convert(const std::string &literal)
{
	try
	{
		int type = getScalarType(literal);
		switch (type)
		{
		case CHAR:
			fromChar(literal);
			break;
		case INT:
			fromInt(literal);
			break;
		case FLOAT:
			fromFloat(literal);
			break;
		case DOUBLE:
			fromDouble(literal);
			break;
		default:
			break;
		}
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
}

void ScalarConverter::fromInt(const std::string &literal)
{
	int i = std::atoi(literal.c_str());
	std::cout << BLUE << "[fromInt] -> " << RESET << literal << std::endl;
	std::cout << "int: " << i << std::endl;
}

void ScalarConverter::fromChar(const std::string &literal)
{
	char c = literal[0];
	std::cout << BLUE << "[fromChar] -> " << RESET << literal << std::endl;
	std::cout << "char: " << c << std::endl;
}

void ScalarConverter::fromFloat(const std::string &literal)
{
	float f = std::atof(literal.c_str());
	std::cout << BLUE << "[fromFloat] -> " << RESET << literal << std::endl;
	std::cout << "float: " << f << std::endl;
}

void ScalarConverter::fromDouble(const std::string &literal)
{
	double d = std::atof(literal.c_str());
	std::cout << BLUE << "[fromDouble] -> " << RESET << literal << std::endl;
	std::cout << "double: " << d << std::endl;
	
}
