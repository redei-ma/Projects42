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

int move(t_list *head_a, t_list *head_b, int size)
{
	int	*move;
	int i;

	i = 0;
	move = ft_calloc(size, sizeof(int));
	if (!move)
		return (0);
	if (size % 2 == 0)
	{
		while (i <= size/2)
		{
			move[i] = i;
			i++;
		}
		while (i < size)
		{
			move[i] = i - size;
			i++;
		} 
	}
}