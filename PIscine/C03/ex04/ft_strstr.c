/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: redei-ma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 09:43:38 by redei-ma          #+#    #+#             */
/*   Updated: 2024/10/29 09:48:08 by redei-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>

char	*ft_strstr(char *str, char *to_find)
{
	int	temp;

	if (!*to_find)
		return (str);
	while (*str)
	{
		temp = 0;
		while (str[temp] == to_find[temp])
		{
			if (to_find[temp + 1] == '\0')
				return (str);
			temp++;
		}
		str++;
	}
	return (0);
}
/*
int main(void)
{
	char *str = "ciao belQWfE72IO..li";
	char to_find[] = "QWE72IO.";
	char *result = ft_strstr(str, to_find);
	printf("%s", result);
	return 0;
}
*/
