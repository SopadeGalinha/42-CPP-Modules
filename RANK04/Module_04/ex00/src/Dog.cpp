#include "../includes/Animal.hpp"

/* -----> Methods <----- */

// Default Constructor
Dog::Dog(void) : Animal("Dog") {
	cout << BLUE << "[Dog] - \tDefault Constructor" << RESET << endl;
}

// Copy Constructor
Dog::Dog(const Dog &other) : Animal(other) {
	cout << BLUE << "[Dog] - \tCopy Constructor" << RESET << endl;
	*this = other;
}

// Destructor
Dog::~Dog(void) {
	cout << RED << "[Dog] - \t" << this->getType() << " Destroyed" << RESET << endl;
}

// Operator Overload
Dog	&Dog::operator=(const Dog &other) {
	cout << BLUE << "[Dog] - \tOperator Overload" << RESET << endl;
	this->_type = other._type;
	return *this;
}

/* -----> Member Functions <----- */

// Make Sound
void	Dog::makeSound(void) const {
	cout << GREEN << "[Dog] - \t" << this->getType() << " says: \"Woof\"" << RESET << endl;
}
