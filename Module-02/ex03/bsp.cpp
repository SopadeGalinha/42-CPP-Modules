/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhogonca <jhogonca@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 21:45:19 by jhogonca          #+#    #+#             */
/*   Updated: 2024/01/08 21:45:19 by jhogonca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

bool bsp(Point const a, Point const b, Point const c, Point const point) {
	Fixed const x = point.getX();
	Fixed const y = point.getY();
	Fixed const x1 = a.getX();
	Fixed const y1 = a.getY();
	Fixed const x2 = b.getX();
	Fixed const y2 = b.getY();
	Fixed const x3 = c.getX();
	Fixed const y3 = c.getY();
	Fixed const x4 = x2 - x1;
	Fixed const y4 = y2 - y1;
	Fixed const x5 = x3 - x1;
	Fixed const y5 = y3 - y1;
	Fixed const x6 = x - x1;
	Fixed const y6 = y - y1;
	Fixed const x7 = x - x2;
	Fixed const y7 = y - y2;
	Fixed const x8 = x - x3;
	Fixed const y8 = y - y3;
	Fixed const z1 = x4 * y6 - x6 * y4;
	Fixed const z2 = x5 * y7 - x7 * y5;
	Fixed const z3 = x4 * y8 - x8 * y4;
	Fixed const z4 = x5 * y8 - x8 * y5;
	if ((z1 >= 0 && z2 >= 0 && z3 <= 0 && z4 <= 0) ||
		(z1 <= 0 && z2 <= 0 && z3 >= 0 && z4 >= 0))
		return (true);
	return (false);
}