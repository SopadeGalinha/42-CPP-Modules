/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhogonca <jhogonca@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 12:36:57 by jhogonca          #+#    #+#             */
/*   Updated: 2023/12/16 12:36:57 by jhogonca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

// randomChump() is a function that creates a Zombie object on the stack and
// calls the announce() member function on it. The memory is allocated on the stack

// newZombie() is a function that creates a Zombie object on the heap and returns
// a pointer to it. The memory is allocated on the heap and must be freed manually

int	main(void)
{
	Zombie	*zombieHeap;
	Zombie	zombieStack("StackZombie");
	
	std::cout << BLUE << "Testing the Zombie class with a Zombie object on the stack:" << RESET << std::endl;
	std::cout << GREEN << "\tCreating a Zombie object on the stack..." << RESET << std::endl;
	std::cout << GREEN << "\tCalling the announce() member function on the Zombie object..." << RESET << std::endl;
	zombieStack.announce();

	std::cout << BLUE << "\nTesting the Zombie class with a Zombie object on the heap:" << RESET << std::endl;
	std::cout << GREEN << "\tCreating a Zombie object on the heap..." << RESET << std::endl;
	zombieHeap = newZombie("HeapZombie");

	std::cout << GREEN << "\tCalling the announce() member function on the Zombie object..." << RESET << std::endl;
	zombieHeap->announce();
	
	std::cout << BLUE << "\nDeleting the Zombie object..." << RESET << std::endl;
	delete zombieHeap;	
	std::cout << GREEN << "\tZombie object deleted." << RESET << std::endl;

	std::cout << BLUE << "\nTesting automatic Zombie creation with randomChump():" << RESET << std::endl;
	std::cout << GREEN << "\tCalling randomChump()..." << RESET << std::endl;
	randomChump("AutomaticZombie");
	std::cout << GREEN << "\tZombie created." << RESET << std::endl;	
	return (0);
}
