#include "push_swap.h"

//Da capire se stiamoperdendo le teste e quindi salvarcele in ogni funzione o stare attenti
//a cosa passi alle funzioni
//CApire se i controlli va bene se fatti per tutte le funzioni

void	ft_sa(t_list **head_a)
{
	int	tmp;

	if((*head_a) && (*head_a)->next)
	{
		tmp = (*head_a)->value;
		(*head_a)->value = (*head_a)->next->value;
		(*head_a)->next->value = tmp;
		write(1, "sa\n", 3);
	}
}

void	ft_sb(t_list **head_b)
{
	int	tmp;

	if((*head_b) && (*head_b)->next)
	{
		tmp = (*head_b)->value;
		(*head_b)->value = (*head_b)->next->value;
		(*head_b)->next->value = tmp;
		write(1, "sb\n", 3);
	}
}

void	ft_ss(t_list **head_a, t_list **head_b)
{
	int	tmp;
	if((*head_a) && (*head_a)->next && (*head_b) && (*head_b)->next)
	{
		tmp = (*head_a)->value;
		(*head_a)->value = (*head_a)->next->value;
		(*head_a)->next->value = tmp;
		tmp = (*head_b)->value;
		(*head_b)->value = (*head_b)->next->value;
		(*head_b)->next->value = tmp;
		write(1, "ss\n", 3);
	}
}
void	ft_pa(t_list **head_a, t_list **head_b)
{
	t_list	*tmp;

	if (*head_b)
	{
		tmp = *head_b;
		if((*head_b)->next)
		{
			*head_b = (*head_b)->next;
			(*head_b)->prev = NULL;
		}
		else
			*head_b = NULL;
		if (*head_a)
			(*head_a)->prev = tmp;
		tmp->next = *head_a;
		*head_a = tmp;
	}
	write(1, "pa\n", 3);
}

void	ft_pb(t_list **head_a, t_list **head_b)
{
	t_list	*tmp;

	if (*head_a)
	{
		tmp = *head_a;
		if((*head_a)->next)
		{
			*head_a = (*head_a)->next;
			(*head_a)->prev = NULL;
		}
		else
			*head_a = NULL;
		if (*head_b)
			(*head_b)->prev = tmp;
		tmp->next = *head_b;
		*head_b = tmp;
	}
	write(1, "pb\n", 3);
}

void	ft_ra(t_list **head_a)
{
	int	tmp;
	t_list	*head;

	head = *head_a;
	if((*head_a) && (*head_a)->next)
	{
		tmp = (*head_a)->value;
		while ((*head_a)->next)
		{
			(*head_a)->value = (*head_a)->next->value;
			(*head_a) = (*head_a)->next;
		}
		(*head_a)->value = tmp;
		write(1, "ra\n", 3);
	}
	*head_a = head;
}

void	ft_rb(t_list **head_b)
{
	int	tmp;
	t_list	*head;

	head = *head_b;
	if((*head_b) && (*head_b)->next)
	{
		tmp = (*head_b)->value;
		while ((*head_b)->next)
		{
			(*head_b)->value = (*head_b)->next->value;
			(*head_b) = (*head_b)->next;
		}
		(*head_b)->value = tmp;
		write(1, "rb\n", 3);
	}
	*head_b = head;
}

void	ft_rr(t_list **head_a, t_list **head_b)
{
	int	tmp;
	t_list	*head;

	if((*head_a) && (*head_a)->next && (*head_b) && (*head_b)->next)
	{
		head = *head_a;
		tmp = (*head_a)->value;
		while ((*head_a)->next)
		{
			(*head_a)->value = (*head_a)->next->value;
			(*head_a) = (*head_a)->next;
		}
		(*head_a)->value = tmp;
		*head_a = head;
		head = *head_b;
		tmp = (*head_b)->value;
		while ((*head_b)->next)
		{
			(*head_b)->value = (*head_b)->next->value;
			(*head_b) = (*head_b)->next;
		}
		(*head_b)->value = tmp;
		*head_b = head;
		write(1, "rr\n", 3);
	}
}

void	ft_rra(t_list **head_a)
{
	t_list *tmp;

	if((*head_a) && (*head_a)->next)
	{
		tmp = *head_a;
		while (tmp->next != NULL)
			tmp = tmp->next;
		tmp->prev->next = NULL;
		tmp->prev = NULL;
		tmp->next = *head_a;
		(*head_a)->prev = tmp;
		*head_a = tmp;
		write(1, "rra\n", 4);
	}
}

void	ft_rrb(t_list **head_b)
{
	t_list *tmp;

	if((*head_b) && (*head_b)->next)
	{
		tmp = *head_b;
		while (tmp->next != NULL)
			tmp = tmp->next;
		tmp->prev->next = NULL;
		tmp->prev = NULL;
		tmp->next = *head_b;
		(*head_b)->prev = tmp;
		*head_b = tmp;
		write(1, "rrb\n", 4);
	}
}

void	ft_rrr(t_list **head_a, t_list **head_b)
{
	t_list *tmp;

	if((*head_a) && (*head_a)->next && (*head_b) && (*head_b)->next)
	{
		tmp = *head_a;
		while (tmp->next != NULL)
			tmp = tmp->next;
		tmp->prev->next = NULL;
		tmp->prev = NULL;
		tmp->next = *head_a;
		(*head_a)->prev = tmp;
		*head_a = tmp;
		tmp = *head_b;
		while (tmp->next != NULL)
			tmp = tmp->next;
		tmp->prev->next = NULL;
		tmp->prev = NULL;
		tmp->next = *head_b;
		(*head_b)->prev = tmp;
		*head_b = tmp;
		write(1, "rrr\n", 4);
	}
}
