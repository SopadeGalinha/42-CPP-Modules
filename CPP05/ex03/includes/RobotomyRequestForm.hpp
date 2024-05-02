/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhogonca <jhogonca@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 07:52:11 by jhogonca          #+#    #+#             */
/*   Updated: 2024/05/02 07:52:11 by jhogonca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

// Libraries
# include <iostream>
# include <string>
# include "AForm.hpp"
# include "Bureaucrat.hpp"

/**
 * @class RobotomyRequestForm
 * @brief Represents a form for robotomy requests.
 * 
 * The RobotomyRequestForm class is a derived class of AForm and represents
 * a form that can be used to request robotomy.
 */
class RobotomyRequestForm : public AForm
{
	private:
		std::string _target;
	public:
		// Constructors & Destructor
		RobotomyRequestForm();
		RobotomyRequestForm(std::string target);
		RobotomyRequestForm(RobotomyRequestForm const &other);
		~RobotomyRequestForm() { };
	
		RobotomyRequestForm &operator=(RobotomyRequestForm const &other);
		
		// Getters
		std::string const	&getTarget() const;
		
		// Member functions
		void				execute(Bureaucrat const &executor) const;
};

#endif
