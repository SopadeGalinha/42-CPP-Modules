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

#include "Phonebook.hpp"

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
		this->contacts[this->index % _MAX_CONTACTS].setContact();
		if (this->contactsCount < _MAX_CONTACTS)
			this->contactsCount++;
		else
			std::cout << BOLD_YELLOW << "Phonebook is full!" << RESET << "\nOldest register have been replaced." << std::endl;
		this->index++;
	}
	catch (const std::runtime_error& e) {
		std::cout << BOLD_RED << "Contact not added: " << e.what() << RESET << std::endl;
	}
	return ;
}

void printMenu() {
	std::cout << BOLD_GREEN <<"\n	**** WELCOME TO PHONEBOOK **** \n" << RESET << std::endl;
	std::cout << BOLD_CYAN << "1. ADD CONTACT	- to add a new contact" << std::endl;
	std::cout << BOLD_CYAN << "2. SEARCH CONTACT	- to search a contact" << std::endl;
	std::cout << BOLD_CYAN << "3. EXIT PHONEBOOK	- to exit the phonebook" << std::endl;
	std::cout << std::string(50, '-') << std::endl;
}

void ft_tolower(std::string& str) {
    for (int i = 0; i < (int)str.length(); i++) {
        if (std::isupper(str[i])) {
            str[i] = std::tolower(str[i]);
        }
    }
}

bool is_add(std::string& command) {
	return (command == "add" || command == "1" || command == "add contact");
}

bool is_search(std::string& command) {
	return (command == "search" || command == "2" || command == "search contact");
}

bool is_exit(std::string& command) {
	return (command == "exit" || command == "3" || command == "exit phonebook");
}

int inputParser(std::string& command) {
	ft_tolower(command);
	if (is_add(command))
		return 1;
	if (is_search(command))
		return 2;
	if (is_exit(command))
		return 3;
    return 0;
}

bool getInput(std::string& command) {
	std::cout << PROMPT_MESSAGE;
	if (!std::getline(std::cin, command)){
		if (std::cin.eof())
			std::cout << BOLD_RED \
			<< "\nError reading command!" << RESET << std::endl;
		return false;
	}
	return true;
}

void PhoneBook::searchContact(void) {
	std::stringstream	ss;
	std::string 		input;

	std::cout << std::endl;
	print_line("Index", "First Name", "Last Name", "Nickname");
	print_line("-----------", "-----------", "-----------", "-----------");
	for (int i = 0; i < this->contactsCount; i++) {
		ss.str("");
		ss << i + 1;
		print_line(ss.str(), this->contacts[i].getFirstName(), this->contacts[i].getLastName(), this->contacts[i].getNickname());
	}
	std::cout << std::endl;
	std::cout << "Enter the index of the contact you want to see: ";
	std::getline(std::cin, input);
	if (input.length() == 1 && input[0] >= '0' && input[0] <= '7' && input[0] - '0' < this->contactsCount)
		this->contacts[input[0] - '0'].printContact();
	else
		std::cout << BOLD_RED << "\nError: Invalid index.\n" << RESET << std::endl;
	return ;
}

void	print_line(std::string index, std::string first_name, std::string last_name, std::string nickname) {
	
	std::cout << "| ";
	print_field(index);
	std::cout << "| ";
	print_field(first_name);
	std::cout << "| ";
	print_field(last_name);
	std::cout << "| ";
	print_field(nickname);
	std::cout << "| " << std::endl;
	return ;
}

void	print_field(std::string field) {
	std::string	truncatedText;
	int 		padding;
	
	if (field.length() > 10) {
		truncatedText = field.substr(0, 8) + "..";
	} 
	else {
		truncatedText = field;
	}
	padding = 10 - truncatedText.length();
	for (int i = 0; i < padding; ++i) {
		std::cout << " ";
	}
	std::cout << truncatedText;
	return ;
}