/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: redei-ma <redei-ma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 16:42:13 by redei-ma          #+#    #+#             */
/*   Updated: 2024/12/05 17:00:35 by redei-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	t_list		*tmp;
	int	count;

	tmp = lst;
	count = 0;
	while (lst)
	{
		tmp = tmp->next;
		count++;
	}
	return (count);
}
