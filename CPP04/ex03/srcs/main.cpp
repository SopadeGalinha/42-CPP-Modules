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

# include "Character.hpp"

int main(void)
{
	cout << "\n-------- Create Materia Source --------" << endl;
	IMateriaSource* src = new MateriaSource();
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());

	cout << "\n-------- Create Character --------" << endl;
	ICharacter* me = new Character("ME");
	
	cout << "\n-------- Assign Materia --------" << endl;
	AMateria* tmp;
	tmp = src->createMateria("ice");
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);

	cout << "\n-------- Create Character Bob --------" << endl;
	ICharacter* bob = new Character("bob");

	cout << "\n-------- Use Materia on Bob --------" << endl;
	me->use(0, *bob);
	me->use(1, *bob);

	cout << "\n-------- Delete characters --------" << endl;
	cout << "\n-------- Bob has no materia --------" << endl;
	delete bob;
	cout << "\n-------- I have two materia --------" << endl;
	delete me;
	cout << "\n-------- Delete Materia Source --------" << endl;
	delete src;

	return (0);
}
