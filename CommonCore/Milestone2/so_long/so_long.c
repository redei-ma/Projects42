/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: redei-ma <redei-ma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 12:52:24 by redei-ma          #+#    #+#             */
/*   Updated: 2025/03/01 20:03:21 by redei-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int ac, char **av)
{
	t_sprite	sprite;
	t_game		*game;
	int	screen_width;
	int	screen_height;

	if (ac != 2)
		return (ft_printfd(2, "Error\nBad number argument\n"));
	game = ft_calloc(1, sizeof(t_game));
	if (!game)
		return (ft_printfd(2, "Error\nFailed to allocate memory\n"));
	game->map = parsing_map(av[1], &sprite, game);
	if (!game->map)
		return (free(game), ft_printfd(2, "Error\nCan't take map\n"));
	if (!init_game(game))
		return (free_all(game),
			ft_printfd(2, "Error\nFailed to initialize game\n"));
	mlx_get_screen_size(game->mlx, &screen_width, &screen_height);//ciao
	if (game->width * 48 > screen_width || game->height * 48 > screen_height)
		return (free_all(game), ft_printfd(2, "Error\nMap too big"));
	start_game(game);
}
