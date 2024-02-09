/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhogonca <jhogonca@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/23 12:46:45 by jhogonca          #+#    #+#             */
/*   Updated: 2023/12/23 12:46:45 by jhogonca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

int main(void)
{
	//inside
	bool result = bsp(Point(0, 0), Point(10, 30), Point(20, 0), Point(10, 15));
	if (result)
		std::cout << "Point inside of the triangle" << std::endl;
	else
		std::cout << "Point outside of the triangle" << std::endl;

	//outside
	result = bsp(Point(0, 0), Point(10, 30), Point(20, 0), Point(0, 100));
	if (result)
		std::cout << "Point inside of the triangle" << std::endl;
	else
		std::cout << "Point outside of the triangle" << std::endl;
	return EXIT_SUCCESS;
}
