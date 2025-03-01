/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_map1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: redei-ma <redei-ma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 15:23:38 by redei-ma          #+#    #+#             */
/*   Updated: 2025/03/01 19:50:30 by redei-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	**check_valid_map(char **map, t_sprite *sprite, t_game *game)
{
	int		i;
	int		j;
	int		test;
	char	**test_map;
	t_point	size;

	i = 0;
	map = fill_map(map, &i, &j);
	if (!map)
		return (NULL);
	if (!(check_size(map, i, j) && check_surrounded(map)
			&& count_elements(map, sprite)))
		return (free_map(map), NULL);
	size = (t_point){j, i};
	test_map = copy_map(map, size);
	if (!test_map)
		return (free_map(map), NULL);
	flood_fill_dfs(test_map, size, find_player(map, game), "0PEC");
	test = count_elements_filled(test_map);
	free_map(test_map);
	if (test == 0)
		return (free_map(map), NULL);
	game->width = j;
	game->height = i;
	return (map);
}

char	**write_map(char **map, int *i, int fd)
{
	char	*line;

	line = get_next_line(fd);
	if (!line)
		return (free_map(map), NULL);
	while (line)
	{
		map[*i] = line;
		(*i)++;
		line = get_next_line(fd);
		if (*i >= 50 && line)
		{
			map = ft_realloc(map, (*i + 1) * sizeof(char *),
					(*i + 2) * sizeof(char *));
			if (!map)
				return (NULL);
		}
	}
	return (map);
}

int	check_extension(char *file)
{
	if (ft_strncmp(file + (ft_strlen(file) - 4), ".ber", 4) != 0)
		return (0);
	else
		return (1);
}

char	**take_map(char *file)
{
	char	**map;
	int		fd;
	int		i;

	if (check_extension(file) == 0)
		return (NULL);
	fd = open(file, O_RDONLY);
	if (fd < 0)
		return (NULL);
	map = (char **)ft_calloc(51, sizeof(char *));
	if (!map)
		return (close(fd), NULL);
	i = 0;
	map = write_map(map, &i, fd);
	if (!map)
		return (close(fd), NULL);
	if (i < 49)
	{
		map = ft_realloc(map, 51 * sizeof(char *),
				(i + 1) * sizeof(char *));
		if (!map)
			return (close(fd), NULL);
	}
	close(fd);
	return (map);
}

char	**parsing_map(char *file, t_sprite *sprite, t_game *game)
{
	char	**map;

	sprite->collect = 0;
	sprite->exit = 0;
	sprite->player = 0;
	map = take_map(file);
	if (!map)
		return (NULL);
	map = check_valid_map(map, sprite, game);
	if (!map)
		return (NULL);
	game->collectibles = sprite->collect;
	return (map);
}
