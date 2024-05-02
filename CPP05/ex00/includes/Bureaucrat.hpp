/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhogonca <jhogonca@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 00:23:44 by jhogonca          #+#    #+#             */
/*   Updated: 2024/05/02 00:23:44 by jhogonca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

// Libraries
# include <iostream>
# include <string>
# include <exception>
# include <stdexcept>

// Colors
# define RED "\033[1m\033[31m"
# define BLUE "\033[1m\033[34m"
# define GREEN "\033[1m\033[32m"
# define YELLOW "\033[1m\033[33m"
# define RESET "\033[0m"

// Alias
using std::cout;
using std::endl;

// Macros
# define MAX_GRADE 1
# define MIN_GRADE 150

// Class

class Bureaucrat
{
	private:
		std::string const	_name;
		int					_grade;
	public:
		// Constructors & Destructor
		Bureaucrat();
		Bureaucrat(std::string name, int grade);
		Bureaucrat(Bureaucrat const &other);
		~Bureaucrat() { };
	
		Bureaucrat &operator=(Bureaucrat const &other);
		
		// Getters
		std::string const	&getName() const;
		int					getGrade() const;
		
		// Member functions
		void				incrementGrade();
		void				decrementGrade();		
	// Exception classes
	class GradeTooHighException : public std::exception
	{
		public:
			virtual const char *what() const throw();
	};
	class GradeTooLowException : public std::exception
	{
		public:
			virtual const char *what() const throw();
	};
};

std::ostream	&operator<<(std::ostream &os, const Bureaucrat &bureaucrat);

#endif