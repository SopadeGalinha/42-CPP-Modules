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

Fixed::Fixed(void) : _rawBits(0) {
	// Default constructor
}

// Int constructor
Fixed::Fixed(const int value) {
	_rawBits = value << fractionalBits;
}

// Float constructor
Fixed::Fixed(const float value) {
	_rawBits = roundf(value * (1 << fractionalBits));
}

// Copy constructor
Fixed::Fixed(const Fixed &other) : _rawBits(other._rawBits) {
	*this = other;
}

Fixed::~Fixed(void) {
	// Destructor
}

// Assignment Operator overload
Fixed &Fixed::operator=(const Fixed &other) {
	if (this == &other)
		return (*this);
	_rawBits = other.getRawBits();
	return (*this);
}

// Comparison Operator overload
bool Fixed::operator>(const Fixed &other) const {
	return (_rawBits > other.getRawBits());
}

bool Fixed::operator<(const Fixed &other) const {
	return (_rawBits < other.getRawBits());
}

bool Fixed::operator>=(const Fixed &other) const {
	return (_rawBits >= other.getRawBits());
}

bool Fixed::operator<=(const Fixed &other) const {
	return (_rawBits <= other.getRawBits());
}

bool Fixed::operator==(const Fixed &other) const {
	return (_rawBits == other.getRawBits());
}

bool Fixed::operator!=(const Fixed &other) const {
	return (_rawBits != other.getRawBits());
}

// Arithmetic Operator overload
Fixed Fixed::operator+(const Fixed &other) const {
	return (Fixed(toFloat() + other.toFloat()));
}

Fixed Fixed::operator-(const Fixed &other) const {
	return (Fixed(toFloat() - other.toFloat()));
}

Fixed Fixed::operator*(const Fixed &other) const {
	return (Fixed(toFloat() * other.toFloat()));
}

Fixed Fixed::operator/(const Fixed &other) const {
	return (Fixed(toFloat() / other.toFloat()));
}

// Increment and Decrement Operator overload
Fixed &Fixed::operator++(void) {
	_rawBits++;
	return (*this);
}

Fixed Fixed::operator++(int) {
	Fixed tmp(*this);
	operator++();
	return (tmp);
}

Fixed &Fixed::operator--(void) {
	_rawBits--;
	return (*this);
}

Fixed Fixed::operator--(int) {
	Fixed tmp(*this);
	operator--();
	return (tmp);
}

// Setters and getters
int	Fixed::getRawBits(void) const {
	return (_rawBits);
}

void	Fixed::setRawBits(int const raw) {
	_rawBits = raw;
	return ;
}

float	Fixed::toFloat(void) const {
	return ((float)_rawBits / (float)(1 << fractionalBits));
}

int	Fixed::toInt(void) const {
	return (_rawBits >> fractionalBits);
}

Fixed &Fixed::min(Fixed &a, Fixed &b) {
	return (a < b ? a : b);
}

const Fixed &Fixed::min(const Fixed &a, const Fixed &b) {
	return (a < b ? a : b);
}

Fixed &Fixed::max(Fixed &a, Fixed &b) {
	return (a > b ? a : b);
}

const Fixed &Fixed::max(const Fixed &a, const Fixed &b) {
	return (a > b ? a : b);
}

std::ostream &operator<<(std::ostream &out, const Fixed &fixed) {
	out << fixed.toFloat();
	return (out);
}
