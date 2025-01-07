/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   funct1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anacotti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/03 23:01:27 by anacotti          #+#    #+#             */
/*   Updated: 2024/11/03 23:01:33 by anacotti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include "functions.h"

int	str_len(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

int	file_dimension(void)
{
	int		f_open;
	int		n_bytes_r;
	int		n_bytes_r2;
	char	buffer[100];

	n_bytes_r = 0;
	n_bytes_r2 = 0;
	f_open = open("numbers.dict", O_RDONLY);
	if (f_open == -1 || n_bytes_r2 == -1) //errore nel controllaare r2 qua perche e per frza 0
	{
		write(2, "DictError\n", 10);
		return (0);
	}
	n_bytes_r = read(f_open, buffer, 100);
	while (n_bytes_r > 0)
	{
		n_bytes_r = read(f_open, buffer, 100);
		n_bytes_r2 += n_bytes_r;
	}
	close(f_open);
	return (n_bytes_r2);
}

char	*put_dictionary(void)
{
	unsigned int	fd;
	unsigned int	n_bytes_r;
	int				f_open;
	char			*dct;

	fd = file_dimension();
	dct = (char *)malloc(fd + 1 * sizeof(char));
	f_open = open("numbers.dict", O_RDONLY);
	if (f_open == -1 || dct == NULL)
	{
		write(2, "DictError\n", 10);
		return (NULL);
	}
	n_bytes_r = read(f_open, dct, fd);
	if (n_bytes_r != fd)
	{
		write(2, "DictError\n", 10);
		close(f_open);
		return (NULL);
	}
	close(f_open);
	dct[fd] = '\0';
	return (dct);
}

void	drop(char *dct)
{
	int	i;

	i = 0;
	while (dct[i] == ' ')
		i++;
	while (dct[i] != '\n' && dct[i] != '\0')
	{
		write(1, &dct[i], 1);
		i++;
	}
	write(1, " ", 1);
}
