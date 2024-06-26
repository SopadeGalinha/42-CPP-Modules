/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhogonca <jhogonca@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 19:44:13 by jhogonca          #+#    #+#             */
/*   Updated: 2024/05/17 19:44:13 by jhogonca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

int main() {
	// Create a data structure
	Data data;
	data.str_data = "Hello, World!";
	data.int_data = 42;
	data.bool_data = true;
	data.double_data = 3.14159;

	// Serialize the data pointer to an integer representation
	uintptr_t serializedData = Serializer::serialize(&data);

	// Print the serialized data
	std::cout 
	<< "Valor serializado (endereço de memória como uintptr_t): " 
	<< serializedData << std::endl;

	// Deserialize the integer representation back to a pointer
	Data* deserializedData = Serializer::deserialize(serializedData);

	// Check if the deserialized data is the same as the original data
	if (deserializedData == &data) {
		std::cout << "Serialization and deserialization successful!" << std::endl;
		std::cout << "Values:" << std::endl;
		std::cout << "str_data: " << deserializedData->str_data << std::endl;
		std::cout << "int_data: " << deserializedData->int_data << std::endl;
		std::cout << "bool_data: " << (deserializedData->bool_data ? "true" : "false") << std::endl;
		std::cout << "double_data: " << deserializedData->double_data << std::endl;
	} else {
		std::cout << "Serialization and deserialization failed!" << std::endl;
	}

	return 0;
}
