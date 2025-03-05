NAME = pipex
NAME_BONUS = pipex_bonus
CC = cc
CFLAGS = -Wall -Wextra -Werror

SRCS =	forking.c \
		utils1.c \
		utils2.c

SRCS_BONUS = bonus/forking_bonus.c \
			bonus/here_doc.c \
			bonus/utils_bonus.c

SRCS_ALL = $(SRCS) $(SRCS_BONUS)

LIBFT_DIR = ./libft
LIBFT = ./libft/libft.a

all: $(NAME)

bonus: $(NAME_BONUS)

$(LIBFT):
	@echo "Compiling libft..."
	@$(MAKE) -C $(LIBFT_DIR) --quiet

$(NAME): $(LIBFT) $(SRCS) pipex.c
	@echo "Compiling $(NAME)..."
	@$(CC) $(CFLAGS) $(SRCS) pipex.c $(LIBFT) -I$(CURDIR) -o $(NAME)

$(NAME_BONUS): $(LIBFT) $(SRCS_ALL) ./bonus/pipex_bonus.c
	@echo "Compiling $(NAME_BONUS)..."
	@$(CC) $(CFLAGS) $(SRCS_ALL) ./bonus/pipex_bonus.c $(LIBFT) -I$(CURDIR) -o $(NAME_BONUS)

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
