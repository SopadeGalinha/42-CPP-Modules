/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhogonca <github.com/SopadeGalinha>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 21:20:36 by jhogonca          #+#    #+#             */
/*   Updated: 2024/02/10 11:00:00 by jhogonca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

# include "ScavTrap.hpp"

class FragTrap : public ClapTrap {
	public:
		// Constructor
		FragTrap();
		FragTrap(std::string name);
		FragTrap(const FragTrap &other);
		
		// Destructor
		~FragTrap();

		// Operator Overload
		FragTrap &operator=(const FragTrap &other);
		
		// Member Functions
		void highFivesGuys(void);
};

#endif
