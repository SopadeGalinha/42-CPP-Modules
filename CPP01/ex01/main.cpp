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

static std::string	*generate_horde_name(int size);
static void	callingZombieHorde(int hordeCount, int hordeSize, \
std::string* hordeNames, Zombie* horde[]);
static void	callingAnnounce(int hordeCount, int hordeSize, Zombie* horde[]);
static void	deleteHordes(int hordeCount, Zombie* horde[]);


int	main(void)
{
	const int hordeCount = 3;
	const int hordeSize	 = 3;
	std::string* hordeNames;
	Zombie* horde[hordeCount];

	hordeNames = generate_horde_name(hordeCount);
	callingZombieHorde(hordeCount, hordeSize, hordeNames, horde);
	callingAnnounce(hordeCount, hordeSize, horde);
	deleteHordes(hordeCount, horde);
	std::cout << BLUE << "End of the program." << RESET << std::endl;
	return (0);
}

static void 	   callingZombieHorde(int hordeCount, \
int hordeSize, std::string* hordeNames, Zombie* horde[]) {
	std::cout << BLUE << "Calling zombieHorde()...\n" << RESET << std::endl;
	for (int i = 0; i < hordeCount; i++)
		horde[i] = zombieHorde(hordeSize, hordeNames[i]);
	std::cout << BLUE << "\nzombieHorde() finished." << RESET << std::endl;
	std::cout << std::endl;
}
static void	callingAnnounce(int hordeCount, int hordeSize, Zombie* horde[]) {
	std::cout << BLUE << "Calling announce() on hordes..." << RESET << std::endl;
	for (int i = 0; i < hordeCount; i++)
		for (int j = 0; j < hordeSize; j++)
			horde[i][j].announce();
	std::cout << BLUE << "announce() finished." << RESET << std::endl;
	std::cout << std::endl;
}

static void	deleteHordes(int hordeCount, Zombie* horde[]) {
	int i = 0;
	std::cout << BLUE << "Deleting the hordes..." << RESET << std::endl;
	while (i < hordeCount)
		delete[] horde[i++];
	std::cout << BLUE << "Hordes deleted." << RESET << std::endl;
	std::cout << std::endl;
}

static std::string  *generate_horde_name(int size)
{
	const int numNames = 45;
	int	randomIndex = 0;

	// Creating a zombie horde   
	std::string zombieNames[] = {
		"Valkyrie",	"Maestro",	"Bandit", 
		"Maverick",	"Caveira",	"Lesion",
		"Gridlock",	"Capitao",	"Frost", 
		"Montagne",	"Hibana",	"Blitz", 
		"Thermite",	"Castle",	"Vigil", 

		"Pulse",	"Ying",			"Buck",
		"Nomad",	"Ela",			"Mira",
		"Alibi",	"Zofia",		"Echo",
		"Finka",	"Thatcher",		"Rook",
		"Jager",	"Blackbeard",	"Doc",

		"Ash", 		"Twitch",	"Sledge",
		"IQ",		"Fuze",		"Tachanka",
		"Kapkan",	"Kali",		"Fuze",
		"Smoke",	"Clash",	"Mozzie",
		"Glaz",		"Jackal",	"Mute"
	};
	std::string* hordeNames = new std::string[size];

	// Generating random names for the horde
	std::srand(static_cast<unsigned int>(std::time(NULL)));

	if (size == 1)
		std::cout << BLUE << "Generating a random name for the horde..." << RESET << std::endl;
	else
		std::cout << BLUE << "Generating random names for the hordes..." << RESET << std::endl;
	std::cout << "\t";
	for (int i = 0; i < size; i++)
	{
		randomIndex = std::rand() % numNames;
		hordeNames[i] = zombieNames[randomIndex];
		
		std::cout << GREEN << hordeNames[i] << RESET;

		if (i < size - 1) {
			if (i == size -2)
				std::cout << GREEN << " and " << RESET;
			else
				std::cout << ",  ";
		}
	}
	if (size == 1) {
		std::cout << GREEN << " is the name of the horde." << RESET << std::endl;
		std::cout << BLUE << "Name generated." << RESET << std::endl;
	}
	else {
		std::cout << GREEN << " are the names of the hordes." << RESET << std::endl;	
		std::cout << BLUE << "Names generated." << RESET << std::endl;
	}
	std::cout << std::endl;
	return (hordeNames);
}
