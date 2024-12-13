/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: redei-ma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 16:36:48 by redei-ma          #+#    #+#             */
/*   Updated: 2024/10/23 16:36:51 by redei-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	is_alphanumeric(char *str, int i)
{
	if ((str[i - 1] >= 'A' && str[i - 1] <= 'Z')
		|| (str[i - 1] >= 'a' && str[i - 1] <= 'z')
		|| (str[i - 1] >= '0' && str[i - 1] <= '9'))
	{
		return (1);
	}
	else if (!(str[i - 1] >= 'A' && str[i] <= 'Z')
		|| !(str[i - 1] >= 'a' && str[i - 1] <= 'z')
		|| !(str[i - 1] >= '0' && str[i - 1] <= '9'))
	{
		return (0);
	}
	return (0);
}

char	*ft_strcapitalize(char *str)
{
	int	i;

	if (str[0] >= 'a' && str[0] <= 'z')
		str[0] -= 32;
	i = 1;
	while (str[i] != '\0')
	{
		if (str[i] >= 'a' && str[i] <= 'z')
		{
			if (is_alphanumeric(str, i) == 0)
			{
				str[i] -= 32;
			}
		}
		if (str[i] >= 'A' && str[i] <= 'Z')
		{
			if (is_alphanumeric(str, i) == 1)
			{
				str[i] += 32;
			}
		}
		i++;
	}
	return (str);
}
/*
int main(void)
{
    char    str[] = {"saLut, comMet tu VAS ? 42mots; cinquante+et+un"};
    printf("Prima la stringa è: %s \n", str);
	ft_strcapitalize(str);
    printf("Dopo la stringa è: %s", str);
	return 0;
}
*/
