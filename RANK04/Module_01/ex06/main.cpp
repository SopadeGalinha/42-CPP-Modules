/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhogonca <jhogonca@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 15:23:20 by jhogonca          #+#    #+#             */
/*   Updated: 2023/12/20 15:23:20 by jhogonca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int main(int ac, char **av)
{
	if (ac != 2)
	{
		std::cout << YELLOW << "Usage: ./complain [DEBUG|INFO|WARNING|ERROR]" << std::endl;
		return (1);
	}
  	std::string level = av[1];
    Harl harl;
    harl.filter(level);

    return 0;
}
