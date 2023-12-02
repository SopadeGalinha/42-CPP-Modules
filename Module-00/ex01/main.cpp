/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhogonca <jhogonca@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 22:12:12 by jhogonca          #+#    #+#             */
/*   Updated: 2023/12/02 22:12:12 by jhogonca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

// PhoneBook

// COLORS
# define RESET			"\001\033[0m\002"
# define BOLD_RED		"\001\033[1;31m\002"
# define BOLD_ORANGE	"\001\033[1;33m\002"
# define BOLD_PURPLE	"\001\033[1;35m\002"
# define BOLD_GREY		"\001\033[1;39m\002"
# define BOLD_GREEN		"\001\033[1;92m\002"
# define BOLD_BLUE		"\001\033[1;94m\002"
# define BOLD_CYAN		"\001\033[1;96m\002"
# define BOLD_WHITE		"\001\033[1;97m\002"
# define BOLD_PURPLE_FLASH	"\001\033[1;3;5;35m"

#define PROMPT_MESSAGE		BOLD_PURPLE_FLASH "Enter a command: " RESET

// Convert string to lowercase

void printMenu() {
	std::cout << BOLD_GREEN <<"\n	**** WELCOME TO PHONEBOOK **** \n" << RESET << std::endl;
	std::cout << BOLD_CYAN << "1. ADD CONTACT	- to add a new contact" << std::endl;
	std::cout << BOLD_CYAN << "2. SEARCH CONTACT	- to search a contact" << std::endl;
	std::cout << BOLD_CYAN << "3. EXIT PHONEBOOK	- to exit the phonebook" << std::endl;
	std::cout << std::string(50, '-') << std::endl;
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

void ft_tolower(std::string& str) {
    for (int i = 0; i < str.length(); i++) {
        if (std::isupper(str[i])) {
            str[i] = std::tolower(str[i]);
        }
    }
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

int	main(void)
{
	std::string		command;

	printMenu();
	while (true)
	{
		if (!getInput(command))
			break ;
		if (command.empty() || command == " ")
			continue ;
		switch (inputParser(command))
		{
			case 1:
				std::cout << "ADD CONTACT" << std::endl;
				break ;
			case 2:
				std::cout << "SEARCH CONTACT" << std::endl;
				break ;
			case 3:
				std::cout << "EXIT PHONEBOOK" << std::endl;
				return (0);
			default:
				std::cout << BOLD_RED << "Invalid command!" << RESET << std::endl;
				break ;
		}
	}
}
