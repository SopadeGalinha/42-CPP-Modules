/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhogonca <jhogonca@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 06:49:26 by jhogonca          #+#    #+#             */
/*   Updated: 2024/05/02 06:49:26 by jhogonca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Bureaucrat.hpp"

// Default constructor
Form::Form() : _name("Default"), _signed(false), _gradeToSign(150), _gradeToExecute(150)
{
	return;
}

// parameterized constructor
Form::Form(std::string name, int gradeToSign, int gradeToExecute) : _name(name), _signed(false), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute)
{
	if (gradeToSign < MAX_GRADE || gradeToExecute < MAX_GRADE)
		throw GradeTooHighException();
	else if (gradeToSign > MIN_GRADE || gradeToExecute > MIN_GRADE)
		throw GradeTooLowException();
	return;
}

// Copy constructor
Form::Form(Form const &other) : _name(other._name), _signed(other._signed), _gradeToSign(other._gradeToSign), _gradeToExecute(other._gradeToExecute)
{
	*this = other;
	return;
}

// Operator overloads
Form &Form::operator=(Form const &other)
{
	if (this == &other)
		return (*this);
	_signed = other._signed;
	return (*this);
}

// Getters
std::string const &Form::getName() const
{
	return (_name);
}

bool Form::getSigned() const
{
	return (_signed);
}

int Form::getGradeToSign() const
{
	return (_gradeToSign);
}

int Form::getGradeToExecute() const
{
	return (_gradeToExecute);
}

// Member functions
void Form::beSigned(Bureaucrat &bureaucrat)
{
	if (bureaucrat.getGrade() > _gradeToSign)
		throw GradeTooLowException();
	_signed = true;
}

// Exception classes
const char *Form::GradeTooHighException::what() const throw()
{
	return (RED "Grade is too high" RESET);
}

const char *Form::GradeTooLowException::what() const throw()
{
	return (RED "Grade is too low" RESET);
}

// Stream operator overload
std::ostream &operator<<(std::ostream &os, Form const &form)
{
	os << BLUE
	   << "Form: " << form.getName() << std::endl
	   << "Signed: " << (form.getSigned() ? "Yes" : "No") << std::endl
	   << "Grade to sign: " << form.getGradeToSign() << std::endl
	   << "Grade to execute: " << form.getGradeToExecute()
	   << RESET;
	return (os);
}
