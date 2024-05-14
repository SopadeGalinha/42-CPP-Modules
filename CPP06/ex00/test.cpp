#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <climits>
#include <cmath>

class ScalarConverter
{
public:
	~ScalarConverter();

	static void convert(const std::string& literal);

private:
	ScalarConverter();
	ScalarConverter(const ScalarConverter& src);
	ScalarConverter& operator =(const ScalarConverter& src);
};


ScalarConverter::ScalarConverter() {}

ScalarConverter::~ScalarConverter() {}

ScalarConverter::ScalarConverter(const ScalarConverter& src)
{
	(void)src;
}

ScalarConverter& ScalarConverter::operator =(const ScalarConverter& src)
{
	(void)src;
	return *this;
}


static void convertFromChar(char c)
{
	// print char
	std::cout << "char: '" << c << "'" << std::endl;

	// print int
	std::cout << "int: " << static_cast<int>(c) << std::endl;

	// calculate precision
	long temp = std::labs(c);
	int len = 2;
	while (temp >= 10)
	{
		len++;
		temp /= 10;
	}
	std::cout << std::showpoint << std::setprecision(len);

	// print float
	std::cout << "float: "  << static_cast<float>(c) << "f" << std::endl;
	
	// print double
	std::cout << "double: " << static_cast<double>(c) << std::endl;
}

static void convertFromInt(int i)
{
	// print char
	if (i < CHAR_MIN || i > CHAR_MAX)
		std::cout << "char: impossible" << std::endl;
	else if (!std::isprint(i))
		std::cout << "char: Non displayable" << std::endl;
	else
		std::cout << "char: '" << static_cast<char>(i) << "'" << std::endl;

	// print int
	std::cout << "int: " << i << std::endl;

	// calculate precision
	long temp = std::labs(i);
	int len = 2;
	while (temp >= 10)
	{
		len++;
		temp /= 10;
	}
	std::cout << std::showpoint << std::setprecision(len);

	// print float
	std::cout << "float: "  << static_cast<float>(i) << "f" << std::endl;
	
	// print double
	std::cout << "double: " << static_cast<double>(i) << std::endl;
}

static void convertFromFloat(float f)
{
	// print char
	if (f != f || f < CHAR_MIN || f > CHAR_MAX)
		std::cout << "char: impossible" << std::endl;
	else if (f == f && !std::isprint(f))
		std::cout << "char: Non displayable" << std::endl;
	else
		std::cout << "char: '" << static_cast<char>(f) << "'" << std::endl;

	// print int
	if (f != f || f < INT_MIN || f > INT_MAX)
		std::cout << "int: impossible" << std::endl;
	else
		std::cout << "int: " << static_cast<int>(f) << std::endl;

	// print float
	if (f == std::floor(f) && std::isfinite(f))
		std::cout << "float: "  << f << ".0f" << std::endl;
	else
		std::cout << "float: "  << f << "f" << std::endl;
	
	// print double
	if (f == std::floor(f) && std::isfinite(f))
		std::cout << "double: "  << static_cast<double>(f) << ".0" << std::endl;
	else
		std::cout << "double: " << static_cast<double>(f) << std::endl;
}

static void convertFromDouble(double d)
{
	// print char
	if (d != d || d < CHAR_MIN || d > CHAR_MAX)
		std::cout << "char: impossible" << std::endl;
	else if (d == d && !std::isprint(d))
		std::cout << "char: Non displayable" << std::endl;
	else
		std::cout << "char: '" << static_cast<char>(d) << "'" << std::endl;

	// print int
	if (d != d || d < INT_MIN || d > INT_MAX)
		std::cout << "int: impossible" << std::endl;
	else
		std::cout << "int: " << static_cast<int>(d) << std::endl;

	// print float
	if ((float)d == std::floor((float)d) && std::isfinite(d))
		std::cout << "float: "  << static_cast<float>(d) << ".0f" << std::endl;
	else
		std::cout << "float: "  << static_cast<float>(d) << "f" << std::endl;
	
	// print double
	if (d == std::floor(d) && std::isfinite(d))
		std::cout << "double: "  << d << ".0" << std::endl;
	else
		std::cout << "double: " << d << std::endl;
}


void ScalarConverter::convert(const std::string& literal)
{
	bool error = false;

	// some validations
	if (literal[0] == '\0' || literal[0] == ' ')
	{
		std::cerr << "Invalid value." << std::endl; // it's empty!
		return;
	}

	// check for double
	if (literal == "-inf" || literal == "+inf" || literal == "inf" || literal == "nan")
	{
		convertFromDouble(std::atof(literal.c_str()));
		return;
	}
	if (literal.find('.') != std::string::npos && literal.find('f') == std::string::npos)
	{
		bool foundSeparator = false;
		for (size_t i = 0; i < literal.length(); i++)
		{
			// skip plus or minus sign
			if (i == 0 && (literal[0] == '-' || literal[0] == '+') && literal.length() > 1)
				i++;
			// more than one . is bad
			if (literal[i] == '.')
			{
				if (!foundSeparator)
					foundSeparator = true;
				else
				{
					error = true;
					break;
				}
			}
			// characters other than digits or . is bad
			if (!std::isdigit(literal[i]) && literal[i] != '.')
			{
				error = true;
				break;
			}
			// . at end is bad
			if (i == literal.length() - 1 && literal[i] == '.')
			{
				error = true;
				break;
			}
		}
		if (!error)
		{
			convertFromDouble(std::atof(literal.c_str()));
			return;
		}
	}
	// check for float
	if (literal == "-inff" || literal == "+inff" || literal == "inff" || literal == "nanf")
	{
		convertFromFloat(std::atof(literal.c_str()));
		return;
	}
	if (literal.find('.') != std::string::npos && literal.find('f') != std::string::npos)
	{
		bool foundSeparator = false;
		for (size_t i = 0; i < literal.length(); i++)
		{
			// skip plus or minus sign
			if (i == 0 && (literal[0] == '-' || literal[0] == '+') && literal.length() > 1)
				i++;
			// more than one . is bad
			if (literal[i] == '.')
			{
				if (!foundSeparator)
					foundSeparator = true;
				else
				{
					error = true;
					break;
				}
			}
			// characters other than digits or . or f is bad
			if (!std::isdigit(literal[i]) && literal[i] != '.' && literal[i] != 'f')
			{
				error = true;
				break;
			}
			// f anywhere other than at the end is bad
			if (literal[i] == 'f' && i != literal.length() - 1)
			{
				error = true;
				break;
			}
			// . before f is bad
			if (literal[i] == 'f' && literal[i - 1] == '.')
			{
				error = true;
				break;
			}
		}
		if (!error)
		{
			convertFromFloat(std::atof(literal.c_str()));
			return;
		}
	}

	// check for char
	if (literal.length() == 1 && std::isprint(literal[0]) && !std::isdigit(literal[0]))
	{
		convertFromChar(literal[0]);
		return ;
	}

	// check for int
	// every character is a number
	long temp = 0;
	for (size_t i = 0; i < literal.length(); i++)
	{
		if (i == 0 && (literal[0] == '-' || literal[0] == '+') && literal.length() > 1)
			i++;
		if (!std::isdigit(literal[i]))
		{
			error = true;
			break;
		}
		temp = temp * 10 + literal[i] - '0';
		if ((literal[0] != '-' && temp > INT_MAX) || (literal[0] == '-' && -temp < INT_MIN))
		{
			error = true;
			break;
		}
	}
	if (!error)
	{
		if (literal[0] == '-')
			temp = -temp;
		convertFromInt((int)temp);
		return;
	}

	// error
	std::cerr << "Invalid value." << std::endl;
}

#include <stdio.h>

int main(int argc, char **argv)
{
	float f = .45f;
	std::cout << "f: " << f << std::endl;
	if (argc != 2)
	{
		std::cerr << "Invalid number of arguments." << std::endl;
		return 1;
	}
	ScalarConverter::convert(argv[1]);
	return 0;
}