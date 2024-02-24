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
	Animal();
	Animal(string animal_type);
	Animal(const Animal &other);
	virtual ~Animal();

	// Operator overloads
	Animal &operator=(const Animal &other);

	// Member functions
	string getType() const;
	virtual void makeSound() const;
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
