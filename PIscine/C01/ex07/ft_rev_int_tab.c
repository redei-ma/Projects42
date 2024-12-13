/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_int_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: redei-ma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 10:44:23 by redei-ma          #+#    #+#             */
/*   Updated: 2024/10/21 10:45:43 by redei-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	ft_rev_int_tab(int *tab, int size)
{
	int	i;
	int	j;
	int	app;

	i = 0;
	j = size - 1;
	while (size / 2 > i)
	{
		app = tab[i];
		tab[i] = tab[j];
		tab[j] = app;
		j--;
		i ++;
	}
}

int	main(void)
{
	int	arr[5] = {1, 2, 3, 4, 5};
	ft_rev_int_tab(arr, 5);
	for (int i = 0; i < 5; i++)
		printf("%d", arr[i]);
	return 0;
}

