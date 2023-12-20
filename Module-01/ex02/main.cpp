/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhogonca <jhogonca@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 17:24:15 by jhogonca          #+#    #+#             */
/*   Updated: 2023/12/19 17:24:15 by jhogonca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#define RESET	"\033[0m"
#define RED		"\033[1m\033[31m"
#define GREEN	"\033[1m\033[32m"
#define YELLOW	"\033[1m\033[33m"
#define BLUE	"\033[1m\033[34m"

int main(void)
{
	std::string str = "HI THIS IS BRAIN";
	std::string *ptr = &str;
	std::string &ref = str;

	std::cout << BLUE << "POINTER VS REFERENCE\n" << std::endl;
	
	std::cout << BLUE << "Variables" << RESET << std::endl;
	std::cout << YELLOW << "\t str = HI THIS IS BRAIN" << std::endl;
	std::cout << YELLOW << "\t*ptr = &str" << std::endl;
	std::cout << YELLOW << "\t&ref = str" << std::endl;

	std::cout << BLUE << "Values" << RESET << std::endl;
	std::cout << GREEN << "\t str: " << str << std::endl;
	std::cout << GREEN << "\t*ptr: " << *ptr << std::endl;
	std::cout << GREEN << "\t ref: " << ref << std::endl;

	std::cout << BLUE << "Addresses" << RESET << std::endl;
	std::cout << RED << "\t&str: " << &str << std::endl;
	std::cout << RED << "\t ptr: " << ptr << std::endl;
	std::cout << RED << "\t&ref: " << &ref << std::endl;
	return (0);
}