#include <unistd.h>

int	ft_strlen(char *str)
{
	int i = 0;
	while (str[i] != '\0')
		i++;
	return i;
}

int main(int ac, char **av)
{
	int i = 0;
	int s1 = ft_strlen(av[2]);
	int s2 = ft_strlen(av[3]);
	int count = 0;
	
	if (ac != 4 || s1 != 1 || s2 != 1)
	{
		write(1, "\n", 2);
		return 0;
	}
	else
	{
		while (av[1][i] != '\0')
		{
			if (av[1][i] == av[2][0])
				av[1][i] = av[3][0];
			write(1, &av[1][i], 1);
			i++;
		}
		write(1, "\n", 2);
	}
	return 0;
}
