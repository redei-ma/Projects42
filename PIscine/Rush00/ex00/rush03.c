/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush03.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapascal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/19 12:52:24 by mapascal          #+#    #+#             */
/*   Updated: 2024/10/19 12:59:02 by mapascal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
void	ft_putchar(char c);

void	rush(int length, int height)
{
	int	x;
	int	y;

	x = 1;
	y = 1;
	if (length <= 0 || height <= 0)
		return ;
	while (y <= height)
	{
		while (x <= length)
		{
			if (x == 1 && (y == 1 || y == height))
				ft_putchar('A');
			else if (x == length && (y == 1 || y == height))
				ft_putchar('C');
			else if (x == 1 || x == length || y == 1 || y == height)
				ft_putchar('B');
			else if (x != 1 && x != length && y != 1 && y != height)
				ft_putchar(' ');
			x++;
		}
		ft_putchar('\n');
		x = 1;
		y++;
	}
}
