#pragma once

// Libraries
# include <iostream>
# include <string>
# include <sstream>
#include "Character.hpp"
#include "Cure.hpp"
#include "Ice.hpp"
#include "ICharacter.hpp"
#include "IMateriaSource.hpp"
#include "MateriaSource.hpp"

// Classes
class Character;
class ICharacter;
class Cure;
class Ice;
class IMateriaSource;
class MateriaSource;
class AMateria;

using std::string;
using std::cout;
using std::endl;

// Color codes
#define RESET		"\033[0m"
#define RED			"\033[31m"
#define BLUE		"\033[34m"
#define GREEN		"\033[32m"
#define YELLOW		"\033[33m"

// AMateria class

// -----> Description <-----
/* A materia is a magical entity that can be used to cast spells.
It is a virtual class that will be inherited by concrete classes that
will implement the spells. The materia has a type, which is the name
of the spell, and a use function that will be implemented by the concrete
classes. The use function will receive a target as parameter, which will
be the character that will be the target of the spell. */


class IMateriaSource
{
public:
	// Constructors and destructor
	virtual ~IMateriaSource(void) {};
	// Member functions
	virtual void learnMateria(AMateria* m) = 0;
	virtual AMateria* createMateria(std::string const &type) = 0;
};

class AMateria
{
protected:
    std::string     _type;
public:
    // Constructors and destructor
    AMateria(void);
    AMateria(std::string const &type);
    AMateria(const AMateria &source);
    virtual ~AMateria(void);

    // Operator overloads
    AMateria        &operator=(const AMateria &other);

    // Member functions
    std::string const   &getType(void) const;
    virtual void        use(ICharacter &target);
    virtual AMateria    *clone(void) const = 0;
};

class ICharacter
{
public:
    // Constructors and destructor
    virtual ~ICharacter(void) {};
    // Member functions
    virtual std::string const &getName(void) const = 0;
    virtual void equip(AMateria* m) = 0;
    virtual void unequip(int idx) = 0;
    virtual void use(int idx, ICharacter& target) = 0;
};

class Character : public ICharacter
{
private:
	string		_name;
	AMateria	*_inventory[4];
public:
	// Constructors and destructor
	Character(void);
	Character(string const &name);
	Character(const Character &source);
	virtual ~Character(void);

	// Operator overloads
	Character		&operator=(const Character &other);

	// Member functions
	string const	&getName(void) const;
	void				equip(AMateria* m);
	void				unequip(int idx);
	void				use(int idx, ICharacter& target);
};


class MateriaSource : public IMateriaSource
{
private:
    AMateria    *_inventory[4];
public:
    // Constructors and destructor
    MateriaSource(void);
    MateriaSource(const MateriaSource &source);
    virtual ~MateriaSource(void);

    // Operator overloads
    MateriaSource   &operator=(const MateriaSource &other);

    // Member functions
    void            learnMateria(AMateria* m);
    AMateria        *createMateria(std::string const &type);
};

class Cure : public AMateria
{
public:
    // Constructors and destructor
    Cure();
    Cure(const Cure &source);
    virtual ~Cure();

    // Operator overloads
    Cure &operator=(const Cure &other);

    // Member functions
    AMateria *clone() const;
    void use(ICharacter& target);
};

class Ice : public AMateria
{
public:
    // Constructors and destructor
    Ice(void);
    Ice(const Ice &source);
    virtual ~Ice(void);

    // Operator overloads
    Ice &operator=(const Ice &other);

    // Member functions
    AMateria    *clone(void) const;
    void        use(ICharacter& target);
};
