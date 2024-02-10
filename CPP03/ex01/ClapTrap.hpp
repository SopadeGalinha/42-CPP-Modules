/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhogonca <github.com/SopadeGalinha>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 16:05:58 by jhogonca          #+#    #+#             */
/*   Updated: 2024/02/09 19:20:46 by jhogonca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

// Headers
#include <string>
#include <iostream>

// directives
using std::cout;
using std::endl;
using std::string;

// Color Codes
#define RED     "\033[31m"
#define BLUE    "\033[34m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define RESET   "\033[0m"

// Class
class ClapTrap {
    protected:
        string          _name;
        unsigned int    _hitPoints;
        unsigned int    _energyPoints;
        unsigned int    _attackDamage;

    public:
        // Constructor
        ClapTrap();
        ClapTrap(string name);
        ClapTrap(const ClapTrap &other);
        
        // Operator Overload
        ClapTrap &operator=(const ClapTrap &other);

        // Destructor
        ~ClapTrap();
        
        // Member Functions
        void attack(const string &target);
        void takeDamage(unsigned int amount);
        void beRepaired(unsigned int amount);

        // Getters
        string          getName() const;
        unsigned int    getHitPoints() const;
        unsigned int    getEnergyPoints() const;
        unsigned int    getAttackDamage() const;
        
        // Setters
        void setName(string name);
        void setHitPoints(unsigned int hitPoints);
        void setEnergyPoints(unsigned int energyPoints);
        void setAttackDamage(unsigned int attackDamage);
};

#endif
