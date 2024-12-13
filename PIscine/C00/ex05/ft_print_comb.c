/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: redei-ma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 18:08:24 by redei-ma          #+#    #+#             */
/*   Updated: 2024/10/17 10:10:47 by redei-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	stampa(int n1, int n2, int n3)
{
	char	a;

	if (n1 != n2 && n2 != n3 && n1 != n3)
	{
		if (n1 < n2 && n2 < n3)
		{
			a = n1 + 48;
			write(1, &a, 1);
			a = n2 + 48;
			write(1, &a, 1);
			a = n3 + 48;
			write(1, &a, 1);
			if (n1 != 7)
			{
				write(1, ", ", 2);
			}
		}
	}
}

void	ft_print_comb(void)
{
	int	n1;
	int	n2;
	int	n3;

	n1 = 0;
	n2 = 1;
	n3 = 2;
	while (n1 <= 7)
	{
		while (n2 <= 8)
		{
			while (n3 <= 9)
			{
				stampa(n1, n2, n3);
				n3++;
			}
			n3 = 0;
			n2++;
		}
		n2 = 0;
		n1++;
	}
}

int	main(void)
{
	ft_print_comb();
}
