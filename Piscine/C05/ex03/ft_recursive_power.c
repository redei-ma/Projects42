/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursive_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: redei-ma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 12:01:52 by redei-ma          #+#    #+#             */
/*   Updated: 2024/10/29 12:01:54 by redei-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>

int	ft_recursive_power(int nb, int power)
{
	if (power < 0)
		return (0);
	else if (power == 0)
		return (1);
	else
	{
		if (power > 1)
			nb = nb * ft_recursive_power(nb, power - 1);
		return (nb);
	}
}
/*
int main()
{
int n = ft_recursive_power(6, 3);
printf("%d", n);
return 0;
}
*/
