.SILENT:

NAME = exec

# Colors
GREEN = \033[0;32m
BOLD_WHITE = \033[1;37m
RESET = \033[0m

# Sources and objects files
SRCS = $(wildcard srcs/*.cpp)
OBJS = $(SRCS:srcs/%.cpp=srcs/%.o)

# Compilation flags
CXX = c++
WFLAGS = -Wall -Wextra -Werror
CXX_FLAGS = -std=c++98 -pedantic-errors -fsanitize=address -Iincludes

# Program compilation
$(NAME): $(OBJS)
	$(CXX) $(WFLAGS) $(CXX_FLAGS) srcs/*.o -o $(NAME)
	printf "$(GREEN) Program compiled\n$(RESET)"
	printf "Usage: $(BOLD_WHITE)./$(NAME)$(RESET)\n"

# Objects compilation
srcs/%.o: srcs/%.cpp
	$(CXX) $(WFLAGS) $(CXX_FLAGS) -c $< -o $@

# Phony rules
.PHONY: all clean fclean re

# Compile all
all: $(NAME)

# Clean objects
clean:
	rm -f srcs/*.o

# Clean objects and program
fclean: clean
	rm -f $(NAME)

# Re-compile
re: fclean all
