/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Macros.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhogonca <jhogonca@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 19:21:35 by jhogonca          #+#    #+#             */
/*   Updated: 2024/05/16 23:01:54 by jhogonca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MACROS_HPP
# define MACROS_HPP

// Colors
#define RED "\033[1;31m"
#define BLUE "\033[1;34m"
#define GREEN "\033[1;32m"
#define YELLOW "\033[1;33m"
#define RESET "\033[0m"

// Enum
enum ScalarType
{
	NONE,
	CHAR,
	INT,
	FLOAT,
	DOUBLE
};

// Logical Operators
#define AND &&
#define OR ||
#define NO_DISPLAYABLE RED "Non displayable" RESET
#define IMPOSSIBLE RED "impossible" RESET

// Pseudo-Literals

// -> Floating Point Literals <- //
#define FLT_NAN "nanf"
#define FLT_POS_INF "+inff"
#define FLT_NEG_INF "-inff"

// -> Double Literals <- //
#define DBL_NAN "nan"
#define DBL_POS_INF "+inf"
#define DBL_NEG_INF "-inf"

#define IS_FLOAT_LITERAL(literal) ( \
	(literal == FLT_NAN) || \
	(literal == FLT_POS_INF) || \
	(literal == FLT_NEG_INF) \
)

#define IS_DOUBLE_LITERAL(literal) ( \
	(literal == DBL_NAN) || \
	(literal == DBL_POS_INF) || \
	(literal == DBL_NEG_INF) \
)

#endif
