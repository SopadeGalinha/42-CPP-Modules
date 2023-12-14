/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhogonca <jhogonca@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 00:00:50 by jhogonca          #+#    #+#             */
/*   Updated: 2023/12/03 00:00:50 by jhogonca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
#define CONTACT_HPP

// Includes
#include <iostream>
#include <stdexcept>
#include <string>
#include <sstream>

// COLORS
#define RESET				"\001\033[0m\002"
#define BOLD_RED			"\001\033[1;31m\002"
#define BOLD_YELLOW			"\001\033[1;33m\002"
#define BOLD_ORANGE			"\001\033[1;38;5;208m\002"
#define BOLD_GREY			"\001\033[1;39m\002"
#define BOLD_GREEN			"\001\033[1;92m\002"
#define BOLD_BLUE			"\001\033[1;94m\002"
#define BOLD_CYAN			"\001\033[1;96m\002"
#define BOLD_WHITE			"\001\033[1;97m\002"
#define BOLD_PURPLE_ITALIC	"\001\033[1;3;5;35m"
#define BOLD_CYAN_ITALIC	"\001\033[1;3;5;96m"

// PROMPT
#define PROMPT_MESSAGE	BOLD_PURPLE_ITALIC "Enter a command: " RESET

// Contact class
class Contact {
	// Attributes
private:
	std::string		firstName;
	std::string		lastName;
	std::string		nickname;
	std::string		phoneNumber;
	std::string		darkestSecret;
public:
	// Constructor and destructor
	Contact(void);
	~Contact(void);

	// Setter
	void			setInput(std::string input, std::string& value);
	void			setFirstName(std::string firstName);
	void			setLastName(std::string lastName);
	void			setNickname(std::string nickname);
	void			setPhoneNumber(std::string phoneNumber);
	void			setDarkestSecret(std::string darkestSecret);
	bool			validateName(std::string& name);
	bool			validatePhoneNumber(std::string& phoneNumber);
	void			clearInput(std::string& input);
	void			printContact(void);
	// Methods
	void			setContact(void);

	// Getters
	std::string		getFirstName(void);
	std::string		getLastName(void);
	std::string		getNickname(void);
	std::string		getPhoneNumber(void);
	std::string		getDarkestSecret(void);

};

#endif // CONTACT_HPP
