#include "Span.hpp"

// Constructor
Span::Span(unsigned int n) : _n(n)
{
	_v.clear();
	return;
}

// Copy constructor
Span::Span(const Span &other)
{
	if (this == &other)
		return;
	this->_n = other._n;
	const std::vector<int> &otherVec = other._v;
	this->_v = std::vector<int>(otherVec.begin(), otherVec.end());
}

// Destructor
Span::~Span()
{
	_v.clear();
	return;
}

// Assignation operator
Span &Span::operator=(Span const &other)
{
	if (this == &other)
		return (*this);
	this->_n = other.getN();
	const std::vector<int> &otherV = other.getV();
	for (std::vector<int>::const_iterator it = otherV.begin(); it != otherV.end(); it++)
		this->_v.push_back(*it);
	return (*this);
}

// Add number to the vector
void Span::addNumber(int n)
{
	if (_v.size() >= _n)
		throw Span::FullSpanException();
	_v.push_back(n);
	return;
}

// Add a range of numbers to the vector
void Span::addNumber(std::vector<int>::iterator begin, std::vector<int>::iterator end)
{
	if (this->_v.size() + std::distance(begin, end) > this->_n)
		throw Span::FullSpanException();
	this->_v.insert(this->_v.end(), begin, end);
	return;
}

// Get the shortest span
int Span::shortestSpan()
{
	if (_v.size() <= 1)
		throw Span::NoSpanException();
	std::vector<int> v = _v;
	std::sort(v.begin(), v.end());
	int min = v[1] - v[0];
	for (std::vector<int>::iterator it = v.begin(); it != v.end() - 1; it++)
	{
		if (*(it + 1) - *it < min)
			min = *(it + 1) - *it;
	}
	return (min);
}

// Get the longest span
int Span::longestSpan()
{
	if (_v.size() <= 1)
		throw Span::NoSpanException();
	std::vector<int> v = _v;
	std::sort(v.begin(), v.end());
	return (v[v.size() - 1] - v[0]);
}

// Get the size of the vector
unsigned int Span::getN() const
{
	return (_n);
}

// Get the vector
const std::vector<int> &Span::getV() const
{
	return (_v);
}

// FullSpanException class
const char *Span::FullSpanException::what() const throw()
{
	return ("The span is full");
}

// NoSpanException class
const char *Span::NoSpanException::what() const throw()
{
	return ("There is no span");
}
