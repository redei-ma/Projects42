NAME = push_swap
NAME_BONUS = checker
CC = cc
CFLAGS = -Wall -Wextra -Werror

SRCS =  ./algorithm/algorithm_1.c \
		./algorithm/algorithm_2.c \
		./algorithm/algorithm_3.c \
		./function/function_1.c \
		./function/function_2.c \
		./function/function_3.c \
		./function/function_4.c \
		./utils/utils_1.c \
		./utils/utils_2.c

SRCS_BONUS =	./bonus/function_bonus_1.c \
				./bonus/function_bonus_2.c 

SRC_ALL = $(SRCS) $(SRCS_BONUS)

LIBFT_DIR = ./libft
LIBFT = ./libft/libft.a

all: $(NAME)

bonus: $(NAME_BONUS)

$(LIBFT):
	@echo "Compiling libft..."
	@$(MAKE) -C $(LIBFT_DIR) --quiet

$(NAME): $(LIBFT) $(SRCS) push_swap.c
	@echo "Compiling $(NAME)..."
	@$(CC) $(CFLAGS) $(SRCS) push_swap.c $(LIBFT) -I$(CURDIR) -o $(NAME)

$(NAME_BONUS): $(LIBFT) $(SRCS_ALL) ./bonus/checker.c
	@echo "Compiling $(NAME_BONUS)..."
	@$(CC) $(CFLAGS) $(SRCS_ALL) ./bonus/checker.c $(LIBFT) -I$(CURDIR) -o $(NAME_BONUS)

clean:
	@echo "Removing object files..."
	@$(MAKE) -C $(LIBFT_DIR) clean --quiet

fclean: clean
	@echo "Removing library and executables..."
	@rm -rf $(NAME) $(NAME_BONUS)
	@$(MAKE) -C $(LIBFT_DIR) fclean --quiet

re: fclean all

.PHONY: normal all clean fclean re bonus
.SILENT:
