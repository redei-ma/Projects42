/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: redei-ma <redei-ma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 12:43:32 by redei-ma          #+#    #+#             */
/*   Updated: 2025/01/28 16:37:29 by redei-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	tidy_up(t_node **head_a)
{
	int	min;
	int	pos;
	int	i;
	int	size;

	i = 0;
	size = ft_lstsize_push(*head_a);
	min = ft_minor(*head_a);
	pos = pos_calc(*head_a, min, size);
	while (i < ft_abs(pos))
	{
		if (pos > 0)
			ft_ra(head_a);
		else
			ft_rra(head_a);
		i++;
	}
}

int	pos_calc(t_node	*head, int num, int size)
{
	int		i;
	t_node	*tmp;

	tmp = head;
	i = 0;
	while (tmp)
	{
		if (tmp->value == num && i <= size / 2)
			return (i);
		else if (tmp->value == num && i > size / 2)
			return (i - size);
		i++;
		tmp = tmp->next;
	}
	return (404);
}

void	set_weights(int *moves, int *tmp_moves)
{
	moves[0] = tmp_moves[0];
	moves[1] = tmp_moves[1];
	moves[2] = ft_abs(tmp_moves[2]);
}
