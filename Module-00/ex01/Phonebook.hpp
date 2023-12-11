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
	// Attributes
	private:
		int			index;
		int			contactsCount;
		Contact		contacts[8];
	public:
		// Constructor and destructor
		PhoneBook(void);
		~PhoneBook(void);

		// Methods
		void	addContact(void);
};

# endif
