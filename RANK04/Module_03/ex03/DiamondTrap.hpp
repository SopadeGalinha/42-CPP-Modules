/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhogonca <jhogonca@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/11 22:14:27 by jhogonca          #+#    #+#             */
/*   Updated: 2024/02/11 22:14:27 by jhogonca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DIAMONDTRAP_HPP
# define DIAMONDTRAP_HPP

#include "FragTrap.hpp"
#include "ScavTrap.hpp"

class DiamondTrap: public ScavTrap, public FragTrap
{
	private:
		std::string _name;
	
	public:
		// Constructors
		DiamondTrap();
		DiamondTrap(std::string name);
		DiamondTrap(DiamondTrap const &other);

		// Destructor
		~DiamondTrap();

		// Operator Overload
		DiamondTrap &operator=(DiamondTrap const &other);

		//Getters
/*
 		string	getName() const;
		string	getClapName() const;
		string	getFragName() const;
*/

		// Member Functions
		void whoAmI();
};

#endif
