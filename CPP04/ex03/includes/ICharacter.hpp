/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ICharacter.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhogonca <jhogonca@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/30 20:22:45 by jhogonca          #+#    #+#             */
/*   Updated: 2024/03/30 20:22:45 by jhogonca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICHARACTER_HPP
# define ICHARACTER_HPP

// Libraries
# include <iostream>
# include <string>
# include <sstream>


/* -----> Description <----- */
/* The ICharacter class is an interface class that will be inherited by the
Character class. It has a virtual destructor and three pure virtual functions.
The getName function returns the name of the character. The equip function
receives an AMateria pointer as parameter and equips it in the first empty slot
of the array. The unequip function receives an integer as parameter and unequips
the materia in the slot of the array corresponding to the index received as
parameter. The use function receives an integer as parameter and uses the materia
in the slot of the array corresponding to the index received as parameter. */

// ICharacter class
class AMateria;
class ICharacter
{
public:
	// Constructors and destructor
	virtual ~ICharacter(void) {};
	// Member functions
	virtual std::string const &getName(void) const = 0;
	virtual void equip(AMateria* m) = 0;
	virtual void unequip(int idx) = 0;
	virtual void use(int idx, ICharacter& target) = 0;
};
#endif