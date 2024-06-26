#include "../includes/Animal.hpp"

/* -----> Methods <----- */

// Default Constructor
WrongAnimal::WrongAnimal(void) : _type("") {
	cout << BLUE << "[WrongAnimal] - \tDefault Constructor" << RESET << endl;
}

// Parameterized Constructor
WrongAnimal::WrongAnimal(string type) : _type(type) {
	cout << BLUE << "[WrongAnimal] - \tParameterized Constructor" << RESET << endl;
}

// Copy Constructor
WrongAnimal::WrongAnimal(const WrongAnimal &other) {
	cout << BLUE << "[WrongAnimal] - \tCopy Constructor" << RESET << endl;
	*this = other;
}

// Destructor
WrongAnimal::~WrongAnimal(void) {
	cout << RED << "[WrongAnimal] - \t" << this->_type << " Destroyed" << RESET << endl;
}

// Operator Overload
WrongAnimal	&WrongAnimal::operator=(const WrongAnimal &other) {
	cout << BLUE << "[WrongAnimal] - \tOperator Overload" << RESET << endl;
	this->_type = other._type;
	return *this;
}

/* -----> Getters & Setters <----- */

// Get Type of Animal
string	WrongAnimal::getType(void) const {
	return this->_type;
}

/* -----> Member Functions <----- */

// Make Sound
void	WrongAnimal::makeSound(void) const {
	cout << GREEN << "[WrongAnimal] - \t";
	if (this->_type != "")
		cout << this->_type << " ";
	cout << "says: \"...\"" << RESET << endl;
}
