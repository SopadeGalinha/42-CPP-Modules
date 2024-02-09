/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhogonca <jhogonca@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/22 17:17:38 by jhogonca          #+#    #+#             */
/*   Updated: 2023/12/22 17:17:38 by jhogonca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>
#include <cmath>

#define RESET	"\033[0m"
#define RED		"\033[1m\033[31m"
#define GREEN	"\033[1m\033[32m"
#define YELLOW	"\033[1m\033[33m"
#define BLUE	"\033[1m\033[34m"
#define PURPLE	"\033[1m\033[35m"
#define WHITE	"\033[1m\033[37m"

class Fixed {
	private:
		static const int	fractionalBits = 8;
		int					_rawBits;

	public:
		// Constructors
		Fixed(void);
		Fixed(const int value);
		Fixed(const float value);

		//Copy Constructor
		Fixed(const Fixed &other);
		
		// Destructor
		~Fixed(void);

		// Assignment Operator
		// Operator overload
		Fixed	&operator=(const Fixed &other);

		// Setters and getters
		int		getRawBits(void) const;
		void	setRawBits(int const raw);

		// Member functions
		float	toFloat(void) const;
		int		toInt(void) const;
};

std::ostream &operator<<(std::ostream &out, const Fixed &fixed);

#endif
