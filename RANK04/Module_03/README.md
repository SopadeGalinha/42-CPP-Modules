# ClapTrap, FragTrap, and DiamondTrap Class Documentation

## Introduction
This document provides documentation for the `ClapTrap`, `FragTrap`, and `DiamondTrap` classes, representing robot characters in a C++ program. The `DiamondTrap` class inherits from both `FragTrap` and `ScavTrap`, combining attributes and functionalities from both parent classes.

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

## FragTrap Class (fragtrap.hpp)
The `FragTrap` class represents a robot character specialized in combat, inheriting from the `ClapTrap` class. It introduces additional functionality such as high-fiving.

### Constructors
- `FragTrap()`: Default constructor initializing FragTrap attributes.
- `FragTrap(string name)`: Parameterized constructor initializing with a specified name.
- `FragTrap(const FragTrap &other)`: Copy constructor for copying FragTrap objects.

### Destructor
- `~FragTrap()`: Destructor to destroy FragTrap objects.

### Member Functions
- `highFivesGuys()`: Requests a high five.

## DiamondTrap Class (diamondtrap.hpp)
The `DiamondTrap` class represents a robot combining features of both `FragTrap` and `ScavTrap`, inheriting from both classes. It introduces additional functionality such as displaying its own name and its ClapTrap name.

### Constructors
- `DiamondTrap()`: Default constructor initializing DiamondTrap attributes.
- `DiamondTrap(string name)`: Parameterized constructor initializing with a specified name.
- `DiamondTrap(const DiamondTrap &other)`: Copy constructor for copying DiamondTrap objects.

### Destructor
- `~DiamondTrap()`: Destructor to destroy DiamondTrap objects.

### Member Functions
- `whoAmI()`: Displays both its own name and its ClapTrap name.

## Usage
To use these classes, include the respective header files in your C++ program. You can create instances of ClapTrap, FragTrap, and DiamondTrap objects using the available constructors and call their member functions to perform actions.

Example:
```cpp
#include "DiamondTrap.hpp"

int main() {
    DiamondTrap diamond("Sparky");
    diamond.whoAmI();
    diamond.attack("Enemy");
    diamond.highFivesGuys();
    return 0;
}
```

## Conclusion
The `DiamondTrap` class demonstrates multiple inheritance in C++, inheriting attributes and functionalities from both `FragTrap` and `ScavTrap` classes. By combining features from its parent classes, DiamondTrap showcases the flexibility and power of object-oriented programming in creating complex and versatile robot characters.
