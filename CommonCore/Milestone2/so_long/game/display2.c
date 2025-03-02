/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: redei-ma <redei-ma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 19:10:38 by redei-ma          #+#    #+#             */
/*   Updated: 2025/03/02 15:19:53 by redei-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	put_player(t_game *game, int i, int j)
{
	if (game->p_direct == 0)
		mlx_put_image_to_window(game->mlx, game->win, game->p_up_img,
			j * 48, i * 48);
	else if (game->p_direct == 1)
		mlx_put_image_to_window(game->mlx, game->win, game->p_down_img,
			j * 48, i * 48);
	else if (game->p_direct == 2)
		mlx_put_image_to_window(game->mlx, game->win, game->p_left_img,
			j * 48, i * 48);
	else if (game->p_direct == 3)
		mlx_put_image_to_window(game->mlx, game->win, game->p_right_img,
			j * 48, i * 48);
}

int	check_display_size(t_game game)
{
	int	screen_width;
	int	screen_height;

	mlx_get_screen_size(game.mlx, &screen_width, &screen_height);
	if (game.width * 48 > screen_width || game.height * 48 > screen_height)
		return (0);
	else
		return (1);
}
