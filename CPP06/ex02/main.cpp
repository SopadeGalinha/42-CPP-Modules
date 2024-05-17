/* ************************************************************************** */
/*                                                                            */
/*                                                        :::\t     ::::::::\t  */
/*   main.cpp                                           :+:\t     :+:\t   :+:\t  */
/*                                                    +:+ +:+         +:+     */
/*   By:\tjhogonca <jhogonca@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created:\t2024/05/17 20:53:35 by jhogonca          #+#    #+#             */
/*   Updated:\t2024/05/17 20:53:35 by jhogonca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"

/**
 * Generates a random Base object.
 * @return A pointer to a Base object.
 */
Base *generate(void)
{
	int random = rand() % 3;
	if (random == 0)
		return new A();
	else if (random == 1)
		return new B();
	else
		return new C();
}

/**
 * Identifies the type of object pointed to
 * by the given pointer and prints the corresponding letter.
 * @param p A pointer to a Base object.
 */

void identify_from_pointer(Base *p)
{
	if (dynamic_cast<A *>(p))
		std::cout << GREEN "From pointer:\tA" << RESET << std::endl;
	else if (dynamic_cast<B *>(p))
		std::cout << BLUE "From pointer:\tB" << RESET << std::endl;
	else if (dynamic_cast<C *>(p))
		std::cout << YELLOW "From pointer:\tC" << RESET << std::endl;
	else
		std::cerr << RED "Error:\tUnknown type" << RESET << std::endl;
}

/**
 * Identifies the type of object referenced by the given reference
 * and prints the corresponding letter.
 * @param p A reference to a Base object.
 */
void identify_from_reference(Base &p)
{
	// Try to cast the reference to each derived class.
	try
	{
		A &a = dynamic_cast<A &>(p);
		(void)a;
		std::cout << GREEN << "From reference:\tA" << RESET << std::endl;
	}
	catch (const std::exception &e) {
		std::cerr << RED << e.what() << RESET << std::endl;
	}
	
	try {
		B &b = dynamic_cast<B &>(p);
		(void)b;
		std::cout << BLUE << "From reference:\tB" << RESET << std::endl;
	}
	catch (const std::exception &e) {
		std::cerr << RED << e.what() << RESET << std::endl;
	}
	try {
		C &c = dynamic_cast<C &>(p);
		(void)c;
		std::cout << YELLOW << "From reference:\tC" << RESET << std::endl;
	}
	catch (const std::exception &e) {
		std::cerr << RED << e.what() << RESET << std::endl;
	}
}

int main()
{
	srand(time(NULL));
	Base *base = generate();
	identify_from_pointer(base);
	identify_from_reference(*base);
	delete base;
	return 0;
}
