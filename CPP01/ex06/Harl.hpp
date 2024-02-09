/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhogonca <jhogonca@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 14:46:07 by jhogonca          #+#    #+#             */
/*   Updated: 2023/12/20 14:46:07 by jhogonca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARL_HPP
# define HARL_HPP

#include <iostream>
#include <string>
#include <algorithm>

#define RESET	"\033[0m"
#define RED		"\033[1m\033[31m"
#define GREEN	"\033[1m\033[32m"
#define YELLOW	"\033[1m\033[33m"
#define BLUE	"\033[1m\033[34m"
#define PURPLE	"\033[1m\033[35m"
#define WHITE	"\033[1m\033[37m"

class Harl
{
private:
	// Private methods
	void	_debug(void);
	void	_info(void);
	void	_warning(void);
	void	_error(void);

public:
	// Constructor & Destructor
	Harl(void);
	~Harl(void);

	// Member functions
	void	complain(const std::string& level);
	void	filter(const std::string& level);
};

#endif
