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
    // Cria um objeto Data e inicializa seus membros
    Data data;
    data.str_data = "Hello, World!";
    data.int_data = 42;
    data.bool_data = true;
    data.double_data = 3.14159;

    // Serializa o ponteiro do objeto Data
    uintptr_t serializedData = Serializer::serialize(&data);

    // Imprime o valor serializado
    std::cout << "Valor serializado (endereço de memória como uintptr_t): " << serializedData << std::endl;

    // Desserializa o dado serializado de volta para um ponteiro Data
    Data* deserializedData = Serializer::deserialize(serializedData);

    // Verifica se o ponteiro desserializado aponta para o mesmo objeto
    if (deserializedData == &data) {
        std::cout << "Serialização e desserialização bem-sucedidas!" << std::endl;
        std::cout << "Valores dos dados:" << std::endl;
        std::cout << "str_data: " << deserializedData->str_data << std::endl;
        std::cout << "int_data: " << deserializedData->int_data << std::endl;
        std::cout << "bool_data: " << (deserializedData->bool_data ? "true" : "false") << std::endl;
        std::cout << "double_data: " << deserializedData->double_data << std::endl;
    } else {
        std::cout << "Falha na serialização e desserialização!" << std::endl;
    }

    return 0;
}
