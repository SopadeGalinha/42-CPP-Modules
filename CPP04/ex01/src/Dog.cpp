#include "../includes/Animal.hpp"

/* -----> Methods <----- */

// Default Constructor
Dog::Dog(void) : Animal("Dog") {
	cout << BLUE << "[Dog] - \tDefault Constructor" << RESET << endl;
	_brain = new Brain();
}

// Copy Constructor
Dog::Dog(const Dog &other) : Animal(other) {
	cout << BLUE << "[Dog] - \tCopy Constructor" << RESET << endl;
	if (this == &other)
		return ;
	_type = other._type;
	_brain = new Brain(*other._brain);
}

// Destructor
Dog::~Dog(void) {
	delete _brain; // Free the memory of the _brain
	cout << RED << "[Dog] - \t" << this->getType() << " Destroyed" << RESET << endl;
}

// Operator Overload
Dog &Dog::operator=(const Dog &other) {
    cout << BLUE << "[Dog] - \tOperator Overload" << RESET << endl;
    if (this != &other) {
        this->_type = other._type;
        delete _brain; // Free the memory of the existing _brain
        _brain = new Brain(*other._brain); // Allocate memory for a new _brain
    }
    return *this;
}

/* -----> Member Functions <----- */

// Make Sound
void	Dog::makeSound(void) const {
	cout << GREEN << "[Dog] - \t" << this->getType() << " says: \"Woof\"" << RESET << endl;
}

// Get Brain
Brain	*Dog::getBrain(void) const {
	return (_brain);
}