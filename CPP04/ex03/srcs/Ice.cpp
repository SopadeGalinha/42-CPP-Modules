/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhogonca <jhogonca@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/30 19:20:00 by jhogonca          #+#    #+#             */
/*   Updated: 2024/03/30 19:20:00 by jhogonca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Ice.hpp"

/* -----> Methods <----- */

// Default constructor
Ice::Ice(void) : AMateria("ice") {
	cout << BLUE << "[Ice] constructed!" << RESET << endl;
	return ;
}

// Copy constructor
Ice::Ice(const Ice &source) : AMateria(source) {
	cout << BLUE << "[Ice] copy constructed!" << RESET << endl;
	return ;
}

// Destructor
Ice::~Ice(void) {
	cout << RED << "[Ice] destructed!" << RESET << endl;
	return ;
}

// Assignment operator
Ice	&Ice::operator=(const Ice &other) {
	if (this == &other)
		return (*this);
	this->_type = other._type;
	return (*this);
}

// Member function
AMateria	*Ice::clone(void) const {
	return (new Ice(*this));
}

void Ice::use(ICharacter& target) {
	cout << GREEN << "* shoots an ice bolt at " << target.getName() << " *" << RESET << endl;
	return ;
}
