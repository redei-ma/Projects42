/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: redei-ma <redei-ma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/02 15:10:42 by redei-ma          #+#    #+#             */
/*   Updated: 2025/03/02 15:30:12 by redei-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	exit_error(t_game *game, char *msg)
{
	clear_libx(game);
	free_all(game);
	ft_printfd(2, "Error\n%s\n", msg);
	exit(1);
}

void	clear_libx(t_game *game)
{
	if (game->p_up_img)
		mlx_destroy_image(game->mlx, game->p_up_img);
	if (game->p_down_img)
		mlx_destroy_image(game->mlx, game->p_down_img);
	if (game->p_left_img)
		mlx_destroy_image(game->mlx, game->p_left_img);
	if (game->p_right_img)
		mlx_destroy_image(game->mlx, game->p_right_img);
	if (game->wall_img)
		mlx_destroy_image(game->mlx, game->wall_img);
	if (game->collect_img)
		mlx_destroy_image(game->mlx, game->collect_img);
	if (game->exit_img)
		mlx_destroy_image(game->mlx, game->exit_img);
	if (game->enemy_img1)
		mlx_destroy_image(game->mlx, game->enemy_img1);
	if (game->enemy_img2)
		mlx_destroy_image(game->mlx, game->enemy_img2);
	if (game->floor_img)
		mlx_destroy_image(game->mlx, game->floor_img);
	if (game->win)
		mlx_destroy_window(game->mlx, game->win);
	if (game->mlx)
		mlx_destroy_display(game->mlx);
}

int	close_game(t_game *game)
{
	clear_libx(game);
	free_all(game);
	exit(0);
}
