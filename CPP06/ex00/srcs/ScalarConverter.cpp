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
std::string ScalarConverter::toLowerCase(std::string str)
{
	for (size_t i = 0; i < str.length(); i++)
		str[i] = std::tolower(str[i]);
	return (str);
}

// Check if Char
bool ScalarConverter::_isChar(const std::string &literal)
{
	size_t length = literal.length();
	std::cout << "Length: " << length << std::endl;
	switch(length)
	{
		case 1:
			if (std::isprint(literal[0]))
				return true;
			break;
		case 2:
			if (literal[0] == '\'' && std::isprint(literal[1]) && literal[2] == '\'')
				return true;
			break;
		default:
			break;
	}
	return false;
}	

// Get Scalar Type
int ScalarConverter::getScalarType(const std::string &literal)
{
	if(_isChar(literal))
		return CHAR;
/* 	if(_isInt(lower))
		return INT;
	if(_isFloat(lower))
		return FLOAT;
	if(_isDouble(lower))
		return DOUBLE; */
	throw invalidLiteralException();
}

void ScalarConverter::convert(const std::string &literal)
{
	try
	{
		int type = getScalarType(literal);
		switch (type)
		{
		case CHAR:
			toChar(literal);
			break;
		case INT:
			toInt(literal);
			break;
		case FLOAT:
			toFloat(literal);
			break;
		case DOUBLE:
			toDouble(literal);
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
