/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhogonca <github.com/SopadeGalinha>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 16:31:55 by jhogonca          #+#    #+#             */
/*   Updated: 2024/02/10 12:13:09 by jhogonca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

 void    printHeader(string str) {
	cout << YELLOW << "\n" << str << "\n" << RESET;
}

void	printPoints(ScavTrap &clap) {
	cout << GREEN << "\nClapTrap Points" << RESET << endl;
	cout << "Name: " << clap.getName() << endl;
	cout << "Hit Points: " << clap.getHitPoints() << endl;
	cout << "Energy Points: " << clap.getEnergyPoints() << endl;
}

int main() {
	printHeader("Creating ClapTrap instances...");
	ScavTrap skav("Skav");
	ScavTrap trap("Trap");

 	printPoints(skav);
	printPoints(trap);

	printHeader("Testing member functions...");
	skav.attack("Target");
	trap.takeDamage(5);
	skav.beRepaired(3);
	trap.beRepaired(3);

	printHeader("Testing guardGate...");
	skav.guardGate();
	trap.guardGate();
	
	printPoints(skav);
	printPoints(trap);
	
	printHeader("Testing constructors and operator overload...");

	ScavTrap skav2 = skav;
	ScavTrap trap2;
	trap = trap;
	
	cout << YELLOW << "\nTesting destruction..." << RESET << endl;
	return 0; 
}
