/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhogonca <jhogonca@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 21:29:46 by jhogonca          #+#    #+#             */
/*   Updated: 2024/01/08 21:29:46 by jhogonca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Point::Point() : x(0), y(0) {
	// Default constructor
}

Point::Point(const Point &point) : x(point.x), y(point.y) {
	// Copy constructor
}

Point::Point(const float x, const float y) : x(x), y(y) {
	// Constructor
}

Point::~Point() {
	// Destructor
}

Point &Point::operator=(const Point &point) {
	// Assignment operator
	(void)point;
	return (*this);
}

Fixed Point::getX() const {
	return (this->x);
}

Fixed Point::getY() const {
	return (this->y);
}
