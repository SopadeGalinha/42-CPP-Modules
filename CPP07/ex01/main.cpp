/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhogonca <jhogonca@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/18 00:26:52 by jhogonca          #+#    #+#             */
/*   Updated: 2024/05/18 00:26:52 by jhogonca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Iter.hpp"

int main()
{
	int intArray[] = {1, 2, 3, 4, 5};
	float floatArray[] = {1.1, 2.2, 3.3, 4.4, 5.5};
	std::string stringArray[] = {"one", "two", "three", "four", "five"};

	std::cout << "Int array:" << std::endl;
	iter(intArray, 5, printElement);
	
	std::cout << "Float array:" << std::endl;
	iter(floatArray, 5, printElement);
	
	std::cout << "String array:" << std::endl;
	iter(stringArray, 5, printElement);

	std::cout << "Char array:" << std::endl;
	iter("Hello", 5, printElement);

	return 0;
}
