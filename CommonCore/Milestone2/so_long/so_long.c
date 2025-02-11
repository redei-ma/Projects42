/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: redei-ma <redei-ma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 12:52:24 by redei-ma          #+#    #+#             */
/*   Updated: 2025/02/11 13:11:31 by redei-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int ac, char **av)
{
	t_sprite	sprite;
	t_game		*game;

	if (ac != 2)
		return (ft_printf("Error\nBad number argument\n"));
	game = ft_calloc(1, sizeof(t_game));
	if (!game)
		return (ft_printf("Error\nFailed to allocate memory\n"));
	game->map = parsing_map(av[1], &sprite, game);
	if (!game->map)
		return (free(game), ft_printf("Error\nCan't take map\n"));
	if (!init_game(game))
		return (free_all(game),
			ft_printf("Error\nFailed to initialize game\n"));
	start_game(game);
}
