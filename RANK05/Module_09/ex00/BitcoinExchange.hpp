#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

// Libraries
#include <map>
#include <iostream>
#include <sstream>
#include <fstream>
#include <stdexcept>
#include <string>
#include <stdlib.h>

using std::map;
using std::string;

// Colors
#define BOLD "\033[1m"
#define RED "\033[31m"
#define BLUE "\033[34m"
#define GREEN "\033[32m"
#define YELLOW "\033[33m"
#define RESET "\033[0m"

// Macros
#define MIN_VALUE 0
#define MAX_VALUE 1000

#define DATABASE "./data.csv"
#define ERROR(error_message) \
	(string(BOLD) + "Error: " \
	+ RED + (error_message) + RESET).c_str()

class BitcoinExchange
{
	map<string, float> _database;
public:
	BitcoinExchange();
	~BitcoinExchange();
	BitcoinExchange(const BitcoinExchange &other);
	BitcoinExchange &operator=(const BitcoinExchange &other);

	map<string, float> getDatabase() const;
	map<string, float> loadCSV(const string file);

	void	handleLine(const string &line);
	void	processInput(const string &file);
};

#endif
