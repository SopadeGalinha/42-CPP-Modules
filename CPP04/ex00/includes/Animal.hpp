/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhogonca <jhogonca@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 08:50:14 by jhogonca          #+#    #+#             */
/*   Updated: 2024/02/24 08:50:14 by jhogonca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
# define ANIMAL_HPP

// Colors
# define RESET "\033[0m"
# define RED "\033[1;31m"
# define BLUE "\033[1;34m"
# define GREEN "\033[1;32m"
# define YELLOW "\033[1;33m"

# include <iostream>

using std::string;
using std::cout;
using std::endl;

// Animal Class
class Animal {
protected:
	string _type;
public:
	
	// Constructors
	Animal(void);
	Animal(string animal_type);
	Animal(const Animal& other);
	virtual ~Animal(void);

	// Operator overloads
	Animal	&operator=(const Animal& other);

	// Member functions
	string			getType(void) const;
	virtual void	makeSound(void) const;
};

// Cat Class
class Cat : public Animal {
public:
	// Constructors
	Cat(void);
	Cat(const Cat &other);
	virtual ~Cat(void);

	// Operator overloads
	Cat	&operator=(const Cat &other);

	// Member functions
	virtual void	makeSound(void) const;
};

// Dog Class
class Dog : public Animal {
public:
	// Constructors
	Dog(void);
	Dog(const Dog &other);
	virtual ~Dog(void);

	// Operator overloads
	Dog	&operator=(const Dog &other);

	// Member functions
	virtual void	makeSound(void) const;
};

// WrongAnimal Class
class WrongAnimal {
protected:
	string _type;
public:
	// Constructors
	WrongAnimal();
	WrongAnimal(string animal_type);
	WrongAnimal(const WrongAnimal& other);
	virtual ~WrongAnimal();

	// Operator overloads
	WrongAnimal	&operator=(const WrongAnimal& other);

	// Member functions
	string			getType() const;
	virtual void	makeSound(void) const;
};

class WrongCat : public WrongAnimal
{
public:
	// Constructors
	WrongCat();
	WrongCat(const WrongCat &other);
	virtual ~WrongCat();

	// Operator overloads
	WrongCat	&operator=(const WrongCat &other);

	// Member functions
		virtual void	makeSound(void) const;
};

#endif