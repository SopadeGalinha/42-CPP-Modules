/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhogonca <jhogonca@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 23:36:13 by jhogonca          #+#    #+#             */
/*   Updated: 2023/12/02 23:36:13 by jhogonca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

// Constructor
PhoneBook::PhoneBook(void) {
	this->index = 0;
	this->contactsCount = 0;
	return ;
}

// Destructor
PhoneBook::~PhoneBook(void) {
	return ;
}

// Methods
void	PhoneBook::addContact(void) {
	try {
		if (this->contactsCount == 8)
			std::string(BOLD_ORANGE "Phonebook is full. Overwriting the oldest contact." RESET);
		this->contacts[this->index % 8].setContact();
		if (this->contactsCount < 8) {
			this->contactsCount++;
		}
		this->index++;
	} catch (std::exception& exception_message) {
		std::cout << BOLD_YELLOW << "! - Contact not added - !" << RESET << std::endl;
		std::cout << BOLD_RED << "Error: " << exception_message.what() << RESET << std::endl;
	}
	return ;
}