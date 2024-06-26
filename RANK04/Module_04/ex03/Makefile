# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jhogonca <jhogonca@student.42porto.com>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/30 20:27:23 by jhogonca          #+#    #+#              #
#    Updated: 2024/03/30 20:27:23 by jhogonca         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = amateria

# Source files
SRCS = $(wildcard srcs/*.cpp)
OBJS = $(SRCS:.cpp=.o)

# Compilation flags
CXX = c++
WFLAGS = -Wall -Wextra -Werror
CXX_FLAGS = -std=c++98 -pedantic-errors -fsanitize=address

# Compile the program
$(NAME): $(OBJS)
	$(CXX) $(WFLAGS) -Iincludes $(CXX_FLAGS) $^ -o $@

# Compile the object files
%.o: %.cpp
	$(CXX) $(WFLAGS) -Iincludes $(CXX_FLAGS) -c $< -o $@

# Commands
all: $(NAME)

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)

re: fclean all

# Phony rules
.PHONY: all clean fclean re

