#include "easyfind.hpp"
#include <vector>
#include <list>
#include <deque>
#include <map>
#include <set>

/* void testMap()
{
	std::cout << YELLOW "\nTesting Map" RESET << std::endl;

	std::map<int, std::string> myMap;
	myMap[1] = "one";
	myMap[2] = "two";
	myMap[3] = "three";

	try
	{
		std::cout << BLUE << "Testing a value that exists" RESET << std::endl;
		std::cout << GREEN << "Map: " << easyfind(myMap, 2)->second << RESET << std::endl;
		std::cout << BLUE << "Testing a value that doesn't exist" RESET << std::endl;
		std::cout << GREEN << "Map: " << easyfind(myMap, 4)->second << RESET << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cout << RED << "Value not found in map" << RESET << std::endl;
	}
}

void testSet()
{
	std::cout << YELLOW "\nTesting Set" RESET << std::endl;

	std::set<int> mySet;
	mySet.insert(1);
	mySet.insert(2);
	mySet.insert(3);

	try
	{
		std::cout << BLUE << "Testing a value that exists" RESET << std::endl;
		std::cout << GREEN << "Set: " << *easyfind(mySet, 2) << RESET << std::endl;
		std::cout << BLUE << "Testing a value that doesn't exist" RESET << std::endl;
		std::cout << GREEN << "Set: " << *easyfind(mySet, 4) << RESET << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cout << RED << "Value not found in set" << RESET << std::endl;
	}
}

void testMultiMap()
{
	std::cout << YELLOW "\nTesting MultiMap" RESET << std::endl;
	std::multimap<int, std::string> myMultiMap;
	myMultiMap.insert(std::pair<int, std::string>(1, "one"));
	myMultiMap.insert(std::pair<int, std::string>(2, "two"));
	myMultiMap.insert(std::pair<int, std::string>(2, "two"));
	myMultiMap.insert(std::pair<int, std::string>(3, "three"));

	try
	{
		std::cout << BLUE << "Testing a value that exists" RESET << std::endl;
		std::cout << GREEN << "Multimap: " << easyfind(myMultiMap, 2)->second << RESET << std::endl;
		std::cout << BLUE << "Testing a value that doesn't exist" RESET << std::endl;
		std::cout << GREEN << "Multimap: " << easyfind(myMultiMap, 4)->second << RESET << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cout << RED << "Value not found in multimap" << RESET << std::endl;
	}
}

void testMultiSet()
{
	std::cout << YELLOW "\nTesting MultiSet" RESET << std::endl;
	std::multiset<int> myMultiSet;
	myMultiSet.insert(1);
	myMultiSet.insert(2);
	myMultiSet.insert(2);
	myMultiSet.insert(3);

	try
	{
		std::cout << BLUE << "Testing a value that exists" RESET << std::endl;
		std::cout << GREEN << "Multiset: " << *easyfind(myMultiSet, 2) << RESET << std::endl;
		std::cout << BLUE << "Testing a value that doesn't exist" RESET << std::endl;
		std::cout << GREEN << "Multiset: " << *easyfind(myMultiSet, 4) << RESET << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cout << RED << "Value not found in multiset" << RESET << std::endl;
	}
}

// "Associative containers" typically refer to containers that allow
// for efficient retrieval of elements based on keys. 
// These include containers like map, set, multimap, and multiset.
void testAssociativeContainers()
{
	testMap();
	testSet();
	testMultiMap();
	testMultiSet();
}
*/
void testList()
{
	std::cout << YELLOW "\nTesting List" RESET << std::endl;

	std::list<int> myList;
	for (int i = 0; i < 10; i++)
		myList.push_back(i);

	try
	{
		std::cout << BLUE << "Testing a value that exists" RESET << std::endl;
		std::cout << GREEN << "List: " << *easyfind(myList, 5) << RESET << std::endl;
		std::cout << BLUE << "Testing a value that doesn't exist" RESET << std::endl;
		std::cout << GREEN << "List: " << *easyfind(myList, 11) << RESET << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cout << RED << "Value not found in list" << RESET << std::endl;
	}
}

void testVector()
{
	std::cout << YELLOW "\nTesting Vector" RESET << std::endl;

	std::vector<int> myVector;
	for (int i = 0; i < 10; i++)
		myVector.push_back(i);

	try
	{
		std::cout << BLUE << "Testing a value that exists" RESET << std::endl;
		std::cout << GREEN << "Vector: " << *easyfind(myVector, 5) << RESET << std::endl;
		std::cout << BLUE << "Testing a value that doesn't exist" RESET << std::endl;
		std::cout << GREEN << "Vector: " << *easyfind(myVector, 11) << RESET << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cout << RED << "Value not found in vector" << RESET << std::endl;
	}
}

void testDeque()
{
	std::cout << YELLOW "\nTesting Deque" RESET << std::endl;

	std::deque<int> myDeque;
	for (int i = 0; i < 10; i++)
		myDeque.push_back(i);

	try
	{
		std::cout << BLUE << "Testing a value that exists" RESET << std::endl;
		std::cout << GREEN << "Deque: " << *easyfind(myDeque, 5) << RESET << std::endl;
		std::cout << BLUE << "Testing a value that doesn't exist" RESET << std::endl;
		std::cout << GREEN << "Deque: " << *easyfind(myDeque, 11) << RESET << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cout << RED << "Value not found in deque" << RESET << std::endl;
	}
}

void testSequenceContainers()
{
	testList();
	testVector();
	testDeque();
}

int main(void)
{
	// testAssociativeContainers();
	testSequenceContainers();
	return 0;
}
