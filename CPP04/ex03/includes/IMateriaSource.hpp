/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IMateriaSource.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhogonca <jhogonca@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/30 20:23:54 by jhogonca          #+#    #+#             */
/*   Updated: 2024/03/30 20:23:54 by jhogonca         ###   ########.fr       */
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
// IMateriaSource class

// -----> Description <-----
/* The IMateriaSource class is an interface class that will be inherited by the
MateriaSource class. It has a virtual destructor and two pure virtual functions.
The learnMateria function receives an AMateria pointer as parameter and stores it
in the source. The createMateria function receives a string as parameter and returns
a new instance of the AMateria class. */

/* class IMateriaSource
{
public:
	// Constructors and destructor
	virtual ~IMateriaSource(void) {};
	// Member functions
	virtual void learnMateria(AMateria* m) = 0;
	virtual AMateria* createMateria(std::string const &type) = 0;
};
 */