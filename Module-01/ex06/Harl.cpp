/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhogonca <jhogonca@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 22:59:18 by jhogonca          #+#    #+#             */
/*   Updated: 2023/12/20 22:59:18 by jhogonca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

// Constructor
Harl::Harl(void) {
    std::cout << GREEN << std::endl << "Hi, I'm Harl!" << RESET << std::endl;
    return ;
}

// Destructor
Harl::~Harl(void) {
    std::cout << PURPLE << "Harl died of starvation" << RESET << std::endl;
    return ;
}

// Private methods
void Harl::_debug(void) {
    std::cout << BLUE << "[DEBUG]\t- I love having extra bacon for my\n";
    std::cout << "7XL-double-cheese-triple-pickle-special-ketchup burger. ";
    std::cout << "I really do!" << RESET << std::endl;
}

void Harl::_info(void) {
    std::cout << GREEN << "[INFO]\t- I cannot believe adding extra bacon costs more money.\n";
    std::cout << "You didn’t put enough bacon in my burger! ";
    std::cout << "If you did, I wouldn’t be asking for more!" << RESET << std::endl;
}

void Harl::_warning(void) {
    std::cout << YELLOW << "[WARN]\t- I think I deserve to have some extra bacon for free.\n";
    std::cout << "\t- I’ve been coming here for years, and you just started working since last month." << RESET << std::endl;
}

void Harl::_error(void) {
    std::cout << RED << "[ERROR]\t- This is unacceptable; I want to speak to the manager now." << RESET << std::endl;
}

// Member functions
void Harl::complain(const std::string& level) {
    // Convert level to uppercase
    std::string upperLevel = level;
    std::transform(upperLevel.begin(), upperLevel.end(), upperLevel.begin(), ::toupper);

    std::string levels[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
    void (Harl::*_complain[4])(void) = {
        &Harl::_debug,
        &Harl::_info,
        &Harl::_warning,
        &Harl::_error
    };

    if (level != "DEBUG" && level != "INFO" && level != "WARNING" && level != "ERROR") {
        std::cout << WHITE << "Bla bla bla bla... [in the distance]" << RESET << std::endl;
        return ;
    }

    // Check level
    for (int i = 0; i < 4; i++) {
        if (levels[i] == upperLevel) {
            (this->*_complain[i])();
            return ;
        }
    }
}

// Setters
void Harl::setFilter(const std::string& filter) {
    std::string levels[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
    int i_filter;

    for (i_filter = 0; i_filter < 4; i_filter++) {
        if (levels[i_filter] == filter) {
            break;
        }
    }

    switch (i_filter) {
        case 0:
            _filter = DEBUG;
            break;
        case 1:
            _filter = INFO;
            break;
        case 2:
            _filter = WARNING;
            break;
        case 3:
            _filter = ERROR;
            break;
        default:
            break;
    }
    return ;
}

// Getters
e_levels Harl::getFilter(void) const {
	return (_filter);
}