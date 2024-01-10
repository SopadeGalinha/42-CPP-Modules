/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhogonca <jhogonca@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/22 17:28:31 by jhogonca          #+#    #+#             */
/*   Updated: 2023/12/22 17:28:31 by jhogonca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

// Constructor
Fixed::Fixed(void) : _rawBits(0) {
	std::cout << GREEN << "Fixed - Default constructor called" << RESET << std::endl;
	return ;
}

// Copy constructor
Fixed::Fixed(const Fixed &other) : _rawBits(other._rawBits) {
	std::cout << BLUE << "Fixed - Copy constructor called" << RESET << std::endl;
	*this = other;
}

// Destructor
Fixed::~Fixed(void) {
	std::cout << RED << "Fixed - Destructor called" << RESET << std::endl;
}

// Operator overload - Assignment
Fixed &Fixed::operator=(const Fixed &other) {
	std::cout << BLUE << "Fixed - Copy assignment operator called" << RESET << std::endl;
	if (this == &other)
		return (*this);
	_rawBits = other.getRawBits();
	return (*this);
}

// Setter
void	Fixed::setRawBits(int const raw) {
	std::cout << GREEN << "Fixed - setRawBits member function called" << RESET << std::endl;
	_rawBits = raw;
}

//Getter
int	Fixed::getRawBits(void) const {
	std::cout << GREEN << "Fixed - getRawBits member function called" << RESET << std::endl;
	return (_rawBits);
}
