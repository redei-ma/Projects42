NAME = pipex
NAME_BONUS = pipex_bonus
CC = cc
CFLAGS = -Wall -Wextra -Werror

SRC =	forking.c \
		utils1.c \
		utils2.c

SRC_BONUS = bonus/forking_bonus.c \
			bonus/here_doc.c \
			bonus/utils_bonus.c

OBJS = $(SRC:.c=.o)
OBJS_BONUS = $(SRC_BONUS:.c=.o)

LIBFT_DIR = ./libft
LIBFT = ./libft/libft.a

normal: $(NAME)

bonus: $(NAME_BONUS)

all: $(NAME) $(NAME_BONUS)

$(LIBFT):
	@echo "Compiling libft..."
	@$(MAKE) -C $(LIBFT_DIR) --quiet

$(NAME): $(LIBFT) $(OBJS) pipex.o
	@echo "Compiling $(NAME)..."
	@$(CC) $(CFLAGS) $(OBJS) pipex.o $(LIBFT) -o $(NAME)

$(NAME_BONUS): $(LIBFT) $(OBJS) $(OBJS_BONUS) ./bonus/pipex_bonus.o
	@echo "Compiling $(NAME_BONUS)..."
	@$(CC) $(CFLAGS) $(OBJS) $(OBJS_BONUS) ./bonus/pipex_bonus.o $(LIBFT) -o $(NAME_BONUS)

%.o: %.c
	@$(CC) $(CFLAGS) -I$(CURDIR) -I$(LIBFT_DIR) -c $< -o $@

clean:
	@echo "Removing object files..."
	@rm -rf $(OBJS) $(OBJS_BONUS) pipex.o ./bonus/pipex_bonus.o
	@$(MAKE) -C $(LIBFT_DIR) clean --quiet

fclean: clean
	@echo "Removing library and executables..."
	@rm -rf $(NAME) $(NAME_BONUS)
	@$(MAKE) -C $(LIBFT_DIR) fclean --quiet

re: fclean all

.PHONY: normal all clean fclean re bonus
.SILENT:
