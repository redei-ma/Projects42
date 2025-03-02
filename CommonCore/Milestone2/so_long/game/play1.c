/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   play1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: redei-ma <redei-ma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 18:07:42 by redei-ma          #+#    #+#             */
/*   Updated: 2025/03/02 15:28:17 by redei-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	make_move(t_game *game, int new_x, int new_y)
{
	if (game->map[new_y][new_x] == 'C')
		game->collectibles--;
	if (game->map[new_y][new_x] == 'F')
	{
		ft_printf("You lose!\n");
		close_game(game);
	}
	if (game->map[new_y][new_x] == 'E' && game->collectibles == 0)
	{
		ft_printf("You won! Moves: %d\n", game->moves + 1);
		close_game(game);
	}
	if (game->map[new_y][new_x] == 'E' && game->collectibles != 0)
		game->prev_tile = 'E';
	if (game->prev_tile == 'E' && game->map[new_y][new_x] != 'E')
	{
		game->map[game->player_y][game->player_x] = 'E';
		game->prev_tile = game->map[new_y][new_x];
	}
	else
		game->map[game->player_y][game->player_x] = '0';
}

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
