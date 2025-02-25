/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: redei-ma <redei-ma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 16:38:17 by redei-ma          #+#    #+#             */
/*   Updated: 2025/02/25 12:21:17 by redei-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *str)
{
	size_t	n;

	n = 0;
	while (str[n] != '\0')
		n++;
	return (n);
}

char	*find_newline(char **str)
{
	char	*fin;
	char	*tmp;
	int		i;

	i = 0;
	fin = NULL;
	while ((*str)[i] && (*str)[i] != '\n')
		i++;
	if ((*str)[i] == '\n')
	{
		fin = ft_substr(*str, 0, i + 1);
		if (!fin)
			return (free(*str), NULL);
		if (i == (int)ft_strlen(*str) - 1)
			tmp = NULL;
		else
		{
			tmp = ft_substr(*str, i + 1, ft_strlen(*str) - i - 1);
			if (!tmp)
				return (free(fin), free(*str), NULL);
		}
		free(*str);
		*str = tmp;
	}
	return (fin);
}

int	read_line(char **s, int fd)
{
	char	*buff;
	char	*tmp;
	ssize_t	bytes_read;

	buff = (char *)ft_calloc((BUFFER_SIZE + 1), sizeof(char));
	if (!buff)
		return (-1);
	bytes_read = read(fd, buff, BUFFER_SIZE);
	if (bytes_read > 0)
	{
		tmp = ft_strjoin(*s, buff);
		if (!tmp)
		{
			free(buff);
			return (-1);
		}
		free(*s);
		*s = tmp;
	}
	free(buff);
	return (bytes_read);
}

char	*test(char **leftovers, char **final, int bytes)
{
	if (bytes < 0)
	{
		free(*leftovers);
		*leftovers = NULL;
		return (NULL);
	}
	else if (bytes == 0)
	{
		if (*leftovers && ft_strlen(*leftovers) > 0)
		{
			*final = *leftovers;
			*leftovers = NULL;
			return (*final);
		}
		free(*leftovers);
		*leftovers = NULL;
		return (NULL);
	}
	return (NULL);
}

char	*get_next_line(int fd)
{
	static char	*leftovers;
	char		*final;
	int			bytes;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (!leftovers)
		leftovers = (ft_strdup(""));
	if (!leftovers)
		return (NULL);
	while (1)
	{
		final = find_newline(&leftovers);
		if (final)
			return (final);
		if (!leftovers)
			return (NULL);
		bytes = read_line(&leftovers, fd);
		if (bytes <= 0)
			return (test(&leftovers, &final, bytes));
	}
}

/* int main(int argc, char **argv)
{
    int fd1;
    char *line1;
	if (argc != 2) // Un file richiesti come input
    {
        fprintf(stderr, "Usage: %s <file1>\n", argv[0]);
        return (EXIT_FAILURE);
    }    // Apertura del primo file
    fd1 = -1;
    if (fd1 < 0)
    {
        perror("Error opening file 1");
        return (EXIT_FAILURE);
    }
    while (1)
    {
        line1 = get_next_line(fd1);
        if (line1 != NULL)
        {
            printf("%s\n", line1);
            free(line1);
        }        
        if (line1 == NULL)
            break;
    }    close(fd1);
    return (EXIT_SUCCESS);
} */
