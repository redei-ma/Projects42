#include "push_swap.h"

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
	}
	return (1);
}

/*
int	check_finish_2(t_list *head_a, t_list *head_b)
{
	t_list	*tmp_a;
	t_list		*min;

	tmp_a = head_a;
	min = tmp_a;
	if (!head_b)
	{
		while (tmp_a && tmp_a->next)
		{
			if (min->value > tmp_a->next->value)
				min->value = tmp_a->next->value;
			tmp_a = tmp_a->next;
		}
		tmp_a = head_a;
		
	}
	return (1);
}
*/

int *ft_weight_b(t_list *head_b, int size)
{
	int	*weight;
	int i;

	i = 0;
	weight = ft_calloc(size, sizeof(int));
	if (!weight)
		return (0);
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
}

int *ft_weight_a(t_list *head_a, t_list *head_a, int size)
{
	t_list tmp_a;
	t_list tmp_b;
	int *weight;
	int i;

	weight = ft_calloc(size, sizeof(int));
	tmp_b = head_b;
	i = 0;
	while (tmp_b)
	{
		while (tmp_a)
		{
			tmp_a = head_a;
			if (tmp_a->next)
			{
				if (tmp_b->value > tmp_a->value && tmp_b->value < tmp_a->next->value)
				{
					weight[i] = pos_calc(head_a, tmp_a->next->value, size);
					break;
				}
			}
			else if (tmp_b->value > tmp_a->value && tmp_b->value < head_a->value)
				{
					weight[i] = pos_calc(head_a, head_a->value, size);
					break;
				}
			tmp_a = tmp_a->next;
		}
		if (!tmp_a->next)
			weight[i] = pos_calc(head_a, ft_minor(head_a), size);
		tmp_b = tmp_b->next;
		i++;
	}
	return (weight);
}

int	pos_calc(t_list	*head, int num, int size)
{
	t_list *tmp;
	int	i;
	int	nm;

	tmp = head;
	i = 0;
	while (tmp)
	{
		if (tmp->value == num && i <= size / 2)
			return (i);
		else if (tmp->value == num i > size / 2)
			return (i - size);
		i++
		tmp = tmp->next;
	}
	return (404);
}

int	ft_minor(t_list *head)
{
	t_list *tmp;
	int	min;

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









t_list	*circolared(t_list *head)
{
	t_list *tmp;

	tmp = head;
	while (tmp)
		tmp = tmp->next;
	head->prev = tmp;
	tmp->next = head;
	return (head);
}
