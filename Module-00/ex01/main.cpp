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

#include "Phonebook.hpp"

// PhoneBook

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
    for (int i = 0; i < (int)str.length(); i++) {
        if (std::isupper(str[i])) {
            str[i] = std::tolower(str[i]);
        }
    }
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

int	main(void)
{
	PhoneBook		pb;
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
				std::cout << BOLD_GREEN << "Bye bye :)" << RESET << std::endl;
				return (0);
			default:
				std::cout << BOLD_RED << "Invalid command!" << RESET << std::endl;
				break ;
		}
	}
	return (0);
}
