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

int	main(void) {
	cout << endl << YELLOW << "-------- Create Dog --------" << RESET << endl << endl;
	const Animal* j = new Dog();

	cout << endl << YELLOW << "-------- Create Cat --------" << RESET << endl << endl;
	const Animal* i = new Cat();

	cout << endl << YELLOW << "-------- Make Sounds --------" << RESET << endl << endl;
	j->makeSound();
	i->makeSound();

    cout << endl << YELLOW << "-------- Get ideas ----------" << RESET << endl << endl;
    
    cout << GREEN << "Dog's: " << ((Dog*)j)->getBrain()->getIdeas()[0] << RESET << endl;
    cout << GREEN << "Cat's: " << ((Cat*)i)->getBrain()->getIdeas()[1] << RESET << endl;

    cout << GREEN << "Dog's: " << ((Dog*)j)->getBrain()->getIdeas()[2] << RESET << endl;
    cout << GREEN << "Cat's: " << ((Cat*)i)->getBrain()->getIdeas()[3] << RESET << endl;

	cout << endl << YELLOW << "-------- Create copies --------" << RESET << endl << endl;
	Animal* copy_dog = new Dog(*((Dog*)j));
	Animal* copy_cat = new Cat(*((Cat*)i));

	cout << endl << YELLOW << "-------- Delete Copies --------" << RESET << endl << endl;
	delete copy_dog;
	delete copy_cat;
	
	cout << endl << YELLOW << "-------- Delete Dog --------" << RESET << endl << endl;
	delete j; //should not create a leak
	
	cout << endl << YELLOW << "-------- Delete Cat --------" << RESET << endl << endl;
	delete i; //should not create a leak
	
	return (0);
}
