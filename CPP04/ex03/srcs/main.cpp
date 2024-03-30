/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhogonca <jhogonca@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/30 19:50:41 by jhogonca          #+#    #+#             */
/*   Updated: 2024/03/30 19:50:41 by jhogonca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/AMateria.hpp"

int main(void)
{
	cout << "-------- Create Materia Source --------" << endl;
	IMateriaSource* src = new MateriaSource();
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());

	cout << "-------- Create Character --------" << endl;
	ICharacter* me = new Character("me");
	
	cout << "-------- Assign Materia --------" << endl;
	AMateria* tmp;
	tmp = src->createMateria("ice");
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);

	cout << "-------- Create Character Bob --------" << endl;
	ICharacter* bob = new Character("bob");

	cout << "-------- Use Materia on Bob --------" << endl;
	me->use(0, *bob);
	me->use(1, *bob);

	cout << "-------- Delete characters --------" << endl;
	cout << "-------- Bob has no materia --------" << endl;
	delete bob;
	cout << "-------- I have two materia --------" << endl;
	delete me;
	cout << "-------- Delete Materia Source --------" << endl;
	delete src;

	return (0);
}
