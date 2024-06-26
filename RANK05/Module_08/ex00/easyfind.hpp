#ifndef EASYFIND_HPP
# define EASYFIND_HPP

# include <algorithm>
# include <iostream>
# include <exception>

// Colors
#define RED "\033[1;31m"
#define GREEN "\033[1;32m"
#define YELLOW "\033[1;33m"
#define BLUE "\033[1;34m"
#define RESET "\033[0m"

/**
 * @brief Finds the first occurrence of a value in a container.
 * 
 * This function searches for the first occurrence of the specified value in the given container.
 * It returns an iterator pointing to the found element if it exists, otherwise it throws an exception.
 * 
 * @tparam T The type of the container.
 * @param container The container to search in.
 * @param value The value to search for.
 * @return An iterator pointing to the found element.
 * @throws std::exception if the value is not found in the container.
 */

// Handle sequential containers
template <typename T>
typename T::iterator easyfind(T &container, int value)
{
	typename T::iterator it = std::find(container.begin(), container.end(), value);
	if (it == container.end())
		throw std::exception();
	return it;
}


/* // Handle associative containers
template <typename T>
typename T::iterator easyfind(T &container, int value)
{
	typename T::iterator it = container.find(value);
	if (it == container.end())
		throw std::exception();
	return it;
}
 */
#endif
