/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: redei-ma <redei-ma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 13:30:38 by redei-ma          #+#    #+#             */
/*   Updated: 2025/01/28 16:37:03 by redei-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_freelst(t_node **head_a, t_node **head_b)
{
	t_node	*tmp;

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

t_node	*ft_nlstnew(char *av)
{
	int		content;
	t_node	*node;

	content = ft_natoi(av);
	if (content == 0 && !(av[0] == '0' && av[1] == '\0'))
		return (NULL);
	node = (t_node *)ft_calloc(1, sizeof(t_node));
	if (!node)
		return (NULL);
	node -> value = content;
	node -> next = NULL;
	node -> prev = NULL;
	return (node);
}

t_node	*ft_lstcreation(char **av)
{
	int		i;
	t_node	*node;
	t_node	*prev_node;
	t_node	*begin;

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

int	ft_lstsize_push(t_node *lst)
{
	int		count;
	t_node	*tmp;

	tmp = lst;
	count = 0;
	while (tmp)
	{
		tmp = tmp->next;
		count++;
	}
	return (count);
}
