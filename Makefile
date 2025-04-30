NAME = philo

C_FILES = main.c\
			utils.c\
			parsing.c\


BOLD = \033[1m
RED = \033[31m
RESET = \033[0m
BLACK  = \033[30m
GREEN  = \033[32m
YELLOW = \033[33m
BLUE   = \033[34m
MAGENTA= \033[35m
CYAN   = \033[36m
WHITE  = \033[37m

SRCS = $(addprefix srcs/,$(C_FILES))

# CFLAGS = -Wall -Werror -Wextra -I includes/  -pthread -fsanitize=thread -g
CFLAGS = -Wall -Werror -Wextra -I includes/ -g
# -pthread -fsanitize=thread

all: ${NAME}

$(NAME): $(SRCS)
	@echo "$(BOLD)$(RED)Creation de $(NAME)...$(RESET)"
	@cc $(CFLAGS) $(SRCS) -o $(NAME) $(DEPS) -lreadline
	@echo "$(BOLD)$(YELLOW) COMPILATION TERMINE $(RESET)"

clean:
	@echo "$(RED)FR$(WHITE)E$(GREEN)E $(RED)PAL$(WHITE)EST$(GREEN)INE$(RESET)"

fclean: clean
	@echo "Removing executable..."
	@rm -rf $(NAME)

re:	fclean all

.PHONY: all clean fclean re