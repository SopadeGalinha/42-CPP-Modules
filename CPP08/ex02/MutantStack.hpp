#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

// colors
# define RED "\033[1;31m"
# define GREEN "\033[1;32m"
# define YELLOW "\033[1;33m"
# define BLUE "\033[1;34m"
# define RESET "\033[0m"

// Libraries
#include <iostream>
#include <stack>
#include <deque>
#include <vector>

// Template class
template <typename T>
class MutantStack : public std::stack<T> {
public:
	// Default Constructor
	MutantStack(void);

	// Copy Constructor
	MutantStack(MutantStack const &src);

	// Destructor
	virtual ~MutantStack(void);

	// Assignation operator overload
	MutantStack &operator=(MutantStack const &obj);

	// Member functions
	typedef typename std::stack<T>::container_type::iterator iterator;
	typedef typename std::stack<T>::container_type::const_iterator const_iterator;

	iterator begin(void);
	iterator end(void);

	const_iterator begin(void) const;
	const_iterator end(void) const;
};

#include "MutantStack.tpp"

#endif
