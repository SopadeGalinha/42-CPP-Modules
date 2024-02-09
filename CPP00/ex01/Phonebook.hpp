/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhogonca <jhogonca@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 23:53:02 by jhogonca          #+#    #+#             */
/*   Updated: 2023/12/02 23:53:02 by jhogonca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

// Includes
# include "Contact.hpp"

// PhoneBook class
class PhoneBook {
	private:
		// Attributes
		static const int _MAX_CONTACTS = 8;
		int			index;
		int			contactsCount;
		Contact		contacts[8];
		
	public:
		// Constructor and destructor
		PhoneBook(void);
		~PhoneBook(void);

		// Methods
		void	addContact(void);
		void	searchContact(void);
};
	int		inputParser(std::string& command);
	bool 	getInput(std::string& command);
	bool 	is_exit(std::string& command);
	bool 	is_search(std::string& command);
	bool 	is_add(std::string& command);
	void 	ft_tolower(std::string& str);
	void 	printMenu();
	bool	validateName(std::string name);
	void 	print_field(std::string field);
	void 	print_line(std::string index, std::string first_name, std::string last_name, std::string nickname);
# endif
