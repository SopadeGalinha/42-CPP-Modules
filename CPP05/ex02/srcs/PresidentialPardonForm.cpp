/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhogonca <jhogonca@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 07:57:11 by jhogonca          #+#    #+#             */
/*   Updated: 2024/05/02 07:57:11 by jhogonca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/PresidentialPardonForm.hpp"

// Default constructor
PresidentialPardonForm::PresidentialPardonForm() : AForm("Default", 25, 5)
{
	return;
}

// parameterized constructor
PresidentialPardonForm::PresidentialPardonForm(std::string target) : AForm("PresidentialPardonForm", 25, 5), _target(target)
{
	return;
}

// Copy constructor
PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const &other) : AForm(other), _target(other._target)
{
	*this = other;
	return;
}

// Operator overloads
PresidentialPardonForm &PresidentialPardonForm::operator=(PresidentialPardonForm const &other)
{
	if (this == &other)
		return (*this);
	_target = other._target;
	return (*this);
}

// Member functions
void PresidentialPardonForm::execute(Bureaucrat const &executor) const
{
	if (executor.getGrade() > getGradeToExecute())
		throw GradeTooLowException();
	std::cout << _target << " has been pardoned by Zafod Beeblebrox." << std::endl;
	return;
}
