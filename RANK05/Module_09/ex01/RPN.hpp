#ifndef RPN_HPP
#define RPN_HPP

#include <stack>
#include <sstream>
#include <iostream>
#include <cstdlib>
#include <stdexcept>
#include <vector>

// Colors
#define BOLD "\033[1m"
#define RED "\033[31m"
#define BLUE "\033[34m"
#define GREEN "\033[32m"
#define YELLOW "\033[33m"
#define RESET "\033[0m"

class RPN {
    std::vector<std::string> _tokens;
    
    // Private methods
    static std::vector<std::string> _split(const std::string &str, char delimiter);
    static bool _isOperator(const std::string &s);

public:

    RPN(const std::string &input);
    RPN &operator=(const RPN &rpn);
    ~RPN() {}
    RPN(const RPN &rpn) : _tokens(rpn._tokens) {}
    
    // Public methods
    int evaluate() const;
};

#endif // RPN_HPP
