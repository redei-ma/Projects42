/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   play2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: redei-ma <redei-ma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 16:41:51 by redei-ma          #+#    #+#             */
/*   Updated: 2025/03/02 15:28:08 by redei-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	print_moves(t_game *game)
{
	char	*moves_str;

	moves_str = ft_itoa(game->moves);
	mlx_string_put(game->mlx, game->win, 10, 10, 0x000000, "Moves: ");
	mlx_string_put(game->mlx, game->win, 100, 10, 0x000000, moves_str);
	free(moves_str);
}

int	animate_enemies(t_game *game)
{
	game->enemy_frame++;
	if (game->enemy_frame >= 10000)
	{
		if (game->enemy_img_curr == game->enemy_img1)
			game->enemy_img_curr = game->enemy_img2;
		else
			game->enemy_img_curr = game->enemy_img1;
		game->enemy_frame = 0;
		render_map(game);
	}
	print_moves(game);
	return (0);
}
