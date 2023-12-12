/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhogonca <jhogonca@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 00:14:26 by jhogonca          #+#    #+#             */
/*   Updated: 2023/12/03 00:14:26 by jhogonca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

// Constructor
Contact::Contact(void) {
	return ;
}

// Destructor
Contact::~Contact(void) {
	return ;
}

void	Contact::setContact(void) {
	std::string message = "first name";
	if (!setInput(message, &Contact::setFirstName))
		return ;
	message = "last name";
	if (!setInput(message, &Contact::setLastName))
		return ;
	message = "nickname";
	if (!setInput(message, &Contact::setNickname))
		return ;
	message = "phone number";
	if (!setInput(message, &Contact::setPhoneNumber))
		return ;
	message = "darkest secret";
	if (!setInput(message, &Contact::setDarkestSecret))
		return ;
	return ;
}

void	Contact::setFirstName(std::string firstName) {
	std::string::iterator it;
	bool isAlpha = true;

	if (firstName.empty()) {
		throw std::invalid_argument("Empty first name.");
	}	
	for (it = firstName.begin(); it < firstName.end(); ++it) {
		if (!std::isalpha(*it)) {
			isAlpha = false;
			break ;
		}
	}
	if (!isAlpha) {
		throw std::invalid_argument("Invalid first name.");
	}
	this->firstName = firstName;
}

bool	Contact::setInput(std::string& message, void (Contact::*func)(std::string&)) {
	std::string input;

	for (int retry = 0; retry < 3; retry++) {
		std::cout << BOLD_GREEN "Enter " << message << ": ";
		if (!std::getline(std::cin, input)) {
			if (std::cin.eof())
				std::cout << BOLD_RED \
				<< "\nError reading input!" << RESET << std::endl;
			return false;
		}
		if (input.empty()) {
			std::cout << BOLD_RED "Invalid input. Please try again." RESET << std::endl;
			continue ;
		}
		(this->*func)(input);
		return true;
	}
	throw std::runtime_error("Too many retries. Aborting...");
	return false;
}
