/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: memillet <memillet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/15 11:54:15 by memillet          #+#    #+#             */
/*   Updated: 2026/08/04 13:24:03 by memillet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	check_filename(char *map_name)
{
	int	len;

	len = ft_strlen(map_name);
	if (len < 4 || ft_strcmp(&map_name[len - 4], ".cub") != 0)
		return (printf("wrong file extension\n"), 1);
	return (0);
}

int	count_line(int fd)
{
	char	*line;
	int		i;

	i = 0;
	line = get_next_line(fd);
	while (line)
	{
		i++;
		free(line);
		line = get_next_line(fd);
	}
	return (i);
}
