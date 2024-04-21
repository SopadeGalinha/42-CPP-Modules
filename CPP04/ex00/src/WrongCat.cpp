/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhogonca <jhogonca@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/21 21:43:13 by jhogonca          #+#    #+#             */
/*   Updated: 2024/04/21 21:43:13 by jhogonca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Animal.hpp"

// Constructor
WrongCat::WrongCat(void) : WrongAnimal("WrongCat") {
	cout << BLUE << "[W_Cat] - \tDefault Constructor" << RESET << endl;
}

// Copy Constructor
WrongCat::WrongCat(const WrongCat &other) : WrongAnimal(other) {
	cout << BLUE << "[W_Cat] - \tCopy Constructor" << RESET << endl;
	*this = other;
}

// Destructor
WrongCat::~WrongCat(void) {
	cout << RED << "[W_Cat] - \t" << this->getType() << " Destroyed" << RESET << endl;
}

// Operator Overload
WrongCat	&WrongCat::operator=(const WrongCat &other) {
	cout << BLUE << "[W_Cat] - \tOperator Overload" << RESET << endl;
	this->_type = other._type;
	return *this;
}

// Make Sound
void	WrongCat::makeSound(void) const {
	cout << GREEN << "[W_Cat] - \t" << this->getType() << " says: \"Meow\"" << RESET << endl;
}
