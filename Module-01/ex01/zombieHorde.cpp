/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhogonca <jhogonca@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/17 17:38:47 by jhogonca          #+#    #+#             */
/*   Updated: 2023/12/17 17:38:47 by jhogonca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie* zombieHorde(int N, std::string name) {
	Zombie* horde = new Zombie[N];
	for (int i = 0; i < N; i++) {
		std::stringstream ss;
		ss << i;
		std::string zombieName = name + "'s zombie No." + ss.str();
		horde[i].setName(zombieName);
	}
	std::cout << BLUE << name << " horde created.\n" << RESET << std::endl;
	return horde;
}
