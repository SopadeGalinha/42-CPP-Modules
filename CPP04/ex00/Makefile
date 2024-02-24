# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jhogonca <jhogonca@student.42porto.com>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/24 08:37:19 by jhogonca          #+#    #+#              #
#    Updated: 2024/02/24 08:37:19 by jhogonca         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = makeSounds

# Source files
SRCS = $(wildcard src/*.cpp)
OBJS = $(SRCS:.cpp=.o)

# Compilation flags
CXX = c++
WFLAGS = -Wall -Wextra -Werror -Iincludes
CXX_FLAGS = -std=c++98 -pedantic-errors -fsanitize=address

# Compile the program
$(NAME): $(OBJS)
	$(CXX) $(WFLAGS) $(CXX_FLAGS) $^ -o $@

# Compile the object files
%.o: %.cpp
	$(CXX) $(WFLAGS) $(CXX_FLAGS) -c $< -o $@

# Commands
all: $(NAME)

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)

re: fclean all

# Phony rules
.PHONY: all clean fclean re
