/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_map2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: redei-ma <redei-ma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 13:17:18 by redei-ma          #+#    #+#             */
/*   Updated: 2025/03/01 19:50:58 by redei-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	count_elements_filled(char **map)
{
	int		i;
	int		j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'C')
				return (0);
			else if (map[i][j] == 'E')
				return (0);
			else if (map[i][j] == 'P')
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	count_elements(char **map, t_sprite *sprite)
{
	int		i;
	int		j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'C')
				sprite->collect++;
			else if (map[i][j] == 'E')
				sprite->exit++;
			else if (map[i][j] == 'P')
				sprite->player++;
			else if (!(map[i][j] == '1' || map[i][j] == '0'
					|| map[i][j] == '\n' || map[i][j] == 'F'))
				return (0);
			j++;
		}
		i++;
	}
	if (sprite->collect < 1 || sprite->exit != 1 || sprite->player != 1)
		return (0);
	return (1);
}

int	check_surrounded(char **map)
{
	int	l;
	int	m;

	l = 1;
	m = 0;
	while (map[0][m])
	{
		if (map[0][m] != '1' && map[0][m] != '\n')
			return (0);
		m++;
	}
	while (map[l + 1])
	{
		if (map[l][0] != '1' || map[l][m - 2] != '1')
			return (0);
		l++;
	}
	m = 0;
	while (map[l][m])
	{
		if (map[l][m] != '1' && map[l][m] != '\n')
			return (0);
		m++;
	}
	return (1);
}

int	check_size(char **map, int i, int j)
{
	int	k;

	if (i < 3 || j < 3 || i == j)
		return (0);
	i = 0;
	while (map[i])
	{
		k = 0;
		while (map[i][k] && map[i][k] != '\n')
			k++;
		if (k != j)
			return (0);
		i++;
	}
	return (1);
}

char	**fill_map(char **map, int *i, int *j)
{
	int	size;

	while (map[*i + 1])
	{
		*j = 0;
		while (map[*i][*j])
			(*j)++;
		(*i)++;
	}
	size = *j;
	*j = 0;
	while (map[*i][*j])
		(*j)++;
	if (*j < size)
	{
		map[*i] = ft_realloc(map[*i], (*j + 1) * sizeof(char),
				(*j + 2) * sizeof(char));
		if (!map[*i])
			return (NULL);
		map[*i][*j] = '\n';
	}
	else
		*j -= 1;
	*i += 1;
	return (map);
}
