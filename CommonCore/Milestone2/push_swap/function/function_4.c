/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   function_4.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: redei-ma <redei-ma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 12:42:02 by redei-ma          #+#    #+#             */
/*   Updated: 2025/01/28 15:51:27 by redei-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_rra(t_node **head_a)
{
	t_node	*tmp;

	if ((*head_a) && (*head_a)->next)
	{
		tmp = *head_a;
		while (tmp->next != NULL)
			tmp = tmp->next;
		tmp->prev->next = NULL;
		tmp->prev = NULL;
		tmp->next = *head_a;
		(*head_a)->prev = tmp;
		*head_a = tmp;
		write(1, "rra\n", 4);
	}
}

void	ft_rrb(t_node **head_b)
{
	t_node	*tmp;

	if ((*head_b) && (*head_b)->next)
	{
		tmp = *head_b;
		while (tmp->next != NULL)
			tmp = tmp->next;
		tmp->prev->next = NULL;
		tmp->prev = NULL;
		tmp->next = *head_b;
		(*head_b)->prev = tmp;
		*head_b = tmp;
		write(1, "rrb\n", 4);
	}
}

void	ft_rrr(t_node **head_a, t_node **head_b)
{
	t_node	*tmp;

	if ((*head_a) && (*head_a)->next && (*head_b) && (*head_b)->next)
	{
		tmp = *head_a;
		while (tmp->next != NULL)
			tmp = tmp->next;
		tmp->prev->next = NULL;
		tmp->prev = NULL;
		tmp->next = *head_a;
		(*head_a)->prev = tmp;
		*head_a = tmp;
		tmp = *head_b;
		while (tmp->next != NULL)
			tmp = tmp->next;
		tmp->prev->next = NULL;
		tmp->prev = NULL;
		tmp->next = *head_b;
		(*head_b)->prev = tmp;
		*head_b = tmp;
		write(1, "rrr\n", 4);
	}
}
