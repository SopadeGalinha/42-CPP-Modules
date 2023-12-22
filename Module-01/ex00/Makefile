# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jhogonca <jhogonca@student.42porto.com>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/16 13:55:31 by jhogonca          #+#    #+#              #
#    Updated: 2023/12/16 13:55:31 by jhogonca         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = brainz

SRCS = main.cpp Zombie.cpp newZombie.cpp randomChump.cpp

CC = c++

OBJS = $(SRCS:.cpp=.o)

FLAGS = -Wall -Wextra -Werror -std=c++98 -pedantic-errors -fsanitize=address

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(FLAGS) $(OBJS) -o $(NAME)

%.o: %.cpp
	$(CC) $(FLAGS) -c $< -o $@

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)

doAll: all
	make -s -C ../ex01
	make -s -C ../ex02
	make -s -C ../ex03
	make -s -C ../ex04
	make -s -C ../ex05
	make -s -C ../ex06

fcleanAll: fclean 
	make fclean -s -C ../ex01
	make fclean -s -C ../ex02
	make fclean -s -C ../ex03
	make fclean -s -C ../ex04
	make fclean -s -C ../ex05
	make fclean -s -C ../ex06

re: fclean all

.PHONY: all clean fclean re
