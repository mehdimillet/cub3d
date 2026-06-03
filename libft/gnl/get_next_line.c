/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: memillet <memillet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/28 20:27:33 by memillet          #+#    #+#             */
/*   Updated: 2025/12/04 15:23:18 by memillet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_stocknread(char *stock, int fd)
{
	char	*buf;
	int		bytes;

	bytes = 1;
	buf = malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!buf)
		return (NULL);
	while (!ft_strchr(stock, '\n') && bytes > 0)
	{
		bytes = read(fd, buf, BUFFER_SIZE);
		if (bytes < 0)
		{
			free(buf);
			if (stock)
				free (stock);
			return (NULL);
		}
		buf[bytes] = '\0';
		stock = ft_strjoin(stock, buf);
	}
	free(buf);
	return (stock);
}

char	*ft_extract(char *stock)
{
	char	*line;

	line = ft_strdup(stock);
	return (line);
}

char	*ft_clean(char *stock)
{
	char	*cleanstock;
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (stock[i] != '\n' && stock[i])
		i++;
	if (!stock[i])
	{
		free(stock);
		return (NULL);
	}
	cleanstock = malloc(sizeof(char) * (ft_strlen(stock) - i) + 1);
	if (!cleanstock)
		return (NULL);
	i++;
	while (stock[i])
		cleanstock[j++] = stock[i++];
	cleanstock[j] = '\0';
	free(stock);
	return (cleanstock);
}

char	*get_next_line(int fd)
{
	static char	*stock[MAX_FD];
	char		*line;

	if (fd < 0)
		free(stock[fd]);
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	stock[fd] = ft_stocknread(stock[fd], fd);
	if (!stock[fd])
		return (NULL);
	line = ft_extract(stock[fd]);
	stock[fd] = ft_clean(stock[fd]);
	return (line);
}

int	main(void)
{
	int fd;
	int fd1;
	int fd2;
	int	fd3;
	char *line;

	fd = open("empty.txt", O_RDONLY);
	while ((line = get_next_line(fd)))
	{
		printf("%s", line);
		free(line);
	}
	free(line);
	close(fd);

	fd1 = open("backslashn.txt", O_RDONLY);
	while ((line = get_next_line(fd1)))
	{
		printf("%s", line);
		free(line);
	}
	free(line);
	close(fd1);

	fd2 = open("1line.txt", O_RDONLY);
	while ((line = get_next_line(fd2)))
	{
		printf("%s", line);
		free(line);
	}
	free(line);
	close(fd2);

	fd3 = open("normal.txt", O_RDONLY);
	while ((line = get_next_line(fd2)))
	{
		printf("%s", line);
		free(line);
	}
	free(line);
	close(fd3);
	return (0);
}