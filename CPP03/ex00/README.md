# ClapTrap and ScavTrap
## Introduction
This document provides documentation for the `ClapTrap` and `ScavTrap` classes, which represent robot characters in a C++ program. The `ScavTrap` class is derived from the `ClapTrap` class and introduces additional functionality specific to scavenger robots.

## ClapTrap Class (claptrap.hpp)
The `ClapTrap` class represents a basic robot character with attributes such as name, hit points, energy points, and attack damage. It provides functionality for actions like attacking, taking damage, and being repaired.

### Member Variables
- `_name`: Name of the ClapTrap.
- `_hitPoints`: Current hit points of the ClapTrap.
- `_energyPoints`: Current energy points of the ClapTrap.
- `_attackDamage`: Amount of damage caused by the ClapTrap's attack.

### Constructors
- `ClapTrap()`: Default constructor initializing default attribute values.
- `ClapTrap(string name)`: Parameterized constructor initializing with a specified name.
- `ClapTrap(const ClapTrap &other)`: Copy constructor for copying ClapTrap objects.

### Destructor
- `~ClapTrap()`: Destructor to destroy ClapTrap objects.

### Member Functions
- `attack(const string &target)`: Performs an attack action on a target.
- `takeDamage(unsigned int amount)`: Decreases hit points by a specified amount.
- `beRepaired(unsigned int amount)`: Increases hit points by a specified amount.
- Getters and setters for accessing and modifying private member variables.

## ScavTrap Class (scavtrap.hpp)
The `ScavTrap` class is derived from the `ClapTrap` class and introduces additional functionality specific to scavenger robots.

### Constructors
- `ScavTrap()`: Default constructor initializing ScavTrap attributes.
- `ScavTrap(string name)`: Parameterized constructor initializing with a specified name.
- `ScavTrap(const ScavTrap &other)`: Copy constructor for copying ScavTrap objects.

### Destructor
- `~ScavTrap()`: Destructor to destroy ScavTrap objects.

### Member Functions
- `guardGate()`: Displays a message indicating that the ScavTrap is in Gatekeeper mode.
- `attack(const string &target)`: Performs an attack action on a target, overriding the ClapTrap's attack function.

## Usage
To use these classes, include the respective header files in your C++ program. You can create instances of ClapTrap and ScavTrap objects using the available constructors and call their member functions to perform actions.

Example:
```cpp
#include "ScavTrap.hpp"

int main() {
    ScavTrap scav("Scavenger");
    scav.guardGate();
    scav.attack("Enemy");
    return 0;
}
```

## Conclusion
The `ClapTrap` and `ScavTrap` classes provide a flexible framework for implementing different types of robot characters in a C++ program. By inheriting functionality from ClapTrap and introducing additional features, such as guarding gates, ScavTrap demonstrates the power of object-oriented programming in creating diverse and modular code.
