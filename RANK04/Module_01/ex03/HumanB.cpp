/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhogonca <jhogonca@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 18:27:45 by jhogonca          #+#    #+#             */
/*   Updated: 2023/12/19 18:27:45 by jhogonca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB(const std::string initialName, Weapon& initialWeapon)
	: _name(initialName), _weapon(initialWeapon){
	return ;
}

HumanB::~HumanB() {
	return ;
}

void	HumanB::attack(void) const {
	std::cout << YELLOW << _name << " attacks with their " << _weapon.getType() << std::endl;
	return ;
}
