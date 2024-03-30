/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhogonca <jhogonca@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/30 20:14:07 by jhogonca          #+#    #+#             */
/*   Updated: 2024/03/30 20:14:07 by jhogonca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* #pragma once

// Libraries
# include <iostream>
# include <string>
# include <sstream>
#include "Character.hpp"
#include "Cure.hpp"
#include "Ice.hpp"
#include "ICharacter.hpp"
#include "IMateriaSource.hpp"
#include "MateriaSource.hpp"

// Classes
class AMateria;
class Character;
class Cure;
class Ice;
class ICharacter;
class IMateriaSource;
class MateriaSource;
 */
// Character class

// -----> Description <-----
/* The Character class is a concrete class that inherits from the ICharacter
interface class. It has a name and a pointer to an array of 4 AMateria pointers.
It has a virtual destructor and a pure virtual function called equip that will be
implemented by the Character class. The equip function will receive an AMateria
pointer as parameter and will equip it in the first empty slot of the array. The
Character class also has a pure virtual function called unequip that will be
implemented by the Character class. The unequip function will receive an integer
as parameter and will unequip the materia in the slot of the array corresponding
to the index received as parameter. The Character class also has a pure virtual
function called use that will be implemented by the Character class. The use
function will receive an integer as parameter and will use the materia in the
slot of the array corresponding to the index received as parameter. */

/* class Character : public ICharacter
{
private:
	string		_name;
	AMateria	*_inventory[4];
public:
	// Constructors and destructor
	Character(void);
	Character(string const &name);
	Character(const Character &source);
	virtual ~Character(void);

	// Operator overloads
	Character		&operator=(const Character &other);

	// Member functions
	string const	&getName(void) const;
	void				equip(AMateria* m);
	void				unequip(int idx);
	void				use(int idx, ICharacter& target);
};
 */