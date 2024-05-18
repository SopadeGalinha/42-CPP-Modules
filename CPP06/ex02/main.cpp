/* ************************************************************************** */
/*                                                                            */
/*                                                        :::\t     ::::::::\t  */
/*   main.cpp                                           :+:\t     :+:\t   :+:\t  */
/*                                                    +:+ +:+         +:+     */
/*   By:\tjhogonca <jhogonca@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created:\t2024/05/17 20:53:35 by jhogonca          #+#    #+#             */
/*   Updated:\t2024/05/17 20:53:35 by jhogonca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"

int main()
{
	srand(time(NULL));
	Base *base = generate();
	identify_from_pointer(base);
	identify_from_reference(*base);
	delete base;
	return 0;
}
