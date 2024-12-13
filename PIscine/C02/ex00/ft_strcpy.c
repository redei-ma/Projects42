/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: redei-ma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 18:42:51 by redei-ma          #+#    #+#             */
/*   Updated: 2024/10/21 18:42:55 by redei-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>

char	*ft_strcpy(char *dest, char *src)
{
	int	i;

	i = 0;
	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i ++;
	}
	if (src[i] == '\0')
		dest[i] = src[i];
	return (dest);
}
/*
int	main(void)
{
	char	src[5] = {"Ciao"};
	char	dest[5] = {};
	printf("Prima: \n stringa src: %s \n stringa dest: %s \n", src, dest);
	ft_strcpy(dest, src);
	printf("Dopo: \n stringa src: %s \n stringa dest: %s \n", src, dest);
	return 0;
}
*/
