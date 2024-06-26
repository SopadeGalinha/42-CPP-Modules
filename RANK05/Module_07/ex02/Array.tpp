/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhogonca <jhogonca@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/18 00:37:34 by jhogonca          #+#    #+#             */
/*   Updated: 2024/05/18 00:37:34 by jhogonca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"

// Constructors & Destructors
template <typename T>
Array<T>::Array(void) : _array(NULL), _size(0) {
	return ;
}

// Constructor with parameter
template <typename T>
Array<T>::Array(unsigned int n) : _array(new T[n]()), _size(n) {
	return ;
}

// Assingment operator
template <typename T>
Array<T>::Array(Array const &other) {
	*this = other;
}
// Destructor
template <typename T>
Array<T>::~Array(void) {
	delete [] _array;
}

// Assingment operator
template <typename T>
Array<T> &Array<T>::operator=(Array const &other) {
	if (this != &other) {
		delete [] _array;
		_size = other._size;
		_array = new T[_size];
		for (unsigned int i = 0; i < _size; i++) {
			_array[i] = other._array[i];
		}
	}
	return (*this);
}

// Member functions
template <typename T>
T &Array<T>::operator[](const int index) {
	if (index >= static_cast<int>(_size)) {
		throw OutOfLimits();
	}
	return (_array[index]);
}

template <typename T>
unsigned int Array<T>::size(void) {
	return (_size);
}

// Exceptions
template <typename T>
const char *Array<T>::OutOfLimits::what() const throw() {
	return ("Error: Out of limits");
}
