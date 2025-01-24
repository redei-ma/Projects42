/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: redei-ma <redei-ma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 13:22:53 by redei-ma          #+#    #+#             */
/*   Updated: 2025/01/24 19:32:13 by redei-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	make_move(int *moves, t_list **head_a, t_list **head_b)
{
	while (moves[0] != 0 && moves[1] != 0)
		move_double(moves, head_a, head_b);
	while (moves[0] != 0 || moves[1] != 0)
		move_single(moves, head_a, head_b);
	ft_pa(head_a, head_b);
}

void	move_double(int *moves, t_list **head_a, t_list **head_b)
{
	if (moves[0] > 0 && moves[1] > 0)
	{
		ft_rr(head_a, head_b);
		moves[0]--;
		moves[1]--;
	}
	else if (moves[0] < 0 && moves[1] < 0)
	{
		ft_rrr(head_a, head_b);
		moves[0]++;
		moves[1]++;
	}
	else
		move_single(moves, head_a, head_b);
}

void	move_single(int *moves, t_list **head_a, t_list **head_b)
{
	if (moves[0] > 0)
	{
		ft_ra(head_a);
		moves[0]--;
	}
	else if (moves[0] < 0)
	{
		ft_rra(head_a);
		moves[0]++;
	}
	else if (moves[1] > 0)
	{
		ft_rb(head_b);
		moves[1]--;
	}
	else if (moves[1] < 0)
	{
		ft_rrb(head_b);
		moves[1]++;
	}
}
