/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_texture.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: memillet <memillet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/17 07:17:39 by memillet          #+#    #+#             */
/*   Updated: 2026/08/04 13:24:23 by memillet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	check_dup(t_cub *info, int idx)
{
	if (info->seen[idx] == 1)
		return (error_msg("Error\nDuplicate NO\n"), 1);
	return (0);
}

static int	set_texture(t_cub *info, char *line, int idx)
{
	if (check_dup(info, idx))
		return (1);
	info->seen[idx] = 1;
	if (idx == D)
		stock_texture(&info->tex[4], line, idx);
	else
		stock_texture(&info->tex[idx], line, idx);
	return (0);
}

static int	try_cardinal(t_cub *info, char *line)
{
	int	c2;

	c2 = (line[2] == ' ' || line[2] == '\t');
	if (line[0] == 'N' && line[1] == 'O' && c2)
		return (set_texture(info, line, NO));
	else if (line[0] == 'S' && line[1] == 'O' && c2)
		return (set_texture(info, line, SO));
	else if (line[0] == 'W' && line[1] == 'E' && c2)
		return (set_texture(info, line, WE));
	else if (line[0] == 'E' && line[1] == 'A' && c2)
		return (set_texture(info, line, EA));
	else if (line[0] == 'D' && (line[1] == ' ' || line[1] == '\t'))
		return (set_texture(info, line, D));
	else
		return (choose_fc(info, line));
}

int	choose_texture(t_cub *info, char *line)
{
	return (try_cardinal(info, line));
}

void	stock_texture(t_texture *tex, char *line, int id)
{
	int	i;

	if (id == D)
	{
		i = 1;
		while (line[i] == ' ' || line[i] == '\t')
			i++;
		tex->path = ft_strdup(&line[i]);
	}
	else
	{
		i = 2;
		while (line[i] == ' ' || line[i] == '\t')
			i++;
		tex->path = ft_strdup(&line[i]);
	}
}
