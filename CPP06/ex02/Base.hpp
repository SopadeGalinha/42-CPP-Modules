/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhogonca <jhogonca@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 20:51:17 by jhogonca          #+#    #+#             */
/*   Updated: 2024/05/17 20:51:17 by jhogonca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BASE_HPP
# define BASE_HPP

// Colors
# define RED "\033[1;31m"
# define BLUE "\033[1;34m"
# define GREEN "\033[1;32m"
# define YELLOW "\033[1;33m"
# define RESET "\033[0m"

// Libraries
#include <iostream>
#include <cstdlib>
#include <ctime>

// Classes
class Base {
	public:
		virtual ~Base() {};
};

class A : public Base {};
class B : public Base {};
class C : public Base {};

// Functions
Base *generate(void);
void identify_from_pointer(Base *p);
void identify_from_reference(Base &p);

#endif
