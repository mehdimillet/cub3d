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

int	choose_texture(t_cub *info, char *line)
{
	if (line[0] == 'N' && line[1] == 'O' && (line[2] == ' ' || line[2] == '\t'))
	{
		if (info->seen[NO] == 1)
			return (error_msg("Error\nDuplicate NO\n"), 1);
		info->seen[NO] = 1;
		stock_texture(&info->tex[0], line);
	}
	else if (line[0] == 'S' && line[1] == 'O' && (line[2] == ' ' || line[2] == '\t'))
	{
		if (info->seen[SO] == 1)
			return (error_msg("Error\nDuplicate NO\n"), 1);
		info->seen[SO] = 1;
		stock_texture(&info->tex[1], line);
	}
	else if (line[0] == 'W' && line[1] == 'E' && (line[2] == ' ' || line[2] == '\t'))
	{
		if (info->seen[WE] == 1)
			return (error_msg("Error\nDuplicate NO\n"), 1);
		info->seen[WE] = 1;
		stock_texture(&info->tex[2], line);
	}
	else if (line[0] == 'E' && line[1] == 'A' && (line[2] == ' ' || line[2] == '\t'))
	{
		if (info->seen[EA] == 1)
			return (error_msg("Error\nDuplicate NO\n"), 1);
		info->seen[EA] = 1;
		stock_texture(&info->tex[3], line);
	}
	else
	{
		if (choose_fc(info, line) != 0)
			return (1);
	}
	return (0);
}

void	stock_texture(t_texture *tex, char *line)
{
	int	i;
	int	j;

	i = 2;
	j = 0;
	while (line[i] == ' ' || line[i] == '\t')
		i++;
	tex->path = ft_strdup(&line[i]);
}
