/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   control_4.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: redei-ma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 19:29:05 by redei-ma          #+#    #+#             */
/*   Updated: 2024/10/27 19:29:07 by redei-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	g_control_4_up(char control[4][4], char fin[4][4])
{
	char	count;
	int		i;
	int		j;

	i = 0;
	while (i < 4)
	{
		count = '1';
		j = 0;
		if (control[0][i] == '4')
		{
			while (j < 4)
			{
				fin[j][i] = count;
				count++;
				j++;
			}
		}
		i++;
	}
}

void	g_control_4_down(char control[4][4], char fin[4][4])
{
	char	count;
	int		i;
	int		j;

	i = 0;
	while (i < 4)
	{
		count = '1';
		j = 3;
		if (control[1][i] == '4')
		{
			while (j >= 0)
			{
				fin[j][i] = count;
				count++;
				j--;
			}
		}
		i++;
	}
}

void	g_control_4_sx(char control[4][4], char fin[4][4])
{
	char	count;
	int		i;
	int		j;

	i = 0;
	while (i < 4)
	{
		count = '1';
		j = 0;
		if (control[2][i] == '4')
		{
			while (j < 4)
			{
				fin[i][j] = count;
				count++;
				j++;
			}
		}
		i++;
	}
}

void	g_control_4_dx(char control[4][4], char fin[4][4])
{
	char	count;
	int		i;
	int		j;

	i = 0;
	while (i < 4)
	{
		count = '1';
		j = 3;
		if (control[3][i] == '4')
		{
			while (j >= 0)
			{
				fin[i][j] = count;
				count++;
				j--;
			}
		}
		i++;
	}
}
