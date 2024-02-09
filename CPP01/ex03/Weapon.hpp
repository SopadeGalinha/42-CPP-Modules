/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhogonca <jhogonca@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 17:58:46 by jhogonca          #+#    #+#             */
/*   Updated: 2023/12/19 17:58:46 by jhogonca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_HPP
# define WEAPON_HPP

# include <string>
# include <iostream>
# include <sstream>
# include <cstdlib>

#define RESET	"\033[0m"
#define RED		"\033[1m\033[31m"
#define GREEN	"\033[1m\033[32m"
#define YELLOW	"\033[1m\033[33m"
#define BLUE	"\033[1m\033[34m"

class Weapon {
private:
	std::string _type;

public:
	//default constructor
	Weapon();
	//parameter constructor
	Weapon(const std::string initialType);
	//destructor
	~Weapon();
	
	//setter and getter
	void	setType(const std::string newType);
	const std::string&	getType(void) const;
};

#endif
