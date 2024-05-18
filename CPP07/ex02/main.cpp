/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhogonca <jhogonca@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/18 00:40:12 by jhogonca          #+#    #+#             */
/*   Updated: 2024/05/18 00:40:12 by jhogonca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"
#include "Array.tpp"

int main(void)
{
	// Create an Array object of type int with size 5
	Array<int> intArray(5);

	// Create an Array object of type float with size 5
	Array<float> floatArray(5);

	// Create an Array object of type std::string with size 5
	Array<std::string> stringArray(5);

	// Code to populate the intArray with values from 0 to 4
	for (unsigned int i = 0; i < intArray.size(); i++)
	{
		intArray[i] = i;
	}

	// Code to populate the floatArray with values from 0.1 to 4.1
	for (unsigned int i = 0; i < floatArray.size(); i++)
	{
		floatArray[i] = i + 0.1;
	}

	// Print the elements of the intArray
	std::cout << "Int array:" << std::endl;
	for (unsigned int i = 0; i < intArray.size(); i++)
	{
		std::cout << intArray[i] << std::endl;
	}

	// Print the elements of the floatArray
	std::cout << "Float array:" << std::endl;
	for (unsigned int i = 0; i < floatArray.size(); i++)
	{
		std::cout << floatArray[i] << std::endl;
	}

	// Print the elements of the stringArray
	std::cout << "String array:" << std::endl;
	for (unsigned int i = 0; i < stringArray.size(); i++)
	{
		std::cout << stringArray[i] << std::endl;
	}

	// Try to access an element out of limits and catch the exception
	try
	{
		std::cout << "Trying to access an element out of limits:" << std::endl;
		std::cout << intArray[5] << std::endl;
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}

	return 0;
}