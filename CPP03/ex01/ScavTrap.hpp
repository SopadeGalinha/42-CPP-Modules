/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhogonca <github.com/SopadeGalinha>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 18:45:11 by jhogonca          #+#    #+#             */
/*   Updated: 2024/02/10 11:20:23 by jhogonca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

// Headers
#include "ClapTrap.hpp"

// Class
class ScavTrap : public ClapTrap {
	public:
		// Constructor
		ScavTrap();
		ScavTrap(string name);
		ScavTrap(const ScavTrap &other);
		
		// Destructor
		~ScavTrap();

		// Operator Overload
		ScavTrap &operator=(const ScavTrap &other);
		
		// Member Functions
		void guardGate();
		void attack(const string &target);
};

#endif
