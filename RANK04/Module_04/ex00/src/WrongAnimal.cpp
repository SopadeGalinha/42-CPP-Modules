#include "../includes/Animal.hpp"

/* -----> Methods <----- */

// Default Constructor
WrongAnimal::WrongAnimal(void) : _type("") {
	cout << BLUE << "[W_Animal] - \tDefault Constructor" << RESET << endl;
}

// Parameterized Constructor
WrongAnimal::WrongAnimal(string type) : _type(type) {
	cout << BLUE << "[W_Animal] - \tParameterized Constructor" << RESET << endl;
}

// Copy Constructor
WrongAnimal::WrongAnimal(const WrongAnimal &other) {
	cout << BLUE << "[W_Animal] - \tCopy Constructor" << RESET << endl;
	*this = other;
}

// Destructor
WrongAnimal::~WrongAnimal(void) {
	cout << RED << "[W_Animal] - \t" << this->_type << " Destroyed" << RESET << endl;
}

// Operator Overload
WrongAnimal	&WrongAnimal::operator=(const WrongAnimal &other) {
	cout << BLUE << "[W_Animal] - \tOperator Overload" << RESET << endl;
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
	cout << GREEN << "[W_Animal] - \t";
	if (this->_type != "")
		cout << this->_type << " ";
	cout << "says: \"...\"" << RESET << endl;
}
