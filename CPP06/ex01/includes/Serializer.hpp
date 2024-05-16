/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhogonca <jhogonca@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 23:44:52 by jhogonca          #+#    #+#             */
/*   Updated: 2024/05/16 23:44:52 by jhogonca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERIALIZER_HPP
# define SERIALIZER_HPP

// Libraries
#include <iostream>
#include <string>
#include <stdint.h>
#include "Data.hpp"
// Class
class Serializer
{
	// Constructors and Destructor
	Serializer();
	~Serializer();
	Serializer(const Serializer &src);

	// Assignment Operator
	Serializer &operator=(const Serializer &src);

public:
	
	// Methods
	static uintptr_t serialize(Data* ptr);
	static Data *deserialize(uintptr_t raw);
};

#endif
