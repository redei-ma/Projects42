
#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	check(int n, int *cifre, int location)
{
	int	i;

	i = 0;
	if (location == 1)
	{
		ft_putchar(',');
		ft_putchar(' ');
	}
	while (i < n)
	{
		ft_putchar(cifre[i] + '0');
		i++;
	}
}

void	incrementa(int n, int *cifre)
{
	int	i;
	int	max;

	i = n - 1;
	max = 9;
	while (cifre[i] == max)
	{
		i -= 1;
		max -= 1;
	}
	cifre[i] += 1;
	while (i < n)
	{
		cifre[i + 1] = cifre[i] + 1;
		i += 1;
	}
}

void	ft_print_combn(int n)
{
	int	cifre[10];
	int	i;

	i = 0;
	while (i < n)
	{
		cifre[i] = i;
		i++;
	}
	check(n, cifre, 0);
	while (cifre[0] != 10 - n || cifre[n - 1] != 9)
	{
		if (!(cifre[n - 1] == 9))
			cifre[n - 1] += 1;
		else
			incrementa(n, cifre);
		check(n, cifre, 1);
	}
}
