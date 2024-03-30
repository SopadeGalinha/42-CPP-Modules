/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhogonca <jhogonca@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/30 19:36:56 by jhogonca          #+#    #+#             */
/*   Updated: 2024/03/30 19:36:56 by jhogonca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/AMateria.hpp"

/* -----> Methods <----- */

// Default constructor
AMateria::AMateria(void) {
	_type = "default";
	cout << BLUE << "[AMateria] " << _type << " constructed!" << RESET << endl;
	return ;
}

// Parameterized constructor
AMateria::AMateria(std::string const &type) {
	_type = type;
	cout << BLUE << "[AMateria] " << _type << " constructed!" << RESET << endl;
	return ;
}

// Copy constructor
AMateria::AMateria(const AMateria &source) {
	*this = source;
	cout << BLUE << "[AMateria] " << _type << " copy constructed!" << RESET << endl;
	return ;
}

// Destructor
AMateria::~AMateria(void) {
	cout << RED << "[AMateria] " << _type << " destructed!" << RESET << endl;
	return ;
}

// Assignment operator
AMateria	&AMateria::operator=(const AMateria &other) {
	if (this == &other)
		return (*this);
	this->_type = other._type;
	return (*this);
}

// Member functions
std::string const	&AMateria::getType(void) const {
	return (this->_type);
}

void AMateria::use(ICharacter& target) {
	cout << GREEN << "* " << _type << " uses its powers at " << target.getName() << " *" << RESET << endl;
	return ;
}
