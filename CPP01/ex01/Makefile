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

NAME = moarBrainz

SRCS = main.cpp Zombie.cpp newZombie.cpp randomChump.cpp zombieHorde.cpp

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

re: fclean all

.PHONY: all clean fclean re
