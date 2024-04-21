/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhogonca <jhogonca@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/21 20:57:13 by jhogonca          #+#    #+#             */
/*   Updated: 2024/04/21 20:57:13 by jhogonca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AMATERIA_HPP
# define AMATERIA_HPP

// Libraries
# include "ICharacter.hpp"

using std::string;
using std::cout;
using std::endl;

// Color codes
#define RESET		"\033[0m"
#define RED			"\033[31m"
#define BLUE		"\033[34m"
#define GREEN		"\033[32m"
#define YELLOW		"\033[33m"

// AMateria class

// -----> Description <-----
/* A materia is a magical entity that can be used to cast spells.
It is a virtual class that will be inherited by concrete classes that
will implement the spells. The materia has a type, which is the name
of the spell, and a use function that will be implemented by the concrete
classes. The use function will receive a target as parameter, which will
be the character that will be the target of the spell. */

// AMateria class

class AMateria
{
protected:
	std::string _type;
public:
	// Constructors and destructor
	AMateria(void);
	AMateria(std::string const & type);
	AMateria(const AMateria &source);
	virtual ~AMateria(void);

	// Operator overloads
	AMateria			&operator=(const AMateria &other);

	// Member functions
	std::string const 	&getType(void) const; //Returns the materia type
	virtual void 		use(ICharacter& target);
	virtual AMateria	*clone(void) const = 0;
};


#endif