# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jhogonca <jhogonca@student.42porto.com>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/02 01:11:10 by jhogonca          #+#    #+#              #
#    Updated: 2024/05/02 01:11:10 by jhogonca         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.SILENT:

NAME = Bureaucrat

# Colors
GREEN = \033[0;32m
BOLD_WHITE = \033[1;37m
RESET = \033[0m

# Sources and objects files
SRCS = $(wildcard srcs/*.cpp)
OBJS = $(SRCS:.cpp=.o)

# Compilation flags
CXX = c++
WFLAGS = -Wall -Wextra -Werror
CXX_FLAGS = -std=c++98 -pedantic-errors -fsanitize=address

# Program compilation
$(NAME): $(OBJS)
	$(CXX) $(WFLAGS) $(CXX_FLAGS) $(OBJS) -o $(NAME)
	printf "$(GREEN) Program compiled\n$(RESET)"
	printf "Usage: $(BOLD_WHITE)./$(NAME)$(RESET)\n"

# Objects compilation
%.o: %.cpp
	$(CXX) $(WFLAGS) $(CXX_FLAGS) -c $< -o $@

# Phony rules

# Compile all
all: $(NAME)

# Clean objects
clean:
	rm -f $(OBJS)

# Clean objects and program
fclean: clean
	rm -f $(NAME)

# Re-compile
re: fclean all

# Phony rules
.PHONY: all clean fclean re
