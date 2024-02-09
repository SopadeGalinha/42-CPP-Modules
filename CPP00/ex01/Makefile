# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jhogonca <jhogonca@student.42porto.com>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/03 13:10:07 by jhogonca          #+#    #+#              #
#    Updated: 2023/12/03 13:10:07 by jhogonca         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = phonebook

SRCS = main.cpp Contact.cpp Phonebook.cpp

OBJS_DIR = ./objs/

OBJS = $(addprefix $(OBJS_DIR), $(SRCS:.cpp=.o))

CXX = c++

RM = /bin/rm -rf

CXXFLAGS = -Wall -Wextra -Werror -std=c++98 -pedantic-errors -fsanitize=address

$(OBJS_DIR)%.o: %.cpp
	@mkdir -p $(OBJS_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)

clean: 
	$(RM) $(OBJS_DIR)

fclean: clean 
	$(RM) $(NAME)

re: fclean all

.PHONY : all clean fclean re
