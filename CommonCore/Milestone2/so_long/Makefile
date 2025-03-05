NAME = so_long
CC = cc
CFLAGS = -Wall -Wextra -Werror -g
MLXFLAGS = -lmlx -Lminilibx-linux -lXext -lX11 -lm -lz

SRCS =	so_long.c \
		parsing/parsing_map1.c \
		parsing/parsing_map2.c \
		parsing/parsing_map3.c \
		game/display1.c \
		game/display2.c \
		game/play1.c \
		game/play2.c \
		utils/utils1.c \
		utils/utils2.c \
		utils/flood_fill_dfs.c

LIBFT_DIR = ./libft
LIBFT = $(LIBFT_DIR)/libft.a
MINILIBX_DIR = ./minilibx-linux
MINILIBX = $(MINILIBX_DIR)/libmlx.a
MLX_REPO = https://github.com/42Paris/minilibx-linux.git

all: $(NAME)

$(LIBFT):
	@echo "Compiling libft..."
	@$(MAKE) -C $(LIBFT_DIR) --quiet

$(MINILIBX):
	@echo "Cloning MinilibX..."
	@git clone $(MLX_REPO) $(MINILIBX_DIR) --quiet
	@echo "Compiling MinilibX..."
	@$(MAKE) -C $(MINILIBX_DIR) --quiet

$(NAME): $(LIBFT) $(MINILIBX) $(SRCS)
	@echo "Compiling $(NAME)..."
	@$(CC) $(CFLAGS) $(SRCS) $(LIBFT) $(MLXFLAGS) -I$(CURDIR) -o $(NAME)


clean:
	@echo "Removing object files..."
	@$(MAKE) -C $(LIBFT_DIR) clean --quiet
	@$(MAKE) -C $(MINILIBX_DIR) clean --quiet

fclean: clean
	@echo "Removing library and executables..."
	@rm -rf $(NAME)
	@$(MAKE) -C $(LIBFT_DIR) fclean --quiet
	@rm -rf $(MINILIBX_DIR)

re: fclean all

.PHONY: all clean fclean re
.SILENT:
