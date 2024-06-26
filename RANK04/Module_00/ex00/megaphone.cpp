/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhogonca <jhogonca@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/09 00:31:21 by jhogonca          #+#    #+#             */
/*   Updated: 2023/09/09 00:31:21 by jhogonca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

/* 
$>./megaphone "shhhhh... I think the students are asleep..."
SHHHHH... I THINK THE STUDENTS ARE ASLEEP...	->	expected output
SHHHHH... I THINK THE STUDENTS ARE ASLEEP...	->	my output

$>./megaphone Damnit " ! " "Sorry students, I thought this thing was off."
DAMNIT ! SORRY STUDENTS, I THOUGHT THIS THING WAS OFF.	->	expected output
DAMNIT ! SORRY STUDENTS, I THOUGHT THIS THING WAS OFF.	->	my output

$>./megaphone
* LOUD AND UNBEARABLE FEEDBACK NOISE *	->	expected output
* LOUD AND UNBEARABLE FEEDBACK NOISE *	->	my output
$> */

int main(int ac, char **av) {
	if (ac == 1) {
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
	}
	else {
		for (int i = 1; i < ac; ++i) {
			for (int j = 0; av[i][j]; ++j) {
				std::cout << (char)(av[i][j] >= 'a' && av[i][j] <= 'z'\
					? av[i][j] - 32 : av[i][j]);
			}
		}
	}
}