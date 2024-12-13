/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: redei-ma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 12:00:46 by redei-ma          #+#    #+#             */
/*   Updated: 2024/10/31 12:00:49 by redei-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

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

int	check(char *str)
{
	int	i;
	int	j;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '-' || str[i] == '+')
			return (0);
		j = i + 1;
		while (str[j] != '\0')
		{
			if (str[i] == str[j])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

void	ft_putnbr_base(int nbr, char *base)
{
	int	b_len;

	b_len = ft_strlen(base);
	if (check(base) == 0 || b_len <= 1)
		return ;
	if (nbr == -2147483648)
	{
		ft_putnbr_base (nbr / b_len, base);
		nbr = -(nbr % b_len);
	}
	else if (nbr < 0)
	{
		write(1, "-", 1);
		nbr = -nbr;
	}
	if (nbr / b_len > 0)
	{
		ft_putnbr_base (nbr / b_len, base);
	}
	nbr = nbr % b_len;
	write(1, &base[nbr], 1);
	return ;
}
/*
int	main(void)
{
	char str[] = "0123456789";
	ft_putnbr_base(-2147483648, str);
	return 0;
}
*/
