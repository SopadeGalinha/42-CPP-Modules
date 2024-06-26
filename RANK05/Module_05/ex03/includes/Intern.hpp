/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhogonca <jhogonca@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/04 18:14:49 by jhogonca          #+#    #+#             */
/*   Updated: 2024/05/04 19:27:27 by jhogonca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
# define INTERN_HPP

// Libraries
#include <iostream>
#include <map>
#include <string>
#include <stdexcept>
#include <exception>
#include "../includes/AForm.hpp"
#include "../includes/RobotomyRequestForm.hpp"
#include "../includes/PresidentialPardonForm.hpp"
#include "../includes/ShrubberyCreationForm.hpp"

# define TOTAL_FORMS 3
# define MAP_ITERATOR std::map<std::string, AForm *(Intern::*)(std::string const &)>::iterator


// Classes
class AForm;

/**
 * @class Intern
 * @brief Represents an intern that can create forms.
 *
 * The Intern class provides functionality to create forms.
 */

class Intern
{
private:
	std::map<std::string, AForm *(Intern::*)(std::string const &)> _formType;

public:
	// Constructors & Destructor
	Intern();
	Intern(Intern const &other);
	~Intern(){ };

	Intern &operator=(Intern const &other);

	// Member functions
	/**
	 * @brief Create a form based on the given form name and target.
	 * 
	 * @param formName The name of the form to create.
	 * @param target The target of the form.
	 * @return A pointer to the created form.
	 * @throws FormNotFoundException if the form name is not found in the _formType map.
	 */
	AForm *makeForm(std::string const &formName, std::string const &target);

	// Form creation functions
	AForm *createPresidentialPardonForm(std::string const &target);
	AForm *createRobotomyRequestForm(std::string const &target);
	AForm *createShrubberyCreationForm(std::string const &target);
	
	// Exception classes
	class FormNotFoundException : public std::exception
	{
	public:
		// Member functions
		virtual const char *what() const throw();
	};
};

#endif
