/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algoritmo_1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: redei-ma <redei-ma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 12:51:29 by redei-ma          #+#    #+#             */
/*   Updated: 2025/01/24 15:23:01 by redei-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* int	ft_algoritmo(t_list **head_a, t_list **head_b)
{
	int	i;
	int	min_wei;
	int	pos;
	int	*weight_a;
	int	*weight_b;
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
		if (ft_abs(total[i]) < min_wei)
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
} */

