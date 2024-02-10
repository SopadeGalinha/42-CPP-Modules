/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhogonca <github.com/SopadeGalinha>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 18:59:38 by jhogonca          #+#    #+#             */
/*   Updated: 2024/02/10 11:18:21 by jhogonca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

//  ----- Constructors, Destructor, Operator Overload -----  //

// Constructor
ScavTrap::ScavTrap() {
    cout << BLUE << "ScavTrap Default Constructor" << RESET << endl;
    this->_name = "Unknown ScavTrap";
    this->_hitPoints = 100;
    this->_energyPoints = 50;
    this->_attackDamage = 20;
}

// Parameterized Constructor
ScavTrap::ScavTrap(string name) {
    cout << BLUE << "ScavTrap Parameterized Constructor" << RESET << endl;
    this->_name = name;
    this->_hitPoints = 100;
    this->_energyPoints = 50;
    this->_attackDamage = 20;
}

// Copy Constructor
ScavTrap::ScavTrap(const ScavTrap &other) {
    cout << RED << "ScavTrap Copy Constructor" << RESET << endl;
    *this = other;
}

// Destructor
ScavTrap::~ScavTrap() {
    cout << RED << this->_name << " Destroyed" << RESET << endl;
}

//  ----- Member Functions -----  //

// Guard Gate
void	ScavTrap::guardGate() {
    cout << GREEN << "- ScavTrap Guard Gate -" << RESET << endl;
    cout << this->_name << " has entered in Gate keeper mode" << endl;
}

// Attack
void	ScavTrap::attack(const string &target) {
    cout << GREEN << "- ScavTrap Attack -" << RESET << endl;
    cout \
    << this->_name \
    << " attacks " << target \
    << " causing " << this->_attackDamage \
    << " points of damage!" << endl;
}
