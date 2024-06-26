/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhogonca <jhogonca@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 18:25:18 by jhogonca          #+#    #+#             */
/*   Updated: 2023/12/19 18:25:18 by jhogonca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

HumanA::HumanA(const std::string initialName, Weapon& initialWeapon) 
	: _name(initialName), _weapon(initialWeapon){
	return ;
}

HumanA::~HumanA() {
	return ;
}

void	HumanA::attack(void) const {
	std::cout << YELLOW << _name << " attacks with their " << _weapon.getType() << std::endl;
	return ;
}
