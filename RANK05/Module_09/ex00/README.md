# Bitcoin Exchange Project

## Overview

This project implements a Bitcoin exchange rate calculator. The program reads a CSV file containing historical Bitcoin exchange rates and uses it to evaluate the value of Bitcoin transactions provided in an input file. The program can handle various edge cases, including invalid dates, negative values, and excessively large numbers.

## Requirements

1. **Program Name:** `btc`
2. **Input Argument:** The program takes one file as an argument, which contains the Bitcoin transactions to be evaluated.
3. **Input File Format:**
    - Each line follows the format: `date | value`
    - Date is in the format: `Year-Month-Day`
    - Value is a float or a positive integer between 0 and 1000.

### Example Input File (`input.txt`)

```
date | value
2011-01-03 | 3
2011-01-03 | 2
2011-01-03 | 1
2011-01-03 | 1.2
2011-01-09 | 1
2012-01-11 | -1
2001-42-42
2012-01-11 | 1
2012-01-11 | 2147483648
```

### Output Behavior

- For each valid transaction, the program outputs the result of the value multiplied by the exchange rate on the given date.
- If the date does not exist in the database, the program uses the closest previous date.
- Errors are displayed for invalid inputs.

### Example Program Usage

```sh
$ ./btc
Error: could not open file.
$ ./btc input.txt
2011-01-03 => 3 = 0.9
2011-01-03 => 2 = 0.6
2011-01-03 => 1 = 0.3
2011-01-03 => 1.2 = 0.36
2011-01-09 => 1 = 0.32
Error: not a positive number.
Error: bad input => 2001-42-42
2012-01-11 => 1 = 7.1
Error: too large a number.
```

## Implementation

### BitcoinExchange Class Definition

- **Class Definition:** `BitcoinExchange`
- **Attributes:**
  - `_database`: A map that stores the database of exchange rates.
- **Public Methods:**
  - `BitcoinExchange()`: Constructor
  - `~BitcoinExchange()`: Destructor
  - `BitcoinExchange(const BitcoinExchange &other)`: Copy constructor
  - `BitcoinExchange &operator=(const BitcoinExchange &other)`: Assignment operator
  - `map<string, float> getDatabase() const`: Returns the database map.
  - `map<string, float> loadCSV(const string file)`: Loads the CSV file into a map.
  - `void handleLine(const string &line)`: Handles each line of input.
  - `void processInput(const string &file)`: Processes the input file.

### How the Program Works

#### 1. **Constructor (`BitcoinExchange`)**
   - Loads the historical Bitcoin exchange rates from a CSV file into the `_database` attribute using the `loadCSV` method.

#### 2. **loadCSV**
   - Reads the provided CSV file line by line.
   - Parses each line to extract the date and exchange rate.
   - Validates the date format using the `parseDate` function.
   - Stores the date and exchange rate in the `_database` map.
   - Returns an error if the file is not formatted correctly.

#### 3. **handleLine**
   - Parses and processes each line from the input file.
   - Splits the line into a date and value.
   - Trims any leading or trailing whitespace from the date.
   - Validates the date and value formats.
   - Edge cases:
     - Invalid date format
     - Value less than 0
     - Value greater than 1000
   - Looks up the exchange rate for the given date in the `_database` map.
   - If the date does not exist, finds the closest previous date.
   - Calculates and outputs the value multiplied by the exchange rate.
   - Displays appropriate error messages for invalid inputs.

#### 4. **processInput**
   - Opens the input file.
   - Reads the file line by line.
   - Calls `handleLine` for each line to process the transaction.
   - Displays an error message if the input file cannot be opened.

## Error Handling

- **File Errors:** The program checks if the input file and the database file can be opened.
- **Input Validation:** The program validates the date and value formats and handles errors such as invalid dates, negative values, and excessively large numbers.
