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
				std::cout << BOLD_BLUE << "Add Contact selected" << RESET << std::endl;
				pb.addContact();
				break ;
			case 2:
				std::cout << BOLD_BLUE << "Search Contact selected" << RESET << std::endl;
				pb.searchContact();
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
