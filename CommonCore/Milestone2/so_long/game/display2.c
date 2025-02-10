/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: redei-ma <redei-ma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 19:10:38 by redei-ma          #+#    #+#             */
/*   Updated: 2025/02/10 16:31:09 by redei-ma         ###   ########.fr       */
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
