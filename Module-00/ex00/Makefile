# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jhogonca <jhogonca@student.42porto.com>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/09 01:00:06 by jhogonca          #+#    #+#              #
#    Updated: 2023/09/09 01:00:06 by jhogonca         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = megaphone

SRCS = megaphone.cpp

CXX = c++

RM = /bin/rm -rf
CXXFLAGS = -Wall -Wextra -Werror -std=c++98 -pedantic-errors -fsanitize=address

OBJS = $(SRCS:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

doAll: all
	make -s -C ../ex01
	make -s -C ../ex02

fcleanAll: fclean
	make fclean -s -C ../ex01
	make fclean -s -C ../ex02

.PHONY : all clean fclean re

