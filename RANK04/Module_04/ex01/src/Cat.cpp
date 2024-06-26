#include "../includes/Animal.hpp"

/* -----> Methods <----- */

// Default Constructor
Cat::Cat(void) : Animal("Cat") {
	cout << BLUE << "[Cat] - \tDefault Constructor" << RESET << endl;
	_brain = new Brain();
}

// Copy Constructor
Cat::Cat(const Cat &other) : Animal(other) {
	cout << BLUE << "[Cat] - \tCopy Constructor" << RESET << endl;
	if (this == &other)
		return ;
	_type = other._type;
	_brain = new Brain(*other._brain);
}

// Destructor
Cat::~Cat(void) {
	delete _brain; // Free the memory of the _brain
	cout << RED << "[Cat] - \t" << this->getType() << " Destroyed" << RESET << endl;
}

// Operator Overload
Cat &Cat::operator=(const Cat &other) {
    cout << BLUE << "[Cat] - \tOperator Overload" << RESET << endl;
    if (this != &other) {
        this->_type = other._type;
        delete _brain; // Free the memory of the existing _brain
        _brain = new Brain(*other._brain); // Allocate memory for a new _brain
    }
    return *this;
}

/* -----> Member Functions <----- */

// Make Sound
void	Cat::makeSound(void) const {
	cout << GREEN << "[Cat] - \t" << this->getType() << " says: \"Meow\"" << RESET << endl;
}

// Get Brain
Brain	*Cat::getBrain(void) const {
	return (_brain);
}
