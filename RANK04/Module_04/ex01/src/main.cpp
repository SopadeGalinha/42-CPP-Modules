/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhogonca <jhogonca@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 08:49:25 by jhogonca          #+#    #+#             */
/*   Updated: 2024/02/24 08:49:25 by jhogonca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Animal.hpp"

void test()
{
	cout << endl
		 << YELLOW << "-------- My Own Test -------" << RESET << endl
		 << endl;
	const int arraySize = 6;

	// Create Dog and Cat objects
	cout << endl
		 << YELLOW << "-------- Create Dog --------" << RESET << endl
		 << endl;
	const Animal *dog = new Dog();
	cout << endl
		 << YELLOW << "-------- Create Cat --------" << RESET << endl
		 << endl;
	const Animal *cat = new Cat();

	// Get ideas from Dog and Cat objects
	cout << endl
		 << YELLOW << "-------- Get ideas ----------" << RESET << endl
		 << endl;
	cout << GREEN << "Dog's: " << ((Dog *)dog)->getBrain()->getIdeas()[5] << RESET << endl;
	cout << GREEN << "Cat's: " << ((Cat *)cat)->getBrain()->getIdeas()[6] << RESET << endl;

	// Delete the Dog and Cat objects
	cout << endl
		 << YELLOW << "-------- Delete Dog --------" << RESET << endl
		 << endl;
	delete dog;
	cout << endl
		 << YELLOW << "-------- Delete Cat --------" << RESET << endl
		 << endl;
	delete cat;

	cout << endl
		 << YELLOW << "--- Fill an array of Animals --"
		 << RESET << endl
		 << endl;

	Animal *animals[arraySize];

	for (int i = 0; i < arraySize; ++i)
	{
		if (i < arraySize / 2)
			animals[i] = new Dog(); // Create Dog objects in the first half of the array
		else
			animals[i] = new Cat(); // Create Cat objects in the second half of the array
	}

	// Make all Animal objects in the array make a sound
	cout << endl
		 << YELLOW << "-------- Make sound --------" << RESET << endl
		 << endl;
	for (int i = 0; i < arraySize; ++i)
	{
		animals[i]->makeSound();
	}

	// Delete all Animal objects in the array
	cout << endl
		 << YELLOW << "----- Deleting Animals ------" << RESET << endl;
	for (int i = 0; i < arraySize; ++i)
	{
		delete animals[i];
	}
}

void subjectTest()
{
	cout << endl
		 << YELLOW << "-------- Subject Test ------" << RESET << endl
		 << endl;
	const Animal *j = new Dog();
	const Animal *i = new Cat();
	delete j; // should not create a leak
	delete i; // should not create a leak
}

int main()
{
	subjectTest();
	test();
	return 0;
}
