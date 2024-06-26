/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhogonca <jhogonca@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 08:03:11 by jhogonca          #+#    #+#             */
/*   Updated: 2024/05/02 08:03:11 by jhogonca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/AForm.hpp"
#include "../includes/RobotomyRequestForm.hpp"

// Default constructor
RobotomyRequestForm::RobotomyRequestForm() : AForm("Default", 72, 45), _target("Default")
{
	return;
}

// parameterized constructor
RobotomyRequestForm::RobotomyRequestForm(std::string target) : AForm("RobotomyRequestForm", 72, 45), _target(target)
{
	return;
}

// Copy constructor
RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const &other) : AForm(other), _target(other._target)
{
	*this = other;
	return;
}

// Operator overloads
RobotomyRequestForm &RobotomyRequestForm::operator=(RobotomyRequestForm const &other)
{
	if (this == &other)
		return (*this);
	_target = other._target;
	return (*this);
}

// Getters
std::string const &RobotomyRequestForm::getTarget() const
{
	return (_target);
}

// Member functions
/**
 * Executes the RobotomyRequestForm.
 * 
 * @param executor The bureaucrat who is executing the form.
 * @throws FormNotSignedException if the form is not signed.
 * @throws GradeTooLowException if the executor's grade is too low to execute the form.
 */
void RobotomyRequestForm::execute(Bureaucrat const &executor) const
{
	if (!getSigned())
		throw FormNotSignedException();
	if (executor.getGrade() > getGradeToExecute())
		throw GradeTooLowException();
	std::srand(static_cast<unsigned int>(std::time(NULL)));
	std::cout << "* drilling noises *" << std::endl;
	if (std::rand() % 2)
		std::cout << _target << " has been robotomized successfully." << std::endl;
	else
		std::cout << _target << " robotomization failed." << std::endl;
}
