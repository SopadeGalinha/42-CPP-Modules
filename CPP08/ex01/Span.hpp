#ifndef SPAN_HPP
# define SPAN_HPP

// colors
# define RED "\033[1;31m"
# define GREEN "\033[1;32m"
# define YELLOW "\033[1;33m"
# define BLUE "\033[1;34m"
# define RESET "\033[0m"

#include <iostream>
#include <vector>
#include <algorithm>
#include <exception>

class Span
{
	private:
		unsigned int		_n;
		std::vector<int>	_v;
	public:
		
		// Constructors
		Span(unsigned int n);
		Span(Span const &other);
		
		// Destructor
		~Span();

		// Assignation operator
		Span &operator=(Span const &other);

		// Member functions
		void	addNumber(int n);
		void	addNumber(std::vector<int>::iterator begin, std::vector<int>::iterator end);

		// ~Member functions 
		int		shortestSpan();
		int		longestSpan();

		// Getters
		unsigned int getN() const;
		const std::vector<int> &getV() const;

		// Exceptions
		class FullSpanException : public std::exception
		{
			virtual const char *what() const throw();
		};

		class NoSpanException : public std::exception
		{
			virtual const char *what() const throw();
		};
};

#endif
