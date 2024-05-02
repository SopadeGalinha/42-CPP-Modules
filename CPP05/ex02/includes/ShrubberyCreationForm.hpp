/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhogonca <jhogonca@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 07:52:36 by jhogonca          #+#    #+#             */
/*   Updated: 2024/05/02 07:52:36 by jhogonca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

// Libraries
# include <iostream>
# include <string>
# include "AForm.hpp"
# include "Bureaucrat.hpp"
# include <fstream>

class ShrubberyCreationForm : public AForm
{
	private:
		std::string _target;
	public:
		// Constructors & Destructor
		ShrubberyCreationForm();
		ShrubberyCreationForm(std::string target);
		ShrubberyCreationForm(ShrubberyCreationForm const &other);
		~ShrubberyCreationForm() { };
	
		ShrubberyCreationForm &operator=(ShrubberyCreationForm const &other);
		
		// Getters
		std::string const	&getTarget() const;
		
		// Member functions
		void				execute(Bureaucrat const &executor) const;
};

#endif
