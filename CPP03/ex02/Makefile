# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jhogonca <jhogonca@student.42porto.com>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/09 16:00:48 by jhogonca          #+#    #+#              #
#    Updated: 2024/02/13 12:14:32 by jhogonca         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = FragTrap

SRCS = main.cpp ClapTrap.cpp ScavTrap.cpp FragTrap.cpp

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
