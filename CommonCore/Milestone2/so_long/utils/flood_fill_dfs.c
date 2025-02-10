/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill_dfs.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: redei-ma <redei-ma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 16:33:35 by redei-ma          #+#    #+#             */
/*   Updated: 2025/02/10 17:45:49 by redei-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

bool	is_target(char c, char *target)
{
	while (*target)
	{
		if (c == *target)
			return (true);
		target++;
	}
	return (false);
}

void	fill(char **tab, t_point size, t_point current, char *target)
{
	if ((current.y < 0) || (current.x < 0) || (current.y >= size.y)
		|| (current.x >= size.x)
		|| !is_target(tab[current.y][current.x], target))
		return ;
	tab[current.y][current.x] = '1';
	fill(tab, size, (t_point){current.x - 1, current.y}, target);
	fill(tab, size, (t_point){current.x + 1, current.y}, target);
	fill(tab, size, (t_point){current.x, current.y - 1}, target);
	fill(tab, size, (t_point){current.x, current.y + 1}, target);
}

void	flood_fill_dfs(char **tab, t_point size, t_point begin, char *target)
{
	fill(tab, size, begin, target);
}
