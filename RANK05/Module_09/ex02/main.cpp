#include "PmergeMe.hpp"
#include <iostream>
#include <deque>
#include <list>
#include <cstdlib>

std::deque<int> parseInput(int argc, char *argv[]) {
	std::deque<int> input;
	for (int i = 1; i < argc; ++i) {
		int num = std::atoi(argv[i]);
		if (num <= 0) {
			std::cerr << "Error" << std::endl;
			exit(1);
		}
		input.push_back(num);
	}
	return input;
}

int main(int argc, char *argv[]) {
	if (argc < 2) {
		std::cerr << BOLD << "Error: Not enough arguments" << RESET << std::endl;
		return 1;
	}
	std::deque<int> input = parseInput(argc, argv);

	PmergeMe dequeSort(input);
	PmergeMe listSort(std::list<int>(input.begin(), input.end()));

	dequeSort.print(BEFORE);
	dequeSort.sortDeque();
	dequeSort.print(AFTER);

	std::cout << BOLD << "Time to process a range of " \
		<< input.size() << " elements with std::list:\t" \
		<< listSort.getListSortTime() << " us"
		<< RESET << std::endl;

	std::cout << BOLD << "Time to process a range of " \
		<< input.size() << " elements with std::deque:\t" \
		<< dequeSort.getDequeSortTime() << " us" \
		<<  RESET << std::endl;

	return 0;
}
