
#include <unistd.h>

void	display(int num, int n);

void	display_call(int num)
{
	if (num >= 10)
	{
		display(num / 10, 0);
	}
}

void	digit_assign(int num, int *digits, int *temp)
{
	if (num == 0)
	{
		*digits = 1;
	}
	else
	{
		while (*temp != 0)
		{
			*temp /= 10;
			*digits += 1;
		}
	}
}

void	display(int num, int n)
{
	char	c;
	int		temp;
	int		digits;
	int		i;

	temp = num;
	digits = 0;
	i = 0;
	digit_assign(num, &digits, &temp);
	if (num < 0)
	{
		write(1, "-", 1);
		num = -num;
	}
	while (i < (n - digits))
	{
		write(1, "0", 1);
		i++;
	}
	display_call(num);
	c = (num % 10) + 48;
	write(1, &c, 1);
}

void	stamp(int n, int start, int current_digit, int current_number)
{
	int	i;

	if (current_digit == n)
	{
		if (start != n)
		{
			write(1, ", ", 2);
		}
		display(current_number, n);
		return ;
	}
	i = start;
	while (i <= 9)
	{
		stamp(n, i + 1, current_digit + 1, current_number * 10 + i);
		i++;
	}
}

void	ft_print_combn(int n)
{
	if (n <= 0 || n >= 10)
	{
		return ;
	}
	stamp(n, 0, 0, 0);
}
