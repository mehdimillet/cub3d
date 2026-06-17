/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   takes_info.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: memillet <memillet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/03 15:49:24 by memillet          #+#    #+#             */
/*   Updated: 2026/06/17 05:10:54 by memillet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/cub3d.h"

int	get_fd(char *file)
{
	int		fd;

	fd = open(file, O_RDONLY);
	if (fd == -1)
	{
		printf("Cannot open the file, make sure it's a good one\n");
		return (-1);
	}
	else
		return (fd);
}

char	**read_file(int fd, int nbline)
{
	char	*line;
	char	**file;
	int		i;
	int		len;

	i = 0;
	file = malloc(sizeof (char *) * (nbline + 1));
	if (!file)
		return (NULL);
	while ((line = get_next_line(fd)))
	{
		len = ft_strlen(line);
		file[i] = malloc(sizeof(char) * (len + 1));
		if (!file[i])
			return (free_tab(file), free(line), NULL);
		ft_strlcpy(file[i], line, len + 1);
		if (file[i][len - 1] == '\n')
			file[i][len - 1] = '\0';
		free(line);
		i++;
	}
	i++;
	file[i + 1] = NULL;
	return (close(fd), file);
}
