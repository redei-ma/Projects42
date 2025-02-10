/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: redei-ma <redei-ma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 18:07:42 by redei-ma          #+#    #+#             */
/*   Updated: 2025/02/10 17:04:54 by redei-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	move_player(t_game *game, int dx, int dy)
{
	int	new_x;
	int	new_y;

	new_x = game->player_x + dx;
	new_y = game->player_y + dy;
	if (game->map[new_y][new_x] == '1')
		return ;
	make_move(game, new_x, new_y);
	game->map[new_y][new_x] = 'P';
	game->moves++;
	ft_printf("Moves: %d\n", game->moves);
	game->player_x = new_x;
	game->player_y = new_y;
	if (dx == 1)
		game->p_direct = 3;
	else if (dx == -1)
		game->p_direct = 2;
	else if (dy == 1)
		game->p_direct = 1;
	else if (dy == -1)
		game->p_direct = 0;
	render_map(game);
}

int	key_press(int keycode, t_game *game)
{
	if (keycode == 65307)
		close_game(game);
	else if (keycode == 'w')
		move_player(game, 0, -1);
	else if (keycode == 's')
		move_player(game, 0, 1);
	else if (keycode == 'a')
		move_player(game, -1, 0);
	else if (keycode == 'd')
		move_player(game, 1, 0);
	return (0);
}

int	close_game(t_game *game)
{
	mlx_destroy_image(game->mlx, game->p_up_img);
	mlx_destroy_image(game->mlx, game->p_down_img);
	mlx_destroy_image(game->mlx, game->p_left_img);
	mlx_destroy_image(game->mlx, game->p_right_img);
	mlx_destroy_image(game->mlx, game->wall_img);
	mlx_destroy_image(game->mlx, game->collect_img);
	mlx_destroy_image(game->mlx, game->exit_img);
	mlx_destroy_image(game->mlx, game->enemy_img1);
	mlx_destroy_image(game->mlx, game->enemy_img2);
	mlx_destroy_image(game->mlx, game->floor_img);
	mlx_destroy_window(game->mlx, game->win);
	mlx_destroy_display(game->mlx);
	free_all(game);
	exit(0);
}

void	setup_hooks(t_game *game)
{
	mlx_hook(game->win, 17, 0, close_game, game);
	mlx_hook(game->win, 2, 1L << 0, key_press, game);
	mlx_loop_hook(game->mlx, animate_enemies, game);
}

void	start_game(t_game *game)
{
	setup_hooks(game);
	mlx_loop(game->mlx);
}
