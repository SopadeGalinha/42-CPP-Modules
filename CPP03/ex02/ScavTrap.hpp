/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhogonca <jhogonca@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 18:45:11 by jhogonca          #+#    #+#             */
/*   Updated: 2024/02/13 12:14:59 by jhogonca         ###   ########.fr       */
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
		
		// Member Functions
		void guardGate();
		void attack(const string &target);
};

#endif