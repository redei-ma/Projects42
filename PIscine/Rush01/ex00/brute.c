/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   brute.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: redei-ma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 19:28:03 by redei-ma          #+#    #+#             */
/*   Updated: 2024/10/27 19:28:06 by redei-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	can_place(char to_place, int row, int col, char fin[4][4]);

void	brute(char fin[4][4])
{
	int	i;
	int	j;
	int	count;

	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			count = '1';
			while (count <= '4')
			{
				if (fin[i][j] == '0' && can_place(count, i, j, fin))
					fin[i][j] = count;
				count++;
			}
			j++;
		}
		i++;
	}
}
