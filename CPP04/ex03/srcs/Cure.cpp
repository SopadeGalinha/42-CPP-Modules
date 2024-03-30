/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhogonca <jhogonca@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/30 19:23:51 by jhogonca          #+#    #+#             */
/*   Updated: 2024/03/30 19:23:51 by jhogonca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/AMateria.hpp"

/* -----> Methods <----- */

// Default constructor
Cure::Cure(void) : AMateria("cure") {
	cout << BLUE << "[Cure] constructed!" << RESET << endl;
	return ;
}

// Copy constructor
Cure::Cure(const Cure &source) : AMateria(source) {
	cout << BLUE << "[Cure] copy constructed!" << RESET << endl;
	return ;
}

// Destructor
Cure::~Cure(void) {
	cout << RED << "[Cure] destructed!" << RESET << endl;
	return ;
}

// Assignment operator
Cure	&Cure::operator=(const Cure &other) {
	if (this == &other)
		return (*this);
	this->_type = other._type;
	return (*this);
}

// Member function
AMateria	*Cure::clone(void) const {
	return (new Cure(*this));
}

void Cure::use(ICharacter& target) {
	cout << GREEN << "* heals " << target.getName() << "'s wounds *" << RESET << endl;
	return ;
}
