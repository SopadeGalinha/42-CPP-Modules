/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhogonca <jhogonca@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 21:22:15 by jhogonca          #+#    #+#             */
/*   Updated: 2024/02/11 23:16:25 by jhogonca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"
// Constructor
FragTrap::FragTrap() : ClapTrap() {
	cout << BLUE << "[Frag] - \tFragTrap Default Constructor" << RESET << endl;
	this->_name = "Unknown FragTrap";
	this->_hitPoints = 100;
	this->_energyPoints = 100;
	this->_attackDamage = 30;
}

// Parameterized Constructor
FragTrap::FragTrap(std::string name) : ClapTrap(name) {
	cout << BLUE << "[Frag] - \tFragTrap Parameterized Constructor" << RESET << endl;
	this->_hitPoints = 100;
	this->_energyPoints = 100;
	this->_attackDamage = 30;
}

// Copy Constructor
FragTrap::FragTrap(const FragTrap &other) {
	cout << BLUE << "[Frag] - \tFragTrap Copy Constructor" << RESET << endl;
	*this = other;
}

// Destructor
FragTrap::~FragTrap() {
	cout << RED << "[Frag] - \t" << this->_name << " Destroyed" << RESET << endl;
}

// Operator Overload
FragTrap &FragTrap::operator=(const FragTrap &other) {
	cout << BLUE << "[Frag] - \tFragTrap Operator Overload" << RESET << endl;
	if (this != &other) {
		ClapTrap::operator=(other);
	}
	return *this;
}

// Member Functions

void FragTrap::highFivesGuys(void) {
	std::cout       \
	<< "[Frag] - \t"  \
	<< this->_name  \
	<< " requests a high five!" << std::endl;
}
