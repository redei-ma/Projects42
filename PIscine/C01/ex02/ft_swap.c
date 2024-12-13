/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: redei-ma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/20 14:45:32 by redei-ma          #+#    #+#             */
/*   Updated: 2024/10/20 14:45:48 by redei-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <unistd.h>

void	ft_swap(int *a, int *b)
{
	int	c;

	c = *a;
	*a = *b;
	*b = c;
}
/*
int main()
{
	int n1;
	int n2;
	n1 = 6;
	n2 = 2;
	ft_swap(&n1, &n2);
	char a;
	a = n1 + 48;
	write(1, &a, 1);
	a = n2 + 48;
	write(1, &a, 1);
}
*/
