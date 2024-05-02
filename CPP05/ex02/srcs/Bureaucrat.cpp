/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhogonca <jhogonca@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 00:35:29 by jhogonca          #+#    #+#             */
/*   Updated: 2024/05/02 00:35:29 by jhogonca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Bureaucrat.hpp"

// Default constructor
Bureaucrat::Bureaucrat() : _name("Default"), _grade(150)
{
	return ;
}

// parameterized constructor
Bureaucrat::Bureaucrat(std::string name, int grade) : _name(name)
{
	if (grade < MAX_GRADE)
		throw GradeTooHighException();
	else if (grade > MIN_GRADE)
		throw GradeTooLowException();
	_grade = grade;
	return ;
}

// Copy constructor
Bureaucrat::Bureaucrat(Bureaucrat const &other) : _name(other._name), _grade(other._grade)
{
	return ;
}

// Operator overloads
Bureaucrat &Bureaucrat::operator=(Bureaucrat const &other)
{
	if (this == &other)
		return (*this);
	cout << BLUE
		 << "\t [Bureaucrat] - Assignation operator called"
		 << RESET << endl;
	_grade = other._grade;
	return (*this);
}

// Getters
std::string const &Bureaucrat::getName() const
{
	return (_name);
}

int Bureaucrat::getGrade() const
{
	return (_grade);
}

// Member functions
void Bureaucrat::incrementGrade()
{
	if (--_grade < MAX_GRADE)
		throw GradeTooHighException();
}

void Bureaucrat::decrementGrade()
{
	if (++_grade > MIN_GRADE)
		throw GradeTooLowException();
}

// Sign form
void Bureaucrat::signForm(AForm &form)
{
	if (form.getSigned())
	{
		cout << RED
			 << "[Bureaucrat] - " << _name << " cannot sign " << form.getName() << " because it is already signed"
			 << RESET << endl;
	}
	else if (form.getGradeToSign() < _grade)
	{
		cout << RED
			 << "[Bureaucrat] - " << _name << " cannot sign " << form.getName() << " because his grade is too low"
			 << RESET << endl;
	}
	else
	{
		cout << GREEN
			 << "[Bureaucrat] - " << _name << " signs " << form.getName()
			 << RESET << endl;
		form.beSigned(*this);
	}
}

// execute form
void Bureaucrat::executeForm(AForm const &form)
{
	if (form.getSigned())
	{
		if (form.getGradeToExecute() < _grade)
		{
			cout << RED
				 << "[Bureaucrat] - " << _name << " cannot execute " << form.getName() << " because his grade is too low"
				 << RESET << endl;
		}
		else
		{
			cout << GREEN
				 << "[Bureaucrat] - " << _name << " executes " << form.getName()
				 << RESET << endl;
			form.execute(*this);
		}
	}
	else
	{
		cout << RED
			 << "[Bureaucrat] - " << _name << " cannot execute " << form.getName() << " because it is not signed"
			 << RESET << endl;
	}
}

// Exception classes
const char *Bureaucrat::GradeTooHighException::what() const throw()
{
	return (RED "Grade too high!" RESET);
}

const char *Bureaucrat::GradeTooLowException::what() const throw()
{
	return (RED "Grade too low!" RESET);
}

std::ostream &operator<<(std::ostream &out, Bureaucrat const &bureaucrat)
{
	out << GREEN
		<< "\t "<< bureaucrat.getName() << ", bureaucrat grade "
		<< bureaucrat.getGrade()
		<< RESET;
	return (out);
}
