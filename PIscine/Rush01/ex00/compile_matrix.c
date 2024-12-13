/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compile_matrix.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: redei-ma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 19:28:29 by redei-ma          #+#    #+#             */
/*   Updated: 2024/10/27 19:28:31 by redei-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	compile_matrix(char *src, char matrix[4][4])
{
	int	i;
	int	row;
	int	col;

	i = 0;
	row = 0;
	col = 0;
	while (src[i] != '\0' && row < 4)
	{
		if (src[i] >= '1' && src[i] <= '4')
		{
			matrix[row][col] = src[i];
			col++;
			if (col == 4)
			{
				col = 0;
				row++;
			}
		}
		i++;
	}
}

void	compile_initial_matrix(char matrix[4][4])
{
	int	row;
	int	col;

	row = 0;
	while (row < 4)
	{
		col = 0;
		while (col < 4)
		{
			matrix[row][col] = '0';
			col++;
		}
		row++;
	}
}
