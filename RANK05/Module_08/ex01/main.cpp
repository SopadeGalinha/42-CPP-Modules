#include "Span.hpp"
#include <iostream>
#include <stdexcept>

void subjectTest()
{
	Span sp = Span(5);
	sp.addNumber(6);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);
	std::cout << sp.shortestSpan() << std::endl;
	std::cout << sp.longestSpan() << std::endl;
}

void testAddingNumbers()
{
	std::cout << BLUE << "Test Adding Numbers:\n"
			  << RESET;
	Span span(5);
	span.addNumber(3);
	span.addNumber(7);
	span.addNumber(2);
	span.addNumber(8);
	span.addNumber(5);
	const std::vector<int> &v = span.getV();
	std::cout << "Numbers in span:";
	for (std::vector<int>::const_iterator it = v.begin(); it != v.end(); ++it)
	{
		std::cout << " " << *it;
	}
	std::cout << std::endl;
}

void testShortestSpan()
{
	std::cout << BLUE << "\nTest Shortest Span:\n"
			  << RESET;
	Span span(5);
	span.addNumber(3);
	span.addNumber(7);
	span.addNumber(2);
	span.addNumber(8);
	span.addNumber(5);
	int shortest = span.shortestSpan();
	std::cout << "Shortest span: " << shortest << std::endl;
}

void testLongestSpan()
{
	std::cout << BLUE << "\nTest Longest Span:\n"
			  << RESET;
	Span span(5);
	span.addNumber(3);
	span.addNumber(7);
	span.addNumber(2);
	span.addNumber(8);
	span.addNumber(5);
	int longest = span.longestSpan();
	std::cout << "Longest span: " << longest << std::endl;
}

void testAddingRangeOfNumbers()
{
	std::cout << BLUE << "\nTest Adding Large Range of Numbers:\n"
			  << RESET;
	Span span(100);

	// Generate a large range of numbers
	std::vector<int> numbersToAdd(100);
	std::generate(numbersToAdd.begin(), numbersToAdd.end(), rand);

	span.addNumber(numbersToAdd.begin(), numbersToAdd.end());

	const std::vector<int> &v = span.getV();
	std::cout << "Number of elements in span: " << v.size() << std::endl;

	std::cout << "Numbers in span:";
	for (std::vector<int>::const_iterator it = v.begin(); it != v.end(); ++it)
	{
		std::cout << " " << *it;
	}
	std::cout << std::endl;
}

void testExceptions()
{
	std::cout << BLUE << "\nTest Exceptions:\n"
			  << RESET;
	Span span(5);
	try
	{
		span.shortestSpan();
	}
	catch (std::exception &e)
	{
		std::cout << RED << "Caught exception: " << e.what() << RESET << std::endl;
	}
	try
	{
		span.longestSpan();
	}
	catch (std::exception &e)
	{
		std::cout << RED << "Caught exception: " << e.what() << RESET << std::endl;
	}
}

int main(void)
{
	testAddingNumbers();
	testShortestSpan();
	testLongestSpan();
	testAddingRangeOfNumbers();
	testExceptions();
	subjectTest();
	return 0;
}
