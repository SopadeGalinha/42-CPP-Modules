/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhogonca <jhogonca@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 08:49:25 by jhogonca          #+#    #+#             */
/*   Updated: 2024/02/24 08:49:25 by jhogonca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Animal.hpp"

using namespace std;

// Funções auxiliares para organização dos testes

// Função para imprimir um cabeçalho
void printHeader(const string &str)
{
    cout << YELLOW << "\n"
         << str << "\n"
         << RESET;
}

// Função para imprimir os detalhes de um Animal
void printAnimalDetails(const Animal *animal)
{
    std::string type = animal->getType();
    if (type.empty())
        type = "...";
    cout << "Type: " << type << endl;
}

void printWrongAnimalDetails(const WrongAnimal *animal) {
    std::string type = animal->getType();
    if (type.empty())
        type = "...";
    cout << "Type: " << type << endl;
}

// Função para testar makeSound() de um animal
void testMakeSound(const Animal *animal)
{
    animal->makeSound();
}

void testMakeWrongSound(const WrongAnimal *animal) {
    animal->makeSound();
}

void subjectTest()
{
    printHeader("\tSubject test\n");
    const Animal *meta = new Animal();
    const Animal *j = new Dog();
    const Animal *i = new Cat();
    std::cout << j->getType() << " " << std::endl;
    std::cout << i->getType() << " " << std::endl;
    i->makeSound();    // will output the cat sound!
    j->makeSound();    // will output the dog sound!
    meta->makeSound(); // will output the default sound!

    delete meta;
    delete j;
    delete i;
}

void test()
{
    printHeader("\tMy own test");
    printHeader("Criando objetos");

    // Criando objetos de diferentes classes
    const Animal *meta = new Animal();     // Objeto base
    const Animal *dog = new Dog();         // Objeto derivado Dog
    const Animal *cat = new Cat();         // Objeto derivado Cat
    const WrongCat *wrongCat = new WrongCat(); // Objeto derivado WrongCat
    const Animal *cow = new Animal("Cow"); // Objeto base com tipo específico

    // Testando os tipos dos objetos
    printHeader("Testing object types");

    cout << "Dog : ";
    printAnimalDetails(dog);
    
    cout << "Cat : ";
    printAnimalDetails(cat);
    
    cout << "Cow : ";
    printAnimalDetails(cow);
    
    cout << "WCat: ";
    printWrongAnimalDetails(wrongCat);
    
    cout << "Meta: ";
    printAnimalDetails(meta);

    // Testando comportamento polimórfico de makeSound()
    printHeader("Testing polymorphic behavior");
    cout << "Som de Cat : ";
    testMakeSound(cat); // Deve imprimir o som do gato
    cout << "Som de Dog : ";
    testMakeSound(dog); // Deve imprimir o som do cachorro
    cout << "Som de Cow : ";
    testMakeSound(cow); // Pode imprimir o som padrão de `Animal`
    cout << "Som de WCat: ";
    testMakeWrongSound(wrongCat); // Deve imprimir o som do gato errado
    cout << "Som de Meta: ";
    testMakeSound(meta); // Deve imprimir o som padrão de `Animal`

    // Libera a memória
    printHeader("Liberando memória");
    delete meta;
    delete dog;
    delete cat;
    delete cow;
    delete wrongCat;
}

int main(void)
{
    subjectTest();
    test();
    return 0;
}