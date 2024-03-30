/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhogonca <jhogonca@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/30 20:22:10 by jhogonca          #+#    #+#             */
/*   Updated: 2024/03/30 20:22:10 by jhogonca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/* 
#pragma once

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
// Ice class

// -----> Description <-----
/* The Ice class is a concrete class that inherits from the AMateria class.
It has a constructor that initializes the type of the materia to "ice". It
has a copy constructor and a destructor. It has an operator overload for the
assignment operator. It has a clone function that returns a new instance of
the Ice class. It has a use function that prints a message to the standard
output. */

/* class Ice : public AMateria
{
public:
	// Constructors and destructor
	Ice(void);
	Ice(const Ice &source);
	virtual ~Ice(void);

	// Operator overloads
	Ice	&operator=(const Ice &other);

	// Member functions
	AMateria	*clone(void) const;
	void		use(ICharacter& target);
};
 */