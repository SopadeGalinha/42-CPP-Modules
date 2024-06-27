#include "BitcoinExchange.hpp"

// ----------> Orthodox Canonical Form/Rule of Three <----------

// Constructor
BitcoinExchange::BitcoinExchange() : _database(loadCSV(DATABASE, true)) {}

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

map<string, float> BitcoinExchange::getDatabase() const {
	return _database;
}

static bool	parseDate(string &key) {
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

map<string, float> BitcoinExchange::loadCSV(const string file, bool isDataCSV)
{
	ifstream in(file.c_str());
	if (!in.is_open())
		throw OpenFileException();

	map<string, float> database;
	string line;

	getline(in, line);
	if ((line.compare("date,exchange_rate") != 0 && isDataCSV))
		throw invalidCsvDataException();
	
	if ((line.compare("date | value") != 0 && !isDataCSV) || line.empty())
		throw invalidCsvDataException();
	while (getline(in, line))
	{
		if (line.empty())
			continue;
		string key = line.substr(0, line.find(','));
		string value = line.substr(line.find(',') + 1).c_str();
		if (!parseDate(key))
			throw InvalidDateException();
		if (atof(value.c_str()) < MIN_VALUE || atof(value.c_str()) > MAX_VALUE)
			throw InvalidValueException();
		database[key] = atof(value.c_str());
	}
	in.close();
	return database;
}
