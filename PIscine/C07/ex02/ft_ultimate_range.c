/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: redei-ma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 17:07:12 by redei-ma          #+#    #+#             */
/*   Updated: 2024/11/05 17:07:13 by redei-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_ultimate_range(int **range, int min, int max)
{
	int	i;
	int	size;

	i = 0;
	if (min >= max)
	{
		*range = NULL;
		return (0);
	}
	size = max - min;
	*range = (int *)malloc(size * sizeof (int));
	if (!*range)
		return (-1);
	while (max > min)
	{
		(*range)[i] = min;
		min++;
		i++;
	}
	return (size);
}
/*
#include <stdio.h>

int main()
{
    int *range;
    int size;
    int min, max;
    int i;

    // Test con vari valori di min e max
    min = 3;
    max = 10;
    size = ft_ultimate_range(&range, min, max);
    if (size != -1 && range != NULL)
    {
        printf("Range from %d to %d (size %d):\n", min, max, size);
        for (i = 0; i < size; i++)
        {
            printf("%d ", range[i]);
        }
        printf("\n");
        free(range);  // Libera la memoria
    }
    else
    {
        printf("Errore nell'allocazione della memoria.\n");
    }

    // Test con min maggiore di max
    min = 10;
    max = 3;
    size = ft_ultimate_range(&range, min, max);
    if (size == 0)
    {
        printf("Nessun range da %d a %d\n", min, max);
    }

    // Test con min uguale a max
    min = 5;
    max = 5;
    size = ft_ultimate_range(&range, min, max);
    if (size == 0)
    {
        printf("Nessun range da %d a %d\n", min, max);
    }

    return 0;
}
*/
