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

void	Contact::setInput(std::string input, std::string& value) {
	int retry;

	retry = -1;
	while (++retry < 3) {
		std::cout << BOLD_GREEN << "Enter " << input << ": " << RESET;
		std::getline(std::cin, value);

		if (value.empty()) {
			std::cout << BOLD_YELLOW << "Empty input. Please try again." << RESET << std::endl;
			continue ;
		}

		if (input == "first name" || input == "last name" || input == "nickname") {
			if (!Contact::validateName(value)) {
				std::cout << BOLD_YELLOW << "Invalid input. Please try again." << RESET << std::endl;
				continue ;
			}
		}
		if (input == "phone number") {
			if (!Contact::validatePhoneNumber(value)) {
				std::cout << BOLD_YELLOW << "Please try again." << RESET << std::endl;
				continue ;
			}
		}
		break ;
	}
	if (retry == 3) {
		throw std::runtime_error("Too many attempts.");
	}
	return ;
}

void	Contact::setContact(void) {
	try {
		setInput("first name", this->firstName);
		setInput("last name", this->lastName);
		setInput("nickname", this->nickname);
		setInput("phone number", this->phoneNumber);
		setInput("darkest secret", this->darkestSecret);
		std::cout << BOLD_GREEN << "Contact added successfully!" << RESET << std::endl;
	}
	catch (std::exception& e) {
		clearInput(this->firstName);
		clearInput(this->lastName);
		clearInput(this->nickname);
		clearInput(this->phoneNumber);
		clearInput(this->darkestSecret);
		throw;
	}
	return ;
}

bool	Contact::validateName(std::string& name) {

	for (int i = 0; i < (int)name.length(); i++) {
		if (!std::isalpha(name[i]) && name != "nickname") {
			return false;
		}
		if (name == "nickname") {
			if (!std::isalnum(name[i]) && name[i] != '_' && name[i] != '-') {
				return false;
			}
		}
	}
	return true;
}

bool	Contact::validatePhoneNumber(std::string& phoneNumber) {
	for (int i = 0; i < (int)phoneNumber.length(); i++)
	{
		if (!std::isdigit(phoneNumber[i])) {
			std::cout << BOLD_YELLOW << "Phone number must contain only digits." << RESET << std::endl;
			return false;
		}
	}
	return true;
}

void	Contact::clearInput(std::string& input) {
	input.clear();
	return ;
}

void	Contact::printContact(void) {
	std::cout << BOLD_WHITE << "\nFirst name: " << RESET << this->firstName << std::endl;
	std::cout << BOLD_WHITE << "Last name: " << RESET << this->lastName << std::endl;
	std::cout << BOLD_WHITE << "Nickname: " << RESET << this->nickname << std::endl;
	std::cout << BOLD_WHITE << "Phone number: " << RESET << this->phoneNumber << std::endl;
	std::cout << BOLD_WHITE << "Darkest secret: " << RESET << this->darkestSecret << std::endl;
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

std::string	Contact::getDarkestSecret(void) {
	return (this->darkestSecret);
}
