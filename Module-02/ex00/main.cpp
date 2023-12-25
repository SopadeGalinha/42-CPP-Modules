/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhogonca <jhogonca@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/23 12:46:45 by jhogonca          #+#    #+#             */
/*   Updated: 2023/12/23 12:46:45 by jhogonca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

int main(void) {
    // declare a variable of type Fixed
    Fixed a;

    // declare a copy of Fixed a
    Fixed b(a);

    // declare another variable of type Fixed
    Fixed c;

    // assign b to c
    c = b;

    // print the raw bits of a, b, and c
    std::cout << a.getRawBits() << std::endl;
    std::cout << b.getRawBits() << std::endl;
    std::cout << c.getRawBits() << std::endl;

    return (0);
}
