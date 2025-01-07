/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: redei-ma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 10:20:17 by redei-ma          #+#    #+#             */
/*   Updated: 2024/10/21 10:20:22 by redei-ma         ###   ########.fr       */
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
