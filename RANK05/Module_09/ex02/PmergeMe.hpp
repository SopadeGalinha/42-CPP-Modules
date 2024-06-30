#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <deque>
#include <list>
#include <string>
#include <iostream>
#include <sstream>
#include <sys/time.h>

// Colors
#define BOLD "\033[1m"
#define RED "\033[31m"
#define GREEN "\033[32m"
#define YELLOW "\033[33m"
#define BLUE "\033[34m"
#define RESET "\033[0m"

// Macros
#define AFTER 0
#define BEFORE 1
#define ONE_SECOND 1e6

class PmergeMe {
public:
    PmergeMe(const std::deque<int> &input);
    PmergeMe(const std::list<int> &input);
    ~PmergeMe();
    PmergeMe(const PmergeMe &other);
    PmergeMe &operator=(const PmergeMe &other);

    void sortDeque();
    void sortList();

    void print(int type) const;

    double getDequeSortTime();
    double getListSortTime();

private:
    std::deque<int> _deque;
    std::list<int> _list;

    void mergeInsertSortDeque(std::deque<int> &deq);
    void mergeInsertSortList(std::list<int> &lst);
};

#endif
