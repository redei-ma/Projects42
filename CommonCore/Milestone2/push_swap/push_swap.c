/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: redei-ma <redei-ma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 13:34:31 by redei-ma          #+#    #+#             */
/*   Updated: 2025/01/28 16:36:44 by redei-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	int		size;
	t_node	*head_a;
	t_node	*head_b;

	if (ac < 2)
		return (1);
	head_a = ft_lstcreation(av);
	head_b = NULL;
	if (!head_a || checkduplicate(head_a) == 0)
		return (ft_freelst(&head_a, &head_b) & write(2, "Error\n", 6));
	if (check_finish(head_a, head_b) == 1)
		return (ft_freelst(&head_a, &head_b));
	size = ft_lstsize_push(head_a);
	while (size-- > 2)
		ft_pb(&head_a, &head_b);
	while (head_b)
		ft_algo(&head_a, &head_b);
	tidy_up(&head_a);
	if (check_finish(head_a, head_b) == 0)
		write(2, "Erorr function\n", 15);
	ft_freelst(&head_a, &head_b);
	return (0);
}
