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

#include "Fixed.hpp"

int main(void) {
	Fixed a;
	Fixed const b(10);
	Fixed const c(42.42f);
	Fixed const d(b);
	
	a = Fixed(1234.4321f);
	
	std::cout << "a is " << a << std::endl;
	std::cout << "b is " << b << std::endl; 
	std::cout << "c is " << c << std::endl; 
	std::cout << "d is " << d << std::endl;
	
	std::cout << "a is " << a.toInt() << " as integer" << std::endl; 
	std::cout << "b is " << b.toInt() << " as integer" << std::endl; 
	std::cout << "c is " << c.toInt() << " as integer" << std::endl; 
	std::cout << "d is " << d.toInt() << " as integer" << std::endl;
	
	return (0);
}
