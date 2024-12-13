/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: redei-ma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 19:29:16 by redei-ma          #+#    #+#             */
/*   Updated: 2024/10/27 19:29:19 by redei-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	compile_matrix(char *src, char matrix[4][4]);
void	compile_initial_matrix(char matrix[4][4]);
void	g_control_4_up(char control[4][4], char fin[4][4]);
void	g_control_4_down(char control[4][4], char fin[4][4]);
void	g_control_4_sx(char control[4][4], char fin[4][4]);
void	g_control_4_dx(char control[4][4], char fin[4][4]);
void	g_control_1_up(char control[4][4], char fin[4][4]);
void	g_control_1_down(char control[4][4], char fin[4][4]);
void	g_control_1_sx(char control[4][4], char fin[4][4]);
void	g_control_1_dx(char control[4][4], char fin[4][4]);
void	brute(char fin[4][4]);
void	back_tracking(char control[4][4], char fin[4][4]);
void	print_error(void);

void	print_matrix(char matrice[4][4])
{
	char	n;
	int		i;
	int		j;

	n = '\n';
	i = 0;
	j = 0;
	while (i < 4)
	{
		while (j < 4)
		{
			write(1, &matrice[i][j], 1);
			j++;
		}
		j = 0;
		i++;
		write(1, &n, 1);
	}
}

void	control(char control_matrix[4][4], char fin_matrix[4][4])
{
	g_control_1_up(control_matrix, fin_matrix);
	g_control_1_down(control_matrix, fin_matrix);
	g_control_1_sx(control_matrix, fin_matrix);
	g_control_1_dx(control_matrix, fin_matrix);
	g_control_4_up(control_matrix, fin_matrix);
	g_control_4_down(control_matrix, fin_matrix);
	g_control_4_sx(control_matrix, fin_matrix);
	g_control_4_dx(control_matrix, fin_matrix);
}

int	is_valid(char *src)
{
	int	i;

	i = 0;
	while (src[i] != '\0')
	{
		if ((src[i] < '1' || src[i] > '4') && src[i] != ' ')
		{
			return (0);
		}
		i++;
	}
	return (1);
}

int	main(int ac, char **av)
{
	char	control_matrix[4][4];
	char	fin_matrix[4][4];

	if (ac != 2)
	{
		print_error();
		return (0);
	}
	if (!(is_valid(av[1])))
	{
		print_error();
		return (0);
	}
	compile_initial_matrix(fin_matrix);
	compile_matrix(av[1], control_matrix);
	control(control_matrix, fin_matrix);
	brute(fin_matrix);
	print_matrix(fin_matrix);
	return (0);
}
