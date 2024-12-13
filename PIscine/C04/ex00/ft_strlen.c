/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: redei-ma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 10:14:13 by redei-ma          #+#    #+#             */
/*   Updated: 2024/10/28 10:23:40 by redei-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <unistd.h>

int	ft_strlen(char *str)
{
	int	n;

	n = 0;
	while (*str != '\0')
	{
		n++;
		str++;
	}
	return (n);
}
/*
int	main(void)
{
	char	*str;
	
	str = "Ciaooo";
	ft_strlen(str);
	char	a;
	a = ft_strlen(str) + 48;
	write(1, &a, 1);
	return 0;
}
*/
