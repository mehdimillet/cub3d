/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: memillet <memillet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/15 12:05:37 by memillet          #+#    #+#             */
/*   Updated: 2026/06/17 08:41:53 by memillet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../../headers/cub3d.h"

int	check_all_seen(t_cub *info)
{
	int	i;

	i = 0;
	while (i < 6)
	{
		if (info->seen[i] == 0)
			return (error_msg("Error\nMissing element\n"), 1);
		i++;
	}
	return (0);
}

int info_distrib(char **file, t_cub *info)
{
	int	i;
	int	j;

	i = 0;
	while (file[i])
	{
		if (choose_texture(info, file[i]) != 0)
			return (1);
		i++;
	}
	return (0);
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
	close (fd);
	fd = get_fd(av[1]);
	file = read_file(fd, len);
	close(fd);
	if (info_distrib(file, info) != 0)
		return (1);
	if (check_all_seen(info) != 0)
		return (1);
	return(0);
}
