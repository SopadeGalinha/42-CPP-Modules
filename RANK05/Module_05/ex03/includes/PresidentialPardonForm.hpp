/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhogonca <jhogonca@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 07:51:26 by jhogonca          #+#    #+#             */
/*   Updated: 2024/05/02 07:51:26 by jhogonca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP

// Libraries
#include <iostream>
#include <string>
#include "AForm.hpp"
#include "Bureaucrat.hpp"

/**
 * @class PresidentialPardonForm
 * @brief A class representing a presidential pardon form.
 *
 * The `PresidentialPardonForm` class is derived from the `AForm` class 
 * and represents a form that grants a presidential pardon.
 */
class PresidentialPardonForm : public AForm
{
private:
	std::string _target;

public:
	// Constructors & Destructor
	PresidentialPardonForm();
	PresidentialPardonForm(std::string target);
	PresidentialPardonForm(PresidentialPardonForm const &other);
	~PresidentialPardonForm(){};

	PresidentialPardonForm &operator=(PresidentialPardonForm const &other);

	// Getters
	std::string const &getTarget() const;

	// Member functions
	void execute(Bureaucrat const &executor) const;
};

#endif
