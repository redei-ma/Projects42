/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   function_1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: redei-ma <redei-ma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 12:42:02 by redei-ma          #+#    #+#             */
/*   Updated: 2025/01/24 13:11:02 by redei-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sa(t_list **head_a)
{
	int	tmp;

	if ((*head_a) && (*head_a)->next)
	{
		tmp = (*head_a)->value;
		(*head_a)->value = (*head_a)->next->value;
		(*head_a)->next->value = tmp;
		write(1, "sa\n", 3);
	}
}

void	ft_sb(t_list **head_b)
{
	int	tmp;

	if ((*head_b) && (*head_b)->next)
	{
		tmp = (*head_b)->value;
		(*head_b)->value = (*head_b)->next->value;
		(*head_b)->next->value = tmp;
		write(1, "sb\n", 3);
	}
}

void	ft_ss(t_list **head_a, t_list **head_b)
{
	int	tmp;

	if ((*head_a) && (*head_a)->next && (*head_b) && (*head_b)->next)
	{
		tmp = (*head_a)->value;
		(*head_a)->value = (*head_a)->next->value;
		(*head_a)->next->value = tmp;
		tmp = (*head_b)->value;
		(*head_b)->value = (*head_b)->next->value;
		(*head_b)->next->value = tmp;
		write(1, "ss\n", 3);
	}
}
