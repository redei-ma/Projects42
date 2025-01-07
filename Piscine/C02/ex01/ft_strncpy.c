/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: redei-ma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 20:09:13 by redei-ma          #+#    #+#             */
/*   Updated: 2024/10/21 20:09:14 by redei-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>

char	*ft_strncpy(char *dest, char *src, unsigned int n)
{
	unsigned int	i;

	i = 0;
	while (i < n && src[i] != '\0')
	{
		dest[i] = src[i];
		i ++;
	}
	while (i < n)
	{
		dest[i] = '\0';
		i++;
	}
	return (dest);
}
/*
int	main(void)
{
	char	src[7] = {"Ciao"};
	char	dest[7] = {"eeeeee"};
	printf("Prima: \n stringa src: %s \n stringa dest: %s \n", src, dest);
	ft_strncpy(dest, src, 3);
	printf("Dopo: \n stringa src: %s \n stringa dest: %s \n", src, dest);
	return 0;
}
*/
