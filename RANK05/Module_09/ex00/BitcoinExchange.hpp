#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

// Libraries
#include <map>
#include <iostream>
#include <fstream>
#include <stdexcept>
#include <string>
#include <stdlib.h>

// Namespaces
using std::cout;
using std::endl;
using std::map;
using std::string;
using std::getline;
using std::ifstream;
using std::exception;

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

#define DATABASE "./temp_database.csv"

#define ERROR(error_message) (string(BOLD) + "Error: " + RED + (error_message) + RESET).c_str()

class BitcoinExchange
{
    map<string, float> _database;
public:
    BitcoinExchange();
    ~BitcoinExchange();
    BitcoinExchange(const BitcoinExchange &other);
    BitcoinExchange &operator=(const BitcoinExchange &other);

    map<string, float> getDatabase() const;
    map<string, float> loadCSV(const string file, bool isDataCSV);

    // Exceptions
    class OpenFileException : public exception {
        const char *what() const throw() {
            return "could not open file";
        }
    };

    class InvalidValueException : public exception {
        const char *what() const throw() {
            return "invalid value in the file";
        }
    };

	class invalidCsvDataException : public exception {
		const char *what() const throw() {
			return "invalid csv data";
		}
	};
	class InvalidDateException : public exception {
		const char *what() const throw() {
			return "invalid date";
		}
	};
};

#endif
