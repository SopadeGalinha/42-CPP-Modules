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
void ShrubberyCreationForm::execute(Bureaucrat const &executor) const {
    // Call the base class execute method
    AForm::execute(executor);
    
    // Create the filename
    std::string filename = _target + "_shrubbery";
    
    // Create an ofstream and open the file using the filename.c_str()
    std::ofstream file;
    file.open(filename.c_str());
    
    // Check if the file opened successfully
    if (!file.is_open()) {
        std::cerr << "Error: could not open file" << std::endl;
        return;
    }
    
    // Write ASCII trees inside the file
    file << "      /\\      " << std::endl;
    file << "     /\\*\\     " << std::endl;
    file << "    /\\O\\*\\    " << std::endl;
    file << "   /*/\\/\\/\\   " << std::endl;
    file << "  /\\O\\/\\*\\/\\  " << std::endl;
    file << " /\\*\\/\\*\\/\\/\\ " << std::endl;
    file << "/\\O\\/\\/*/\\/O/\\\\" << std::endl;
    file << "      ||      " << std::endl;
    file << "      ||      " << std::endl;
    file << "      ||      " << std::endl;
    file << std::endl;
    
    // Close the file
    file.close();
    
    // Print success message
    std::cout << "Shrubbery has been created successfully" << std::endl;
}
