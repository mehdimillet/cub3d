/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leauvray <leauvray@student.42lehavre.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/29 15:21:27 by memillet          #+#    #+#             */
/*   Updated: 2026/06/30 13:28:39 by leauvray         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/cub3d.h"

static char	*ft_extract_line(char *buff_stay)
{
	char	*pos;
	int		len;

	if (!buff_stay || !*buff_stay)
		return (NULL);
	pos = ft_strchr(buff_stay, '\n');
	if (pos)
		len = pos - buff_stay + 1;
	else
		len = my_strlen(buff_stay);
	return (ft_substr(buff_stay, 0, len));
}

static char	*ft_stay(char *buff_stay)
{
	char	*pos;
	char	*temp;
	int		len;

	pos = ft_strchr(buff_stay, '\n');
	if (!pos)
		return (free(buff_stay), NULL);
	len = pos - buff_stay + 1;
	temp = ft_substr(buff_stay, len, my_strlen(buff_stay) - len);
	free(buff_stay);
	return (temp);
}

char	*get_next_line(int fd)
{
	static char	*buff_stay;
	char		*buffer;
	char		*line;
	int			buff_read;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	if (!buff_stay)
		buff_stay = ft_substr("", 0, 0);
	buff_read = read(fd, buffer, BUFFER_SIZE);
	while (!ft_strchr(buff_stay, '\n') && buff_read > 0)
	{
		buffer[buff_read] = '\0';
		buff_stay = ft_strjoin(buff_stay, buffer);
		buff_read = read(fd, buffer, BUFFER_SIZE);
	}
	free(buffer);
	line = ft_extract_line(buff_stay);
	buff_stay = ft_stay(buff_stay);
	return (line);
}
