/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhogonca <jhogonca@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/12 12:36:59 by jhogonca          #+#    #+#             */
/*   Updated: 2024/05/12 12:36:59 by jhogonca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ScalarConverter.hpp"

int main(int argc, char **argv)
{
	(void)argv;
	if (argc != 2)
	{
		std::cerr << RED << "Error: Invalid number of arguments" << RESET << std::endl;
		return (1);
	}
	ScalarConverter::convert(argv[1]);
	return (0);
}