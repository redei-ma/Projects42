/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: redei-ma <redei-ma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 17:14:31 by redei-ma          #+#    #+#             */
/*   Updated: 2025/03/02 15:30:03 by redei-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdbool.h>
# include "libft/libft.h"
# include "minilibx-linux/mlx.h"

typedef struct s_point
{
	int	x;
	int	y;
}	t_point;

typedef struct s_sprite
{
	int		player;
	int		collect;
	int		exit;
}	t_sprite;

typedef struct s_game
{
	char	**map;
	int		width;
	int		height;
	int		player_x;
	int		player_y;
	int		p_direct;
	int		collectibles;
	void	*mlx;
	void	*win;
	void	*wall_img;
	void	*floor_img;
	void	*enemy_img1;
	void	*enemy_img2;
	void	*enemy_img_curr;
	int		enemy_frame;
	void	*p_up_img;
	void	*p_down_img;
	void	*p_left_img;
	void	*p_right_img;
	void	*exit_img;
	void	*collect_img;
	char	prev_tile;
	int		moves;
}	t_game;

char	**check_valid_map(char **map, t_sprite *sprite, t_game *game);
char	**write_map(char **map, int *i, int fd);
int		check_extension(char *file);
char	**take_map(char *file);
char	**parsing_map(char *file, t_sprite *sprite, t_game *game);

int		count_elements_filled(char **map);
int		count_elements(char **map, t_sprite *sprite);
int		check_surrounded(char **map);
int		check_size(char **map, int i, int j);
char	**fill_map(char **map, int *i, int *j);

char	**copy_map(char **map, t_point size);
t_point	find_player(char **map, t_game *game);

void	put_images(t_game *game, int i, int j);
void	render_map(t_game *game);
void	load_images(t_game *game, int w, int h);
int		load_textures(t_game *game);
int		init_game(t_game *game);

void	put_player(t_game *game, int i, int j);
int		check_display_size(t_game game);

void	make_move(t_game *game, int new_x, int new_y);
void	move_player(t_game *game, int dx, int dy);
int		key_press(int keycode, t_game *game);
void	setup_hooks(t_game *game);
void	start_game(t_game *game);

void	print_moves(t_game *game);
int		animate_enemies(t_game *game);

void	print_map(char **map);
void	free_all(t_game *game);
void	free_map(char **map);

void	exit_error(t_game *game, char *msg);
void	clear_libx(t_game *game);
int		close_game(t_game *game);

void	flood_fill_dfs(char **tab, t_point size, t_point begin, char *target);

#endif
