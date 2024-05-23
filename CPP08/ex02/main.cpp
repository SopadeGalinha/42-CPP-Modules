/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhogonca <jhogonca@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 16:46:31 by jhogonca          #+#    #+#             */
/*   Updated: 2024/05/21 16:46:31 by jhogonca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"

void subjectTest(void)
{
	std::cout << YELLOW << "\nSubject test container: MutantStack" << RESET << std::endl;
	MutantStack<int> mstack;
	mstack.push(5);
	mstack.push(17);
	std::cout << mstack.top() << std::endl;
	mstack.pop();
	std::cout << mstack.size() << std::endl;
	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	mstack.push(0);
	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();
	++it;
	--it;
	while (it != ite)
	{
		std::cout << *it << std::endl;
		++it;
	}
	std::stack<int> s(mstack);
}

#include <iostream>
#include <list>

void subjectTest2(void)
{
	std::cout << YELLOW << "\nSubject test container: list" << RESET << std::endl;
	std::list<int> mylist;
	mylist.push_back(5);
	mylist.push_back(17);
	std::cout << mylist.back() << std::endl;
	mylist.pop_back();
	std::cout << mylist.size() << std::endl;
	mylist.push_back(3);
	mylist.push_back(5);
	mylist.push_back(737);
	mylist.push_back(0);

	std::list<int>::iterator it = mylist.begin();
	std::list<int>::iterator ite = mylist.end();
	++it;
	--it;
	while (it != ite)
	{
		std::cout << *it << std::endl;
		++it;
	}
	std::list<int> s(mylist);
}

void subjectTest3(void)
{
	std::cout << YELLOW << "\nSubject test container: vector" << RESET << std::endl;
    std::vector<int> myvector;
    myvector.push_back(5);
    myvector.push_back(17);
    std::cout << myvector.back() << std::endl;
    myvector.pop_back();
    std::cout << myvector.size() << std::endl;
    myvector.push_back(3);
    myvector.push_back(5);
    myvector.push_back(737);
    myvector.push_back(0);

    std::vector<int>::iterator it = myvector.begin();
    std::vector<int>::iterator ite = myvector.end();
    ++it;
    --it;
    while (it != ite)
    {
        std::cout << *it << std::endl;
        ++it;
    }
    std::vector<int> s(myvector);
}

void test1()
{
	std::cout << BLUE << "\nTest 1: Iterator" << RESET << std::endl;
    MutantStack<int> mstack;
    mstack.push(1);
    mstack.push(2);
    mstack.push(3);

    for (MutantStack<int>::iterator it = mstack.begin(); it != mstack.end(); ++it) {
        std::cout << *it << std::endl;
    }
}

void test2()
{
    std::cout << BLUE << "\nTest 2: Const Iterator" << RESET << std::endl;
    MutantStack<int> mstack;
    mstack.push(4);
    mstack.push(5);
    mstack.push(6);

    const MutantStack<int> &const_mstack = mstack;
    for (MutantStack<int>::const_iterator it = const_mstack.begin(); it != const_mstack.end(); ++it) {
        std::cout << *it << std::endl;
    }
}

void test3()
{
    std::cout << BLUE << "\nTest 3: Copy Constructor and Assignment Operator" << RESET << std::endl;
    MutantStack<int> mstack;
    mstack.push(7);
    mstack.push(8);
    mstack.push(9);

    MutantStack<int> copy_mstack(mstack);
    for (MutantStack<int>::iterator it = copy_mstack.begin(); it != copy_mstack.end(); ++it) {
        std::cout << *it << std::endl;
    }

    MutantStack<int> assigned_mstack;
    assigned_mstack = mstack;
    for (MutantStack<int>::iterator it = assigned_mstack.begin(); it != assigned_mstack.end(); ++it) {
        std::cout << *it << std::endl;
    }
}

void test4()
{
    std::cout << BLUE "\nTest 4: Modifying Elements through Iterators" << RESET << std::endl;
    MutantStack<int> mstack;
    mstack.push(10);
    mstack.push(20);
    mstack.push(30);

    for (MutantStack<int>::iterator it = mstack.begin(); it != mstack.end(); ++it) {
        *it += 10;
    }

    for (MutantStack<int>::iterator it = mstack.begin(); it != mstack.end(); ++it) {
        std::cout << *it << std::endl;
    }
}

void test5()
{
    std::cout << BLUE << "\nTest 5: Empty Stack and Size" << RESET << std::endl;
    MutantStack<int> mstack;
    std::cout << "Initial size: " << mstack.size() << std::endl;

    mstack.push(40);
    mstack.push(50);
    std::cout << "Size after pushing elements: " << mstack.size() << std::endl;

    mstack.pop();
    std::cout << "Size after popping an element: " << mstack.size() << std::endl;

    while (!mstack.empty()) {
        mstack.pop();
    }
    std::cout << "Size after emptying the stack: " << mstack.size() << std::endl;
}


int main()
{
	subjectTest();
	subjectTest2();
	subjectTest3();
	test1();
	test2();
	test3();
	test4();
	test5();
	return 0;
}
