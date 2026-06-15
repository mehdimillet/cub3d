/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   takes_info.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: memillet <memillet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/03 15:49:24 by memillet          #+#    #+#             */
/*   Updated: 2026/06/15 14:51:37 by memillet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/cub3d.h"

int	get_fd(t_cub *cub, char *file)
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

void	check_file(char *line, t_cub *info, int i)
{
	if (line[i] == "N" && line[i] + 1 == "O")
	{

	}
}

char	**read_file(int fd)
{
	char	*line;
	char	**file;
	int		i;
	int		len;

	i = 0;
	file = malloc(sizeof (char *));
	while (line = get_next_line(fd))
	{
		len = ft_strlen(line);
		file[i] = realloc(file ,sizeof(char) * (len + 1));
		if (!file[i])
			return (free_tab(file), NULL);
		ft_strlcpy(file[i], line, len + 1);
		if (!file[i])
			return (free_tab(file), NULL);
		file[i][len] = '\0';
		i++;
	}
	i++;
	file[i + 1] == NULL;
	return (file);
}
