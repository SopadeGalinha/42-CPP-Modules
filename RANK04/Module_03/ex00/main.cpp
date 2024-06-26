/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhogonca <github.com/SopadeGalinha>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 16:31:55 by jhogonca          #+#    #+#             */
/*   Updated: 2024/02/09 18:34:30 by jhogonca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

void    printHeader(string str) {
	cout << YELLOW << "\n" << str << "\n" << RESET;
}

void	printPoints(ClapTrap &clap) {
	cout << GREEN << "\nClapTrap Points" << RESET << endl;
	cout << "Name: " << clap.getName() << endl;
	cout << "Energy Points: " << clap.getEnergyPoints() << endl;
	cout << "Hit Points: " << clap.getHitPoints() << endl;
}

int main() {
	printHeader("Creating ClapTrap instances...");
	ClapTrap clap("Clap");
	ClapTrap trap("Trap");

	printPoints(clap);
	printPoints(trap);
	
	printHeader("Testing member functions...");
	clap.attack("Target");
	trap.takeDamage(5);
	clap.beRepaired(3);
	trap.beRepaired(3);

	printPoints(clap);
	printPoints(trap);
	
	printHeader("Testing constructors and operator overload...");
	ClapTrap clap2 = clap; // Copy constructor
	ClapTrap trap2;
	trap = trap; // Operator overload

	cout << YELLOW << "\nTesting destruction..." << RESET << endl;
	return 0;
}
