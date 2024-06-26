/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhogonca <jhogonca@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/04 18:28:13 by jhogonca          #+#    #+#             */
/*   Updated: 2024/05/04 19:27:29 by jhogonca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Intern.hpp"

// Constructor
Intern::Intern(void)
{
	_formType["presidential pardon"] = &Intern::createPresidentialPardonForm;
	_formType["robotomy request"] = &Intern::createRobotomyRequestForm;
	_formType["shrubbery creation"] = &Intern::createShrubberyCreationForm;
}

// Copy constructor
Intern::Intern(Intern const &other)
{
	*this = other;
}

// Assignment operator
Intern &Intern::operator=(Intern const &other)
{
	if (this != &other)
	{
		// Limpa o mapa atual
		_formType.clear();

		// Itera sobre cada par chave-valor do outro intern usando um iterador
		std::map<std::string, AForm *(Intern::*)(std::string const &)>::const_iterator it;
		for (it = other._formType.begin(); it != other._formType.end(); ++it)
		{
			// Insere cada par chave-valor no mapa atual
			_formType.insert(std::make_pair(it->first, it->second));
		}
	}
	return *this;
}

// Member functions
AForm *Intern::makeForm(std::string const &formName, std::string const &target)
{
	const MAP_ITERATOR it = _formType.find(formName);
	// const std::map<std::string, AForm *(Intern::*)(std::string const &)>::iterator it = _formType.find(formName);
	if (it == _formType.end())
		throw FormNotFoundException();
	return (this->*(it->second))(target);
}

AForm *Intern::createPresidentialPardonForm(std::string const &target)
{
	return (new PresidentialPardonForm(target));
}

AForm *Intern::createRobotomyRequestForm(std::string const &target)
{
	return (new RobotomyRequestForm(target));
}

AForm *Intern::createShrubberyCreationForm(std::string const &target)
{
	return (new ShrubberyCreationForm(target));
}

// Exception classes
const char *Intern::FormNotFoundException::what() const throw()
{
	return ("Form not found");
}
