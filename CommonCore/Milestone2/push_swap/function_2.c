/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   function_2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: redei-ma <redei-ma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 12:42:02 by redei-ma          #+#    #+#             */
/*   Updated: 2025/01/24 13:11:37 by redei-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_pa(t_list **head_a, t_list **head_b)
{
	t_list	*tmp;

	if (*head_b)
	{
		tmp = *head_b;
		if ((*head_b)->next)
		{
			*head_b = (*head_b)->next;
			(*head_b)->prev = NULL;
		}
		else
		{
			(*head_b)->next = NULL;
			(*head_b)->prev = NULL;
			*head_b = NULL;
		}
		if (*head_a)
			(*head_a)->prev = tmp;
		tmp->next = *head_a;
		*head_a = tmp;
	}
	write(1, "pa\n", 3);
}

void	ft_pb(t_list **head_a, t_list **head_b)
{
	t_list	*tmp;

	if (*head_a)
	{
		tmp = *head_a;
		if ((*head_a)->next)
		{
			*head_a = (*head_a)->next;
			(*head_a)->prev = NULL;
		}
		else
			*head_a = NULL;
		if (*head_b)
			(*head_b)->prev = tmp;
		tmp->next = *head_b;
		*head_b = tmp;
	}
	write(1, "pb\n", 3);
}
