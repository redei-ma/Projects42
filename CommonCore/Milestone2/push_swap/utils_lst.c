/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_lst.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: redei-ma <redei-ma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 13:30:38 by redei-ma          #+#    #+#             */
/*   Updated: 2025/01/24 14:25:35 by redei-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_freelst(t_list **head_a, t_list **head_b)
{
	t_list	*tmp;

	while (*head_a)
	{
		tmp = *head_a;
		*head_a = (*head_a)->next;
		free(tmp);
	}
	*head_a = NULL;
	while (*head_b)
	{
		tmp = *head_b;
		*head_b = (*head_b)->next;
		free(tmp);
	}
	*head_b = NULL;
	return (0);
}

t_list	*ft_nlstnew(char *av)
{
	int		content;
	t_list	*node;

	content = ft_natoi(av);
	if (content == 0 && !(av[0] == '0' && av[1] == '\0'))
		return (NULL);
	node = (t_list *)ft_calloc(1, sizeof(t_list));
	if (!node)
		return (NULL);
	node -> value = content;
	node -> next = NULL;
	node -> prev = NULL;
	return (node);
}

t_list	*ft_lstcreation(char **av)
{
	int		i;
	t_list	*node;
	t_list	*prev_node;
	t_list	*begin;

	i = 1;
	node = NULL;
	while (av[i])
	{
		prev_node = node;
		node = ft_nlstnew(av[i]);
		if (!node)
			return (NULL);
		if (i == 1)
			begin = node;
		else
		{
			node->prev = prev_node;
			prev_node->next = node;
		}
		i++;
	}
	return (begin);
}
