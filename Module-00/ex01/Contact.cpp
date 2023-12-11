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

// Setters
void	Contact::setFirstName(std::string firstName) {
	this->firstName = firstName;
	return ;
}

void	Contact::setLastName(std::string lastName) {
	this->lastName = lastName;
	return ;
}

void	Contact::setNickname(std::string nickname) {
	this->nickname = nickname;
	return ;
}

void	Contact::setPhoneNumber(std::string phoneNumber) {
	this->phoneNumber = phoneNumber;
	return ;
}

void	Contact::setDarkestSecret(std::string darkestSecret) {
	this->darkestSecret = darkestSecret;
	return ;
}

// Getters
std::string	Contact::getFirstName(void) {
	return (this->firstName);
}

std::string	Contact::getLastName(void) {
	return (this->lastName);
}

std::string	Contact::getNickname(void) {
	return (this->nickname);
}

std::string	Contact::getPhoneNumber(void) {
	return (this->phoneNumber);
}
/* 
std::string	Contact::getDarkestSecret(void) {
	return (this->darkestSecret);
}
 */
// Methods
/* 
void	Contact::setContact(void) {
	std::string		input;

} */

bool Contact::getInput(std::string command) {
	std::cout << PROMPT_MESSAGE;
	if (!std::getline(std::cin, command)){
		if (std::cin.eof())
			std::cout << BOLD_RED \
			<< "\nError reading command!" << RESET << std::endl;
		return false;
	}
	return true;
}

/* void	Contact::setInput(std::string& prompt, void (Contact::*setter)(std::string)) {
	std::string		input;
	for (int retry = 0; retry < 3; retry++) {
		std::cout << BOLD_CYAN_ITALIC "Enter your " << prompt << ": " RESET;
		if (!getInput(input))
			return ;
		if (input.empty() || input == " ")
			continue ;
		(this->*setter)(input);
		return ;
	}
	throw std::runtime_error("Invalid input!");
} */