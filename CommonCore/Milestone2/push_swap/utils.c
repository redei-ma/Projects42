#include "push_swap.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*dest;
	size_t	tot;

	if (nmemb == 0 || size == 0)
	{
		return (malloc(0));
	}
	tot = nmemb * size;
	if (tot / size != nmemb)
		return (NULL);
	dest = malloc(tot);
	if (dest == NULL)
		return (NULL);
	ft_bzero(dest, tot);
	return (dest);
}

void	ft_bzero(void *s, size_t n)
{
	ft_memset(s, 0, n);
}

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	*temp;

	temp = (unsigned char *)s;
	while (n--)
	{
		*temp = c;
		temp++;
	}
	return (s);
}