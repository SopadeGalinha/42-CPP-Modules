/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhogonca <jhogonca@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 08:27:56 by jhogonca          #+#    #+#             */
/*   Updated: 2024/05/02 08:27:56 by jhogonca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../includes/ShrubberyCreationForm.hpp"
#include "../includes/RobotomyRequestForm.hpp"
#include "../includes/PresidentialPardonForm.hpp"
#include "../includes/Bureaucrat.hpp"

void test11() {
    std::cout << YELLOW << "\nTest 11: Bureaucrat successfully executes ShrubberyCreationForm\n" << RESET;
    Bureaucrat b11("Eve", 130);
    ShrubberyCreationForm shrubberyForm("home");
    shrubberyForm.beSigned(b11);
    b11.executeForm(shrubberyForm);
    std::cout << shrubberyForm << std::endl;
}

int main(void)
{
	test11();
	return (0);
}