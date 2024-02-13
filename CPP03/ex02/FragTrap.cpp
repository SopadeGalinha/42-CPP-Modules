/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhogonca <jhogonca@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 21:22:15 by jhogonca          #+#    #+#             */
/*   Updated: 2024/02/13 12:14:09 by jhogonca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"
// Constructor
FragTrap::FragTrap() : ClapTrap() {
	cout << BLUE << "[Frag] - FragTrap Default Constructor" << RESET << endl;
	this->_name = "Unknown FragTrap";
	this->_hitPoints = 100;
	this->_energyPoints = 100;
	this->_attackDamage = 30;
}

// Parameterized Constructor
FragTrap::FragTrap(std::string name) : ClapTrap(name) {
	cout << BLUE << "[Frag] - FragTrap Parameterized Constructor" << RESET << endl;
	this->_hitPoints = 100;
	this->_energyPoints = 100;
	this->_attackDamage = 30;
}

// Copy Constructor
FragTrap::FragTrap(const FragTrap &other) {
	cout << BLUE << "[Frag] - FragTrap Copy Constructor" << RESET << endl;
	*this = other;
}

// Destructor
FragTrap::~FragTrap() {
	cout << RED << " [Frag] - " << this->_name << " Destroyed" << RESET << endl;
}

// Operator Overload
FragTrap &FragTrap::operator=(const FragTrap &other) {
	cout << BLUE << "[Frag] - FragTrap Operator Overload" << RESET << endl;
	if (this != &other) {
		ClapTrap::operator=(other);
	}
	return *this;
}

// Member Functions

void FragTrap::highFivesGuys(void) {
	std::cout       \
	<< "FragTrap "  \
	<< this->_name  \
	<< " requests a high five!" << std::endl;
}