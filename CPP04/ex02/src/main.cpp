#include "../includes/Animal.hpp"

int main()
{
	/* Uncommenting the following line will result in a compilation error. */
	// Animal* animal = new Animal();

	cout << endl
			  << YELLOW << "-------- Create Dog --------" << RESET << endl
			  << endl;
	const Dog *j = new Dog();

	cout << endl
			  << YELLOW << "-------- Create Cat --------" << RESET << endl
			  << endl;
	const Cat *i = new Cat();

	cout << endl
			  << YELLOW << "-------- Make Sounds --------" << RESET << endl
			  << endl;
	j->makeSound();
	i->makeSound();

	cout << endl
			  << YELLOW << "-------- Create Copies --------" << RESET << endl
			  << endl;
	Dog *copy_dog = new Dog(*j);
	Cat *copy_cat = new Cat(*i);

	cout << endl
			  << YELLOW << "-------- Check Copy Sounds --------" << RESET << endl
			  << endl;
	copy_dog->makeSound();
	copy_cat->makeSound();

	cout << endl
			  << YELLOW << "-------- Delete Copies --------" << RESET << endl
			  << endl;
	delete copy_dog;
	delete copy_cat;

	cout << endl
			  << YELLOW << "-------- Assign Operator --------" << RESET << endl
			  << endl;
	// Test assignment operator
	Dog assigned_dog = *j;
	Cat assigned_cat = *i;

	cout << endl
			  << YELLOW << "-------- Check Assigned Sounds --------" << RESET << endl
			  << endl;
	assigned_dog.makeSound();
	assigned_cat.makeSound();

	cout << endl
			  << YELLOW << "-------- Delete Dog --------" << RESET << endl
			  << endl;
	delete j; // Should not create a leak

	cout << endl
			  << YELLOW << "-------- Delete Cat --------" << RESET << endl
			  << endl;
	delete i; // Should not create a leak
	return 0;
}
