/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhogonca <jhogonca@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 19:33:43 by jhogonca          #+#    #+#             */
/*   Updated: 2024/05/17 19:33:43 by jhogonca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

// Constructors and Destructor
Serializer::Serializer(void) {
	return ;
}

Serializer::~Serializer(void) {
	return ;
}

Serializer::Serializer(const Serializer &src) {
	*this = src;
	return ;
}

// Assignment Operator
Serializer &Serializer::operator=(const Serializer &src) {
	if (this != &src)
		*this = src;
	return (*this);
}

// Methods

/*
*  Convert the pointer to an integer representation. 
* This process is known as serialization. 
* Serialization is the process of converting complex data structures 
* or object state into a format that can be
* stored or transmitted and reconstructed later.*/
uintptr_t Serializer::serialize(Data* ptr) {
	return (reinterpret_cast<uintptr_t>(ptr));
}

/*
*  Convert the integer representation back to a pointer.
* This process is known as deserialization.
* Deserialization is the process of reconstructing the object state
* from the serialized form. */
Data *Serializer::deserialize(uintptr_t raw) {
	return (reinterpret_cast<Data *>(raw));
}
