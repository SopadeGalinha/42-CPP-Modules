# Classes in C++

In C++, a class is a fundamental concept in object-oriented programming, serving as a blueprint for creating objects. It encapsulates data (attributes) and behaviors (methods) into a single unit, promoting code organization and reusability.

## Key Concepts:

### Object-Oriented Programming (P.O.O.):

Object-Oriented Programming (P.O.O.) is a paradigm that revolves around the concept of "objects," which are instances of classes. It introduces several key principles:

1. **Classes and Objects:**
   - **Class:** A class is a blueprint or template for creating objects. It defines a data structure along with methods (functions) that operate on the data.
   - **Object:** An object is an instance of a class. It represents a real-world entity and encapsulates data and behavior.

2. **Encapsulation:**
   - Encapsulation is the bundling of data (attributes) and the methods that operate on the data into a single unit (class). It hides the internal details of an object and exposes only what is necessary.

3. **Inheritance:**
   - Inheritance is a mechanism that allows a class (subclass/derived class) to inherit properties and behaviors from another class (superclass/base class). It promotes code reuse and establishes a hierarchy of classes.

4. **Polymorphism:**
   - Polymorphism allows objects to be treated as instances of their base class rather than their actual derived class. It enables flexibility in handling different types of objects through a common interface.

5. **Abstraction:**
   - Abstraction involves simplifying complex systems by modeling classes based on their essential characteristics. It focuses on what an object does rather than how it achieves its functionality.

6. **Modularity:**
   - Modularity is achieved through the organization of code into classes and objects. Each class represents a modular unit with specific responsibilities and can be reused in different parts of a program.

7. **Message Passing:**
   - Objects communicate with each other by sending messages. This involves invoking methods on objects, and the objects respond by executing the appropriate code.

### Attributes:

Attributes, also known as data members, store data related to the class. They can be categorized as:

- **Private:** Accessible only within the class.

  ```cpp
  class Zombie {
  private:
      std::string _name;
  };
  ```

### Methods (Member Functions):

Member functions are associated with the class and operate on its data. They include constructors for object initialization and destructors for resource cleanup:

```cpp
class Zombie {
public:
    // Constructors and destructors
    Zombie(std::string name);
    ~Zombie(void);

    // Setters
    void setName(std::string name);

    // Getters
    std::string getName(void);

    // Member functions
    void announce(void);
};
```

### Objects:

Objects are specific instances of a class, containing data (attributes) and executing operations (methods). They are created using the class blueprint:

```cpp
Zombie myZombie("Alice"); // Creating a Zombie object
myZombie.setName("Bob");  // Accessing methods
std::string zombieName = myZombie.getName(); // Accessing attributes
```

### Constructors and Destructors:

Constructors initialize objects during creation, and destructors clean up resources when an object is destroyed:

```cpp
Zombie::Zombie(std::string name) {
    setName(name);
    std::cout << "Zombie " << getName() << " created." << std::endl;
}

Zombie::~Zombie(void) {
    std::cout << "Zombie " << getName() << " destroyed." << std::endl;
}
```

### Setters and Getters:

```cpp
int Fixed::getRawBits(void) const {
    std::cout << "getRawBits member function called" << std::endl;
    return (_rawBits);
}

void Fixed::setRawBits(int const raw) {
    std::cout << "setRawBits member function called" << std::endl;
    _rawBits = raw;
    return ;
}
