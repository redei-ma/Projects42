/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush-02_GOOD.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anacotti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/03 22:58:44 by anacotti          #+#    #+#             */
/*   Updated: 2024/11/03 22:58:52 by anacotti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include "functions.h"

int	main(int argc, char *argv[])
{
	char	*dct;

	dct = put_dictionary();
	if (argc < 2 || dct == NULL)
	{
		write(2, "Error\n", 6);
		return (1);
	}
	if (argc == 2)
		build_ntc(dct, argv[1]);
	if (argc == 3)
		build_ntc(dct, argv[2]);
	free (dct);
	return (0);
}
