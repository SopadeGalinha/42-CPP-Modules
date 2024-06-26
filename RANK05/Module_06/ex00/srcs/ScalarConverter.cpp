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

// Check if Char
bool _isChar(const std::string &literal)
{
	return (literal.length() == 1 && !std::isdigit(literal[0]) && std::isprint(literal[0]));
}

// Check if Int
bool _isInt(const std::string &literal)
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
	return true;
}

// Check if Float
bool _isFloat(const std::string &literal)
{
	bool dot = false;
	long i = 0;
	if (IS_FLOAT_LITERAL(toLowerCase(literal)))
		return true;
	if (literal.find('f') == std::string::npos || literal[literal.length() - 1] != 'f')
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
	return true;
}

// Check if Double
bool _isDouble(const std::string &literal)
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
	return true;
}

// Get Scalar Type
int getScalarType(const std::string &literal)
{
	if (!literal.length() || literal.empty())
		throw invalidLiteralException();
	if (_isChar(literal))
		return CHAR;
	if (_isInt(literal))
		return INT;
	if (_isFloat(literal))
		return FLOAT;
	if (_isDouble(literal))
		return DOUBLE;
	throw invalidLiteralException();
}

void printChar(char c)
{
	std::cout << GREEN << "[char] ----->\t[" << RESET
			  << c << GREEN << "]" << RESET << std::endl;
}

void printInt(long i)
{
	if (i < INT_MIN || i > INT_MAX)
	{
		std::cout << RED << "[int] ------>\t[" << RESET
				  << NO_DISPLAYABLE << RED << "]" << RESET << std::endl;
		return;
	}
	std::cout << GREEN << "[int] ------>\t[" << RESET
			  << i << GREEN << "]" << RESET << std::endl;
}

void printFloat(float f)
{
	std::ostringstream oss;
	oss << f;
	if (oss.str().find("e") != std::string::npos)
	{
		std::cout << RED << "[float] ---->\t[" << RESET
				  << NO_DISPLAYABLE << RED << "]" << RESET << std::endl;
		return;
	}
	std::cout << GREEN << "[float] ---->\t[" << RESET;
	(f == std::floor(f) ? std::cout << f << ".0f"
						: std::cout << f << "f");
	std::cout << GREEN << "]" << RESET << std::endl;
}

void printDouble(double d)
{
	std::ostringstream oss;
	oss << d;
	if (oss.str().find("e") != std::string::npos)
	{
		std::cout << RED << "[double] --->\t[" << RESET
				  << NO_DISPLAYABLE << RED << "]" << RESET << std::endl;
		return;
	}
	std::cout << GREEN << "[double] --->\t[" << RESET
			  << d << ".0" << GREEN << "]" << RESET << std::endl;
}

void printImpossible(const std::string &literal)
{
	std::cout << RED << "[char] ----->\t[" << RESET
			  << IMPOSSIBLE << RED << "]" << RESET << std::endl;
	std::cout << RED << "[int] ------>\t[" << RESET
			  << IMPOSSIBLE << RED << "]" << RESET << std::endl;
	std::cout << GREEN << "[float] ---->\t[" << RESET;
	if (strcmp(toLowerCase(literal).c_str(), FLT_NAN) == 0)
	{
		std::cout << FLT_NAN << GREEN << "]" << RESET << std::endl;
		std::cout << GREEN << "[double] --->\t[" << RESET
				  << DBL_NAN << GREEN << "]" << RESET << std::endl;
	}
	else if (strcmp(toLowerCase(literal).c_str(), FLT_POS_INF) == 0)
	{
		std::cout << FLT_POS_INF << GREEN << "]" << RESET << std::endl;
		std::cout << GREEN << "[double] --->\t[" << RESET
				  << DBL_POS_INF << GREEN << "]" << RESET << std::endl;
	}
	else if (strcmp(toLowerCase(literal).c_str(), FLT_NEG_INF) == 0)
	{
		std::cout << FLT_NEG_INF << GREEN << "]" << RESET << std::endl;
		std::cout << GREEN << "[double] --->\t[" << RESET
				  << DBL_NEG_INF << GREEN << "]" << RESET << std::endl;
	}
	else if (strcmp(toLowerCase(literal).c_str(), DBL_NAN) == 0)
	{
		std::cout << FLT_NAN << GREEN << "]" << RESET << std::endl;
		std::cout << GREEN << "[double] ---->\t[" << RESET
				  << DBL_NAN << GREEN << "]" << RESET << std::endl;
	}
	else if (strcmp(toLowerCase(literal).c_str(), DBL_POS_INF) == 0)
	{
		std::cout << FLT_POS_INF << GREEN << "]" << RESET << std::endl;
		std::cout << GREEN << "[float] ---->\t[" << RESET
				  << DBL_POS_INF << GREEN << "]" << RESET << std::endl;
	}
	else if (strcmp(toLowerCase(literal).c_str(), DBL_NEG_INF) == 0)
	{
		std::cout << FLT_NEG_INF << GREEN << "]" << RESET << std::endl;
		std::cout << GREEN << "[float] ---->\t[" << RESET
				  << DBL_NEG_INF << GREEN << "]" << RESET << std::endl;
	}
	else
	{
		std::cout << IMPOSSIBLE << GREEN << "]" << RESET << std::endl;
		std::cout << GREEN << "[double] --->\t[" << RESET
				  << IMPOSSIBLE << GREEN << "]" << RESET << std::endl;
	}
}

void fromChar(const std::string &literal)
{
	char c = static_cast<char>(literal[0]);
	std::cout << BLUE
			  << "[fromChar] ->\t[" << RESET
			  << literal << BLUE << "]"
			  << RESET << std::endl;

	printChar(c);
	printInt(static_cast<int>(c));
	printFloat(static_cast<float>(c));
	printDouble(static_cast<double>(c));
}

void fromInt(const std::string &literal)
{
	long i = std::atol(literal.c_str());

	std::cout << BLUE
			  << "[fromInt] -->\t[" << RESET
			  << literal << BLUE << "]"
			  << RESET << std::endl;

	if (i < 126 && i > 32)
		printChar(static_cast<char>(i));
	else
		std::cout << RED
				  << "[char] ----->\t[" << RESET
				  << NO_DISPLAYABLE << RED << "]" << RESET << std::endl;
	printInt(i);
	printFloat(static_cast<float>(i));
	printDouble(static_cast<double>(i));
}

void fromFloat(const std::string &literal)
{
	std::cout << BLUE
			  << "[fromFloat] ->\t[" << RESET
			  << literal << BLUE << "]"
			  << RESET << std::endl;

	if (IS_DOUBLE_LITERAL(toLowerCase(literal)) || IS_FLOAT_LITERAL(toLowerCase(literal)))
		return (printImpossible(literal));
	float f = std::strtof(literal.c_str(), NULL);

	if (f != f || f > 32 || f < 126)
		printChar(static_cast<char>(f));
	else
		std::cout << RED << "[char] ----->\t["
				  << RESET << NO_DISPLAYABLE << RED << "]" << RESET << std::endl;

	// print int
	if (f != f || f < INT_MIN || f > INT_MAX)
		printInt(LONG_MAX);
	printFloat(f);
	printDouble(static_cast<double>(f));
}

void fromDouble(const std::string &literal)
{
	double d = std::strtod(literal.c_str(), NULL);

	std::cout << BLUE
			  << "[fromDouble] ->\t[" << RESET
			  << literal << BLUE << "]"
			  << RESET << std::endl;

	if (IS_DOUBLE_LITERAL(toLowerCase(literal)) || IS_FLOAT_LITERAL(toLowerCase(literal)))
		return (printImpossible(literal));

	if (d != d || d > 32 || d < 126)
		printChar(static_cast<char>(d));
	else
		std::cout << RED << "[char] ----->\t["
				  << RESET << NO_DISPLAYABLE << RED << "]" << RESET << std::endl;

	// print int
	if (d != d || d < INT_MIN || d > INT_MAX)
		printInt(LONG_MAX);
	printFloat(static_cast<float>(d));
	printDouble(d);
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
			throw impossibleConversionException();
		}
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
}
