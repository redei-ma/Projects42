
#include "push_swap.h"

int	ft_atoi(char *str)
{
	int	i;
	long	n;
	int	sign;

	i = 0;
	n = 0;
	sign = 1;
	while (((str[i] >= 9 && str[i] <= 13) || str[i] == 32) && str[i] != '\0') // va bene salatre gli spazi?
		i++;
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
	if (content == 0 && !(av[0] == '0' && av[1] == '\0'))
		return (NULL);
	node = (t_list *)malloc(1 * sizeof(t_list));
	if (!node)
		return (NULL);
	node -> value = content;
	node -> next = NULL;
	node -> prev = NULL; //capire se serve questa cosa
	return (node);
}

t_list	*list_creation(char **av)
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

int main(int ac, char **av)
{
	t_list *node;
	t_list *head_a;
	t_list *test;
	if (ac < 2)
		return (1);
	head_a = list_creation(av);
	if (!head_a)
		return (write(2, "Error\n", 6));
	node = head_a;
	while (node)
	{
		test = node->next;
		while (test)
		{
			if (node->value == test->value)
				return (write(2, "Error\n", 6));
			test = test->next;
		}
		node = node->next;
	}
	node = head_a;
	ft_sa(&head_a);
	while (node)
	{
		printf("%d\n", node->value);
		if(node->prev)
			printf("prev: %d\n", node->prev->value);
		else
		 printf("prev: %p\n", node->prev);
		node = node->next;
	}
	printf("next: %p\n", node);
}
