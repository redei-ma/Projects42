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
		// credo ci sia un errore che non fa circolare tutta la lista percvhe si perde i valoiri prima 
		tmp_a = tmp_a -> next;
		i++;
	}
	return (total);
}

int	max_ord_seq(t_list **head_a)
{
	t_list *tmp_a;
	int i;
	int count;

	tmp_a = circular_lst(head_a);
	i = 0;
	while (i < ft_lstsize(*head_a))
	{
		if (tmp_a < tmp_a -> next)
			count++;
		i++;
		tmp_a = tmp_a -> next;
	}
	return (i);
}

t_list	*circular_lst(t_list **head)
{
	t_list	*tmp;

	tmp = *head;
	while (tmp->next)
	{
		tmp = tmp->next;
	}
	tmp -> next = *head;
	(*head) -> prev = tmp;
	return (*head);
}
