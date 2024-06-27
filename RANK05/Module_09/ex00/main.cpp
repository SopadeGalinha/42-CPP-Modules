#include "BitcoinExchange.hpp"

int main(int ac, char **av) {

	std::ifstream in(av[1]);
	std::ifstream dt(DATABASE);
	if (ac != 2 || in.bad() || dt.fail())
	{
		return(std::cerr << \
		ERROR("could not open file") << std::endl, 1);
	}
	BitcoinExchange btc;
	btc.processInput(av[1]);
	in.close();
	dt.close();
	return 0;
}
