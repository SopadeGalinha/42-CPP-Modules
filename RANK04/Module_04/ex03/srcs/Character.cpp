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

/* Subject specificatons: 
	- The Character possesses an inventory of 4 slots to equip Materia.
	- The inventory is empty at construction.
	- They equip the Materias in the first empty slot they find. (0 to 3)
	- In case they try to add a Materia to a full inventory, or 
		use/unequip an unexisting Materia, don’t do anything.
	- The unequip() member function must NOT delete the Materia!
*/

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

/* The equip function will store the materia
* in the first available slot in the inventory. */
void Character::equip(AMateria* m) {
	for (int i = 0; i < 4; i++) {
		if (!_inventory[i]) {
			_inventory[i] = m;
			return ;
		}
	}
	return ;
}

/* The unequip function will remove the materia from the inventory.*/
void Character::unequip(int idx) {
	if (idx < 0 || idx > 3 || !_inventory[idx])
		return ;
	_inventory[idx] = NULL;
	return ;
}

/* The use function will use the materia 
* in the inventory on the target character. */
void Character::use(int idx, ICharacter& target) {
	if (idx < 0 || idx > 3 || !_inventory[idx])
		return ;
	_inventory[idx]->use(target);
	return ;
}
