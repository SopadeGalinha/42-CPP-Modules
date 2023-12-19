/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhogonca <jhogonca@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 18:04:31 by jhogonca          #+#    #+#             */
/*   Updated: 2023/12/19 18:04:31 by jhogonca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_HPP
# define HUMANA_HPP

# include "Weapon.hpp"

class HumanA {
private:
	std::string	_name;
	Weapon&		_weapon;

public:
	//default constructor
	HumanA();
	//parameter constructor
	HumanA(const std::string initialName, Weapon& initialWeapon);
	//destructor
	~HumanA();

	void	attack(void) const;
};

#endif