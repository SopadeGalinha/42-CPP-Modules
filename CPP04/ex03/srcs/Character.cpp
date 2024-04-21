/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhogonca <jhogonca@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/30 19:31:24 by jhogonca          #+#    #+#             */
/*   Updated: 2024/03/30 19:31:24 by jhogonca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Character.hpp"

/* -----> Methods <----- */

// Default constructor
Character::Character(void) {
	_name = "Default";
	for (int i = 0; i < 4; i++)
		_inventory[i] = NULL;
	cout << BLUE << "[Character] " << _name << " constructed!" << RESET << endl;
	return ;
}

// Parameterized constructor
Character::Character(std::string const &name) {
	_name = name;
	for (int i = 0; i < 4; i++)
		_inventory[i] = NULL;
	cout << BLUE << "[Character] " << _name << " constructed!" << RESET << endl;
	return ;
}

// Copy constructor
Character::Character(const Character &source) {
	_name = source._name;
	for (int i = 0; i < 4; i++)
		_inventory[i] = source._inventory[i]->clone();
	cout << BLUE << "[Character] copy constructed!" << RESET << endl;
	return ;
}

// Destructor
Character::~Character(void) {
	for (int i = 0; i < 4; i++)
		if (_inventory[i])
			delete _inventory[i];
	cout << RED << "[Character] " << _name << " destructed!" << RESET << endl;
	return ;
}

// Assignment operator
Character	&Character::operator=(const Character &other) {
	if (this == &other)
		return (*this);
	_name = other._name;
	for (int i = 0; i < 4; i++)
		if (_inventory[i])
			delete _inventory[i];
	for (int i = 0; i < 4; i++)
		_inventory[i] = other._inventory[i]->clone();
	return (*this);
}

// Member functions
std::string const	&Character::getName(void) const {
	return (this->_name);
}

void Character::equip(AMateria* m) {
	for (int i = 0; i < 4; i++) {
		if (!_inventory[i]) {
			_inventory[i] = m;
			return ;
		}
	}
	return ;
}

void Character::unequip(int idx) {
	if (idx < 0 || idx > 3 || !_inventory[idx])
		return ;
	_inventory[idx] = NULL;
	return ;
}

void Character::use(int idx, ICharacter& target) {
	if (idx < 0 || idx > 3 || !_inventory[idx])
		return ;
	_inventory[idx]->use(target);
	return ;
}
