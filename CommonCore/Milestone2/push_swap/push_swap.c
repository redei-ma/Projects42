
#include "push_swap.h"

int	ft_natoi(char *str)
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

t_list	*ft_nlstnew(char *av)
{
	t_list	*node;
	int content;

	content = ft_natoi(av);
	if (content == 0 && !(av[0] == '0' && av[1] == '\0')) // fare un ciclo while che salti gli spazi per metterli anche in atoi
		return (NULL);
	node = (t_list *)ft_calloc(1, sizeof(t_list));
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
	int	i;

	i = 1;
	node = NULL;
	while (av[i])
	{
		prev_node = node;
		node = ft_nlstnew(av[i]);
		if (!node)
			return (NULL);
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

void ft_freelst(t_list **head_a, t_list **head_b)
{
	t_list	*tmp;

	while (*head_a)
	{
		tmp = *head_a;
		*head_a = (*head_a)->next;
		free(tmp);
	}
	*head_a = NULL;
	while (*head_b)
	{
		tmp = *head_b;
		*head_b = (*head_b)->next;
		free(tmp);
	}
	*head_b = NULL;
}

int	ft_abs(int x)
{
	if (x < 0)
		return (-x);
	else
		return (x);
}

int	ft_algoritmo(t_list **head_a, t_list **head_b)
{
	int	i;
	int	min_wei;
	int	pos;
	int	*weight_a;
	int *weight_b;
	int	moves[2];
	int	*total;

	i = 0;
	weight_a = ft_weight_a(*head_a, *head_b);
	weight_b = ft_weight_b(*head_b);
	total = (int *)ft_calloc(ft_lstsize(*head_b), sizeof(int));
	if (!(weight_a || weight_b || total))
		return (0);
	while (i < ft_lstsize(*head_b))
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
			total[i] = ft_abs(weight_a[i]) + ft_abs(weight_b[i]);
		i++;
	}
	min_wei = ft_abs(total[0]);
	pos = 0;
	i = 0;
	while (i < ft_lstsize(*head_b))
	{
		if(ft_abs(total[i]) < min_wei)
		{
			pos = i;
			min_wei = ft_abs(total[i]);
		}
		i++;
	}
	//teoricamente si potrebbe sovrascrivere total dato che a questo punto del prpgramma non serve piu',
	//per scaramanzia usiamo moves pi si vedra in corso d'opera;
	moves[0] = weight_a[pos];
	moves[1] = weight_b[pos];
	make_move(moves, head_a, head_b);
	free(weight_a);
	free(weight_b);
	free(total);
	return (1);
}

int main(int ac, char **av)
{
	t_list *head_a;
	t_list *head_b;
	int	size;

	if (ac < 2)
		return (write(2, "Too few arguments\n", 18));
	head_a = ft_lstcreation(av);
	head_b = NULL;
	if (!head_a || checkduplicate(head_a) == 0)
	{
		ft_freelst(&head_a, &head_b);
		return (write(2, "Error\n", 6));
	}
	if (check_finish(head_a, head_b) == 1)
	{
		ft_freelst(&head_a, &head_b);
		return (write(1, "Alredy sorted\n", 14) && 0);
	}
	size = ft_lstsize(head_a);
	while (size-- > 2)
		ft_pb(&head_a, &head_b);
	while (head_b)
	{
		if ((ft_algoritmo(&head_a, &head_b)) == 0)
			break;
	}
	tidy_up(&head_a);
//	ft_lstprint(head_a, head_b);
	if (check_finish(head_a, head_b) == 0)
		write(2, "Erorr function\n", 15);
	ft_freelst(&head_a, &head_b);
//	if(!(head_a && head_b))
//		write(1, "List clear\n", 11);
	return (0);
}
