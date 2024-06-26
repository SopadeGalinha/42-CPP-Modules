## Polimorfismo e o Uso de `virtual` em C++

O polimorfismo é um conceito fundamental da programação orientada a objetos que permite que objetos de diferentes tipos sejam tratados de forma unificada por meio de uma interface comum. Em C++, o polimorfismo é alcançado através do uso de herança e métodos virtuais.

### Métodos Virtuais (`virtual`)

Em C++, um método é considerado virtual quando é declarado com a palavra-chave `virtual` em uma classe base. Isso permite que as classes derivadas forneçam suas próprias implementações desse método, enquanto a classe base define a interface ou comportamento padrão.

O uso de métodos virtuais tem várias implicações:

- **Resolução de tempo de execução:** Quando um método é declarado como virtual em uma classe base, a implementação chamada depende do tipo real do objeto em tempo de execução. Isso significa que a implementação específica da classe derivada será invocada, mesmo que o objeto seja referenciado por um ponteiro ou referência para a classe base.

- **Flexibilidade e Extensibilidade:** Os métodos virtuais permitem que as classes derivadas personalizem ou estendam o comportamento das classes base, promovendo flexibilidade e reutilização de código.

### Exemplo

Considere a classe base `Animal` e suas classes derivadas `Cat` e `Dog`:

```cpp
class Animal {
protected:
    string _type;
public:
    // Construtores
    Animal(void);
    Animal(string animal_type);
    Animal(const Animal& other);
    virtual ~Animal(void);  // Destrutor virtual

    // Sobrecargas de operador
    Animal &operator=(const Animal& other);

    // Funções membro
    string getType(void) const;
    virtual void makeSound(void) const;  // Método virtual
};

// Cat Class
class Cat : public Animal {
public:
    // Construtores
    Cat(void);
    Cat(const Cat &other);
    virtual ~Cat(void);  // Destrutor virtual

    // Sobrecargas de operador
    Cat &operator=(const Cat &other);

    // Funções membro
    virtual void makeSound(void) const;  // Método virtual
};

// Dog Class
class Dog : public Animal {
public:
    // Construtores
    Dog(void);
    Dog(const Dog &other);
    virtual ~Dog(void);  // Destrutor virtual

    // Sobrecargas de operador
    Dog &operator=(const Dog &other);

    // Funções membro
    virtual void makeSound(void) const;  // Método virtual
};
```

Na classe base `Animal`, o método `makeSound` é declarado como `virtual`. Isso significa que quando `makeSound` é chamado em um objeto por meio de um ponteiro ou referência para `Animal`, a implementação da classe derivada (`Cat` ou `Dog`) será chamada, conforme o tipo real do objeto em tempo de execução.

As classes derivadas `Cat` e `Dog` fornecem suas próprias implementações de `makeSound`, que substituem a implementação na classe base `Animal`. Isso é um exemplo de polimorfismo em ação.

Os destrutores das classes `Animal`, `Cat`, e `Dog` também são declarados como `virtual` para garantir que o destrutor correto seja chamado ao deletar um objeto por meio de um ponteiro para a classe base. Isso evita vazamentos de memória e é uma prática recomendada em C++.

## Classes Abstratas

Uma classe abstrata em C++ é uma classe que contém pelo menos uma função virtual pura (`pure virtual function`). Uma função virtual pura é declarada com a sintaxe `= 0` após a sua declaração na classe base. As classes abstratas não podem ser instanciadas diretamente, mas servem como classes base para outras classes que devem implementar as funções virtuais puras.

### Características de Classes Abstratas:

- **Funções Virtuais Puras:** Uma função virtual pura é uma função virtual que não tem implementação na classe base, apenas uma declaração. Isso obriga as classes derivadas a fornecerem uma implementação para essa função.

- **Classe Abstrata:** Uma classe que contém pelo menos uma função virtual pura é chamada de classe abstrata. Por isso, não pode ser instanciada diretamente.

- **Forçando Implementações:** Classes derivadas de uma classe abstrata devem implementar todas as funções virtuais puras da classe base, garantindo que cada classe derivada tenha uma implementação específica.

### Exemplo:

Na classe `Animal` abaixo, a função `makeSound` é declarada como virtual pura (`virtual void makeSound() const = 0;`), tornando `Animal` uma classe abstrata:

```cpp
class Animal {
protected:
    string _type;

    // Construtor protegido para impedir instâncias diretas
    Animal() = default;
    virtual ~Animal() = default;

public:
    // Construtores públicos
    Animal(string animal_type) : _type(animal_type) {}
    Animal(const Animal &other) : _type(other._type) {}

    // Sobrecargas de operador
    Animal &operator=(const Animal &other) {
        if (this != &other) {
            _type = other._type;
        }
        return *this;
    }

    // Funções membro
    string getType() const { return _type; }

    // Função virtual pura
    virtual void makeSound() const = 0;
};
```

### Resumo:

O polimorfismo e as classes abstratas são conceitos fundamentais em C++ para criar código flexível e escalável. O polimorfismo permite que objetos de diferentes tipos sejam tratados de forma unificada por meio de uma interface comum, com a ajuda de métodos virtuais. Ele oferece flexibilidade para personalizar o comportamento de classes derivadas, permitindo resolução dinâmica de métodos em tempo de execução.

Classes abstratas definem interfaces com funções virtuais puras, forçando as classes derivadas a implementar essas funções específicas. Essa abordagem promove consistência no design e garante que as classes derivadas sigam uma estrutura definida.

Juntos, o polimorfismo e as classes abstratas possibilitam a extensão do sistema com novas funcionalidades sem modificar o código existente, tornando esses conceitos valiosos em projetos grandes e complexos para manter e evoluir o código de forma eficiente.