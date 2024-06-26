/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhogonca <jhogonca@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/30 20:19:55 by jhogonca          #+#    #+#             */
/*   Updated: 2024/03/30 20:19:55 by jhogonca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CURE_HPP
# define CURE_HPP

// Libraries
# include "AMateria.hpp"
# include "ICharacter.hpp"

// -----> Description <-----
/* The Cure class is a concrete class that inherits from the AMateria class.
It has a constructor that initializes the type of the materia to "cure". 
It has a clone function that returns a new instance of the Cure class. 
It has a use function that prints a message to the standard
output. */

// Cure class
class Cure : public AMateria
{
public:
    // Constructors and destructor
    Cure();
    Cure(const Cure &source);
    virtual ~Cure();

    // Operator overloads
    Cure &operator=(const Cure &other);

    // Member functions
    AMateria *clone() const;
    void use(ICharacter& target);
};

#endif
