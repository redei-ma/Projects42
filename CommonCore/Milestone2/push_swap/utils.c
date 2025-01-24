/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: redei-ma <redei-ma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 13:24:50 by redei-ma          #+#    #+#             */
/*   Updated: 2025/01/24 13:36:24 by redei-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_minor(t_list *head)
{
	int		min;
	t_list	*tmp;

	tmp = head;
	min = tmp->value;
	while (tmp)
	{
		if (tmp->value < min)
			min = tmp->value;
		tmp = tmp->next;
	}
	return (min);
}

int	check_finish(t_list *head_a, t_list *head_b)
{
	t_list	*tmp_a;

	tmp_a = head_a;
	if (!head_b)
	{
		while (tmp_a && tmp_a->next)
		{
			if (tmp_a->next->value < tmp_a->value)
				return (0);
			tmp_a = tmp_a->next;
		}
		return (1);
	}
	else
		return (0);
}

int	ft_abs(int x)
{
	if (x < 0)
		return (-x);
	else
		return (x);
}

int	ft_natoi(char *str)
{
	int		i;
	int		sign;
	long	n;

	i = 0;
	n = 0;
	sign = 1;
	if (str[i] == '-')
	{
		sign = -sign;
		i++;
	}
	else if (str[i] == '+')
		i++;
	while ((str[i] >= '0' && str[i] <= '9') && str[i] != '\0')
	{
		n = n * 10 + (str[i] - '0');
		i++;
	}
	if (n < INT_MIN || n > INT_MAX || str[i] != '\0')
		n = 0;
	return (sign * n);
}

int	checkduplicate(t_list *lst)
{
	t_list	*node;
	t_list	*test;

	node = lst;
	while (node)
	{
		test = node->next;
		while (test)
		{
			if (node->value == test->value)
				return (0);
			test = test->next;
		}
		node = node->next;
	}
	return (1);
}
