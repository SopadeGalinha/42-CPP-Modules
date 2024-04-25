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

#ifndef ICE_HPP
# define ICE_HPP

// Libraries
# include "AMateria.hpp"
# include "ICharacter.hpp"

/* -----> Description <----- */
/* The Ice class is a concrete class that inherits from the AMateria class.
It has a constructor that initializes the type of the materia to "ice". 
A clone function that returns a new instance of the Ice class. 
It has a use function that prints a message to the standard
output. */

// Ice class
class Ice : public AMateria
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

#endif
