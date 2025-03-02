/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: redei-ma <redei-ma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 14:11:15 by redei-ma          #+#    #+#             */
/*   Updated: 2025/03/02 15:20:28 by redei-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	put_images(t_game *game, int i, int j)
{
	if (game->map[i][j] == '1')
		mlx_put_image_to_window(game->mlx, game->win, game->wall_img,
			j * 48, i * 48);
	else if (game->map[i][j] == 'C')
		mlx_put_image_to_window(game->mlx, game->win, game->collect_img,
			j * 48, i * 48);
	else if (game->map[i][j] == 'P')
		put_player(game, i, j);
	else if (game->map[i][j] == 'E')
		mlx_put_image_to_window(game->mlx, game->win, game->exit_img,
			j * 48, i * 48);
	else if (game->map[i][j] == 'F')
		mlx_put_image_to_window(game->mlx, game->win, game->enemy_img_curr,
			j * 48, i * 48);
	else if (game->map[i][j] == '0')
		mlx_put_image_to_window(game->mlx, game->win, game->floor_img,
			j * 48, i * 48);
}

void	render_map(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (game->map[i])
	{
		j = 0;
		while (game->map[i][j])
		{
			if (game->map[i][j] == '\n')
				break ;
			put_images(game, i, j);
			j++;
		}
		i++;
	}
}

void	load_images(t_game *game, int w, int h)
{
	game->p_up_img = mlx_xpm_file_to_image(game->mlx, "texture/up.xpm",
			&w, &h);
	game->p_down_img = mlx_xpm_file_to_image(game->mlx, "texture/down.xpm",
			&w, &h);
	game->p_left_img = mlx_xpm_file_to_image(game->mlx, "texture/left.xpm",
			&w, &h);
	game->p_right_img = mlx_xpm_file_to_image(game->mlx, "texture/right.xpm",
			&w, &h);
	game->wall_img = mlx_xpm_file_to_image(game->mlx, "texture/wall.xpm",
			&w, &h);
	game->collect_img = mlx_xpm_file_to_image(game->mlx, "texture/collect.xpm",
			&w, &h);
	game->exit_img = mlx_xpm_file_to_image(game->mlx, "texture/exit.xpm",
			&w, &h);
	game->enemy_img1 = mlx_xpm_file_to_image(game->mlx, "texture/enemy1.xpm",
			&w, &h);
	game->enemy_img2 = mlx_xpm_file_to_image(game->mlx, "texture/enemy2.xpm",
			&w, &h);
	game->floor_img = mlx_xpm_file_to_image(game->mlx, "texture/floor.xpm",
			&w, &h);
	game->enemy_img_curr = game->enemy_img1;
}

int	load_textures(t_game *game)
{
	int	w;
	int	h;

	w = 48;
	h = 48;
	load_images(game, w, h);
	if (!(game->p_up_img && game->p_down_img && game->p_left_img
			&& game->p_right_img && game->wall_img && game->collect_img
			&& game->exit_img && game->enemy_img1 && game->enemy_img2
			&& game->floor_img))
		return (0);
	return (1);
}

int	init_game(t_game *game)
{
	game->mlx = mlx_init();
	if (!game->mlx)
		exit_error(game, "Failed to initialize mlx");
	if (!check_display_size(*game))
		exit_error(game, "Map is too big for the screen");
	game->win = mlx_new_window(game->mlx, game->width * 48,
			game->height * 48, "SO_LONG");
	if (!game->win)
		exit_error(game, "Failed to create window");
	if (!load_textures(game))
		exit_error(game, "Failed to load textures");
	game->p_direct = 1;
	game->prev_tile = '0';
	game->moves = 0;
	render_map(game);
	return (1);
}
