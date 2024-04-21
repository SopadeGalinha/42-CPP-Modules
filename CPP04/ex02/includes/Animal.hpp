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

/*
 * The Animal class is designed to be an abstract class, meaning it cannot be instantiated directly.
 * To make a class abstract, we declare at least one pure virtual function within the class.
 * A pure virtual function is a virtual function that has no implementation in the class declaring it.
 * By declaring the makeSound() function as a pure virtual function in the Animal class, we enforce
 * that any class derived from Animal must provide its own implementation of makeSound().
 * Attempting to create an instance of an abstract class like Animal will result in a compilation error,
 * serving as a safeguard against unintentional instantiation and enforcing proper usage of derived classes.
 */

class Animal
{
protected:
	string _type;

	// Protected constructor and destructor to prevent instantiation
	Animal();
	virtual ~Animal();

public:
	// Constructors
	Animal(string animal_type);
	Animal(const Animal &other);

	// Operator overloads
	Animal &operator=(const Animal &other);

	// Member functions
	string getType() const;
	virtual void makeSound() const = 0; // Pure virtual function
};

// Cat Class
class Cat : public Animal
{
private:
	Brain *_brain;

public:
	// Constructors
	Cat();
	Cat(const Cat &other);
	virtual ~Cat();

	// Operator overloads
	Cat &operator=(const Cat &other);

	// Member functions
	virtual void makeSound() const;
	Brain *getBrain(void) const;
};

// Dog Class
class Dog : public Animal
{
private:
	Brain *_brain;

public:
	// Constructors
	Dog();
	Dog(const Dog &other);
	virtual ~Dog();

	// Operator overloads
	Dog &operator=(const Dog &other);

	// Member functions
	virtual void makeSound() const;
	Brain *getBrain(void) const;
};

// WrongAnimal Class
class WrongAnimal
{
protected:
	string _type;

public:
	// Constructors
	WrongAnimal();
	WrongAnimal(string animal_type);
	WrongAnimal(const WrongAnimal &other);
	virtual ~WrongAnimal();

	// Operator overloads
	WrongAnimal &operator=(const WrongAnimal &other);

	// Member functions
	string getType() const;
	void makeSound() const;
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
	~Brain();

	// Operator overloads
	Brain &operator=(const Brain &other);

	// Member functions
	std::string *getIdeas(void);
};

#endif
