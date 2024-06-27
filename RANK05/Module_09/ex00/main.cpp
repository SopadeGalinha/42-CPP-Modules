#include "BitcoinExchange.hpp"

void	printData(map<string, float> database)
{
	map<string, float>::iterator it = database.begin();
	while (it != database.end())
	{
		cout << it->first << " " << it->second << endl;
		++it;
	}
}

int main() {
	try {

		BitcoinExchange btc;
		printData(btc.getDatabase());
		return 0;
	}
	catch (const std::exception &e) {
		std::cerr << ERROR(e.what()) << std::endl;
		return 1;
	}
}
