
unsigned int	ft_strlen(char *str)
{
	unsigned int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int	i;
	unsigned int	d_len;
	unsigned int	s_len;

	d_len = ft_strlen(dest);
	s_len = ft_strlen(src);
	if (size <= d_len)
		return (size + s_len);
	i = 0;
	while (src[i] != '\0' && (d_len + i) < size - 1)
	{
		dest[d_len + i] = src[i];
		i++;
	}
	dest[d_len + i] = '\0';
	return (d_len + s_len);
}
/*
#include <stdio.h>

int main()
{
	char src[] = "body asked you";
	char dest[] = "however, no";
	ft_strlcat(dest, src, 11);
	printf("Returned value: %d\n",ft_strlcat(dest, src, 11));
	return 0;	
}*/
