/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: redei-ma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 09:28:23 by redei-ma          #+#    #+#             */
/*   Updated: 2024/11/06 09:28:26 by redei-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_strlen(char *str)
{
	int	n;

	n = 0;
	while (str[n] != '\0')
		n++;
	return (n);
}

char	*ft_strcat(char *dest, char *src)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (dest[i] != '\0')
		i++;
	while (src[j] != '\0')
	{
		dest[i + j] = src[j];
		j++;
	}
	dest[i + j] = '\0';
	return (dest);
}

int	*check(int size, int *n, char *sep)
{
	if (size == 0)
		*n = 0;
	else
		*n = *n + ((size - 1) * ft_strlen(sep));
	return (n);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	char	*dest;
	int		j;
	int		n;

	j = 0;
	n = 0;
	while (j != size)
	{
		n = n + ft_strlen(strs[j]);
		j++;
	}
	check(size, &n, sep);
	dest = (char *)malloc(n * sizeof(char) + 1);
	dest[0] = '\0';
	j = 0;
	while (j != size)
	{
		ft_strcat(dest, strs[j]);
		if (j + 1 != size)
			ft_strcat(dest, sep);
		j++;
	}
	return (dest);
}
/*
#include <stdio.h>
int main(void)
{
    char *strs[] = {"Hello", "world", "from", "ChatGPT"};
    char *sep = "%.";
    int size = sizeof(strs) / sizeof(strs[0]);

    char *result = ft_strjoin(size, strs, sep);
    if (result == NULL)
    {
        printf("Memory allocation failed\n");
        return 1;
    }

    printf("Joined string: '%s'\n", result);
    free(result); // Don't forget to free the allocated memory
    return 0;
}
*/
