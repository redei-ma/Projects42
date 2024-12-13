/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   funct2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anacotti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/03 23:01:50 by anacotti          #+#    #+#             */
/*   Updated: 2024/11/03 23:01:57 by anacotti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include "functions.h"

void	search_one(char *dct, char *temp_arr, int pos)
{
	int	x;

	x = 0;
	while (dct[x] != '\0')
	{
		if (dct[x] == temp_arr[pos] && dct[x + 1] == ':')
		{
			drop(&dct[x + 3]);
			break ;
		}
		x++;
	}
}

int	search_multi(char *dct, char *temp_arr)
{
	int	x;
	int	y;

	x = 0;
	while (dct[x] != '\0')
	{
		y = 0;
		if (dct[x] == temp_arr[0])
		{
			x++;
			y++;
			while (dct[x] == temp_arr[y])
			{
				x++;
				y++;
			}
			if (temp_arr[y] == '\0' && dct[x] == ':')
			{
				drop(&dct[x + 2]);
				return (0);
			}
		}
		x++;
	}
	return (0);
}

void	hundreds(char *dct, char *temp_arr)
{
	int		n;
	int		x;
	char	temp_tt[2];

	n = 0;
	x = 0;
	search_one(dct, temp_arr, 0);
	search_multi(dct, "100");
	if (temp_arr[1] == '1')
	{
		temp_tt[0] = temp_arr[1];
		temp_tt[1] = temp_arr[2];
		search_multi(dct, temp_tt);
	}
	else
	{
		if (temp_arr[1] != '0')
		{
			temp_tt[0] = temp_arr[1];
			temp_tt[1] = '0';
			search_multi(dct, temp_tt);
			if (temp_arr[2] != '0')
				search_one(dct, temp_arr, 2);
		}
	}
}

void	tens(char *dct, char *temp_arr)
{
	char	temp_tt[3];

	temp_tt[2] = '\0';
	if (temp_arr[1] == '1')
	{
		temp_tt[0] = temp_arr[1];
		temp_tt[1] = temp_arr[2];
		search_multi(dct, temp_tt);
	}
	else
	{
		temp_tt[0] = temp_arr[1];
		temp_tt[1] = '0';
		search_multi(dct, temp_tt);
		if (temp_arr[2] != '0')
			search_one(dct, temp_arr, 2);
	}
}
