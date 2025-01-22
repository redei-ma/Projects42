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
		return (1);
	}
	else
		return (0);
}

void tidy_up(t_list **head_a)
{
	int	min;
	int	pos;
	int	i;
	int	size;

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

int *ft_weight_b(t_list *head_b)
{git@github.com:redei-ma/WorkInProgress.git
	int	*weight;
	int i;
	int	size;

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
}

int *ft_weight_a(t_list *head_a, t_list *head_b)
{
	t_list *tmp_a;
	t_list *tmp_b;
	int *weight;
	int i;
	int size_a;

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
				if (tmp_b->value > tmp_a->value && tmp_b->value < tmp_a->next->value)
				{
					weight[i] = pos_calc(head_a, tmp_a->next->value, size_a);
					break;
				}
			}
			else if (tmp_b->value > tmp_a->value && tmp_b->value < head_a->value)
				{
					weight[i] = pos_calc(head_a, head_a->value, size_a);
					break;
				}
			tmp_a = tmp_a->next;
		}
		if (tmp_a == NULL)
			weight[i] = pos_calc(head_a, ft_minor(head_a), size_a);
		tmp_b = tmp_b->next;
		i++;
	}
	return (weight);
}

int	pos_calc(t_list	*head, int num, int size)
{
	t_list *tmp;
	int	i;

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

void	make_move(int *moves, t_list **head_a, t_list **head_b)
{
	while (moves[0] != 0 || moves[1] != 0)
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
		if(moves[0] > 0)
		{
			ft_ra(head_a);
			moves[0]--;
		}
		else if (moves[0] < 0)
		{
			ft_rra(head_a);
			moves[0]++;
		}
		if(moves[1] > 0)
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
	ft_pa(head_a, head_b);
}
