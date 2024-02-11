/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhogonca <jhogonca@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/11 22:20:43 by jhogonca          #+#    #+#             */
/*   Updated: 2024/02/11 22:20:43 by jhogonca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"
// Constructor
DiamondTrap::DiamondTrap() : ClapTrap(), FragTrap(), ScavTrap() {
	cout << BLUE << "[Diamond] -\tDiamondTrap Default Constructor" << RESET << endl;
	_name = "Unknown";
	ClapTrap::_name = "Unknown_clap_name";
}

// Parameterized Constructor
DiamondTrap::DiamondTrap(std::string name) : \
	ClapTrap(name + "_clap_name"), FragTrap(name), ScavTrap(name) {
	cout << BLUE << "[Diamond] -\tDiamondTrap Parameterized Constructor" << RESET << endl;
	_name = name;
	ClapTrap::_name = name + "_clap";
}

// Copy Constructor
DiamondTrap::DiamondTrap(DiamondTrap const &other) {
	cout << BLUE << "[Diamond] -\tDiamondTrap Copy Constructor" << RESET << endl;
	*this = other;
}

// Destructor
DiamondTrap::~DiamondTrap() {
	cout << RED << "[Diamond] -\t" << this->_name << " Destroyed" << RESET << endl;
}

// Operator Overload
DiamondTrap &DiamondTrap::operator=(DiamondTrap const &other) {
	cout << BLUE << "[Diamond] -\tDiamondTrap Operator Overload" << RESET << endl;
	if (this != &other) {
		ClapTrap::operator=(other);
		_name = other._name;
		_hitPoints = other._hitPoints;
		_energyPoints = other._energyPoints;
		_attackDamage = other._attackDamage;
	}
	return *this;
}

// Member Functions
void DiamondTrap::whoAmI() {
	cout << GREEN << "[Diamond] Name: " << _name \
	<< " ClapTrap Name: " << ClapTrap::_name << RESET << endl;
}
