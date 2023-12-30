/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhogonca <jhogonca@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 12:42:27 by jhogonca          #+#    #+#             */
/*   Updated: 2023/12/16 12:42:27 by jhogonca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

# include <iostream>
# include <string>

// Color codes
#define RESET	"\033[0m"
#define RED		"\033[1m\033[31m"
#define GREEN	"\033[1m\033[32m"
#define YELLOW	"\033[1m\033[33m"
#define BLUE	"\033[1m\033[34m"

class Zombie {
	private:
		std::string _name;
	public:
		// Constructors and destructors
		Zombie(std::string name);
		~Zombie(void);

		// Setters
		void setName(std::string name);
		// Getters
		std::string getName(void);
		
		// Member functions
		void announce(void);
};

Zombie*	newZombie(std::string name);
void 	randomChump(std::string name);

# endif
