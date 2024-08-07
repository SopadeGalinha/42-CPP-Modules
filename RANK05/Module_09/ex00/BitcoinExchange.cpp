#include "BitcoinExchange.hpp"

// ----------> Orthodox Canonical Form/Rule of Three <----------

// Constructor
BitcoinExchange::BitcoinExchange() : _database(loadCSV(DATABASE)) {}

// Copy Constructor
BitcoinExchange::BitcoinExchange(const BitcoinExchange &other)
	: _database(other.getDatabase()) {}

// Destructor
BitcoinExchange::~BitcoinExchange() {}

// Assignment Operator
BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &other)
{
	if (this != &other)
		_database = other.getDatabase();
	return *this;
}

// ---------------------> Public Methods <---------------------

static bool parseDate(string &key);

// Getter
map<string, float> BitcoinExchange::getDatabase() const
{
	return _database;
}

/**
 * @brief Loads a CSV file in the BitcoinExchange class.
 * 
 * This function takes a file as input, reads the file line by line,
 * and parses the data in the file.
 * The data is stored in a map where the key is a date string and the value is a float.
 * 
 * @param file The input file to be loaded.
 * @return A map containing the data from the file.
 * @see parseDate
*/
map<string, float> BitcoinExchange::loadCSV(const string file)
{
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
 * @brief Parses a date string in the BitcoinExchange class.
 * 
 * This function takes a string as input and checks if it is a valid date.
 * 
 * @param key The date string to be parsed.
 * @return true if the date is valid, false otherwise.
*/
static bool parseDate(string &key)
{
	if (key.length() != 10)
		return false;
	for (int i = 0; i < 4; ++i)
	{
		if (!std::isdigit(key[i]))
			if (!(key[i] == '-' && (i == 4 || i == 7 || i == 10)))
				return false;
	}
	string year = key.substr(0, 4);
	string month = key.substr(5, 2);
	string day = key.substr(8, 2);
	if (atoi(month.c_str()) < 1 || atoi(month.c_str()) > 12 ||
		atoi(day.c_str()) < 1 || atoi(day.c_str()) > 31)
		return false;
	return true;
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
void BitcoinExchange::handleLine(const string &line)
{
	std::istringstream iss(line);
	string date;
	float value;

	if (std::getline(iss, date, '|') && iss >> value)
	{
		date.erase(date.find_last_not_of(" \n\r\t") + 1);
		date.erase(0, date.find_first_not_of(" \n\r\t"));
		if (!parseDate(date)) {
			std::cerr << ERROR("date is not formatted correctly => " + date) << std::endl;
			return (void)(std::cerr << ERROR("bad input => " + date) << std::endl);
		}
		if (value < MIN_VALUE) {
			return (void)(std::cerr << ERROR("not a positive number.") << std::endl);
		}
		else if (value > MAX_VALUE){
			return (void)(std::cerr << ERROR("too large a number.") << std::endl);
		}

		std::map<string, float>::iterator it = _database.find(date);
		if (it != _database.end()) {
			std::cout << date << " => " << value << " = " << (value * it->second) << std::endl;
		} else {
			it = _database.lower_bound(date);
			if (it != _database.begin())
				--it;
			std::cout << it->first << " => " << value << " = " << (value * it->second) << std::endl;
		}
	}
	else
		std::cerr << ERROR("bad input => " + line) << std::endl;
}

/**
 * @brief Processes the input file in the BitcoinExchange class.
 *
 * This function takes a file as input, reads the file line by line,
 * and calls the handleLine function for each line.
 *
 * @param file The input file to be processed.
*/
void BitcoinExchange::processInput(const string &file)
{
	std::ifstream in(file.c_str());
	if (!in.is_open()) {
		std::cerr << ERROR("could not open file") << std::endl;
		return;
	}

	std::string line;
	std::getline(in, line);

	if (line.compare("date | value") != 0) {
		std::cerr << ERROR("bad input => " + line) << std::endl;
		in.close();
		return;
	}
	while (std::getline(in, line))
	{
		handleLine(line);
	}
	in.close();
}

