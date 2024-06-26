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
 
#include "../includes/MateriaSource.hpp"

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

/* The destructor is a special member function that is 
* called when the lifetime of an object is over.
* The purpose of the destructor is to free the resources that 
* the object may have acquired during its lifetime. */
MateriaSource::~MateriaSource(void) {
	for (int i = 0; i < 4; i++)
		if (_inventory[i])
			delete _inventory[i];
	std::cout << RED << "[MateriaSource] destructed!" << RESET << std::endl;
	return ;
}

// Assignment operator

/* The assignment operator is invoked when one object, which has already been initialized, 
*  is assigned the state of another existing object. 
*  This operator performs a deep copy of the source object's state, 
*  ensuring that each object maintains its own independent copy of the data. */
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

/*The learnMateria function will store the materia 
* in the first available slot in the inventory.*/
void MateriaSource::learnMateria(AMateria* materia) {
	for (int i = 0; i < 4; i++) {
		if (!_inventory[i]) {
			_inventory[i] = materia;
			return ;
		}
	}
	return ;
}

/* The createMateria function will return a new instance of the materia 
* type passed as an argument if it is stored in the inventory.*/
AMateria* MateriaSource::createMateria(std::string const &type) {
	for (int i = 0; i < 4; i++) {
		if (_inventory[i] && _inventory[i]->getType() == type)
			return (_inventory[i]->clone());
	}
	return (NULL);
}
