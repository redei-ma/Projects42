
#include <stdlib.h>
#include <unistd.h>

int	is_char(char c, char *charset)
{
	int	i;

	i = 0;
	while (charset[i] != '\0')
	{
		if (charset[i] == c)
		{
			return (1);
		}
		i++;
	}
	return (0);
}

char	*ft_strndup(char *src, int len)
{
	int		i;
	char	*dest;

	dest = (char *)malloc((len + 1) * sizeof(char));
	if (dest == NULL)
		return (NULL);
	i = 0;
	while (i < len)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

int	n_words(char *charset, char *str)
{
	int	i;
	int	count;
	int	in_word;

	i = 0;
	count = 0;
	in_word = 0;
	while (str[i] != '\0')
	{
		if (!is_char(str[i], charset) && !in_word)
		{
			count++;
			in_word = 1;
		}
		else if (is_char(str[i], charset))
			in_word = 0;
		i++;
	}
	return (count);
}

char	**split(char **final, char *str, char *charset)
{
	int		i;
	int		start;
	int		row;

	i = 0;
	row = 0;
	start = 0;
	while (str[i] != '\0')
	{
		while (str[i] != '\0' && is_char(str[i], charset))
			i++;
		start = i;
		while (str[i] != '\0' && !is_char(str[i], charset))
			i++;
		if (i > start)
		{
			final[row] = ft_strndup(str + start, i - start);
			row++;
		}
	}
	final[row] = NULL;
	return (final);
}

char	**ft_split(char *str, char *charset)
{
	int		num_words;
	char	**final;

	num_words = n_words(charset, str);
	final = (char **)malloc((num_words + 1) * sizeof(char *));
	if (final == NULL)
		return (NULL);
	return (split(final, str, charset));
}

/*#include <stdio.h>

int main(void) {
    char str[] = "Hello World 42";
    char charset[] = " ";
    char **split = ft_split(str, charset);

    // Print the split result
    int i = 0;
    while (split[i])
    {
        printf("%s\n", split[i]);
        free(split[i]); // Don't forget to free the individual strings
        i++;
    }
    free(split); // Free the array of strings itself
    return 0;
}*/
