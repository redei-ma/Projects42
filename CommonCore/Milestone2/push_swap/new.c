/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: redei-ma <redei-ma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 15:21:10 by redei-ma          #+#    #+#             */
/*   Updated: 2025/01/24 19:02:48 by redei-ma         ###   ########.fr       */
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
	int		i;
	int		size_a;
	t_list	*tmp_a;

	size_a = ft_lstsize(head_a);
	i = 0;
	tmp_a = head_a;
	while (tmp_a)
	{
		if (tmp_a->next)
		{
			if (val_b > tmp_a->value && val_b < tmp_a->next->value)
			{
				weight = pos_calc(head_a, tmp_a->next->value, size_a);
				break ;
			}
		}
		else if (val_b > tmp_a->value && val_b < head_a->value)
		{
			weight = pos_calc(head_a, head_a->value, size_a);
			break ;
		}
		tmp_a = tmp_a->next;
	}
	if (tmp_a == NULL)
		weight = pos_calc(head_a, ft_minor(head_a), size_a);
	return (weight);
}

void	ft_algo(t_list **head_a, t_list **head_b)
{
	int		moves[3];
	int		i;
	// int		size_b;
	t_list	*tmp_b;

	tmp_b = *head_b;
	i = 0;
	moves[2] = -1;
	// size_b = ft_lstsize(head_b);
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

void	set_weights(int *moves, int *tmp_moves)
{
		moves[0] = tmp_moves[0];
		moves[1] = tmp_moves[1];
		moves[2] = ft_abs(tmp_moves[2]);
}