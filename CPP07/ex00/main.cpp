/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhogonca <jhogonca@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/18 00:10:29 by jhogonca          #+#    #+#             */
/*   Updated: 2024/05/18 00:10:29 by jhogonca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "templates.hpp"

void	subjectTest(void)
{
    std::cout << BLUE << "\nSubject test:" << RESET << std::endl;

/*  Expected output:
	a = 3, b = 2
	min(a, b) = 2
	max(a, b) = 3
	c = chaine2, d = chaine1
	min(c, d) = chaine1
	max(c, d) = chaine2 */
	int a = 2;
	int b = 3;
	::swap( a, b );
	std::cout << "a = " << a << ", b = " << b << std::endl;
	std::cout << "min( a, b ) = " << ::min( a, b ) << std::endl;
	std::cout << "max( a, b ) = " << ::max( a, b ) << std::endl;
	std::string c = "chaine1";
	std::string d = "chaine2";
	::swap(c, d);
	std::cout << "c = " << c << ", d = " << d << std::endl;
	std::cout << "min( c, d ) = " << ::min( c, d ) << std::endl;
	std::cout << "max( c, d ) = " << ::max( c, d ) << std::endl;
}

void testInt() {
    int x = 10;
    int y = 20;
    std::cout << BLUE << "\nInitial values: x = " << x << ", y = " << y << RESET << std::endl;

    ::swap(x, y);
    std::cout << YELLOW << "\tAfter swap: x = " << x << ", y = " << y << RESET << std::endl;

    int minResult = ::min(x, y);
    std::cout << YELLOW << "\tMin of x and y: " << minResult << RESET << std::endl;

    int maxResult = ::max(x, y);
    std::cout << YELLOW << "\tMax of x and y: " << maxResult << RESET << std::endl;
}

void testFloat() {
	float x = 10.5;
	float y = 20.5;
	std::cout << BLUE << "\nInitial values: x = " << x << ", y = " << y << RESET << std::endl;

	::swap(x, y);
	std::cout << YELLOW << "\tAfter swap: x = " << x << ", y = " << y << RESET << std::endl;

	float minResult = ::min(x, y);
	std::cout << YELLOW << "\tMin of x and y: " << minResult << RESET << std::endl;

	float maxResult = ::max(x, y);
	std::cout << YELLOW << "\tMax of x and y: " << maxResult << RESET << std::endl;
}

void testString() {
	std::string x = "Hello";
	std::string y = "World";
	std::cout << BLUE << "\nInitial values: x = " << x << ", y = " << y << RESET << std::endl;

	::swap(x, y);
	std::cout << YELLOW << "\tAfter swap: x = " << x << ", y = " << y << RESET << std::endl;

	std::string minResult = ::min(x, y);
	std::cout << YELLOW << "\tMin of x and y: " << minResult << RESET << std::endl;

	std::string maxResult = ::max(x, y);
	std::cout << YELLOW << "\tMax of x and y: " << maxResult << RESET << std::endl;
}

int main()
{
	testInt();
	testFloat();
	testString();
	subjectTest();
	return (0);
}