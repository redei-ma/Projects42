/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_div_mod.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: redei-ma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/20 15:59:06 by redei-ma          #+#    #+#             */
/*   Updated: 2024/10/20 15:59:23 by redei-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <unistd.h>

void	ft_div_mod(int a, int b, int *div, int *mod)
{
	int	result;
	int	rest;

	result = a / b;
	rest = a % b;
	*div = result;
	*mod = rest;
}
/*
int main()
{
	int n1 = 8;
	int n2 = 9;
	ft_div_mod(7, 3, &n1, &n2);
	char a;
	a = n1 + 48;
	write(1, &a, 1);
	a = n2 + 48;
	write(1, &a, 1);
}
*/
