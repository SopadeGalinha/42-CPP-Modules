// main.cpp
#include "RPN.hpp"
#include <iostream>

int main(int ac, char **av)
{
    if (ac < 2) {
        std::cout << "Usage: " << av[0] << " <inverted polish Math expression>" << std::endl;
        return 1;
    }
    try {
        RPN rpn(av[1]);
        int result = rpn.evaluate();
        std::cout << "Result: " << result << std::endl;
    } catch (const std::exception &e) {
        std::cerr << "Error: " << e.what() << std::endl;
        return 1;
    }
    return 0;
}
