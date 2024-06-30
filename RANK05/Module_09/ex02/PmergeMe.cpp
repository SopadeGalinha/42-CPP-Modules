#include "PmergeMe.hpp"
#include <algorithm>
#include <iostream>

PmergeMe::PmergeMe(const std::deque<int> &input) : _deque(input) {}

PmergeMe::PmergeMe(const std::list<int> &input) : _list(input) {}

PmergeMe::~PmergeMe() {}

void PmergeMe::sortDeque() {
	mergeInsertSortDeque(_deque);
}

void PmergeMe::sortList() {
	mergeInsertSortList(_list);
}

void PmergeMe::print(int type) const {
	std::string str = type == AFTER ? "After:\t" : "Before:\t";

	std::cout << BOLD << str;
	for (std::deque<int>::const_iterator it = _deque.begin(); it != _deque.end(); ++it)
		std::cout << *it << " ";
	std::cout << RESET << std::endl;
}

void PmergeMe::mergeInsertSortDeque(std::deque<int> &deq)
{
	if (deq.size() <= 1)
		return;

	// Split the deque into two halves: left and right
	std::deque<int> left(deq.begin(), deq.begin() + deq.size() / 2);
	std::deque<int> right(deq.begin() + deq.size() / 2, deq.end());

	// Recursively sort the left half
	mergeInsertSortDeque(left);

	// Recursively sort the right half
	mergeInsertSortDeque(right);

	// Merge the sorted halves back into the original deque
	std::merge(left.begin(), left.end(), right.begin(), right.end(), deq.begin());
}

void PmergeMe::mergeInsertSortList(std::list<int> &lst)
{
	if (lst.size() <= 1)
		return;

	// Split the list into two halves: left and right
	std::list<int> left, right;
	std::list<int>::iterator it = lst.begin();
	std::advance(it, lst.size() / 2);

	// Splice the first half of the list
	left.splice(left.begin(), lst, lst.begin(), it);

	// Splice the second half of the list
	right.splice(right.begin(), lst, it, lst.end());

	// Recursively sort the halves
	mergeInsertSortList(left);
	mergeInsertSortList(right);

	// Merge the sorted halves back into the original list
	lst.merge(left);
	lst.merge(right);
}

double PmergeMe::getDequeSortTime()
{
	struct timeval start, end;
	gettimeofday(&start, NULL);
	std::deque<int> deq = _deque;
	mergeInsertSortDeque(deq);
	gettimeofday(&end, NULL);
	return (end.tv_sec - start.tv_sec) * ONE_SECOND + (end.tv_usec - start.tv_usec);
}

double PmergeMe::getListSortTime()
{
	struct timeval start, end;
	gettimeofday(&start, NULL);
	std::list<int> lst = _list;
	mergeInsertSortList(lst);
	gettimeofday(&end, NULL);
	return (end.tv_sec - start.tv_sec) * ONE_SECOND + (end.tv_usec - start.tv_usec);
}
