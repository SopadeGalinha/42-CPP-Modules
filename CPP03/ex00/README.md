# ClapTrap Class Documentation

## Introduction
The `ClapTrap` class represents a basic robot character capable of performing various actions such as attacking, taking damage, and being repaired. This class serves as a blueprint for creating different instances of ClapTrap robots with customizable attributes.

## Header File: ClapTrap.hpp
This header file contains the declaration of the `ClapTrap` class along with its member variables, constructors, destructor, member functions, getters, and setters.

### Included Libraries
- `<string>`: Standard C++ library for string manipulation.
- `<iostream>`: Standard C++ library for input/output operations.

### Directives
- Defined color codes for console output formatting.

### Class Definition
The `ClapTrap` class contains private member variables `_name`, `_hitPoints`, `_energyPoints`, and `_attackDamage`. It also includes public member functions for actions like attack, taking damage, and being repaired, as well as getters and setters for accessing and modifying the private member variables.

## Source File: ClapTrap.cpp
This source file contains the implementation of the member functions declared in the `ClapTrap.hpp` header file.

### Constructors
- Default Constructor: Initializes a ClapTrap object with default attribute values.
- Parameterized Constructor: Initializes a ClapTrap object with a specified name.
- Copy Constructor: Creates a new ClapTrap object by copying the attributes of another ClapTrap object.
### Destructor
- Destroys a ClapTrap object and displays a message indicating its destruction.

### Operator Overload
- Overloads the assignment operator to allow copying of ClapTrap objects.

### Member Functions
- `attack(const string &target)`: Performs an attack action on a target.
- `takeDamage(unsigned int amount)`: Decreases hit points by a specified amount to simulate damage.
- `beRepaired(unsigned int amount)`: Increases hit points by a specified amount to simulate repair.

### Getters and Setters
- Getter and setter functions for accessing and modifying private member variables `_name`, `_hitPoints`, `_energyPoints`, and `_attackDamage`.

## Usage
To use the `ClapTrap` class, include the `"ClapTrap.hpp"` header file in your C++ program and create instances of the class using the available constructors. You can then call the member functions to perform actions on the ClapTrap objects.

Example:
```cpp
#include "ClapTrap.hpp"

int main() {
    ClapTrap claptrap("Bob");
    claptrap.attack("Enemy");
    claptrap.takeDamage(5);
    claptrap.beRepaired(3);
    return 0;
}
```

## Conclusion
The `ClapTrap` class provides a basic framework for implementing robot characters in a C++ program. It encapsulates attributes and behaviors related to attacking, taking damage, and being repaired, allowing for easy management and manipulation of ClapTrap objects.
