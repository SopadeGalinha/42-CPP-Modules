/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhogonca <jhogonca@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 18:33:35 by jhogonca          #+#    #+#             */
/*   Updated: 2023/12/19 18:33:35 by jhogonca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon() {
	return ;
}

Weapon::Weapon(const std::string initialType) {
	_type = initialType;
	return ;
}

Weapon::~Weapon() {
	return ;
}

void	Weapon::setType(const std::string newType) {
	_type = newType;
	return ;
}

const std::string&	Weapon::getType(void) const {
	return (_type);
}
