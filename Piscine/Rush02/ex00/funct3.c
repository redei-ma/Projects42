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

int	traffic_light(char *dct, char temp_arr[])
{
	int	n;
	int	n_counter;

	n = 0;
	n_counter = 0;
	while (n < 3)
	{
		if (temp_arr[n] != '0')
			n_counter++;
		else if (temp_arr[n] == '0' && n_counter != 0)
			n_counter++;
		n++;
	}
	if (n_counter == 1)
		search_one(dct, temp_arr, 2);
	else if (n_counter == 2)
		tens(dct, temp_arr);
	else if (n_counter == 3)
		hundreds(dct, temp_arr);
	else
		return (1);
	return (0);
}

void	build_ntc(char *dct, char *argv)
{
	int		n_len;
	int		n_groups;
	int		n_round;
	char	temp_arr[3];
	int		y;
	int		flag;
	int		i;
	char	*zero_mac;
	int		c_zeros;
	int		zero_mac_size;

	i = 0;
	flag = 0;
	y = 0;
	n_round = 0;
	n_len = str_len(argv);
	while (i < 3)
	{
		temp_arr[i] = '0';
		i++;
	}
	i = 0;
	if (n_len % 3 == 0)
	{
		n_groups = n_len / 3;
		flag = 1;
	}
	else
		n_groups = (n_len / 3) + 1;
	if ((n_len - 1) % 3 != 0)
		i = 1;
	else
		i = 2;
	while (n_round < n_groups)
	{
		while (n_len % 3 != 0 && flag == 0 && i < 3)
		{
			temp_arr[i] = argv[y];
			i++;
			y++;
			n_len--;
		}
		i = 0;
		while ((n_len % 3 != 0 || flag == 1) && i < 3)
		{
			temp_arr[i] = argv[y];
			i++;
			y++;
		}
		c_zeros = traffic_light(dct, temp_arr);
		n_len = str_len(argv);
		flag = 1;
		if (n_groups != 1 && (n_groups - n_round) > 1 && c_zeros == 0)
		{
			i = 0;
			zero_mac_size = (n_groups - (n_round + 1)) * 3 + 1;
			zero_mac = (char *)malloc(zero_mac_size * sizeof(char));
			zero_mac[i] = '1';
			while (i < zero_mac_size - 1)
			{
				zero_mac[i] = '0';
				i++;
			}
			zero_mac[zero_mac_size - 1] = '\0';
			search_multi(dct, zero_mac);
			free(zero_mac);
			zero_mac = NULL;
		}
		i = 0;
		n_round++;
	}
}
