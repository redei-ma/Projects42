/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: redei-ma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 10:37:30 by redei-ma          #+#    #+#             */
/*   Updated: 2024/10/28 10:49:15 by redei-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putstr_non_printable(char *str)
{
	int		i;
	char	a;
	char	b;
	char	c;

	i = 0;
	c = 92;
	while (str[i] != '\0')
	{
		if (str[i] < 32 || str[i] == 127)
		{
			a = (str[i] / 16) + 48;
			b = (str[i] % 16);
			if (b <= 9)
				b += 48;
			else
				b += 87;
			write(1, &c, 1);
			write(1, &a, 1);
			write(1, &b, 1);
		}
		else
			write(1, &str[i], 1);
		i++;
	}
}
/*
int main(void)
{
	char str[] = "salut, co\nva";
	ft_putstr_non_printable(str);
}
*/
