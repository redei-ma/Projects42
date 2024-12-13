/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: redei-ma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 10:11:48 by redei-ma          #+#    #+#             */
/*   Updated: 2024/10/29 10:11:50 by redei-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>

int	ft_iterative_factorial(int nb)
{
	int	i;

	i = nb - 1;
	if (nb < 0)
		return (0);
	else if (nb == 0)
		return (1);
	else
	{
		while (i > 1)
		{
			nb = nb * i;
			i--;
		}
	}
	return (nb);
}
/*
int main(void)
{
int n = ft_iterative_factorial(6);
printf("&%d", n);
return 0;
}
*/
