/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_texture.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: memillet <memillet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/17 07:17:39 by memillet          #+#    #+#             */
/*   Updated: 2026/06/25 15:05:52 by memillet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers/cub3d.h"

static int	check_dup(t_cub *info, int idx)
{
	if (info->seen[idx] == 1)
		return (error_msg("Error\nDuplicate NO\n"), 1);
	return (0);
}

static int	try_cardinal(t_cub *info, char *line)
{
	int	c2;

	c2 = line[2] == ' ' || line[2] == '\t';
	if (line[0] == 'N' && line[1] == 'O' && c2)
	{
		if (check_dup(info, NO))
			return (1);
		info->seen[NO] = 1;
		stock_texture(&info->tex[0], line);
	}
	else if (line[0] == 'S' && line[1] == 'O' && c2)
	{
		if (check_dup(info, SO))
			return (1);
		info->seen[SO] = 1;
		stock_texture(&info->tex[1], line);
	}
	else if (line[0] == 'W' && line[1] == 'E' && c2)
	{
		if (check_dup(info, WE))
			return (1);
		info->seen[WE] = 1;
		stock_texture(&info->tex[2], line);
	}
	else if (line[0] == 'E' && line[1] == 'A' && c2)
	{
		if (check_dup(info, EA))
			return (1);
		info->seen[EA] = 1;
		stock_texture(&info->tex[3], line);
	}
	else
		return (choose_fc(info, line));
	return (0);
}

int	choose_texture(t_cub *info, char *line)
{
	return (try_cardinal(info, line));
}

void	stock_texture(t_texture *tex, char *line)
{
	int	i;

	i = 2;
	while (line[i] == ' ' || line[i] == '\t')
		i++;
	tex->path = ft_strdup(&line[i]);
}
