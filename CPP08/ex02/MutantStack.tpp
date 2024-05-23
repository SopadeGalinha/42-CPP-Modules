/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.tpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhogonca <jhogonca@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 13:10:18 by jhogonca          #+#    #+#             */
/*   Updated: 2024/05/23 13:10:18 by jhogonca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"

// Default Constructor
template <typename T>
MutantStack<T>::MutantStack(void) : std::stack<T>() {
	return;
}

// Copy Constructor
template <typename T>
MutantStack<T>::MutantStack(MutantStack const &src) : std::stack<T>(src) {
	return;
}

// Destructor
template <typename T>
MutantStack<T>::~MutantStack(void) {
	return;
}

// Assignation operator overload
template <typename T>
MutantStack<T> &MutantStack<T>::operator=(MutantStack const &obj) {
    if (this != &obj) {
        std::stack<T>::operator=(obj);
    }
    return *this;
}

// Member functions iterator begin
template <typename T>
typename std::stack<T>::container_type::iterator MutantStack<T>::begin(void) {
    return std::stack<T>::c.begin();
}

// Member functions iterator end
template <typename T>
typename std::stack<T>::container_type::iterator MutantStack<T>::end(void) {
    return std::stack<T>::c.end();
}

// Member functions iterator begin const
template <typename T>
typename std::stack<T>::container_type::const_iterator MutantStack<T>::begin(void) const {
    return std::stack<T>::c.begin();
}

// Member functions iterator end const
template <typename T>
typename std::stack<T>::container_type::const_iterator MutantStack<T>::end(void) const {
    return std::stack<T>::c.end();
}
