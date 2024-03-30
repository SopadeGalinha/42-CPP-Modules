/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhogonca <jhogonca@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/30 19:47:00 by jhogonca          #+#    #+#             */
/*   Updated: 2024/03/30 19:47:00 by jhogonca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
 
#include "../includes/AMateria.hpp"

/* -----> Methods <----- */

// Default constructor
MateriaSource::MateriaSource(void) {
	for (int i = 0; i < 4; i++)
		_inventory[i] = NULL;
	std::cout << BLUE << "[MateriaSource] constructed!" << RESET << std::endl;
	return ;
}

// Copy constructor
MateriaSource::MateriaSource(const MateriaSource &source) {
	*this = source;
	std::cout << BLUE << "[MateriaSource] copy constructed!" << RESET << std::endl;
	return ;
}

// Destructor
MateriaSource::~MateriaSource(void) {
	for (int i = 0; i < 4; i++)
		if (_inventory[i])
			delete _inventory[i];
	std::cout << RED << "[MateriaSource] destructed!" << RESET << std::endl;
	return ;
}

// Assignment operator
MateriaSource	&MateriaSource::operator=(const MateriaSource &other) {
	if (this == &other)
		return (*this);
	for (int i = 0; i < 4; i++)
		if (_inventory[i])
			delete _inventory[i];
	for (int i = 0; i < 4; i++)
		_inventory[i] = other._inventory[i]->clone();
	return (*this);
}

// Member functions
void MateriaSource::learnMateria(AMateria* materia) {
	for (int i = 0; i < 4; i++) {
		if (!_inventory[i]) {
			_inventory[i] = materia;
			return ;
		}
	}
	return ;
}

AMateria* MateriaSource::createMateria(std::string const &type) {
	for (int i = 0; i < 4; i++) {
		if (_inventory[i] && _inventory[i]->getType() == type)
			return (_inventory[i]->clone());
	}
	return (NULL);
}
