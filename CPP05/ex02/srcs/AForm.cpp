/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhogonca <jhogonca@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 06:49:26 by jhogonca          #+#    #+#             */
/*   Updated: 2024/05/02 06:49:26 by jhogonca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Bureaucrat.hpp"
#include "../includes/AForm.hpp"

// Default constructor
AForm::AForm() : _name("Default"), _signed(false), _gradeToSign(150), _gradeToExecute(150)
{
	return;
}

// parameterized constructor
AForm::AForm(std::string name, int gradeToSign, int gradeToExecute) : _name(name), _signed(false), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute)
{
	if (gradeToSign < MAX_GRADE || gradeToExecute < MAX_GRADE)
		throw GradeTooHighException();
	else if (gradeToSign > MIN_GRADE || gradeToExecute > MIN_GRADE)
		throw GradeTooLowException();
	return;
}

// Copy constructor
AForm::AForm(AForm const &other) : _name(other._name), _signed(other._signed), _gradeToSign(other._gradeToSign), _gradeToExecute(other._gradeToExecute)
{
	*this = other;
	return;
}

// Operator overloads
AForm &AForm::operator=(AForm const &other)
{
	if (this == &other)
		return (*this);
	_signed = other._signed;
	return (*this);
}

// Getters
std::string const &AForm::getName() const
{
	return (_name);
}

bool AForm::getSigned() const
{
	return (_signed);
}

int AForm::getGradeToSign() const
{
	return (_gradeToSign);
}

int AForm::getGradeToExecute() const
{
	return (_gradeToExecute);
}

// Member functions
void AForm::beSigned(Bureaucrat &bureaucrat)
{
	if (bureaucrat.getGrade() > _gradeToSign)
		throw GradeTooLowException();
	_signed = true;
}

// Exception classes
const char *AForm::GradeTooHighException::what() const throw()
{
	return (RED "Grade is too high" RESET);
}

const char *AForm::GradeTooLowException::what() const throw()
{
	return (RED "Grade is too low" RESET);
}

const char *AForm::FormNotSignedException::what() const throw()
{
	return (RED "Form is not signed" RESET);
}

// Stream operator overload
std::ostream &operator<<(std::ostream &os, AForm const &AForm)
{
	os << BLUE
	   << "Form: " << AForm.getName() << std::endl
	   << "Signed: " << (AForm.getSigned() ? "Yes" : "No") << std::endl
	   << "Grade to sign: " << AForm.getGradeToSign() << std::endl
	   << "Grade to execute: " << AForm.getGradeToExecute()
	   << RESET;
	return (os);
}
