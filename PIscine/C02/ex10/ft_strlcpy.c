/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: redei-ma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 19:47:52 by redei-ma          #+#    #+#             */
/*   Updated: 2024/10/27 19:48:16 by redei-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

unsigned int	ft_strlcpy(char *dest, char *src, unsigned int size)
{
	unsigned int	i;

	i = 0;
	if (size == 0)
	{
		while (src[i])
		{
			i++;
		}
		return (i);
	}
	while (i < size - 1 && src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	while (src[i])
	{
		i++;
	}
	return (i);
}
/*
int	main(void)
{
	int i;
	char dest[100] = "ciao belli";
	char src[] = "Hello";
	i = ft_strlcpy(dest, src, 2);
	printf("%u", i);
	return (0);
}
*/
