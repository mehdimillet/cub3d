/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: memillet <memillet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/15 12:05:37 by memillet          #+#    #+#             */
/*   Updated: 2026/06/18 12:16:16 by memillet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../../headers/cub3d.h"

int	is_know(char *line)
{
	if (line[0] == 'N' && line[1] == 'O')
		return (0);
	else if (line[0] == 'S' && line[1] == 'O')
		return(0);
	else if (line[0] == 'W' && line[1] == 'E')
		return (0);
	else if (line[0] == 'E' && line[1] == 'A')
		return (0);
	else if (line[0] == 'F' || line[0] == 'C')
		return (0);
	return (1);
}

int	check_all_seen(t_cub *info)
{
	int	i;

	i = 0;
	while (i < 6)
	{
		if (info->seen[i] == 0)
			return (error_msg("Error\nMissing element or invalid element\n"), 1);
		i++;
	}
	return (0);
}

int info_distrib(char **file, t_cub *info)
{
	int	i;

	i = 0;
	while (file[i])
	{
		if (is_blank_line(file[i]))
		{
			i++;
			continue;
		}
		if (is_know(file[i]) == 0)
		{
			if (choose_texture(info, file[i]) != 0)
				return (1);
			i++;
		}
		else
		{
			if (check_all_seen(info) == 0)
				return (info->map_start = i, 0);
			return(1);
		}
	}
	return (error_msg(("Error\nNo map found\n")), 1);
}

int start(char **av, t_cub *info)
{
	int		fd;
	int		len;
	char	**file;

	if (check_filename(av[1]) != 0)
		return (1);
	fd = get_fd(av[1]);
	len = count_line(fd);
	info->nb_line = len;
	close (fd);
	fd = get_fd(av[1]);
	file = read_file(fd, len);
	close(fd);
	if (info_distrib(file, info) != 0)
		return (1);
	file_to_map(file, info);
	free_tab(file);
	return(0);
}
