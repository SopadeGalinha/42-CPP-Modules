/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhogonca <jhogonca@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 00:48:01 by jhogonca          #+#    #+#             */
/*   Updated: 2024/05/02 00:48:01 by jhogonca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Bureaucrat.hpp"

void test1()
{
	cout << YELLOW << "\nTest 1: Creating Bureaucrat with lowest valid grade (150)\n" << RESET;
	Bureaucrat b1("Alice", 150);
	cout << b1 << endl;
}

void test2()
{
	cout << YELLOW << "\nTest 2: Creating Bureaucrat with highest valid grade (1)\n" << RESET;
	Bureaucrat b1("Bob", 1);
	cout << b1 << endl;
}

void test3()
{
	cout << YELLOW << "\nTest 3: Incrementing grade from 2 to 1\n" << RESET;
	Bureaucrat b1("Charlie", 2);
	b1.incrementGrade();
	cout << b1 << endl;
}

void test4()
{
	cout << YELLOW << "\nTest 4: Decrementing grade from 149 to 150\n" << RESET;
	Bureaucrat b1("David", 149);
	b1.decrementGrade();
	cout << b1 << endl;
}

void test5()
{
	cout << YELLOW << "\nTest 5: Incrementing grade from 1" << \
	"\n\t(should throw GradeTooHighException)\n"
		 << RESET;
	Bureaucrat b1("Eve", 1);
	try
	{
		b1.incrementGrade();
	}
	catch (const Bureaucrat::GradeTooHighException &e)
	{
		cout << BLUE << "\tCaught exception: " << e.what() << endl
			 << RESET;
	}
}

void test6()
{
	cout << YELLOW << "\nTest 6: Decrementing grade from 150 <<" \
	"\n\t(should throw GradeTooLowException)\n"
		 << RESET;
	Bureaucrat b1("Frank", 150);
	try
	{
		b1.decrementGrade();
	}
	catch (const Bureaucrat::GradeTooLowException &e)
	{
		cout << BLUE << "\tCaught exception: " << e.what() << endl
			 << RESET;
	}
}

void test7()
{
	cout << YELLOW << "\nTest 7: Creating Bureaucrat with grade lower than 1"<< \
	" \n\t(should throw GradeTooHighException)\n"
		 << RESET;
	try
	{
		Bureaucrat b1("Grace", 0);
	}
	catch (const Bureaucrat::GradeTooHighException &e)
	{
		cout << BLUE << "\tCaught exception: " << e.what() << endl
			 << RESET;
	}
}

void test8()
{
	cout << YELLOW << "\nTest 8: Creating Bureaucrat with grade higher than 150" << \
	"\n\t(should throw GradeTooLowException)\n"
		 << RESET;
	try
	{
		Bureaucrat b1("Hannah", 151);
	}
	catch (const Bureaucrat::GradeTooLowException &e)
	{
		cout << BLUE << "\tCaught exception: " << e.what() << endl
			 << RESET;
	}
}

void test9()
{
	cout << YELLOW << "\nTest 9: Copying a Bureaucrat and checking grade\n"
		 << RESET;
	Bureaucrat b1("Ian", 100);
	Bureaucrat b2 = b1;
	cout << b2 << endl;
}

void test10()
{
	cout << YELLOW << "\nTest 10: Using assignment operator"<< \
	"\n\tto copy a Bureaucrat and checking grade\n"
		 << RESET;
	Bureaucrat b1("John", 50);
	Bureaucrat b2("Jane", 75);
	b2 = b1;
	cout << b2 << endl;
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
