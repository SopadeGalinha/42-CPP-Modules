/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhogonca <jhogonca@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 06:46:22 by jhogonca          #+#    #+#             */
/*   Updated: 2024/05/02 06:46:22 by jhogonca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

// Libraries
# include <iostream>

// Classes
class Bureaucrat;

class Form
{
	private:
		std::string const	_name;
		bool				_signed;
		int const			_gradeToSign;
		int const			_gradeToExecute;
	public:
		// Constructors & Destructor
		Form();
		Form(std::string name, int gradeToSign, int gradeToExecute);
		Form(Form const &other);
		~Form() { };
	
		Form &operator=(Form const &other);
		
		// Getters
		std::string const	&getName() const;
		bool				getSigned() const;
		int					getGradeToSign() const;
		int					getGradeToExecute() const;
		
		// Member functions
		void				beSigned(Bureaucrat &bureaucrat);
		
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

// Operator overloads
std::ostream &operator<<(std::ostream &out, Form const &form);

#endif
