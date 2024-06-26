/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhogonca <jhogonca@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 16:31:55 by jhogonca          #+#    #+#             */
/*   Updated: 2024/02/11 23:07:19 by jhogonca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

void printHeader(string str) {
    cout << YELLOW << "\n" << str << "\n" << RESET;
}

void printPoints(FragTrap &trap) {
    cout << "Name: " << trap.getName() << endl;
    cout << "Hit Points: " << trap.getHitPoints() << endl;
    cout << "Energy Points: " << trap.getEnergyPoints() << endl;
}

#include "DiamondTrap.hpp"

int main() {
    // Create a DiamondTrap object
    printHeader("Creating a DiamondTrap");
    DiamondTrap diamond("Diamond");

    // Test inherited FragTrap functionalities
    printHeader("Printing DiamondTrap attributes");
    printPoints(diamond);

    // Test DiamondTrap specific functionality
    printHeader("DiamondTrap requesting a high five");
    diamond.highFivesGuys();

    // Test ScavTrap specific functionality
    printHeader("DiamondTrap guarding the gate");
    diamond.guardGate();

    // Test DiamondTrap specific functionality
    printHeader("DiamondTrap introspecting");
    diamond.whoAmI();

    printHeader("End of Program (Destructors will be called automatically)");

    return 0;
}
