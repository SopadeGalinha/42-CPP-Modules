/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhogonca <jhogonca@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/21 20:06:21 by jhogonca          #+#    #+#             */
/*   Updated: 2024/04/21 20:06:21 by jhogonca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Animal.hpp"

// Constructors and destructor
Brain::Brain(void) {
	cout << BLUE << "[Brain] - \tDefault Constructor" << RESET << endl;
	stringstream ss;
	for (int i = 0; i < 100; i++) {
		ss << i;
		_ideas[i] = "Idea #" + ss.str();
	}
}

// Copy constructor
Brain::Brain(const Brain &source) {
	cout << BLUE << "[Brain] - \tCopy Constructor" << RESET << endl;
	*this = source;
}

// Destructor
Brain::~Brain(void) {
	cout << RED << "[Brain] - \tDestroyed" << RESET << endl;
}

// Operator overloads
Brain	&Brain::operator=(const Brain &other) {
	if (this == &other)
		return (*this);
	for (int i = 0; i < 100; i++)
		_ideas[i] = other._ideas[i];
	return (*this);
}

// Member functions
std::string	*Brain::getIdeas(void) {
	return (_ideas);
}
