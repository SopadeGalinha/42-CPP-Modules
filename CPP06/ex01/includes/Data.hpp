/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhogonca <jhogonca@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 23:52:29 by jhogonca          #+#    #+#             */
/*   Updated: 2024/05/16 23:52:29 by jhogonca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DATA_HPP
# define DATA_HPP

// Libraries
#include <iostream>
#include <string>

// Struct
struct Data
{
	private:
		// Attributes
		std::string privateData;
		int privateNumber;
		
	public:		
		// Public Attributes
		std::string publicData;

		// Constructors and Destructor
		Data(void);
		~Data(void);
		Data(const Data &src);
	
	// Assignment Operator
	Data &operator=(const Data &src);
	
	// Getters
	std::string getPrivateData(void) const;
	int getPrivateNumber(void) const;
	
	Data(std::string publicData, std::string privateData, int privateNumber);
};

#endif