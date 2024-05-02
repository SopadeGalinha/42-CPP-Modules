/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhogonca <jhogonca@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 08:04:35 by jhogonca          #+#    #+#             */
/*   Updated: 2024/05/02 08:04:35 by jhogonca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ShrubberyCreationForm.hpp"
#include <fstream>

// Default constructor
ShrubberyCreationForm::ShrubberyCreationForm() : AForm("Default", 145, 137), _target("Default")
{
	return;
}

// parameterized constructor
ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : AForm("ShrubberyCreationForm", 145, 137), _target(target)
{
	return;
}

// Copy constructor
ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const &other) : AForm(other), _target(other._target)
{
	*this = other;
	return;
}

// Operator overloads
ShrubberyCreationForm &ShrubberyCreationForm::operator=(ShrubberyCreationForm const &other)
{
	if (this == &other)
		return (*this);
	_target = other._target;
	return (*this);
}

// Getters
std::string const &ShrubberyCreationForm::getTarget() const
{
	return (_target);
}

// Member functions
void ShrubberyCreationForm::execute(Bureaucrat const &executor) const
{
	// Check if the form is signed
	if (!this->getSigned())
		throw AForm::FormNotSignedException();
	// Check if the executor has the right grade
	if (executor.getGrade() > this->getGradeToExecute())
		throw AForm::GradeTooLowException();

	// Create the file
	std::ofstream file;
	std::string filename = _target + "_shrubbery";
	file.open(filename.c_str());

	if (!file.is_open())
		throw AForm::FileNotOpenedException();
	file << "      /\\      " << std::endl;
	file << "     /\\*\\     " << std::endl;
	file << "    /\\O\\*\\    " << std::endl;
	file << "   /*/\\/\\/\\   " << std::endl;
	file << "  /\\O\\/\\*\\/\\  " << std::endl;
	file << " /\\*\\/\\*\\/\\/\\ " << std::endl;
	file << "/\\O\\/\\/*/\\/O/\\" << std::endl;
	file << "      ||      " << std::endl;
	file << "      ||      " << std::endl;
	file << "      ||      " << std::endl;
	file << std::endl;

	file.close();

	cout << GREEN
		 << "ShrubberyCreationForm has been executed by "
		 << executor.getName()
		 << RESET
		 << std::endl;
}
