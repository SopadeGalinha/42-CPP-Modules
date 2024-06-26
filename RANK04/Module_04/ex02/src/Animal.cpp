#include "../includes/Animal.hpp"

/* -----> Methods <----- */

// Default Constructor
Animal::Animal(void) : _type("") {
	cout << BLUE << "[Animal] - \tDefault Constructor" << RESET << endl;
}

// Parameterized Constructor
Animal::Animal(string type) : _type(type) {
	cout << BLUE << "[Animal] - \tParameterized Constructor" << RESET << endl;
}

// Copy Constructor
Animal::Animal(const Animal &other) {
	cout << BLUE << "[Animal] - \tCopy Constructor" << RESET << endl;
	*this = other;
}

// Destructor
Animal::~Animal(void) {
	cout << RED << "[Animal] - \t" << this->_type << " Destroyed" << RESET << endl;
}

// Operator Overload
Animal &Animal::operator=(const Animal &other) {
	cout << BLUE << "[Animal] - \tOperator Overload" << RESET << endl;
	this->_type = other._type;
	return *this;
}

/* -----> Getters & Setters <----- */

// Get Type of Animal
string Animal::getType(void) const {
	return this->_type;
}

/* -----> Member Functions <----- */

// Make Sound
void Animal::makeSound(void) const {
	cout << GREEN << "[Animal] - \t";
	if (this->_type != "")
		cout << this->_type << " ";
	cout << "says: \"...\"" << RESET << endl;
}
