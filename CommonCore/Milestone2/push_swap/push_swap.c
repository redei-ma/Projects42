
#include "push_swap.h"

int	ft_atoi(char *str)
{
	int	i;
	long	n;
	int	sign;

	i = 0;
	n = 0;
	sign = 1;
	/* while (((str[i] >= 9 && str[i] <= 13) || str[i] == 32) && str[i] != '\0') // va bene salatre gli spazi?
		i++; */
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

t_list	*ft_lstnew(char *av)
{
	t_list	*node;
	int content;

	content = ft_atoi(av);
	if (content == 0 && !(av[0] == '0' && av[1] == '\0')) // fare un ciclo while che salti gli spazi per metterli anche in atoi
		return (NULL);
	node = (t_list *)malloc(1 * sizeof(t_list));
	if (!node)
		return (NULL);
	node -> value = content;
	node -> next = NULL;
	node -> prev = NULL;
	return (node);
}

t_list	*ft_lstcreation(char **av)
{
	t_list *node;
	t_list *prev_node;
	t_list *begin;
	int value;
	int	i;

	i = 1;
	node = NULL;
	while (av[i])
	{
		prev_node = node;
		node = ft_lstnew(av[i]);
		if (!node)
			return (NULL);  //funzione che free i nodi e termini il programma
		if(i == 1)
			begin = node;
		else
		{
			node->prev = prev_node;
			prev_node->next = node;
		}
		i++;
	}
	return (begin);
}

void	ft_lstprint(t_list *head_a, t_list *head_b)
{
	printf("A	B\n");
	while (head_a || head_b)
	{
		if (head_a)
		{
			printf("%i", head_a->value);
			head_a = head_a->next;
		}
		else
			printf(" ");
		printf("	");
		if (head_b)
		{
			printf("%i\n", head_b->value);
			head_b = head_b->next;
		}
		else
			printf(" \n");
	}
}

int	ft_lstsize(t_list *lst)
{
	t_list	*tmp;
	int	count;

	tmp = lst;
	count = 0;
	while (tmp)
	{
		tmp = tmp->next;
		count++;
	}
	return (count);
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

void	ft_algoritmo(size_t head_a, size_t head_b)
{
	int	i;
	int	*weight_a;
	int *weight_b;
	int	*total;

	while (ft_lstsize(head_a)-- > 2)
		ft_pb(&head_a, &head_b);
	while (1)
	{
		i = 0;
		weight_a = ft_weight_a(head_a);
		weight_b = ft_weight_a(head_b);
		while (i <= ft_lstsize(head_b))
		{
			if (weight_a[i] >= 0 && weight_b[i] >= 0)
			{
				if (weight_a[i] > weight_b[i])
					total[i] = weight_a[i];
				else
					total[i] = weight_b[i];
			}
			else if (weight_a[i] < 0 && weight_b[i] < 0)
			{
				if (weight_a[i] < weight_b[i])
					total[i] = weight_a[i];
				else
					total[i] = weight_b[i];
			}
			else
			{
				if (weight_a[i] < 0)
					total[i] = -weight_a[i] + weight_b[i];
				else
					total[i] = weight_a[i] + (-weight_b[i]);
			}
		}
		/*
		ora dobbiamo controllare quale e il peso piu piccolo, prenderlo e fare una funazone che faccia le 
		mosse stabilite dai due array tenendo anche conto delle combo quando sono uguali
		*/
	}
}

int main(int ac, char **av)
{
	t_list *head_a;
	t_list *head_b;
	int	size;

	if (ac < 2)
		return (1);
	head_a = ft_lstcreation(av);
	head_b = NULL;
	if (!head_a)
		return (write(2, "Error\n", 6));
	if (checkduplicate(head_a) == 0)
		return (write(2, "Error\n", 6));
	size = ft_lstsize(head_a);
	if (size <= 2)
	{
		if (head_a-> value > head_a->next->value)
			ft_sa(&head_a);
	}
	ft_algoritmo(head_a, head_b);




	ft_lstprint(head_a, head_b);
	/*if (head_b)
	while (1)
	{
		if (check_finish(head_a, head_b) == 1)
			break;

	} */

}
