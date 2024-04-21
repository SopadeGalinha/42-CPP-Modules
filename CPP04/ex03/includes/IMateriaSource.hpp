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

#ifndef IMATERIASOURCE_HPP
# define IMATERIASOURCE_HPP

// Libraries
# include "AMateria.hpp"

/* -----> Description <----- */
/* The IMateriaSource class is an interface class that will be inherited by the
MateriaSource class. It has a virtual destructor and two pure virtual functions.
The learnMateria function receives an AMateria pointer as parameter and stores it
in the source. The createMateria function receives a string as parameter and returns
a new instance of the AMateria class. */

// IMateriaSource class
class IMateriaSource
{
public:
	// Constructors and destructor
	virtual ~IMateriaSource(void) {};
	// Member functions
	virtual void learnMateria(AMateria*) = 0;
	virtual AMateria* createMateria(std::string const & type) = 0;
};

#endif