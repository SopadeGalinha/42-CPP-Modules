/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhogonca <jhogonca@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 18:23:56 by jhogonca          #+#    #+#             */
/*   Updated: 2023/12/19 18:23:56 by jhogonca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_HPP
# define HUMANB_HPP

# include "Weapon.hpp"

class HumanB {
private:
	std::string	_name;
	Weapon&		_weapon;

public:
	//default constructor
	HumanB();
	//parameter constructor
	HumanB(const std::string initialName, Weapon& initialWeapon);
	//destructor
	~HumanB();

	void	attack(void) const;
};

#endif
