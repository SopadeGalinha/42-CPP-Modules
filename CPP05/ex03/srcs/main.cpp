/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhogonca <jhogonca@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 20:38:57 by jhogonca          #+#    #+#             */
/*   Updated: 2024/05/02 20:38:57 by jhogonca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "../includes/Intern.hpp"
#include "../includes/RobotomyRequestForm.hpp"
#include "../includes/PresidentialPardonForm.hpp"
#include "../includes/ShrubberyCreationForm.hpp"

// Teste 1: Cria um RobotomyRequestForm com alvo específico.
void test1() {
    std::cout << YELLOW << "\nTest 1: Creating RobotomyRequestForm targeting 'Bender'\n" << RESET;

    Intern intern;
    try {
        AForm* form = intern.makeForm("robotomy request", "Bender");
        std::cout << GREEN << "Intern creates RobotomyRequestForm targeted on 'Bender'\n" << RESET;
        delete form; // Libera a memória alocada para o formulário
    } catch (const std::exception &e) {
        std::cout << RED << "Unexpected exception: " << e.what() << "\n" << RESET;
    }
}

// Teste 2: Cria um PresidentialPardonForm com alvo específico.
void test2() {
    std::cout << YELLOW << "\nTest 2: Creating PresidentialPardonForm targeting 'Arthur'\n" << RESET;

    Intern intern;
    try {
        AForm* form = intern.makeForm("presidential pardon", "Arthur");
        std::cout << GREEN << "Intern creates PresidentialPardonForm targeted on 'Arthur'\n" << RESET;
        delete form; // Libera a memória alocada para o formulário
    } catch (const std::exception &e) {
        std::cout << RED << "Unexpected exception: " << e.what() << "\n" << RESET;
    }
}

// Teste 3: Cria um ShrubberyCreationForm com alvo específico.
void test3() {
    std::cout << YELLOW << "\nTest 3: Creating ShrubberyCreationForm targeting 'Garden'\n" << RESET;

    Intern intern;
    try {
        AForm* form = intern.makeForm("shrubbery creation", "Garden");
        std::cout << GREEN << "Intern creates ShrubberyCreationForm targeted on 'Garden'\n" << RESET;
        delete form; // Libera a memória alocada para o formulário
    } catch (const std::exception &e) {
        std::cout << RED << "Unexpected exception: " << e.what() << "\n" << RESET;
    }
}

// Teste 4: Tenta criar um formulário com nome desconhecido, deve lançar uma exceção.
void test4() {
    std::cout << YELLOW << "\nTest 4: Trying to create unknown form type 'unknown form'\n" << RESET;

    Intern intern;
    try {
        AForm* form = intern.makeForm("unknown form", "Unknown");
        std::cout << RED << "Unexpected success: created form with unknown type\n" << RESET;
        delete form; // Libera a memória alocada para o formulário
    } catch (const Intern::FormNotFoundException &e) {
        std::cout << BLUE << "Caught exception: " << e.what() << "\n" << RESET;
    }
}

// Teste 5: Cria um formulário usando um alvo vazio para testar o comportamento.
void test5() {
    std::cout << YELLOW << "\nTest 5: Creating ShrubberyCreationForm with empty target\n" << RESET;

    Intern intern;
    try {
        AForm* form = intern.makeForm("shrubbery creation", "");
        std::cout << GREEN << "Intern creates ShrubberyCreationForm with empty target\n" << RESET;
        delete form; // Libera a memória alocada para o formulário
    } catch (const std::exception &e) {
        std::cout << RED << "Unexpected exception: " << e.what() << "\n" << RESET;
    }
}

int main() {
    test1();
    test2();
    test3();
    test4();
    test5();
    return 0;
}
