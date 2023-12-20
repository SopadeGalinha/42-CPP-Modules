/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhogonca <jhogonca@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 14:47:35 by jhogonca          #+#    #+#             */
/*   Updated: 2023/12/20 14:47:35 by jhogonca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

Harl::Harl(void) {
	std::cout << GREEN << std::endl << "Hi I'm Harl!" << RESET << std::endl;
	return ;
}

Harl::~Harl(void) {
	std::cout << PURPLE << "Harl died of starvation" << RESET << std::endl;
	return ;
}

// Private methods
void	Harl::_debug(void) {
	std::cout << BLUE << "[DEBUG]\t- I love having extra bacon for my\n";
	std::cout << "7XL-double-cheese-triple-pickle-special-ketchup burger. ";
	std::cout << "I really do!" << RESET << std::endl;
}

void	Harl::_info(void) {
	std::cout << GREEN << "[INFO]\t- I cannot believe adding extra bacon cost more money.\n";
	std::cout << "You didn't put enough bacon in my burger! ";
	std::cout << "If you did I wouldn't be asking for more!"
		<< RESET << std::endl;
}

void	Harl::_warning(void) {
	std::cout << YELLOW << "[WARN]\t- I think I deserve to have some extra bacon for free.\n";
	std::cout << "\t- I've been coming here for years and you just started working since last month." << RESET << std::endl;
}

void	Harl::_error(void) {
	std::cout << RED << "[ERROR]\t- This is unacceptable, I want to speak to the manager now." << RESET << std::endl;
}

void Harl::complain(const std::string& level) {
	// Convert level to uppercase
	std::string upperLevel = level;
	std::transform(upperLevel.begin(), upperLevel.end(), upperLevel.begin(), ::toupper);

	std::string levels[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	void (Harl::*_complain[4])(void) = {&Harl::_debug, &Harl::_info, &Harl::_warning, &Harl::_error};
	// Check level
	for (int i = 0; i < 4; i++) {
		if (levels[i] == upperLevel) {
			(this->*_complain[i])();
			return ;
		}
	}
}
