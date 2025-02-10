/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_map3.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: redei-ma <redei-ma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 18:40:28 by redei-ma          #+#    #+#             */
/*   Updated: 2025/02/10 17:45:40 by redei-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	**copy_map(char **map, t_point size)
{
	int		i;
	char	**test_map;

	i = 0;
	test_map = (char **)ft_calloc(size.y + 1, sizeof(char *));
	if (!test_map)
		return (NULL);
	while (i < size.y)
	{
		test_map[i] = ft_strdup(map[i]);
		if (!test_map[i])
			return (free_map(test_map), NULL);
		i++;
	}
	return (test_map);
}

t_point	find_player(char **map, t_game *game)
{
	t_point	player;
	int		i;
	int		j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'P')
			{
				player.x = j;
				player.y = i;
			}
			j++;
		}
		i++;
	}
	game->player_x = player.x;
	game->player_y = player.y;
	return (player);
}
