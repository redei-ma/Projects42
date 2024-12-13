/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: redei-ma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 10:27:53 by redei-ma          #+#    #+#             */
/*   Updated: 2024/10/29 10:28:01 by redei-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_iterative_power(int nb, int power)
{
	int	count;
	int	i;

	count = 0;
	i = nb;
	if (power < 0)
		return (0);
	else if (power == 0)
		return (1);
	else
	{
		while (count != power - 1)
		{
			nb = nb * i;
			count++;
		}
	}
	return (nb);
}
/*
int main()
{
int n = ft_iterative_power(3, -2);
printf("%d", n);
return 0;
}
*/
