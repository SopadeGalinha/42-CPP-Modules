/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhogonca <jhogonca@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 14:16:37 by jhogonca          #+#    #+#             */
/*   Updated: 2023/12/20 14:16:37 by jhogonca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>
#include <stdexcept>
#include <string>

#define RESET "\033[0m"
#define RED "\033[1m\033[31m"
#define GREEN "\033[1m\033[32m"
#define YELLOW "\033[1m\033[33m"
#define BLUE "\033[1m\033[34m"

void ft_replace(std::string &line,
	const std::string &search, const std::string &replace) {
	
	size_t pos = 0;
	size_t found_pos = line.find(search, pos);

	while (found_pos != std::string::npos) {
		line = line.substr(0, found_pos) + replace +
			line.substr(found_pos + search.length());
		pos = found_pos + replace.length();
		found_pos = line.find(search, pos);
	}
}

void search_and_replace(const std::string &filename,
						const std::string &search, const std::string &replace) {
	if (search.empty()) {
		std::cout << YELLOW << "Warning: search or replace string is empty." << RESET;
		std::cout << BLUE << "\n\tNothing to be done." << RESET << std::endl;
		return ;
	}
	try {
		// Open input file
		std::ifstream input_file(filename.c_str());
		if (!input_file.is_open())
			throw std::runtime_error("Error: file " + filename + " cannot be opened.");

		// Create output file
		std::string output_filename = filename + ".replace";
		std::ofstream output_file(output_filename.c_str());
		if (!output_file.is_open())
			throw std::runtime_error("Error: cannot create output file.");

		// Read file
		std::string line;
		while (std::getline(input_file, line))
		{
			ft_replace(line, search, replace);
			if (!input_file.eof())
				output_file << line << std::endl;
			else
				output_file << line
		}
		std::cout << GREEN << "\nFile successfully replaced." << RESET << std::endl;
		input_file.close();
		output_file.close();
	}
	catch (const std::exception &e) {
		throw e;
	}
}

int main(int ac, char **av)
{
	if (ac != 4) {
		// Argument number error
		std::cout << RED << "Error: wrong number of arguments." << RESET << std::endl;
		std::cout << YELLOW << "\tUsage: ./replace <filename>";
		std::cout << " <string_to_be_replaced> <string_to_replace>" << RESET << std::endl;
		return 1;
	}

	// Search and replace
	try { search_and_replace(av[1], av[2], av[3]); }
	catch (const std::exception &e) {
		std::cout << RED << "Error: " << e.what() << RESET << std::endl;
		return 1;
	}
	return 0;
}
