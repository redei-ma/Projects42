/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algoritmo_1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: redei-ma <redei-ma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 12:51:29 by redei-ma          #+#    #+#             */
/*   Updated: 2025/01/24 19:37:29 by redei-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_weight_b(t_list *head_b, int i)
{
	int		weight;
	int		size_b;

	size_b = ft_lstsize(head_b) + i;
	if (i <= size_b / 2)
		weight = i;
	else if (i < size_b)
		weight = i - size_b;
	return (weight);
}

int	ft_weight_a(t_list *head_a, int val_b)
{
	int		weight;
	t_list	*tmp_a;

	tmp_a = head_a;
	while (tmp_a)
	{
		if (tmp_a->next)
		{
			if (val_b > tmp_a->value && val_b < tmp_a->next->value)
			{
				weight = pos_calc(head_a, tmp_a->next->value,
						ft_lstsize(head_a));
				break ;
			}
		}
		else if (val_b > tmp_a->value && val_b < head_a->value)
		{
			weight = pos_calc(head_a, head_a->value, ft_lstsize(head_a));
			break ;
		}
		tmp_a = tmp_a->next;
	}
	if (tmp_a == NULL)
		weight = pos_calc(head_a, ft_minor(head_a), ft_lstsize(head_a));
	return (weight);
}

void	ft_algo(t_list **head_a, t_list **head_b)
{
	int		moves[3];
	int		i;
	t_list	*tmp_b;

	tmp_b = *head_b;
	i = 0;
	moves[2] = -1;
	while (tmp_b)
	{
		ft_weight_tot(head_a, &tmp_b, moves, i);
		i++;
		tmp_b = tmp_b->next;
	}
	make_move(moves, head_a, head_b);
}

void	ft_weight_tot(t_list **head_a, t_list **head_b, int *moves, int i)
{
	int	tmp_moves[3];

	tmp_moves[0] = ft_weight_a(*head_a, (*head_b)->value);
	tmp_moves[1] = ft_weight_b(*head_b, i);
	if (tmp_moves[0] >= 0 && tmp_moves[1] >= 0)
	{
		if (tmp_moves[0] > tmp_moves[1])
			tmp_moves[2] = tmp_moves[0];
		else
			tmp_moves[2] = tmp_moves[1];
	}
	else if (tmp_moves[0] < 0 && tmp_moves[1] < 0)
	{
		if (tmp_moves[0] < tmp_moves[1])
			tmp_moves[2] = tmp_moves[0];
		else
			tmp_moves[2] = tmp_moves[1];
	}
	else
		tmp_moves[2] = ft_abs(tmp_moves[0]) + ft_abs(tmp_moves[1]);
	if (ft_abs(tmp_moves[2]) < moves[2] || moves[2] == -1)
		set_weights(moves, tmp_moves);
}
