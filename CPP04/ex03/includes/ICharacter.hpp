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
/*
The ICharacter interface represents a character in the game or simulation.
It provides a contract that any class representing a character must adhere to.
This contract includes a set of methods that a character must be able to perform.

The interface includes the following methods:

- `getName`: This method is expected to return the name of the character.
  It is a const method, meaning it does not modify the state of the object it is called on.

- `equip`: This method takes a pointer to an AMateria 
	object and is expected to equip the character with this object.
	The exact behavior of this method is left up to the implementing class.

- `unequip`: This method takes an integer index and is expected to unequip the 
  AMateria object at that index in the character's inventory.
  Again, the exact behavior is left up to the implementing class.

- `use`: This method takes an integer index and a reference to another ICharacter object.
  It is expected to use the AMateria object at the given index on the given character.

The interface also includes a virtual destructor.
This is necessary to ensure that the correct destructor is called when
an object of a class that implements this interface is deleted through
a pointer to the interface. Without a virtual destructor, 
only the ICharacter destructor would be called,
potentially leading to resource leaks.
*/


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