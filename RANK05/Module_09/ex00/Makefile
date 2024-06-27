.SILENT:

NAME = btc

# Colors
GREEN = \033[0;32m
BOLD = \033[1m
RESET = \033[0m

# Sources and objects files
SRCS = $(wildcard *.cpp)
OBJS = $(SRCS:%.cpp=%.o)

# Compilation flags
CXX = c++
WFLAGS = -Wall -Wextra -Werror
CXX_FLAGS = -std=c++98 -pedantic-errors -fsanitize=address

# Program compilation
$(NAME): $(OBJS)
	$(CXX) $(WFLAGS) $(CXX_FLAGS) *.o -o $(NAME)
	printf "$(GREEN) Program compiled\n$(RESET)"
	printf "Usage: $(BOLD)./$(NAME)$(RESET)\n"

# Objects compilation
%.o: %.cpp
	$(CXX) $(WFLAGS) $(CXX_FLAGS) -c $< -o $@

# Compile all
all: $(NAME)

# Clean objects
clean:
	rm -f *.o

# Clean objects and program
fclean: clean
	rm -f $(NAME)

# Re-compile
re: fclean all

# Phony rules
.PHONY: all clean fclean re