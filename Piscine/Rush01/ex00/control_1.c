/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   control_1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: redei-ma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 19:28:51 by redei-ma          #+#    #+#             */
/*   Updated: 2024/10/27 19:28:53 by redei-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	can_place(char to_place, int row, int col, char fin[4][4]);

void	g_control_1_up(char control[4][4], char fin[4][4])
{
	int	i;

	i = 0;
	while (i < 4)
	{
		if (control[0][i] == '1')
		{
			if (can_place('4', 0, i, fin))
				fin[0][i] = '4';
		}
		i++;
	}
}

void	g_control_1_down(char control[4][4], char fin[4][4])
{
	int	i;

	i = 0;
	while (i < 4)
	{
		if (control[1][i] == '1')
		{
			if (can_place('4', 3, i, fin))
				fin[3][i] = '4';
		}
		i++;
	}
}

void	g_control_1_sx(char control[4][4], char fin[4][4])
{
	int	i;

	i = 0;
	while (i < 4)
	{
		if (control[2][i] == '1')
		{
			if (can_place('4', i, 0, fin))
				fin[i][0] = '4';
		}
		i++;
	}
}

void	g_control_1_dx(char control[4][4], char fin[4][4])
{
	int	i;

	i = 0;
	while (i < 4)
	{
		if (control[3][i] == '1')
		{
			if (can_place('4', i, 3, fin))
				fin[i][3] = '4';
		}
		i++;
	}
}
