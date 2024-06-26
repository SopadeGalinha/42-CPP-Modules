/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhogonca <github.com/SopadeGalinha>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 16:16:16 by jhogonca          #+#    #+#             */
/*   Updated: 2024/02/10 11:19:16 by jhogonca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

//  ----- Constructors, Destructor, Operator Overload -----  //
// Constructor
ClapTrap::ClapTrap() {
	cout << BLUE << "ClapTrap Default Constructor" << RESET << endl;
	this->_name = "Unknown ClapTrap";
	this->_hitPoints = 10;
	this->_energyPoints = 10;
	this->_attackDamage = 0;
}

// Parameterized Constructor
ClapTrap::ClapTrap(string name) {
	cout << BLUE << "ClapTrap Parameterized Constructor" << RESET << endl;
	this->_name = name;
	this->_hitPoints = 10;
	this->_energyPoints = 10;
	this->_attackDamage = 0;
}

// Copy Constructor
ClapTrap::ClapTrap(const ClapTrap &other) {
	cout << RED << "ClapTrap Copy Constructor" << RESET << endl;
	*this = other;
}

// Destructor
ClapTrap::~ClapTrap() {
	cout << RED << this->_name << " Destroyed" << RESET << endl;
}

// Operator Overload
ClapTrap	&ClapTrap::operator=(const ClapTrap &other) {
	cout << BLUE << "ClapTrap Operator Overload" << RESET << endl;
	if (this != &other) {
		this->_name = other._name;
		this->_hitPoints = other._hitPoints;
		this->_energyPoints = other._energyPoints;
		this->_attackDamage = other._attackDamage;
	}
	return *this;
}

//  ----- Member Functions -----  //

// Attack
void	ClapTrap::attack(const string &target) {
	cout << GREEN << "- ClapTrap Attack -" << RESET << endl;
	cout \

	<< "ClapTrap " << this->_name \
	<< " attacks " << target \
	<< " causing " << this->_attackDamage \
	<< " points of damage!" << endl;
}

// Take Damage
void	ClapTrap::takeDamage(unsigned int amount) {
	this->_hitPoints -= amount;
	cout << GREEN << "- ClapTrap Take Damage -" << RESET << endl;
	cout << "ClapTrap " << this->_name \
	<< " takes " << amount \
	<< " points of damage!" << endl;
}

// Be Repaired
void	ClapTrap::beRepaired(unsigned int amount) {
	this->_hitPoints += amount;
	cout << GREEN << "- ClapTrap Be Repaired -" << RESET << endl;
	cout << "ClapTrap " << this->_name \
	<< " is repaired for " << amount \
	<< " points of health!" << endl;
}

//  ----- Getters and Setters -----  //

// Get Name
string	ClapTrap::getName() const {
	return this->_name;
}

// Set Name
void	ClapTrap::setName(string name) {
	this->_name = name;
}

// Get Hit Points
unsigned int	ClapTrap::getHitPoints() const {
	return this->_hitPoints;
}

// Set Hit Points
void	ClapTrap::setHitPoints(unsigned int hitPoints) {
	this->_hitPoints = hitPoints;
}

// Get Energy Points
unsigned int	ClapTrap::getEnergyPoints() const {
	return this->_energyPoints;
}

// Set Energy Points
void	ClapTrap::setEnergyPoints(unsigned int energyPoints) {
	this->_energyPoints = energyPoints;
}