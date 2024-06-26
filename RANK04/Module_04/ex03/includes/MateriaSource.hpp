/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhogonca <jhogonca@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/30 20:24:40 by jhogonca          #+#    #+#             */
/*   Updated: 2024/03/30 20:24:40 by jhogonca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATERIASOURCE_HPP
# define MATERIASOURCE_HPP

// Libraries
# include "IMateriaSource.hpp"

/* -----> Description <----- */
/* The MateriaSource class is a concrete class that inherits from the 
IMateriaSource interface class. It has a learnMateria function that receives an
AMateria pointer as parameter and stores it in the source. It has
a createMateria function that receives a string as parameter and returns
a new instance of the AMateria class. */

// MateriaSource class
class MateriaSource : public IMateriaSource
{
private:
	AMateria *_inventory[4];
public:
	// Constructors and destructor
	MateriaSource(void);
	MateriaSource(const MateriaSource &source);
	virtual ~MateriaSource(void);

	// Operator overloads
	MateriaSource	&operator=(const MateriaSource &other);

	// Member functions
	void learnMateria(AMateria*);
	AMateria* createMateria(std::string const &type);
};

#endif
