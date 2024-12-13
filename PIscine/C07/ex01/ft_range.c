/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: redei-ma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 14:13:42 by redei-ma          #+#    #+#             */
/*   Updated: 2024/11/05 14:13:44 by redei-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_range(int min, int max)
{
	int	*dest;
	int	i;

	i = 0;
	if (min >= max)
		return (NULL);
	dest = (int *)malloc((max - min) * sizeof (int));
	if (!dest)
		return (NULL);
	while (max > min)
	{
		dest[i] = min;
		min++;
		i++;
	}
	dest[i] = '\0';
	return (dest);
}
/*
#include <stdio.h>
int main(void)
{
    int *range;
    int min = -71, max = 8;
    
    // Chiamata alla funzione ft_range
    range = ft_range(min, max);
    
    // Verifica se la memoria è stata allocata correttamente
    if (range != NULL)
    {
        // Stampa i valori dell'array
        for (int i = 0; i < max - min; i++)
        {
            printf("%d ", range[i]);
        }
        printf("\n");

        // Libera la memoria allocata
        free(range);
    }
    return 0;
}
*/
