/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush04.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapascal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/19 12:52:24 by mapascal          #+#    #+#             */
/*   Updated: 2024/10/19 12:59:02 by mapascal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
void	ft_putchar(char c);

void	check(int x, int y, int length, int height)
{
	if (x == 1 && y == 1)
		ft_putchar('A');
	else if (x == length && y == 1)
		ft_putchar('C');
	else if (x == 1 && y == height)
		ft_putchar('C');
	else if (x == length && y == height)
		ft_putchar('A');
	else if (y == 1 || y == height)
		ft_putchar('B');
	else if (x == 1 || x == length)
		ft_putchar('B');
	else
		ft_putchar(' ');
}

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
			check(x, y, length, height);
			x++;
		}
		ft_putchar('\n');
		x = 1;
		y++;
	}
}
