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

int main()
{
    const Animal* meta = new Animal();
    const Animal* j = new Dog();
    const Animal* i = new Cat();
	const Animal* k = new Animal("Tiger");
    std::cout << j->getType() << " " << std::endl;
    std::cout << i->getType() << " " << std::endl;
	std::cout << k->getType() << " " << std::endl;
    i->makeSound(); //will output the cat sound!
    j->makeSound();
	k->makeSound();

    meta->makeSound();

    delete meta;
    delete i;
    delete j;
	delete k;

    return 0;
}
