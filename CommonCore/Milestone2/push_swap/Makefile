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

OBJS = $(SRCS:.c=.o)
OBJS_BONUS = $(SRCS_BONUS:.c=.o)

LIBFT_DIR = ./libft
LIBFT = ./libft/libft.a

normal: $(NAME)

bonus: $(NAME_BONUS)

all: $(NAME) $(NAME_BONUS)

$(LIBFT):
	@echo "Compiling libft..."
	@$(MAKE) -C $(LIBFT_DIR) --quiet

$(NAME): $(LIBFT) $(OBJS) push_swap.o
	@echo "Compiling $(NAME)..."
	@$(CC) $(CFLAGS) $(OBJS) push_swap.o $(LIBFT) -o $(NAME)

$(NAME_BONUS): $(LIBFT) $(OBJS) $(OBJS_BONUS) ./bonus/checker.o
	@echo "Compiling $(NAME_BONUS)..."
	@$(CC) $(CFLAGS) $(OBJS) $(OBJS_BONUS) ./bonus/checker.o $(LIBFT) -o $(NAME_BONUS)

%.o: %.c
	@$(CC) $(CFLAGS) -I$(CURDIR) -I$(LIBFT_DIR) -c $< -o $@

clean:
	@rm -rf $(OBJS) $(OBJS_BONUS) push_swap.o ./bonus/checker.o
	@$(MAKE) -C $(LIBFT_DIR) clean --quiet

fclean: clean
	@rm -rf $(NAME) $(NAME_BONUS)
	@$(MAKE) -C $(LIBFT_DIR) fclean --quiet

re: fclean all

.PHONY: normal all clean fclean re bonus
