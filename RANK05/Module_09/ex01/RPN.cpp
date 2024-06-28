#include "RPN.hpp"

// Constructor
RPN::RPN(const std::string &input) : _tokens(_split(input, ' ')) {} 

// Assignment operator
RPN &RPN::operator=(const RPN &rpn) {
	if (this != &rpn)
		_tokens = rpn._tokens;
	return *this;
}

// Private methods
std::vector<std::string> RPN::_split(const std::string &str, char delimiter) {
	std::vector<std::string> tokens;
	std::stringstream ss(str);
	std::string tok;

	while (getline(ss, tok, delimiter))
		tokens.push_back(tok);
	return tokens;
}

bool RPN::_isOperator(const std::string &s) {
	return (s == "+" || s == "-" || s == "/" || s == "*");
}

int RPN::evaluate() const {
	std::stack<int> stack;

	for (std::vector<std::string>::const_iterator it = _tokens.begin(); it != _tokens.end(); ++it)
	{
		const std::string &token = *it;
		if (_isOperator(token))
		{
			if (stack.size() < 2)
				throw std::runtime_error("Error: Insufficient values in expression");

			int right = stack.top();
			stack.pop();
			
			int left = stack.top();
			stack.pop();

			if (token == "+")
				stack.push(left + right);
			
			else if (token == "-")
				stack.push(left - right);
			
			else if (token == "*")
				stack.push(left * right);
			
			else if (token == "/") {
				if (right == 0)
					throw std::runtime_error("Error: Division by zero");
				stack.push(left / right);
			}
		}
		else
			stack.push(std::atoi(token.c_str()));
	}
	if (stack.size() != 1)
		throw std::runtime_error("Error: Malformed expression");
	return stack.top();
}
