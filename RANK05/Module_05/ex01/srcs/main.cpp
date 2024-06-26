/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhogonca <jhogonca@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 07:12:54 by jhogonca          #+#    #+#             */
/*   Updated: 2024/05/02 07:12:54 by jhogonca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Bureaucrat.hpp"

void test1()
{
	std::cout << YELLOW << "\nTest 1: Signing form with matching grade\n"
			  << RESET;
	Bureaucrat b1("Alice", 50);
	Form form1("Form A", 50, 50);
	b1.signForm(form1);
	std::cout << form1 << std::endl;
}

void test2()
{
	std::cout << YELLOW << "\nTest 2: Signing form with higher bureaucrat grade\n"
			  << RESET;
	Bureaucrat b2("Bob", 40);
	Form form2("Form B", 50, 50);
	b2.signForm(form2);
	std::cout << form2 << std::endl;
}

void test3()
{
	std::cout << YELLOW << "\nTest 3: Signing form with lower bureaucrat grade "
			  << "(should fail)\n"
			  << RESET;
	Bureaucrat b3("Charlie", 60);
	Form form3("Form C", 50, 50);
	b3.signForm(form3);
	std::cout << form3 << std::endl;
}

void test4()
{
	std::cout << YELLOW << "\nTest 4: Attempting to sign already signed form\n"
			  << RESET;
	Bureaucrat b4("David", 30);
	Form form4("Form D", 40, 40);
	b4.signForm(form4);
	std::cout << form4 << std::endl;
	b4.signForm(form4); // Second attempt should print already signed message
}

void test5()
{
	std::cout << YELLOW << "\nTest 5: Creating form with grade requirements too high "
			  << "(should throw exception)\n"
			  << RESET;
	try
	{
		Form form5("Form E", 0, 50);
	}
	catch (const Form::GradeTooHighException &e)
	{
		std::cout << BLUE << "\tCaught exception: " << e.what() << std::endl
				  << RESET;
	}
}

void test6()
{
	std::cout << YELLOW << "\nTest 6: Creating form with grade requirements too low "
			  << "(should throw exception)\n"
			  << RESET;
	try
	{
		Form form6("Form F", 150, 151);
	}
	catch (const Form::GradeTooLowException &e)
	{
		std::cout << BLUE << "\tCaught exception: " << e.what() << std::endl
				  << RESET;
	}
}

void test7()
{
	std::cout << YELLOW << "\nTest 7: Bureaucrat with the highest grade (1) signing form\n"
			  << RESET;
	Bureaucrat b7("Grace", 1);
	Form form7("Form G", 1, 1);
	b7.signForm(form7);
	std::cout << form7 << std::endl;
}

void test8()
{
	std::cout << YELLOW << "\nTest 8: Bureaucrat with the lowest grade (150) trying to sign form "\
			  << "(should fail)\n"
			  << RESET;
	Bureaucrat b8("Henry", 150);
	Form form8("Form H", 140, 140);
	b8.signForm(form8);
	std::cout << form8 << std::endl;
}

void test9()
{
	std::cout << YELLOW << "\nTest 9: Bureaucrat signing form with different required grades\n"
			  << RESET;
	Bureaucrat b9("Ivy", 75);
	Form form9("Form I", 75, 100);
	b9.signForm(form9);
	std::cout << form9 << std::endl;
}

void test10()
{
	std::cout << YELLOW << "\nTest 10: Bureaucrat with exact grade signing form\n"
			  << RESET;
	Bureaucrat b10("John", 100);
	Form form10("Form J", 100, 120);
	b10.signForm(form10);
	std::cout << form10 << std::endl;
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
	test9();
	test10();
	return 0;
}
