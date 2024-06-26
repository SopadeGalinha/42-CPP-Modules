# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jhogonca <jhogonca@student.42porto.com>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/09 16:00:48 by jhogonca          #+#    #+#              #
#    Updated: 2024/02/11 22:13:35 by jhogonca         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = DiamondTrap

SRCS = main.cpp ClapTrap.cpp ScavTrap.cpp FragTrap.cpp DiamondTrap.cpp

CXX = c++

OBJS = $(SRCS:.cpp=.o)

WFLAGS = -Wall -Wextra -Werror 

CXX_FLAGS = -std=c++98 -pedantic-errors -fsanitize=address -Wshadow -Wno-shadow

all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(WFLAGS) $(CXX_FLAGS) $^ -o $@

%.o: %.cpp
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re
