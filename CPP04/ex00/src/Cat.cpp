#include "../includes/Animal.hpp"

/* -----> Methods <----- */

// Default Constructor
Cat::Cat(void) : Animal("Cat") {
	cout << BLUE << "[Cat] - \tDefault Constructor" << RESET << endl;
}

// Copy Constructor
Cat::Cat(const Cat &other) : Animal(other) {
	cout << BLUE << "[Cat] - \tCopy Constructor" << RESET << endl;
	*this = other;
}

// Destructor
Cat::~Cat(void) {
	cout << RED << "[Cat] - \t" << this->getType() << " Destroyed" << RESET << endl;
}

// Operator Overload
Cat	&Cat::operator=(const Cat &other) {
	cout << BLUE << "[Cat] - \tOperator Overload" << RESET << endl;
	this->_type = other._type;
	return *this;
}

/* -----> Member Functions <----- */

// Make Sound
void	Cat::makeSound(void) const {
	cout << GREEN << "[Cat] - \t" << this->getType() << " says: \"Meow\"" << RESET << endl;
}
