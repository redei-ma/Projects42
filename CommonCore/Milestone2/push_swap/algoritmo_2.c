/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algoritmo_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: redei-ma <redei-ma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 12:43:32 by redei-ma          #+#    #+#             */
/*   Updated: 2025/01/24 15:22:38 by redei-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	tidy_up(t_list **head_a)
{
	int		min;
	int		pos;
	int		i;
	int		size;

	i = 0;
	size = ft_lstsize(*head_a);
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

/* int	*ft_weight_b(t_list *head_b)
{
	int		*weight;
	int		i;
	int		size;

	size = ft_lstsize(head_b);
	i = 0;
	weight = ft_calloc(size, sizeof(int));
	if (!weight)
		return (NULL);
	while (i <= size / 2)
	{
		weight[i] = i;
		i++;
	}
	while (i < size)
	{
		weight[i] = i - size;
		i++;
	}
	return (weight);
} */

/* int	*ft_weight_a(t_list *head_a, t_list *head_b)
{
	int		*weight;
	int		i;
	int		size_a;
	t_list	*tmp_a;
	t_list	*tmp_b;

	size_a = ft_lstsize(head_a);
	weight = (int *)ft_calloc(ft_lstsize(head_b), sizeof(int));
	if (!weight)
		return (NULL);
	tmp_b = head_b;
	i = 0;
	while (tmp_b)
	{
		tmp_a = head_a;
		while (tmp_a)
		{
			if (tmp_a->next)
			{
				if (tmp_b->value > tmp_a->value
					&& tmp_b->value < tmp_a->next->value)
				{
					weight[i] = pos_calc(head_a, tmp_a->next->value, size_a);
					break ;
				}
			}
			else if (tmp_b->value > tmp_a->value
				&& tmp_b->value < head_a->value)
			{
				weight[i] = pos_calc(head_a, head_a->value, size_a);
				break ;
			}
			tmp_a = tmp_a->next;
		}
		if (tmp_a == NULL)
			weight[i] = pos_calc(head_a, ft_minor(head_a), size_a);
		tmp_b = tmp_b->next;
		i++;
	}
	return (weight);
} */

int	pos_calc(t_list	*head, int num, int size)
{
	int		i;
	t_list	*tmp;

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
