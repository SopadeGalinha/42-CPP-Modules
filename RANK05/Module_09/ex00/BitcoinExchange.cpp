#include "BitcoinExchange.hpp"

// ----------> Orthodox Canonical Form/Rule of Three <----------

// Constructor
BitcoinExchange::BitcoinExchange() :_database(loadCSV(DATABASE)) {}

// Copy Constructor
BitcoinExchange::BitcoinExchange(const BitcoinExchange &other)
	: _database(other.getDatabase()) {}

// Destructor
BitcoinExchange::~BitcoinExchange() {}

// Assignment Operator
BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &other) {
	if (this != &other)
		_database = other.getDatabase();
	return *this;
}

// ---------------------> Public Methods <---------------------


static bool	parseDate(string &key);

// Getter
map<string, float> BitcoinExchange::getDatabase() const {
	return _database;
}

// Load the database from a CSV file
map<string, float> BitcoinExchange::loadCSV(const string file) {
	string line;
	map<string, float> database;

	std::ifstream in(file.c_str());
	std::getline(in, line); // Skip the first line
	if ((line.compare("date,exchange_rate") != 0))
	{
		in.close();
		std::cerr << ERROR("Data.csv is not formatted correctly") << std::endl;
		exit(1);
	}
	while (std::getline(in, line))
	{
		string key = line.substr(0, line.find(','));
		string value = line.substr(line.find(',') + 1).c_str();
		database[key] = atof(value.c_str());
		if (!parseDate(key))
		{
			in.close();
			std::cerr << ERROR("Data.csv is not formatted correctly") << std::endl;
			exit(1);
		}
	}
	in.close();
	return database;
}


/**
 * @brief Handles a line of input in the BitcoinExchange class.
 * 
 * This function takes a line of input, parses it, 
 * and performs the necessary operations based on the input.
 * The input line should be in the format "date|value", where date is a string~
 * representing a date and value is a float representing a value.
 * 
 * @param line The input line to be handled.
 */
void BitcoinExchange::handleLine(const string &line) {
	std::istringstream iss(line);
	string date;
	float value;

	if (std::getline(iss, date, '|') && iss >> value) {
		date.erase(date.find_last_not_of(" \t") + 1); // Remove trailing spaces
		if (!parseDate(date)) {
			std::cerr << ERROR("bad input => " + date) << std::endl;
			return;
		}
		if (value < MIN_VALUE) {
			std::cerr << ERROR("not a positive number.") << std::endl;
			return;
		}
		else if (value > MAX_VALUE) {
			std::cerr << ERROR("too large a number.") << std::endl;
			return;
		}
		std::map<string, float>::iterator it = _database.find(date);
		if (it != _database.end()) {
			std::cout << date << " => " << value << " = " << (value * it->second) << std::endl;
		} else {
			std::cerr << ERROR("date not found in database.") << std::endl;
		}
	} else {
		std::cerr << ERROR("bad input => " + line) << std::endl;
	}
}


/**
 * @brief Processes the input file in the BitcoinExchange class.
 * 
 * This function takes a file as input, reads the file line by line, 
 * and calls the handleLine function for each line.
 * 
 * @param file The input file to be processed.
 */
void BitcoinExchange::processInput(const string &file) {
	std::ifstream in(file.c_str());
	if (!in.is_open()) {
		throw std::runtime_error("Error: could not open input file.");
	}

	std::string line;
	std::getline(in, line);

	while (std::getline(in, line)) {
		handleLine(line);
	}

	in.close();
}

static bool	parseDate(string &key) {
	if (key.length() != 10)
		return false;
	for (int i = 0; i < 4; ++i) {
		if (!std::isdigit(key[i]))
			if (!(key[i] == '-' && (i == 4 || i == 7 || i == 10)))
				return false;
	}
	string year = key.substr(0, 4);
	string month = key.substr(5, 2);
	string day = key.substr(8, 2);
	if (atoi(month.c_str()) < 1 || atoi(month.c_str()) > 12 || \
		atoi(day.c_str()) < 1 || atoi(day.c_str()) > 31)
		return false;
	return true;
}
