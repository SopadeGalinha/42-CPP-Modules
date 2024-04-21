/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhogonca <jhogonca@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/21 19:59:45 by jhogonca          #+#    #+#             */
/*   Updated: 2024/04/21 19:59:45 by jhogonca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
#define ANIMAL_HPP

// Colors
#define RESET "\033[0m"
#define RED "\033[1;31m"
#define BLUE "\033[1;34m"
#define GREEN "\033[1;32m"
#define YELLOW "\033[1;33m"

#include <iostream>
#include <sstream>

using std::cout;
using std::endl;
using std::string;
using std::stringstream;

class Brain;

// Animal Class
class Animal
{
protected:
	string _type;

public:
	// Constructors
	Animal(void);
	Animal(string animal_type);
	Animal(const Animal &other);
	virtual ~Animal(void);

	// Operator overloads
	Animal &operator=(const Animal &other);

	// Member functions
	string getType(void) const;
	virtual void makeSound(void) const;
};

// Cat Class
class Cat : public Animal
{
private:
	Brain *_brain;
public:
	// Constructors
	Cat(void);
	Cat(const Cat &other);
	virtual ~Cat(void);

	// Operator overloads
	Cat &operator=(const Cat &other);

	// Member functions
	virtual void makeSound(void) const;
	Brain *getBrain(void) const;
};

// Dog Class
class Dog : public Animal
{
private:
	Brain *_brain;

public:
	// Constructors
	Dog(void);
	Dog(const Dog &other);
	virtual ~Dog(void);

	// Operator overloads
	Dog &operator=(const Dog &other);

	// Member functions
	virtual void makeSound(void) const;
	Brain *getBrain(void) const;
};

// WrongAnimal Class
class WrongAnimal
{
protected:
	string _type;

public:
	// Constructors
	WrongAnimal(void);
	WrongAnimal(string animal_type);
	WrongAnimal(const WrongAnimal &other);
	virtual ~WrongAnimal(void);

	// Operator overloads
	WrongAnimal &operator=(const WrongAnimal &other);

	// Member functions
	string getType(void) const;
	void makeSound(void) const;
};

// Brain Class
class Brain
{
private:
	std::string _ideas[100];

public:
	// Constructors
	Brain(void);
	Brain(const Brain &source);
	~Brain(void);

	// Operator overloads
	Brain &operator=(const Brain &other);

	// Member functions
	std::string *getIdeas(void);
};

#endif
