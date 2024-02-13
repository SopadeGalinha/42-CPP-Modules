/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhogonca <jhogonca@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 16:31:55 by jhogonca          #+#    #+#             */
/*   Updated: 2024/02/13 12:15:08 by jhogonca         ###   ########.fr       */
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

int main() {
    printHeader("Creating a FragTrap");
    FragTrap trap("Frag");

    printHeader("Printing FragTrap attributes");
    printPoints(trap);

    printHeader("FragTrap requesting a high five");
    trap.highFivesGuys();

    printHeader("End of Program (Destructors will be called automatically)");

    return 0;
}