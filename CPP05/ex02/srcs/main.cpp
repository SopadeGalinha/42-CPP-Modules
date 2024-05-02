/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhogonca <jhogonca@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 20:38:57 by jhogonca          #+#    #+#             */
/*   Updated: 2024/05/02 20:38:57 by jhogonca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "../includes/AForm.hpp"
#include "../includes/Bureaucrat.hpp"
#include "../includes/RobotomyRequestForm.hpp"
#include "../includes/PresidentialPardonForm.hpp"
#include "../includes/ShrubberyCreationForm.hpp"

void test1()
{
	std::cout << YELLOW << "\nTest 1: Bureaucrat successfully signs and executes ShrubberyCreationForm\n"
			  << RESET;
	Bureaucrat b1("John", 130);
	ShrubberyCreationForm form1("garden");
	form1.beSigned(b1);
	b1.executeForm(form1);
	std::cout << form1 << std::endl;
}

void test2()
{
	std::cout << YELLOW << "\nTest 2: Bureaucrat attempts to execute form without signing\n"
			  << RESET;
	Bureaucrat b2("Mary", 130);
	RobotomyRequestForm form2("robot");
	try
	{
		b2.executeForm(form2);
	}
	catch (const AForm::GradeTooLowException &e)
	{
		std::cout << BLUE << "\tCaught exception: " << e.what() << std::endl
				  << RESET;
	}
}

void test3()
{
	std::cout << YELLOW << "\nTest 3: Bureaucrat with high grade attempts to execute PresidentialPardonForm\n"
			  << RESET;
	Bureaucrat b3("Alice", 10);
	PresidentialPardonForm form3("Bob");
	try
	{
		form3.beSigned(b3);
		b3.executeForm(form3);
	}
	catch (const AForm::GradeTooLowException &e)
	{
		std::cout << BLUE << "\tCaught exception: " << e.what() << std::endl
				  << RESET;
	}
}

void test4()
{
	std::cout << YELLOW << "\nTest 4: Bureaucrat with exact required grades successfully executes PresidentialPardonForm\n"
			  << RESET;
	Bureaucrat b4("Charlie", 5);
	PresidentialPardonForm form4("Alice");
	form4.beSigned(b4);
	b4.executeForm(form4);
	std::cout << form4 << std::endl;
}

void test5()
{
	std::cout << YELLOW << "\nTest 6: Bureaucrat with grade too high attempts to sign and execute RobotomyRequestForm\n"
			  << RESET;
	Bureaucrat b6("Susan", 50);
	RobotomyRequestForm form6("test subject");
	form6.beSigned(b6);
	b6.executeForm(form6);
	std::cout << form6 << std::endl;
}

void test6()
{
	std::cout << YELLOW << "\nTest 8: Bureaucrat with highest grade executes PresidentialPardonForm successfully\n"
			  << RESET;
	Bureaucrat b8("Eleanor", 1);
	PresidentialPardonForm form8("test target");
	form8.beSigned(b8);
	b8.executeForm(form8);
	std::cout << form8 << std::endl;
}

void test7()
{
	std::cout << YELLOW << "\nTest 9: Bureaucrat executes RobotomyRequestForm with 50% chance of success\n"
			  << RESET;
	Bureaucrat b9("George", 40);
	RobotomyRequestForm form9("patient");
	form9.beSigned(b9);
	b9.executeForm(form9);
	std::cout << form9 << std::endl;
}

void test8()
{
	std::cout << YELLOW << "\nTest 10: Bureaucrat attempts to execute unsigned ShrubberyCreationForm\n"
			  << RESET;
	Bureaucrat b10("Patricia", 145);
	ShrubberyCreationForm form10("landscape");
	try
	{
		b10.executeForm(form10);
	}
	catch (const AForm::GradeTooLowException &e)
	{
		std::cout << BLUE << "\tCaught exception: " << e.what() << std::endl
				  << RESET;
	}
}

int main()
{
	test1();
	test2();
	test3();
	test4();
	test5();
	test6();
	test7();
	test8();
	return 0;
}
