/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_div_mod.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: redei-ma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/20 16:24:42 by redei-ma          #+#    #+#             */
/*   Updated: 2024/10/20 16:24:45 by redei-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <unistd.h>

void	ft_ultimate_div_mod(int *a, int *b)
{
	int	result;
	int	rest;

	result = *a / *b;
	rest = *a % *b;
	*a = result;
	*b = rest;
}
/*
int main()
{
	int a = 7;
	int b = 3;	
	ft_ultimate_div_mod(&a, &b);
	char p;
	p = a + 48;
	write(1, &p, 1);
	p = b + 48;
	write(1, &p, 1);
	return 0;
}
*/
