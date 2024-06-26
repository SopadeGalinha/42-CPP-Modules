/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhogonca <jhogonca@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 13:37:09 by jhogonca          #+#    #+#             */
/*   Updated: 2023/12/16 13:37:09 by jhogonca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie(std::string name) {
	setName(name);
	std::cout << GREEN << "\tZombie " << _name << " created." << RESET << std::endl;
}

Zombie::~Zombie(void) {
	std::cout << RED << "\tZombie " << _name << " destroyed." << RESET << std::endl;
}

// Setters
void	Zombie::setName(std::string name) {
	_name = name;
}

// Getters
std::string	Zombie::getName(void) {
	return (_name);
}

// Member functions
void	Zombie::announce(void) {
	std::cout << YELLOW << "\t" << _name << ": BraiiiiiiinnnzzzZ...";
	std::cout << RESET << std::endl;
}
