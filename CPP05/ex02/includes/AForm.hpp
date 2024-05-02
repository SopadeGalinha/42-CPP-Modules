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

#ifndef AFORM_HPP
# define AFORM_HPP

// Libraries
# include <iostream>

// Classes
class Bureaucrat;

class AForm
{
	private:
		std::string const	_name;
		bool				_signed;
		int const			_gradeToSign;
		int const			_gradeToExecute;
	public:
		// Constructors & Destructor
		AForm();
		AForm(std::string name, int gradeToSign, int gradeToExecute);
		AForm(AForm const &other);
		virtual ~AForm() { };
	
		AForm &operator=(AForm const &other);
		
		// Getters
		std::string const	&getName() const;
		bool				getSigned() const;

		// Member functions
		int					getGradeToSign() const;
		int					getGradeToExecute() const;
		void				beSigned(Bureaucrat &bureaucrat);
		
		// Pure virtual functions
		virtual void		execute(Bureaucrat const &executor) const = 0;
		
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

		class FormNotSignedException : public std::exception
		{
			public:
				virtual const char *what() const throw();
		};
};

// Operator overloads
std::ostream &operator<<(std::ostream &os, AForm const &form);

#endif
