#include "push_swap.h"

int	*max_arr(t_list **head_a, t_list **head_b)
{
	t_list *tmp_a;
	int		*total;
	int		i;

	total = (int *)ft_calloc(ft_lstsize(*head_a), sizeof(int));
	if (!total)
		return (NULL);
	i = 0;
	tmp_a = *head_a;
	while (tmp_a)
	{
		total[i] = max_ord_seq(&tmp_a);
		i++;
		tmp_a = tmp_a->next;
	}
	return (total);
}

int	max_ord_seq(t_list **head)
{
	t_list	*tmp_a;
	int		i;
	int		count;
	int		first_val;
	int		val;
	int		max;

	max = ft_max(*head);
	tmp_a = circular_lst(head);
	i = 0;
	count = 1;
	first_val = tmp_a->value;
	val = tmp_a->value;
	while (tmp_a->value < max)
	{
		if (tmp_a->value > val)
		{
			val = tmp_a->value;
			count++;
		}
		tmp_a = tmp_a->next;
		i++;
	}
	if (tmp_a->value == max)
	{
		count++;
		i++;
		tmp_a = tmp_a->next;
	}
	while (i < ft_lstsize(*head))
	{
		i++;
		if (tmp_a->value < first_val)
		{
			count++;
			val = tmp_a->value;
			break;
		}
		tmp_a = tmp_a -> next;
	}
	while (i < ft_lstsize(*head))
	{
		if (tmp_a->value > val && tmp_a->value < first_val)
		{
			count++;
			val = tmp_a->value;
		}
		i++;
		tmp_a = tmp_a -> next;
	}
	return (count);
}

t_list	*circular_lst(t_list **head)
{
	t_list	*tmp;
	t_list	*start;

	tmp = *head;
	start = *head;
	while ((*head)->prev)
		*head = (*head)->prev;
	while (tmp->next)
		tmp = tmp->next;
	tmp -> next = *head;
	(*head) -> prev = tmp;
	return (start);
}

int	ft_max(t_list *head)
{
	t_list *tmp;
	int	max;

	tmp = head;
	max = tmp->value;
	while (tmp)
	{
		if (tmp->value > max)
			max = tmp->value;
		tmp = tmp->next;
	}
	return (max);
}