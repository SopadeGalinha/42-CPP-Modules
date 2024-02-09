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
	std::cout << GREEN << "Default constructor called" << RESET << std::endl;
	return ;
}

// Copy constructor
Fixed::Fixed(const Fixed &other) : _rawBits(other._rawBits) {
	std::cout << BLUE << "Copy constructor called" << RESET << std::endl;
	*this = other;
}
// Int constructor
Fixed::Fixed(const int value) {
	std::cout << GREEN << "Int constructor called" << RESET << std::endl;
	_rawBits = value << fractionalBits;
	return ;
}

// Float constructor
Fixed::Fixed(const float value) {
	std::cout << GREEN << "Float constructor called" << RESET << std::endl;
	_rawBits = roundf(value * (1 << fractionalBits));
	return ;
}


// Destructor
Fixed::~Fixed(void) {
	std::cout << RED << "Destructor called" << RESET << std::endl;
}

// Operator overload
Fixed &Fixed::operator=(const Fixed &other) {
	std::cout << BLUE << "Copy assignment operator called" << RESET << std::endl;
	if (this == &other)
		return (*this);
	_rawBits = other.getRawBits();
	return (*this);
}

// Setter
void	Fixed::setRawBits(int const raw) {
	std::cout << GREEN << "setRawBits member function called" << RESET << std::endl;
	_rawBits = raw;
}

//Getter
int	Fixed::getRawBits(void) const {
	std::cout << GREEN << "getRawBits member function called" << RESET << std::endl;
	return (_rawBits);
}

float Fixed::toFloat(void) const {
	return ((float)_rawBits / (float)(1 << fractionalBits));
}

int Fixed::toInt(void) const {
	return (_rawBits >> fractionalBits);
}

std::ostream &operator<<(std::ostream &out, const Fixed &fixed) {
	out << fixed.toFloat();
	return (out);
}
